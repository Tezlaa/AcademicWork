from dataclasses import dataclass
from datetime import datetime
from typing import Optional


class PassProductError(Exception):
    def __init__(self) -> None:
        super().__init__('You need to pass a code or product name')


@dataclass
class ProductInfo:
    name: str
    price: int
    fee: float = 0


class ProductDatabase:
    PRODUCTS = {
        1: ProductInfo(name='Banane', price=1000, fee=10),
        2: ProductInfo(name='Apple', price=50, fee=0),
        3: ProductInfo(name='Orange', price=100, fee=5),
        4: ProductInfo(name='Grapes', price=200, fee=15),
        5: ProductInfo(name='Mango', price=150, fee=12),
        6: ProductInfo(name='Pineapple', price=300, fee=20),
        7: ProductInfo(name='Watermelon', price=250, fee=18),
        8: ProductInfo(name='Strawberry', price=120, fee=8),
        9: ProductInfo(name='Cherry', price=80, fee=6),
        10: ProductInfo(name='Pear', price=75, fee=5),
    }
    
    def _get_product_by_name(self, name: str) -> tuple[int, ProductInfo]:
        for code, product in self.PRODUCTS.items():
            if product.name == name:
                return code, product
        raise ValueError(f'Not found product by name {name}')

    def _get_product_by_code(self, code: int) -> tuple[int, ProductInfo]:
        product = self.PRODUCTS.get(code)
        if product is None:
            raise ValueError(f'Not found product by code {code}')
        return code, product


class Product(ProductDatabase):
    def __init__(self,
                 code: Optional[int] = None,
                 name: Optional[str] = None,
                 dirty_price: Optional[float] = None,
                 fee: float = 0) -> None:
        
        if code is not None:
            code, self.product = self._get_product_by_code(code)
        elif name is not None:
            code, self.product = self._get_product_by_name(name)
        else:
            raise PassProductError
        
        self._fee = self.product.fee
        self._dirty_price = self.product.price
        self.name = self.product.name
        self.code = code
    
    def _get_price(self) -> float:
        return self._dirty_price - self._fee
    
    def __str__(self) -> str:
        return f'\n| {self.code} | Name: {self.name}. Price: {self.price}\n'
    
    price = property(_get_price)


class Cheque:
    def __init__(self, products: list[Product], tax: float) -> None:
        self.products = products
        self.tax = tax
    
    def __prices_generator(self, use_tax: bool = False):
        for product in self.products:
            if use_tax:
                yield product.price * self.tax
                
            yield product.price
    
    def __str__(self) -> str:
        products_sum = sum(self.__prices_generator())
        products_with_tax = sum(self.__prices_generator(use_tax=True))
        datetime_now = datetime.now()
        date = datetime_now.strftime("%m/%d/%Y")
        time = datetime_now.strftime("%H:%M:%S")
        
        return (
            f'Date: {date}\n'
            f'Time: {time}\n'
            f'Product tax: {self.tax * 100}%\n\n'
            f'Products count: {len(self.products)}'
            f'{self.products}'
            f'\nSum: {products_with_tax}\n'
            f'Sum without tax: {products_sum}'
        )
        
        
class POS:
    tax: float = 0.25
    products: list[Product] = []
    Cheques: list[Cheque] = []
        
    def __init__(self, departament: str, product_limit: int = 5) -> None:
        self.departament = departament
        self.product_limit = product_limit
    
    def __valid_size(self, new_products_size: int) -> None | Exception:
        if len(self.products) + new_products_size > self.product_limit:
            raise Exception(f'Size out of the size limit {self.product_limit}')
    
    def add_product(self, name: Optional[str] = None, code: Optional[int] = None) -> None:
        if name is not None or code is not None:
            raise PassProductError
        self.__valid_size(1)
        self.products.append(Product(code, name))
    
    def add_products(self, products: list[Product]) -> None:
        self.__valid_size(len(products))
        self.products.extend(products)
    
    # TODO method for created cheque
    

if __name__ == "__main__":
    pass
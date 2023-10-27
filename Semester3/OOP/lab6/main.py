from dataclasses import dataclass
from datetime import datetime
from typing import Optional


class PassProductError(Exception):
    def __init__(self) -> None:
        super().__init__('You need to pass a code or product name')


@dataclass
class ProductInfo:
    name: str
    price: float
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
    
    def append(self, name: str, price: float, fee: float = 0, code: Optional[int] = None) -> None:
        if code is None:
            code = len(self.PRODUCTS) + 1
        self.PRODUCTS.update({code: ProductInfo(name, price, fee)})
    
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
                 name: Optional[str] = None) -> None:
        
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
    
    def __repr__(self) -> str:
        return f'\n| {self.code} | Name: {self.name}. Price: {self.price}\n'
    
    def __str__(self) -> str:
        return super().__repr__()
    
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
            f'\n{"-" * 30}\n'
            f'Date: {date}\n'
            f'Time: {time}\n'
            f'Product tax: {self.tax * 100}%\n\n'
            f'Products count: {len(self.products)}\n'
            f'{self.products}'
            f'\nSum: {products_with_tax}\n'
            f'Sum without tax: {products_sum}'
            f'\n{"-" * 30}\n'
        )
        
        
class POS:
    tax: float = 0.25
    _products: list[Product] = []
    _cheques: list[Cheque] = []
        
    def __init__(self, departament: str, product_limit: int = 5) -> None:
        self.departament = departament
        self.product_limit = product_limit
    
    def __valid_size(self, new_products_size: int) -> None | Exception:
        if len(self._products) + new_products_size > self.product_limit:
            raise Exception(f'Size out of the size limit {self.product_limit}')
    
    def __sweep_up_products(self) -> list[Product]:
        products = self._products.copy()
        self._products.clear()
        return products
    
    def add_product(self, name: Optional[str] = None, code: Optional[int] = None) -> Product:
        if name is None and code is None:
            raise PassProductError
        self.__valid_size(1)
        product = Product(code, name)
        self._products.append(product)
        
        return product
    
    def add_product_inctances(self, products: list[Product]) -> None:
        self.__valid_size(len(products))
        self._products.extend(products)
    
    def created_cheque(self) -> Cheque:
        products = self.__sweep_up_products()
        cheque = Cheque(products, self.tax)
        self._cheques.append(cheque)
        return cheque
    
    def get_cheques_history(self) -> list[Cheque]:
        return self._cheques
    
    def get_current_products(self) -> list[Product]:
        return self._products
    
    cheques_history = property(get_cheques_history)
    products = property(get_current_products)


class ConsoleMenu:
    def __init__(self, department_name: str, product_limit: int):
        self.pos = POS(department_name, product_limit)
        self.product_database = ProductDatabase()
    
    def display_menu(self):
        print("\nCash Register Simulator Menu:")
        print("1. Add a product")
        print("2. Create a new cheque")
        print("3. View cheques history")
        print("4. Exit")

    def add_product(self):
        print('Write "your_code -c" or "your_product_name -n" or if you want to create and add product, write --create')
        product_input = input(">>> ")
        
        if product_input.strip().find('--create') != -1:
            self.create_product()
            return
        
        product_filter = {'code': None, 'name': None}
        split_code, split_name = product_input.split(' -c'), product_input.split(' -n')
        
        if len(split_code) >= 2:
            product_filter['code'] = int(split_code[0])  # type: ignore
        if len(split_name) >= 2:
            product_filter['name'] = split_name[0]  # type: ignore

        try:
            product = self.pos.add_product(**product_filter)
            print(f"Added {product.name} to the department.")
        except PassProductError:
            print("Please provide a product name or code.")
        except ValueError:
            print("Not found this product. Try again.")
            
    def create_product(self):
        code = int(input('\nWrite code for product: '))
        name = input('Write name for product: ')
        price = float(input('Write price for product: '))
        fee = float(input('Write fee fro your product:'))
        
        self.product_database.append(name, price, fee, code)
        
        self.pos.add_product(code=code, name=name)
        print(f"Added {name} to the department.")
    
    def create_cheque(self):
        cheque = self.pos.created_cheque()
        print("Cheque created. Details:")
        print(cheque)

    def view_cheques_history(self):
        cheques_history = self.pos.cheques_history
        if cheques_history:
            print("Cheques History:")
            for index, cheque in enumerate(cheques_history, start=1):
                print(f"Cheque {index}:")
                print(cheque)
        else:
            print("No cheques in the history.")

    def run(self):
        while True:
            self.display_menu()
            choice = input("Enter your choice (1/2/3/4): ")

            if choice == "1":
                self.add_product()
            elif choice == "2":
                self.create_cheque()
            elif choice == "3":
                self.view_cheques_history()
            elif choice == "4":
                print("Exiting the Cash Register Simulator. Goodbye!")
                break
            else:
                print("Invalid choice. Please select a valid option (1/2/3/4).")


if __name__ == "__main__":
    department_name = input("Enter the name of the department: ")
    product_limit = int(input("Enter the product limit for the department: "))
    cash_register = ConsoleMenu(department_name, product_limit)
    cash_register.run()

def valid_class_receipt(func):
    def wrapper(*args, **kwarks):
        class_ = args[1]
        if not isinstance(class_, SimpleFraction):
            raise TypeError(f'{type(class_)} is not the class {SimpleFraction}')
        return func(*args, **kwarks)
    return wrapper


class SimpleFraction:
    def __init__(self, number_ceiling: float | int, number_floor: float | int):
        self.number_ceiling = number_ceiling
        self.number_floor = number_floor
    
    @valid_class_receipt
    def __add__(self, other):
        ceiling = (self.number_ceiling * other.number_floor) + (other.number_ceiling * self.number_floor)
        floor = self.number_floor * other.number_floor
        return SimpleFraction(ceiling, floor)
    
    @valid_class_receipt
    def __sub__(self, other):
        ceiling = (self.number_ceiling * other.number_floor) - (other.number_ceiling * self.number_floor)
        floor = self.number_floor * other.number_floor
        return SimpleFraction(ceiling, floor)
    
    @valid_class_receipt
    def __mul__(self, other):
        ceiling = self.number_ceiling * other.number_ceiling
        floor = self.number_floor * other.number_floor
        return SimpleFraction(ceiling, floor)
    
    @valid_class_receipt
    def __truediv__(self, other):
        ceiling = self.number_ceiling * other.number_floor
        floor = self.number_floor * other.number_ceiling
        return SimpleFraction(ceiling, floor)
    
    def __repr__(self) -> str:
        return f'{self.number_ceiling}/{self.number_floor}'
    
    
if __name__ == "__main__":
    fraction1 = SimpleFraction(5, 1)
    fraction2 = SimpleFraction(4, 10)
    
    result = fraction1 + 1
    print(result)

    result = fraction1 - fraction2
    print(result)

    result = fraction1 * fraction2
    print(result)

    result = fraction1 / fraction2
    print(result)
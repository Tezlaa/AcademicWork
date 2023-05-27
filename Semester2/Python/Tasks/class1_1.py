from math import gcd


def valid_class_receipt(func):
    """Decorator to validate the second argument"""
    def wrapper(*args, **kwargs):
        class_ = args[1]
        if not isinstance(class_, SimpleFraction):
            raise TypeError(f'{type(class_)} is not the class {SimpleFraction}')
        return func(*args, **kwargs)
    return wrapper


class SimpleFraction:
    def __init__(self, number_ceiling: float | int, number_floor: float | int):
        self.number_ceiling = number_ceiling
        self.number_floor = number_floor
    
    @valid_class_receipt
    def __add__(self, other):
        """Addition operator overload."""
        ceiling = (self.number_ceiling * other.number_floor) + (other.number_ceiling * self.number_floor)
        floor = self.number_floor * other.number_floor
        result = SimpleFraction(ceiling, floor)
        result.simplify()
        return result
    
    @valid_class_receipt
    def __sub__(self, other):
        """Subtraction operator overload."""
        ceiling = (self.number_ceiling * other.number_floor) - (other.number_ceiling * self.number_floor)
        floor = self.number_floor * other.number_floor
        result = SimpleFraction(ceiling, floor)
        result.simplify()
        return result
    
    @valid_class_receipt
    def __mul__(self, other):
        """Multiplication operator overload."""
        ceiling = self.number_ceiling * other.number_ceiling
        floor = self.number_floor * other.number_floor
        result = SimpleFraction(ceiling, floor)
        result.simplify()
        return result
    
    @valid_class_receipt
    def __truediv__(self, other):
        """Division operator overload."""
        ceiling = self.number_ceiling * other.number_floor
        floor = self.number_floor * other.number_ceiling
        result = SimpleFraction(ceiling, floor)
        result.simplify()
        return result
    
    def simplify(self):
        """Simplify the fraction to its minimal expression."""
        common_divisor = gcd(self.number_ceiling, self.number_floor)
        self.number_ceiling //= common_divisor
        self.number_floor //= common_divisor
    
    def __repr__(self) -> str:
        """Representation of the fraction."""
        return f'{self.number_ceiling}/{self.number_floor}'


if __name__ == "__main__":
    fraction1 = SimpleFraction(5, 1)
    fraction2 = SimpleFraction(4, 10)
    
    result = fraction1 + fraction2
    print(result)

    result = fraction1 - fraction2
    print(result)

    result = fraction1 * fraction2
    print(result)

    result = fraction1 / fraction2
    print(result)

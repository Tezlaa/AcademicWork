class SempleFraction:
    def __init__(self, number: int):
        self.number = number
    
    def __add__(self, other):
        return SempleFraction(self.number + other.number)
    
    def __sub__(self, other):
        return SempleFraction(self.number - other.number)
    
    def __mul__(self, other):
        return SempleFraction(self.number * other.number)
    
    def __repr__(self) -> str:
        return f'{self.number}'
    
    
if __name__ == "__main__":
    a = SempleFraction(1)
    b = SempleFraction(3)
    
    print(a + b + b)
    print(a - b)
    print(a * b)
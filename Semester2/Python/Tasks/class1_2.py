
class MoneyBox:
    def __init__(self, money: float = 0, max_value: float | int = 10):
        self.max_value = max_value
        self.money = self.valid_adding(money)

    def __repr__(self):
        return f'SIZE BOX: {self.max_value}\nIN THE BOX: {self.money}'
        
    def __add__(self, other):
        return MoneyBox(self.valid_adding(self.money + other), self.max_value)
    
    def add(self, how_much_money: float | int):
        """Add in the money box money

        Args:
            how_much_money (float | int): how much you needed add in the box
        """
        
        self.money += self.valid_adding(how_much_money)
        
    def possible_adding(self, how_much_money: float | int) -> bool:
        """check if you can add in the box same money

        Args:
            how_much_money (float | int): money that need to check

        Returns:
            bool: Returns True if you can add this money to the box,
                  returns False if you can`t add this money to the box
        """
        try:
            self.valid_adding(how_much_money)
            return True
        except ValueError:
            return False
        
    def valid_adding(self, how_much_money: float | int) -> float | int:
        """
        Validation money, check size box, if size box less than needed add - raise ValueError

        Args:
            how_much_money (float | int): How much you need to add

        Raises:
            ValueError: The size of the box less than you needed to add 

        Returns:
            float | int: returns how_much_money
        """
        
        if self.max_value >= how_much_money:
            return how_much_money
        raise ValueError(f'{how_much_money} > {self.max_value} The size of the box'
                         f'less than you needed to add')


if __name__ == "__main__":
    box = MoneyBox(max_value=15)
    
    # Test adding in the box different quantity money:
    for money in range(1, 30, 4):
        print(f'check possible adding in the box: \n{box} \n{money}:', box.possible_adding(money), end='\n\n')
    
    # Test adding
    print('start money box:\n', box)
    box.add(9)
    print('\nafter adding 9:\n', box, end='\n\n')
    box += 3
    print('after adding via box += 3\n', box, end='\n\n')
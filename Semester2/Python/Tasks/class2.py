from typing import List

""" Style """
RED = '\x1b[31m'
GREEN = '\x1b[32m'
WHITE = '\x1b[37m'
YELLOW = '\x1b[33m'
STRONG_TEXT_STYLE = '\x1b[1m'


class Buffer:
    """ Spliting sequence numbers and finding their sum
    
    Args:
        all_number (List[int]): buffer-list with all numbers
        sum_five_numbers (List[int]): buffer-list with the sum
    """
    def __init__(self) -> None:
        self.all_numbers = []
        self.sum_five_numbers = []
    
    def add_sequence(self, sequence: List[int]) -> None | ValueError:
        """ Adding your sequence to the buffer and valid

        Args:
            sequence (List[int]): your list with numbers for adding
                Example: [1, 3, 5, 4, 3]

        Raises:
            ValueError: If numbers in the buffer not enough to caclulate the sum
        """
        self.all_numbers.extend(sequence)
        
        if len(self.all_numbers) < 5:
            raise ValueError
    
    def calculate_the_sum(self) -> list[int]:
        """ Calculate the sum using recursion method
        
        basic situation:
            if the length all numbers in the buffer is less than 5
        recursion situation:
            the length all number in the buffer is more than 5
        
        Returns:
            list[int]: list with result sum
        """
        if len(self.all_numbers) >= 5:
            self.sum_five_numbers.append(sum(self.all_numbers[:5]))
            del self.all_numbers[:5]
            
            return self.calculate_the_sum()
        
        result = self.sum_five_numbers[:]
        self.sum_five_numbers.clear()
        return result
            

if __name__ == "__main__":
    print(f'{STRONG_TEXT_STYLE}Write the numbers using spase, example: 1 2 3 1 4...')
    sequence = Buffer()
    
    while True:
        numbers = list(map(int, input(f'{GREEN}>>{WHITE} ').split()))
        
        try:
            sequence.add_sequence(numbers)
        except ValueError:
            print((f'{RED}Is not enough to calculate the sum\n'
                   f'Need 5 number but now you have {len(sequence.all_numbers)} numbers\n'
                   f': {sequence.all_numbers}\n{YELLOW}'
                   f'Add {5 - len(sequence.all_numbers)}{WHITE}'))
            continue
        
        sum_five_numbers = sequence.calculate_the_sum()
        if len(sum_five_numbers) == 1:
            sum_five_numbers = str(*sum_five_numbers)

        if len(sequence.all_numbers) > 0:
            print(f'\n{GREEN}Result sum: {sum_five_numbers}\n{YELLOW}'
                  f'You have in the buffer: {sequence.all_numbers}{WHITE}')
        else:
            print(f'\n{GREEN}Result sum: {sum_five_numbers}{WHITE}')
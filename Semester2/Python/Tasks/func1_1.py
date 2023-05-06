from typing import List
import random


def create_random_array(len_array: int, min: int = 1, max: int = 100) -> List[int]:
    """Func for creating random array

    Args:
        len_array (int): how long is the array
        min (int, optional): min for the array. Defaults to 1.
        max (int, optional): max for the array. Defaults to 100.

    Returns:
        List[int]: random list
    """
    return [random.randint(min, max) for _ in range(len_array)]


def modify_list(array: List[int]) -> None:
    """remake list

    Args:
        array (List[int]): array which need to modify,
                           delete odd digit and share on 2
    """
    array[:] = [digit // 2 for digit in array if not digit % 2]


if __name__ == "__main__":
    how_many_arrays = int(input('Write how many test arrays: '))
    
    test_list = [
        create_random_array(random.randint(4, 12)) for _ in range(how_many_arrays)
    ]
    
    print(f'\nAll test list with arrays: \n{test_list}\n')
    for array in test_list:
        print(f'Start array: {array}')
        
        modify_list(array)
        
        print(f'Result array: {array}\n')
    print(f'Result test list with arrays: \n{test_list}\n')

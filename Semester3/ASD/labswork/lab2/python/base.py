import time
import random

from PythonASDLib.base import AlgorithmBase


class CustomizeAlgorithmBase(AlgorithmBase):
    
    def __init__(self,
                 excel_table_char: str,
                 excel_table_index: int,
                 element_type: int | float) -> None:
        
        self.element_type = element_type
        super().__init__(excel_table_char, excel_table_index)
    
    def algorithm(self, array: list[int | float], search_element: int | float):
        pass

    def prestart_algorithm(self, array: list[int | float]) -> list[int | float]:
        return array

    def get_random_element_from_array(self, array: list[int | float]) -> int | float:
        random_index = len(array) // 2
        return array[random_index]
    
    def create_array(self, length: int) -> list[int | float]:
        element_range = (0, length)

        if isinstance(self.element_type, float):
            return random.sample(
                [random.uniform(*element_range) for _ in range(length)], length
            )
        
        elif isinstance(self.element_type, int):
            return random.sample(range(*element_range), length)
        
        raise ValueError('Select correct element_type')
    
    def _banchmark_algorithm(self, array: list[int | float]) -> float:
        search_element = self.get_random_element_from_array(array)
        array = self.prestart_algorithm(array)
        
        time_start = time.perf_counter()
        self.algorithm(array=array, search_element=search_element)
        return time.perf_counter() - time_start
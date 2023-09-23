from random import randint
import time

from colorama import Fore, Style, init
from openpyxl import load_workbook


class EmptyLengthField(Exception):
    def __init__(self, message='Empty array length field!'):
        super().__init__(message)
    

class ExcelActions:
    def __init__(self, excel_table_char: str,
                 excel_table_index: int) -> None:
        self.excel_table_char = excel_table_char
        self.excel_table_index = excel_table_index
    
        self.cell = self.get_cell()

    def get_cell(self) -> str:
        return "{}{}".format(self.excel_table_char, self.excel_table_index)
    
    def connect_table(self, excel_file_name: str) -> None:
        self.excel_file_name = excel_file_name
        self.workbook = load_workbook(filename=excel_file_name)
        self.sheet = self.workbook.get_sheet_by_name(
            name=self.get_sheet_name()
        )
    
    def save_excel_file(self):
        try:
            self.workbook.save(self.excel_file_name)
        except PermissionError:
            print(f'Close the {self.excel_file_name} file!')

    def set_time(self, value: int | str):
        cell = self.get_cell()
        
        self.sheet[cell] = str(value)
        self.save_excel_file()
        
    def get_value(self, cell: str) -> str:
        return self.sheet[cell].value
    
    def get_sheet_name(self) -> str:
        return str(self.workbook.get_sheet_names()[0])
    
    def _next_excel_index(self) -> int:
        self.excel_table_index += 1
        return self.excel_table_index


class AlgorithmBase(ExcelActions):
    algorithm_name: str
    
    def __str__(self) -> str:
        return f'Algorithm: {self.algorithm_name}'
    
    def algorithm(self, array: list[int]):
        pass
    
    def create_array(self, length: int) -> list[int]:
        return [randint(0, 100_000) for _ in range(length)]
    
    def start(self) -> None | ValueError:
        length_array = self.get_length_array()
        array = self.create_array(length_array)
        time = self._banchmark_algorithm(array)
        time_str = f'{(time):.6f}'
        
        self.__show_info(length_array, time_str)
        self.set_time(time_str)
        self._next_excel_index()
        
        self.start()
    
    def get_length_array(self) -> int:
        value = self.get_value('B' + str(self.excel_table_index))
        if value is None:
            raise EmptyLengthField
        
        return int(value)
    
    def __show_info(self, length_array: int, time: str) -> None:
        init()
        print(f'\n{Style.BRIGHT}{Fore.WHITE}Algorithm: {Fore.GREEN}{self.algorithm_name}{Fore.CYAN}\n'
              f'Time sorting: {Fore.GREEN}{time}{Fore.CYAN}c\n'
              f'Length: {Fore.GREEN}{length_array}{Style.RESET_ALL}\n')
    
    def _banchmark_algorithm(self, array: list[int]) -> float:
        time_start = time.perf_counter()
        self.algorithm(array)
        return time.perf_counter() - time_start
    
    
class StartAlgorithmics:
    def __init__(self, algorithms: list[AlgorithmBase], file_name: str) -> None:
        for algorithm in algorithms:
            algorithm.connect_table(file_name)
            try:
                algorithm.start()
            except EmptyLengthField:
                print(f'End {algorithm}')

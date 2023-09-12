from random import randint
from time import time

from openpyxl import load_workbook


class ExcelActions:
    def __init__(self, excel_table_char: str,
                 excel_table_index: int) -> None:
        self.excel_table_char = excel_table_char
        self.excel_table_index = excel_table_index
    
        self.cell = "{}{}".format(self.excel_table_char,
                                  self.excel_table_index)

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

    def set_value(self, value: int | str):
        self.sheet[self.cell] = str(value)
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
    
    def create_array(self, length: int) -> list[int]:
        return [randint(0, 100_000) for _ in range(length)]
    
    def start(self):
        length_array = self.get_length_array()
        print(length_array)
        
    def get_length_array(self) -> int:
        value = self.get_value('B' + str(self.excel_table_index))
        return int(value)
    
    def __str__(self) -> str:
        return f'Algorithm: {self.algorithm_name}'

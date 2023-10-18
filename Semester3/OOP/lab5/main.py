from typing import Any, TypeVar


T = TypeVar('T')


class ArrayBaseMethods:
    def min(self, arg1, arg2, *args) -> Any:
        min_element = arg1 if arg1 < arg2 else arg2
        
        if len(args) > 0:
            for element in args:
                min_element = self.min(min_element, element)
        
        return min_element
    
    def max(self, arg1, arg2, *args) -> Any:
        max_element = arg1 if arg1 > arg2 else arg2
        
        if len(args) > 0:
            for element in args:
                max_element = self.max(max_element, element)
        
        return max_element

    def _max_element_by_type(self, _type: type) -> float | str:
        cases = {
            int: float('inf'),
            float: float('inf'),
            str: ('w' * 100)
        }
        return cases[_type]

    def _min_element_by_type(self, _type: type) -> float | str:
        cases = {
            int: float('-inf'),
            float: float('-inf'),
            str: ''
        }
        return cases[_type]

    def _format_array_type(self, _type: str) -> type:
        match _type:
            case 'int':
                return int
            case 'str':
                return str
            case 'float':
                return float
        
        raise Exception('Not found type ({})'.format(_type))


class Array(ArrayBaseMethods):
    def __init__(self, size: int = 0, _type: str = 'int') -> None:
        self.size = size
        self.__valid_on_empty_size()
        
        self.__len = 0
        self.__zero_elements = self.size
        self.__array_type = self._format_array_type(_type)
        self.__str_array_type = _type
        self.__array = self.__create_array()
        self.__max_element = self._min_element_by_type(self.__array_type)
        self.__min_element = self._max_element_by_type(self.__array_type)

    def __set_max_element(self, element) -> Any:
        self.__max_element = self.max(self.__max_element, element)
        return self.__max_element
    
    def __set_min_element(self, element) -> Any:
        self.__min_element = self.min(self.__min_element, element)
        return self.__min_element
    
    def __get_clear_array(self) -> list:
        array = []
        for element in self._get_array():
            if element != float('inf'):
                array.append(element)
        return array

    @property
    def average(self) -> float:
        
        unavailable_types = ('str', )
        if self.__str_array_type in unavailable_types:
            raise TypeError(f'Type {self.array_type} unsupported average method')
        
        array = self.__get_clear_array()
        return sum(array) / len(array)
    
    @property
    def max_element(self):
        return self.__max_element
    
    @property
    def min_element(self):
        return self.__min_element

    @property
    def array_type(self) -> type:
        return self.__array_type
    
    def __create_array(self) -> list:
        return [float('inf')] * self.size
    
    def _get_array(self):
        self.__valid_on_empty_size()
        return self.__array
    
    def __valid_on_empty_size(self):
        if self.size is not None and self.size <= 0:
            raise Exception('The size of array is less or equal zero : {}'.format(self.size))

    def __getitem__(self, index: int) -> Any:
        array = self._get_array()
        element = array[index]
        if element == float('inf'):
            raise IndexError('Not found element by index {}'.format(index))
        
        return element

    def __setitem__(self, index: int, value: T) -> T:
        array = self._get_array()
        if type(value) is not self.array_type:
            raise TypeError(f'{type(value)} != {self.array_type}')
        
        if not 0 <= index < self.size:
            raise IndexError('Index out of range')
        
        array[index] = value
        self.__len += 1
        self.__zero_elements -= 1
        self.__set_max_element(value)
        self.__set_min_element(value)
        
        return value

    def __len__(self) -> int:
        return self.__len

    def __str__(self) -> str:
        array = self.__get_clear_array()        
        return f'|| {" | ".join(array)} || type: {self.__str_array_type}'


if __name__ == "__main__":
    array = Array(3, 'str')
    
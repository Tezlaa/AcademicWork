from typing import Any


class Array:
    def __init__(self, size: int = 0, _type: str = 'int') -> None:
        self.size = size
        self.__valid_on_empty_size()
        
        self.__array_type = self.__format_array_type(_type)
        self.__str_array_type = _type
        self.empty = True
        self.__array = self.__create_array()
    
    def __format_array_type(self, _type: str) -> type:
        match _type:
            case 'int':
                return int
            case 'str':
                return str
            case 'float':
                return float
        
        raise Exception('Not found type ({})'.format(_type))

    @property
    def array_type(self) -> type:
        return self.__array_type
    
    def _get_array(self):
        self.__valid_on_empty_size()
        return self.__array

    def __setitem__(self, index, value) -> Any:
        array = self._get_array()
        if type(value) is not self.array_type:
            raise TypeError(f'{type(value)} != {self.array_type}')
        
        if not 0 <= index < self.size:
            raise IndexError('Index out of range')
        
        array[index] = value
        self.empty = False
        
        return value
    
    def __create_array(self) -> list:
        return [float('inf')] * self.size

    def __str__(self) -> str:
        array = []
        for element in self._get_array():
            if element != float('inf'):
                array.append(element)
        
        return f'|| {" | ".join(array)} || type: {self.__str_array_type}'
    
    def __valid_on_empty_size(self):
        if self.size is not None and self.size <= 0:
            raise Exception('The size of array is less or equal zero : {}'.format(self.size))


if __name__ == "__main__":
    array = Array(3, 'str')
    print(array)
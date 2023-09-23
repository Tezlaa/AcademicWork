from base import CustomizeAlgorithmBase


class LineSearch(CustomizeAlgorithmBase):
    algorithm_name = 'Line search'
    
    def algorithm(self, array: list[int | float], search_element: int | float):
        for i in range(len(array)):
            if array[i] == search_element:
                return i
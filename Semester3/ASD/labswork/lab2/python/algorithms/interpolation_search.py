from base import CustomizeAlgorithmBase


class InterpolationSearch(CustomizeAlgorithmBase):
    algorithm_name = 'Interpolation search'
    
    def algorithm(self, array: list[int | float], search_element: int | float):
        left, right = 0, len(array) - 1
        
        while left <= right and search_element >= array[left] and search_element <= array[right]:
            pos = left + ((search_element - array[left]) * (right - left)) // (array[right] - array[left])
            if array[pos] == search_element:
                return pos
            if array[pos] < search_element:
                left = pos + 1
            else:
                right = pos - 1
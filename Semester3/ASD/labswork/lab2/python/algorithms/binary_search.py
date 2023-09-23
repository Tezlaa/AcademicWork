from base import CustomizeAlgorithmBase


class BinarySearch(CustomizeAlgorithmBase):
    algorithm_name = 'Binary search'
    
    def prestart_algorithm(self, array: list[int | float]) -> list[int | float]:
        return sorted(array)
    
    def algorithm(self, array: list[int | float], search_element: int | float):
        left, right = 0, len(array) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            if array[mid] == search_element:
                return mid
            if array[mid] < search_element:
                left = mid + 1
            else:
                right = mid - 1
from base import CustomizeAlgorithmBase


class BinarySearchFromBorder(CustomizeAlgorithmBase):
    algorithm_name = 'Binary search from border'
    
    def prestart_algorithm(self, array: list[int | float]) -> list[int | float]:
        return sorted(array)
    
    def algorithm(self, array: list[int | float], search_element: int | float):
        left, right = 0, len(array) - 1
        result = -1

        while left <= right:
            mid = left + (right - left) // 2
            if array[mid] == search_element:
                result = mid
                left = mid + 1
            elif array[mid] < search_element:
                left = mid + 1
            else:
                right = mid - 1
        
        return result
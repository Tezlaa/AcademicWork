from PythonASDLib.base import AlgorithmBase


class MergeSort(AlgorithmBase):
    algorithm_name = 'Merge Sort'
    
    def algorithm(self, array: list[int]) -> list[int]:
        if not len(array) > 1:
            return array
        mid = len(array) // 2
        left = array[:mid]
        right = array[mid:]

        # Recursive call on each half
        self.algorithm(left)
        self.algorithm(right)

        # Two iterators for traversing the two halves
        i = 0
        j = 0

        # Iterator for the main list
        k = 0

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                # The value from the left half has been used
                array[k] = left[i]
                # Move the iterator forward
                i += 1
            else:
                array[k] = right[j]
                j += 1
            # Move to the next slot
            k += 1

        # For all the remaining values
        while i < len(left):
            array[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            array[k] = right[j]
            j += 1
            k += 1
        
        return array
import itertools
import os
import random
import time


class SortAlgorithms:
    """ Class with different sort algoritms """
    
    def __init__(self, array: list[int]) -> None:
        self.array = array
    
    def bubble_sort(self):
        """ Perform bubble sort on the given array.

        Args:
            array(list): The list to be sorted.

        Yields:
            array(list): The current state of the array after each swap operation.
        """
        
        length = len(array)
        for i in range(length):
            for j in range(0, length - i - 1):
                if array[j] > array[j + 1]:
                    array[j], array[j + 1] = array[j + 1], array[j]
                    yield array


class VisualizationSorting(SortAlgorithms):
    """ Class for visualizations sorting algorithms

    Args:
        SortAlgoritms: sorting algorithms
    """
    
    def __init__(self, array: list[int]) -> None:
        """
        Args:
            array (list[int]): list for the sorting
        """
        super().__init__(array)

    def start_visualizetion(self, delay_sec: float = 0) -> None:
        """ Visualize the sorting process using bubble sort algorithm.
        
        Args:
            delay_sec(float): delay in seconds for visualisation bars. Default 0
        """
        for array in itertools.islice(self.bubble_sort(), 1000):
            self.print_bar(array, delay_sec)
    
    @staticmethod
    def print_bar(array: list[int], delay_sec: float) -> None:
        """ Method for visualizations bars in array

        Args:
            array (list[float]): array for visualizations
        """
        # set sleep and clear console
        time.sleep(delay_sec)
        os.system('cls')

        max_value = max(array)
        for i in range(max_value, 0, -1):
            for bar in array:
                if bar >= i:
                    print(' [] ', end='')
                else:
                    print('    ', end='')
            print()


if __name__ == "__main__":
    # create random array
    array = random.sample(range(1, 50), 45)
    
    sorts = VisualizationSorting(array)
    sorts.start_visualizetion(delay_sec=0.01)
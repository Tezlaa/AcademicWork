from algorithms.bubble_sort import BubbleSort
from algorithms.counting_sort import CountingSort
from algorithms.merge_sort import MergeSort

from base import AlgorithmBase


class Sort:
    def __init__(self, algorithms: list[AlgorithmBase], file_name: str) -> None:
        algorithms[0].create_array(10)
        for algorithm in algorithms:
            algorithm.connect_table(file_name)
            algorithm.start()


if __name__ == "__main__":
    file_name = 'ResultLab1.xlsx'
    
    a = BubbleSort('E', 3)
    b = CountingSort('E', 26)
    c = MergeSort('E', 49)
    
    Sort([a, b, c], file_name)
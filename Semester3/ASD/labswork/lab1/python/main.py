from algorithms.bubble_sort import BubbleSort
from algorithms.counting_sort import CountingSort
from algorithms.merge_sort import MergeSort

from PythonASDLib.base import StartAlgorithmics


if __name__ == "__main__":
    file_name = 'labswork/lab1/ResultLab1.xlsx'
    
    bubble = BubbleSort('E', 3)
    counting = CountingSort('E', 26)
    merge = MergeSort('E', 49)
    
    StartAlgorithmics([bubble, counting, merge], file_name)
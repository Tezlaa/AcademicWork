from algorithms.binary_search import BinarySearch
from algorithms.binary_search_from_border import BinarySearchFromBorder
from algorithms.interpolation_search import InterpolationSearch
from algorithms.line_search import LineSearch

from PythonASDLib.base import StartAlgorithmics


if __name__ == "__main__":
    file_name = 'labswork/lab2/ResultLab2.xlsx'
    
    line = LineSearch('D', 3, int())
    binary = BinarySearch('D', 26, int())
    interpolation = InterpolationSearch('D', 49, int())
    binary_from_border = BinarySearchFromBorder('D', 72, int())
    
    StartAlgorithmics(
        algorithms=[line, binary, interpolation, binary_from_border],
        file_name=file_name
    )

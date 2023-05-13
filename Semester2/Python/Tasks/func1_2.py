from typing import List
from math import sin, cos

from func1_1 import create_random_array


def Z(x: List[int]) -> List[float]:
    """Calculate Z argument for all elements in the list x.

    Args:
        x (List[int]): List with digits.

    Returns:
        List[float]: List with the result for each element in x.
    """
    
    return [(sin(xi) - 1) / cos(xi)**2 + 1 for xi in x]


if __name__ == "__main__":
    n = int(input("'n': "))
    x = create_random_array(n)
    print("'x': ", *x, '\n')

    Z_list = Z(x)

    F = []
    for i in range(0, n):
        Z_i = Z_list[i]
        F.append((cos(Z_i)**2) / (Z_i + 3.5)**(1. / 3.))
    
    for i, result in enumerate(F):
        print(f'F({i + 1}) - {result}')
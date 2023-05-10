from typing import List
from math import sin, cos

from func1_1 import create_random_array


def Z(x: List[int], i: int) -> float:
    """calculate Z argument

    Args:
        x (List[int]): list with digits
        i (int): index for 'x' list

    Returns:
        float: result before calculate
    """
    return (sin(x[i]) - 1) / cos(x[i])**2 + 1


if __name__ == "__main__":
    n = int(input("'n': "))
    x = create_random_array(n)
    print("'x': ", *x, '\n')

    F = []
    for i in range(0, n):
        Z_i = Z(x, i)
        F.append((cos(Z_i)**2) / (Z_i + 3.5)**(1. / 3.))
    
    for i, result in enumerate(F):
        print(f'F({i + 1}) - {result}')
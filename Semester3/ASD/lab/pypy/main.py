import time
from random import randint


def bubble(array: list[int]) -> list[int]:
    n = len(array)
    # optimize code, so if the array is already sorted, it doesn't need
    # to go through the entire process
    swapped = False
    # Traverse through all array elements
    for i in range(n - 1):
        # range(n) also work but outer loop will
        # repeat one time more than needed.
        # Last i elements are already in place
        for j in range(0, n - i - 1):
        
            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if array[j] > array[j + 1]:
                swapped = True
                array[j], array[j + 1] = array[j + 1], array[j]
        if not swapped:
            # if we haven't needed to make a single swap, we
            # can just exit the main loop.
            return array
    return array


def counting(array: list[int]) -> list[int]:
    # Find the maximum element in the array
    maxElement = max(array)
    count_array_length = maxElement + 1
    # Initialize the count_array with (max+1) zeros
    count_array = [0] * count_array_length
    # Step 1 -> Traverse the array and increase
    # the corresponding count for every element by 1
    for el in array:
        count_array[el] += 1
    # Step 2 -> For each element in the count_array,
    # sum up its value with the value of the previous
    # element, and then store that value
    # as the value of the current element
    for i in range(1, count_array_length):
        count_array[i] += count_array[i - 1]
    # Step 3 -> Calculate element position
    # based on the count_array values
    outputArray = [0] * len(array)
    i = len(array) - 1
    while i >= 0:
        currentEl = array[i]
        count_array[currentEl] -= 1
        new_position = count_array[currentEl]
        outputArray[new_position] = currentEl
        i -= 1
    return outputArray


def merge(array: list[int]) -> list[int]:
    if not len(array) > 1:
        return array
    mid = len(array) // 2
    left = array[:mid]
    right = array[mid:]
    # Recursive call on each half
    merge(left)
    merge(right)
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


if __name__ == "__main__":
    for length_array in range(50_000, 1_050_000, 50_000):
        array = [randint(0, 100_000) for _ in range(length_array)]
        time_start = time.perf_counter()
        # merge(array)
        # bubble(array)
        # counting(array)
        print(length_array, " - ", time.perf_counter() - time_start)
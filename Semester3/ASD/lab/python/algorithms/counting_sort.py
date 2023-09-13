from base import AlgorithmBase


class CountingSort(AlgorithmBase):
    algorithm_name = 'Counting Sort'

    def algorithm(self, array: list[int]) -> list[int]:
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

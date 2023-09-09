using System;

class ArraySolution
{
    static void Main()
    {
        double[] array = { -1.0, -5.4, 0.0, 3.1, 9.1, 10.3, 0.0, 32.0, -44.1, 32.0 };
        double min = FindMinimalElement(array);
        double sum = FindSum(array);

        ShowArray(array);
        SortByZero(array);
        ShowArray(array);

        Console.WriteLine($"\nMinimal element in the array: {min}");
        Console.WriteLine($"Sum between positive elements in the array: {sum}");
    }

    /// <summary>
    /// Finds the sum of elements in the array that are located between the first positive element
    /// and the end of the array. If there are no positive elements, the sum is zero.
    /// </summary>
    /// <param name="array">The input array of double values.</param>
    /// <returns>The sum of elements between the first positive element and the end of the array.</returns>
    static double FindSum(double[] array)
    {
        bool foundFirstPositiveIndex = false;
        double sum = 0;

        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] > 0)
            {
                foundFirstPositiveIndex = true;
            }

            if (foundFirstPositiveIndex)
            {
                sum += array[i];
            }
        }
        return sum;
    }

    /// <summary>
    /// Finds the minimal element in the input array.
    /// </summary>
    /// <param name="array">The input array of double values.</param>
    /// <returns>The minimal element in the array.</returns>
    static double FindMinimalElement(double[] array)
    {
        double min = array[0];

        for (int i = 1; i < array.Length; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }

    /// <summary>
    /// Sorts the input array by moving all non-zero elements to the end of the array
    /// and replacing the original positions with zeros.
    /// </summary>
    /// <param name="array">The input array of double values.</param>
    static void SortByZero(double[] array)
    {
        int zeroIndex = array.Length - 1;

        for (int index = array.Length - 1; index >= 0; index--)
        {
            if (array[index] != 0)
            {
                array[zeroIndex] = array[index];
                zeroIndex--;
            }
        }

        for (int i = 0; i <= zeroIndex; i++)
        {
            array[i] = 0;
        }
    }

    /// <summary>
    /// Displays the elements of the input array in a formatted way.
    /// </summary>
    /// <param name="array">The input array of double values.</param>
    static void ShowArray(double[] array)
    {
        Console.Write("[");

        foreach (var element in array)
        {
            Console.Write(element + " ");
        }

        Console.Write("]\n");
    }
}
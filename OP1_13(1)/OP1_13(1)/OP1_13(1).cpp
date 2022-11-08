#include <iostream>
using namespace std;

int main()
{
    int n, i;

    cout << "Write length array: "; cin >> n;

    float *array = new float[n];

    for (i = 0; i < n; i++)
    {
        array[i] = (0.2 + rand() % 15) / 3;
        cout << array[i] << " ";
    }

    return 0;
}

float func(float *a, int length)
{
    float min;

    min = a[0];

    for (int i = 1; i = length; i++)
    {
        -
    }
}
#include <iostream>
using namespace std;

void func(float*, int);
int main()
{
    int n, i;

    cout << "Write length array: "; cin >> n;

    float *array = new float[n];

    for (i = 0; i < n; i++)
    {
        *(array + i) = (0.2 + rand() % 15) / 3;
        cout << *(array + i) << " ";
    }

    cout << "\n\n";

    func(array, n);

    for (i = 0; i < n; i++)
    {
        cout << *(array + i) << " ";
    }

    cout << "\n\n";

    return 0;
}

void func(float *a, int length)
{
    float min;
    int imin;
    
    imin = 0;
    min = *a;

    for (int i = 1; i < length; i++)
    {
        if (min > *(a + i))
        {
            min = *(a + i);
            imin = i;
        }
    }

    for (int i = imin + 1; i < length; i++)
    {
        if (i % 2 != 0)
        {
            *(a + i) *= min;
        }
    }
}
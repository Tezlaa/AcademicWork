#include <iostream>
using namespace std;

int ready(int* , int);
int main()
{
    int n, i, t;

    cout << "Write quantities: "; cin >> n;

    int* array = new int[n];

    for (i=0; i < n; i++)
    {
        *(array + i) = rand() % 26;
        cout << *(array + i) << " ";
    }

    cout << "\n\n\n" << ready(array, n) << endl;

    return 0;
}

int ready(int* arr, int length)
{
    int ready = 0;

    for (int i = 0; i < length; i++)
    {
        if (*(arr + i) >= 20)
        {
            ready += 1;
        }
    }

    return ready;
}
#include <iostream>
using namespace std;

int countready = 0;

void ready(int* , int);

int main()
{
    int n, i;

    cout << "Write quantities: "; cin >> n;

    int* array = new int[n];

    for (i=0; i < n; i++)
    {
        *(array + i) = rand() % 26;   
        cout << *(array + i) << " ";
    }

    ready(array, n);

    cout << "\n\n\n" << countready;

    return 0;
}

void ready(int* arr, int length)
{

    for (int i = 0; i < length; i++)
    {
        if (*(arr + i) >= 20)
        {
            countready += 1;
        }
    }
}
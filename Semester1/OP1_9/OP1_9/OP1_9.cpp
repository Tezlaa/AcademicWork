#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int N, k, d;
    float max;
    cout << "Введіть кількість елементів масиву ";
    cin >> N;
    float* a = new float[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = 0.1 * (rand() % 201);
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    cout << endl;
    k = -1;
    for (int i = 0; i < N; i++)
    {
        if (0 > a[i] && k == -1)
        {
            k = i;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (a[i]<0 && a[i]>a[k])
        {
            k = i;
        }
    }
    cout << "Номер максимального від'ємного елементу "
        << k << endl;
    cout << "Максимальне від'ємне значення: " << a[k];

    delete[] a;
    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m, n, i, j;
    float sumn, tamp;

    setlocale(LC_ALL, "Russian");
    cout << "Введите количество рядков: "; cin >> m;
    cout << "Введите количество столбцов: "; cin >> n;

    float** a = new float* [m];
    float* sum = new float[m];

    for (i = 0; i < m; i++)
        a[i] = new float[n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = -10 + rand() % 21;
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    for (j = 0; j < n; j++)
    {
        sumn = 0;
        for (i = 0; i < m; i++)
        {
            sumn += a[i][j];
        }
        sum[j] = sumn;
    }

    for (j = 0; j < n; j++)
    {
        if (sum[j] < sum[j + 1])
        {
            tamp = sum[j];
            sum[j] = sum[j + 1];
            sum[j + 1] = tamp;

            for (i = 0; i < m ; i++)
            {
                tamp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = tamp;
            }
            j = 0;
        }
    }

    for (j = 0; j < m; j++)
    {
        cout << sum[j] << " ";
    }
    cout << endl;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    delete[]a; delete[]sum;
    return 0;
}
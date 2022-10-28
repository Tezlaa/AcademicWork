#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m, n, i, j;
    float sumn, tamp;

    cout << "Enter the number of rows: "; cin >> n;
    cout << "Enter the number of columns: "; cin >> m;

    float** a = new float* [n];
    float* sum = new float[n];

    for (i = 0; i < n; i++)
        a[i] = new float[m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = -10 + rand() % 21;
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    //sum columns
    for (j = 0; j < m; j++)
    {
        sumn = 0;
        for (i = 0; i < n; i++)
        {
            sumn += a[i][j];
        }
        sum[j] = sumn;
    }

    //sorted sum and main matrix
    for (j = 0; j < m; j++)
    {
        if (sum[j] < sum[j + 1])
        {
            tamp = sum[j];
            sum[j] = sum[j + 1];
            sum[j + 1] = tamp;

            for (i = 0; i < n ; i++)
            {
                tamp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = tamp;
            }
            j = 0;
        }
    }

    //sum display
    for (j = 0; j < n; j++)
    {
        cout << sum[j] << " ";
    }

    cout << endl;

    //display sorted matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int di, nl ,i1, i2, m1, m2;

    cout << "write lingth for the matrix: "; cin >> nl;

    int* arr = new int[nl];

    cout << "\nMatrix: " << endl;

    for (di = 0; di < nl; di++)
    {
        arr[di] = 2 + rand() % 50;
        cout << arr[di] << endl;
    }
    i1 = 0; i2 = 0; m1 = 0; m2 = 0;
    for (di = 0; di < nl; di++)
    {
        if (arr[di] > m1)
        {
            m2 = m1;
            i1 = di;
            m1 = arr[di];
        }
        else if (arr[di] > m2)
        {
            m2 = arr[di];
            i2 = di;
        }

    }

    cout << "shid: " << m1 << " gram" << endl << "mir: " << m2 << " gram" << endl;
    cout << "shid index: " << i1 << endl << "mir index: " << i2;

    return 0;
}

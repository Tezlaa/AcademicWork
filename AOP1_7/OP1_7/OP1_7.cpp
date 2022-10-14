#include <iostream>
using namespace std;

int main()
{
    float e, x, u1, u2, n, sum;

    cout << "Write X: "; cin >> x;
    cout << "Write E: "; cin >> e;

    u1 = 1;
    n = 1;
    sum = 1;
    u2 = 0;

    while (abs(u1) >= e)
    {   
        u2 = u1 * (x*x) / ((2*n-1)*(2*n));
        sum += u2;
        u1 = u2;
        n = n + 1;
        cout << "u2: " << u2 << endl << "u1: " << u2 << endl << "n: " << n << endl << endl;

    }

    cout << "N: " << n << endl << "U: " << u1 << endl;
    return 0;
}
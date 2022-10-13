#include <iostream>
using namespace std;

int main()
{
    float e, x, u, u2, n;

    cout << "Write X: "; cin >> x;
    cout << "Write E: "; cin >> e;

    u = x;
    u2 = 1;
    n = 0;

    while (abs(u) >= e)
    {   
        u = u2 * (x / (n+1));
        n = n + 2;
        u2 = u;
        cout << "n: " << n << endl << "U: " << u << endl << "U2: " << u2 << endl;

    }

    cout << "n: " << n/2 << endl << "U: " << u << endl;
}
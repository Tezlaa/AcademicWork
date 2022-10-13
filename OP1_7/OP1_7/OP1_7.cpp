#include <iostream>
using namespace std;

int main()
{
    float e, x, u1, u2, result, n;

    cout << "Write X: "; cin >> x;
    cout << "Write E: "; cin >> e;

    u1 = 0;
    u2 = 1;
    result = 0;
    n = 0;

    while (abs(u2 - u1) >= e)
    {
        u1 = u2;
        n = n + 2;
        u2 = u1 + (x / (n + 1));
        result = u2;
    }

    cout << "R: " << result << endl;
}

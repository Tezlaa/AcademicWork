#include <iostream>
using namespace std;

int main()
{
    float x, z, k, y, q;

    cout << "write x:"; cin >> x;
    cout << "write z:"; cin >> z;
    cout << "write k:"; cin >> k;
    cout << "write Q:"; cin >> q;

    if (x > q)
    {
        y = pow(k, x) + 3 * z;
    }
    else if (x <= q)
    {
        y = exp(abs(x - k)) + x / 2;
    }
    else 
    {
        cout << "Error";
    }

    cout <<"result:" << y;


    return 0;
}

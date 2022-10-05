#include <iostream>
using namespace std;

int main()
{
    float y, x;

    cout << "Hello World!\n";

    cin >> x;


    if (abs(x) >= 0 && abs(x) < 1)
    {
        y = abs(x);
    }
    if (abs(x) >= 1 )
    {
        y = pow(x, 2);
    }
    cout << endl << "Y=" << y << endl << "X=" << x;

    return 0;
}

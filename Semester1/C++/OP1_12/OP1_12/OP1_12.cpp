#include <iostream>
using namespace std;

float formula(float, float, float);

int main()
{
    float z, x, y;
    
    cout << "Write X: "; cin >> x;
    cout << "Write Y: "; cin >> y;

    z = formula(2, x, -3) / abs(y + formula(-x, y, 0)) - sin(x + y) + formula (1, y, 0);

    cout << z;

    return 0;
}

float formula(float a, float b, float p)
{
    float result = exp(-a * b) - p;
    return result;
}
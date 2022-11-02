#include <iostream>
using namespace std;

float formula(float, float, float, float);

int main()
{
    float z, x, y, e;
    
    cout << "Write X: "; cin >> x;
    cout << "Write Y: "; cin >> y;
    cout << "Write E: "; cin >> e;

    z = formula(-2, x, -3, e) / abs(y + formula(x, y, 0, e)) - sin(x + y) + formula (1, -y, 0, e);

    cout << z;

    return 0;
}

float formula(float a, float b, float p, float c)
{
    float result = pow(c, -a * b) - p;
    return result;
}
#include <iostream>
using namespace std;

float result, e;

float formula(float, float, float);

int main()
{
    float z, x, y;
    
    cout << "Write X: "; cin >> x; cout << endl;
    cout << "Write Y: "; cin >> y; cout << endl;
    cout << "Write E: "; cin >> e; cout << endl;

    z = formula(-2, x, -3) / abs(y + formula(x, y, 0)) - sin(x + y) + formula (1, -y, 0);

    cout << z;

    return 0;
}

float formula(float a, float b, float p)
{
    result = pow(e, -a * b) - p;
    cout << endl << result << endl;
    return result;
}
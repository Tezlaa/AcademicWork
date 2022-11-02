#include <iostream>
#include <complex>
using namespace std;

float square_equation(float, float, float);

int main()
{
    square_equation(1, -6, 13);
    
    return 0;
}

float square_equation(float a, float b, float c)
{
    float x1, x2, in; //declare variables for the function

    float d = b * b - 4 * a * c; // calculate the discriminant

    cout << d << endl;
    if (d > 0) // if discriminant > 0
    {
        cout << "D>0\n";
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    if (d == 0) // if discriminant = 0
    {
        cout << "D==0\n";
        x1 = -(b / (2 * a));
        cout << "x1 = x2 = " << x1 << "\n";
    }
    if (d < 0) // if discriminant < 0
    {
        cout << "NO";
    }

    return 1;
}

#include <iostream>
#include <complex>
using namespace std;

float s_e(float, float, float);

//1 3 -5        x1 = -1.41   x2 = 1.41
//2 -5 3        x1 = 1.5     x2 = 1
//1 13 15       x1 = -1.27   x2 = -11.72

int main()
{
    float min_1, min_2, min_3, number_a, number_b, number_c, result;

    for (int i = 1; i <= 3; i++) // for with writing all the equations
    {
        cout << "\nEQUATION #" << i << "\t\n";
        cout << "Write a: "; cin >> number_a;
        cout << "Write b: "; cin >> number_b;
        cout << "Write c: "; cin >> number_c;
        if (i == 1)
            min_1 = s_e(number_a, number_b, number_c);
        if (i == 2)
            min_2 = s_e(number_a, number_b, number_c);
        if (i == 3)
            min_3 = s_e(number_a, number_b, number_c);
        
    }

    result = min_1;  // Check which less
    if (min_2 < result)
        result = min_2;
    if (min_3 < result)
        result = min_3;

    cout << "The very small: " << result;

    return 0;
}

float s_e(float a, float b, float c)
{
    float x1, x2, min; //declare variables for the function

    float d = b * b - 4 * a * c; // calculate the discriminant

    if (d > 0) // if discriminant > 0
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        if (x1 < x2)
        {
            min = x1;
        }
        else
            min = x2;
    }
    if (d == 0) // if discriminant = 0
    {
        x1 = -(b / (2 * a));
        min = x1;
    }
    if (d < 0) // if discriminant < 0
    {
        min = pow(10, 10);
    }

    return min;
}

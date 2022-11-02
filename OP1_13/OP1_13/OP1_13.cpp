#include <iostream>
#include <complex>
using namespace std;

float square_equation(float, float, float);

//1 -6 10      x1 = 3+2i   x2 = 3-2i
//2 -5 3       x1 = 1.5   x2 = 1
//1 13 15      x1 = -1.27   x2 = -11.72

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
            min_1 = square_equation(number_a, number_b, number_c);
        if (i == 2)
            min_2 = square_equation(number_a, number_b, number_c);
        if (i == 3)
            min_3 = square_equation(number_a, number_b, number_c);
        
    }

    result = min_1;  // Check which less
    if (min_2 < result)
        result = min_2;
    if (min_3 < result)
        result = min_3;

    cout << "The very small: " << result;

    return 0;
}

float square_equation(float a, float b, float c)
{
    float x1, x2, x1_i, x2_i, in; //declare variables for the function

    float d = b * b - 4 * a * c; // calculate the discriminant

    cout << d << endl;
    if (d > 0) // if discriminant > 0
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        if (x1 < x2)
        {
            return x1;
        }
        else
            return x2;
    }
    if (d == 0) // if discriminant = 0
    {
        x1 = -(b / (2 * a));
        return x1;
    }
    if (d < 0) // if discriminant < 0
    {
        x1_i = ((-b) + sqrt(d * -1)) / (2 * a);
        x2_i = ((-b) - sqrt(d * -1)) / (2 * a);
        if (x1_i < x2_i)
        {
            return x1_i;
        }
        else
            return x2_i;
    }
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float side, radius_circles, squares_circles, pi;
    cout << "hexagon side: ";
    cin >> side;
    radius_circles = side * sqrt(3) / 2;
    pi = 3.14159F;
    squares_circles = pi * pow(radius_circles, 2);
    cout << squares_circles;
    return 0;
}


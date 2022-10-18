#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int index;
    double y, bigp;

    int* fi = new int[5];
    cout << "Фи масив: ";
    for (index = 0; index < 5; index++)
    {
        fi[index] = rand() % 301;
        cout << fi[index] << ", ";
    }

    cout << "\n\nП от i=1 до 5: ";
    bigp = 1;
    for (index = 1; index <= 5; index++) 
    {
        bigp *= pow(sin(fi[index]), 2);
        cout << bigp << "    ";
    }

    y = pow(cos(fi[2]), 2) - bigp;

    cout << "\n\nY = " << y << endl;
}

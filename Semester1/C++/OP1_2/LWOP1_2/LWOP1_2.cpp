#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float v, p, yunga, n;

    cout << "Модель Юнга" << endl << endl;
    cout << "Задайте V:"; cin >> v;
    cout << "Задайте p:"; cin >> p;
    cout << "Задайте процент пористости:"; cin >> n;

    if (n <= 2)
    {
        yunga = pow(v, 2) * p / 1.21;
    }
    else
    {
        yunga = pow(v, 2) * p / 1.76;
    }
    cout << yunga;

    return 0;
}

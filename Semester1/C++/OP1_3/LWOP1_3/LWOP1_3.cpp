#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float result, n_1, n_2, n_3, n_4, max;

    cout << "Введите число 1: "; cin >> n_1;
    cout << "Введите число 2: "; cin >> n_2;
    cout << "Введите число 3: "; cin >> n_3;
    cout << "Введите число 4: "; cin >> n_4;
    cout << endl << endl ;

    max = n_1;
    if (n_2 > max)
    {
        max = n_2;
    }
    if (n_3 > max) 
    {
        max = n_3;
    }
    if (n_4 > max)
    {
        max = n_4;
    }
    result = sqrt(max);
    cout << "Корень самого большого числа: " << result;
    cout << endl << endl;

    return 0;
}

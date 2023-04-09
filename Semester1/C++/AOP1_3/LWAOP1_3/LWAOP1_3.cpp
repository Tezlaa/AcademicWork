#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int a1, ab_1 , a2, ab_2, a3, ab_3, min;

    cout << "Розрахунок вартости\n";
    cin >> a1; cin >> a2; cin >> a3;

    min = a1;
    if (a2 < min)
    {
        min = a2;
    }
    if (a3 < min)
    {
        min = a3;
    }
    cout << "Самый економный способ:" << min;
}

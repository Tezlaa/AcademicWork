#include <iostream>
using namespace std;

int main()
{
    float salary, result;

    cout << "YOUR TAX" << endl;

    cout << "Please write your salary: " ; cin >> salary;

    switch (salary < 120)
    {
    case 1:
        cout << "Your tax: 15%";
        result = salary - (salary * 0.15);
        break;
    }

    switch (salary >= 120 && salary < 440)
    {
    case 1:
        cout << "Your tax: 20%";
        result = salary - (salary * 0.20);
        break;
    }

    switch (salary >= 441 && salary <= 1000)
    {
    case 1:
        cout << "Your tax: 30%";
        result = salary - (salary * 0.30);
        break;
    }

    switch (salary >= 1001)
    {
    case 1:
        cout << "Your tax: 50%";
        result = salary - (salary * 0.50);
        break;
    }

    cout << "\nYour salary together with the tax: " << result << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    float visco;
    string result;

    cout << "machine lubrication" << endl << endl;

    cout << "Write your viscosity: "; cin >> visco;

    result = "Error your viscosity <3.50";

    if (3.5 <= visco && visco <= 9)
    {
        result = "light viscosity";
    }
    if (10 <= visco && visco <= 57)
    {
        result = "average viscosity";
    }
    if (visco >= 58)
    {
        result = "heavy";
    }

    cout << result << endl << endl;

    return 0;
}
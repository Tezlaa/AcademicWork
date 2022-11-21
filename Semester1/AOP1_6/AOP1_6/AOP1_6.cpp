#include <iostream>
using namespace std;

int main()
{
    int max_gram, price, gram, step_price;
    cin >> max_gram;

    price = 100;
    step_price = 25;
    gram = 50;
    while (gram <= max_gram)
    {
        cout << gram << "-" << price << endl;
        gram = gram + 50;
        price = price + step_price;

    }
    
    return 0;
}

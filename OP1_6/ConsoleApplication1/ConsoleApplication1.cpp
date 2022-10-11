#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    int n, k, i, d;
    float f;

    cout << "Write n,k 0<=k<=n" << endl;
    cin >> n; cin >> k;

    //k!
    f = 1;
    for (i = 1; i <= k; i++)
    {
        f = f * i;
    }

    i = 0;
    d = 1;
    do
    {
        i++;
        d = d * (n * (n - i));
        
    } while (i < k);

    cout << endl << d / f << endl;
    return 0;
}

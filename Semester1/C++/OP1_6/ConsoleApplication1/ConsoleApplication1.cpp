#include <iostream>
using namespace std;

int main()
{
    int n, k, i;
    float f, d, result;

    cout << "Write n,k 0<=k<=n" << endl;
    cin >> n; cin >> k;

    //k!
    f = 1;
    for (i = 1; i <= k; i++)
    {
        f = f * i;
    }
    //main
    i = 1;
    d = 1;
    do
    {
        i++;
        d = d * (n * (n - i));

    } while (i < k);

    result = d / f;
    cout << result << endl;

    return 0;
}

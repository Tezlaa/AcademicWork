#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int N, i;

    cout << "N = "; cin >> N;

    float* a = new float[N * 2];

    for (i = 0; i < N * 2; i++)
    {
        a[i] = 0.1 * (rand() % 201 - 100);
        cout << i << "|" << a[i] << "\t";
    }

    for (i = 0; i < N; i++)
    {
        cout << "\nsum: " << a[i] + a[N * 2 - 1 - i] << endl;
        a[i] = a[i] + a[N * 2 - 1 - i];

    }

    cout << endl << endl;

    for (i = 0; i < N; i++)
    {
        cout << "val[" << i << "] = " << a[i] << endl;
    }


    delete[] a;
    a = nullptr;
}

//if (N % 2 == 1)
//{
//    for (int i = 0; i < (N - 1) / 2; i++)
//    {
//        p = val[N + i];
//        val[N + i] = val[N * 2 - 1 - i];
//        val[N * 2 - 1 - i] = p;
//        cout << "val[" << i << "] = " << val[i] << endl;
//    }
//}
//else
//{
//
//    for (int i = 0; i < N / 2; i++)
//    {
//        p = val[N + i];
//        val[N + i] = val[N * 2 - 1 - i];
//        val[N * 2 - 1 - i] = p;
//        cout << "val[" << i << "] = " << val[i] << endl;
//    }
//}
//
//
//int pere = 1;
//for (int i = 1; i < 2 * (N - 1); i += 2)
//{
//    p = val[2 * N - 1];
//
//    for (int j = i; j < 2 * N - 1; j++)
//    {
//        val[2 * N - pere] = val[2 * N - pere - 1];
//        pere++;
//        cout << "val[" << i << "] = " << val[i] << endl;
//    }
//    val[i] = p;
//    pere = 1;
//}

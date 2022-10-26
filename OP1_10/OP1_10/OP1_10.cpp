#include <iostream>

using namespace std;

int main()
{
    int N, k;

    cout << "Write your matrix:"; cin >> N;

    int* A = new int[N];

    cout << "Matrix:";

    for (int i = 0; i < N; i++)
    {
        A[i] = 2 * rand() % 40;
        cout << A[i] << " ";
    }

    cout << "\nWrite index: ";
    cin >> k;

    for (int i = k; i < N - 1; i++) //Двигаемся слева направо с заданной позиции
    {
        A[i] = A[i + 1]; //Сдвигаем элементы
    }

   
    cout << "\nFinish matrix:";

    for (int i = 0; i < N - 1; i++) //Уменьшаем размер массива на единицу
    {
        cout << A[i] << " "; //Выводим массив после удаления элемента
    }

    cout << endl;
    delete[] A;
    return 0;
}

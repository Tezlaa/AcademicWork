#include <iostream>

using namespace std;

int main()
{
    int N, k, i;

    cout << "Write the length of the array:"; cin >> N;

    int* A = new int[N];

    cout << "Array:";

    for (i = 0; i < N; i++)
    {
        A[i] = 2 * rand() % 40;
        cout << A[i] << " ";
    }

    cout << "\nWrite index: ";cin >> k;

    for (i = k; i < N - 1; i++) //Двигаемся слева направо с заданной позиции
    {
        A[i] = A[i + 1]; //Сдвигаем элементы
    }

   
    cout << "\nFinish matrix:";

    for (i = 0; i < N - 1; i++) //Уменьшаем размер массива на единицу
    {
        cout << A[i] << " "; //Выводим массив после удаления элемента
    }

    cout << endl;
    delete[] A;
    return 0;
}

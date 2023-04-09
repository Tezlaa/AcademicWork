#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j, N, M, inumb;
	float number;

	cout << "Length matrix (M) :"; cin >> M;
	cout << "Elevation matrix (N) :"; cin >> N;

	float** A = new float*[M];

	for (i = 0; i < M; i++)
		A[i] = new float[N];

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			A[i][j] = -10 + rand() % 21;
			cout << setw(5) << A[i][j];
		}
		cout << endl;
	}

	float* numbermatrix = new float[M];

	for (j = 0; j < N; j++)
	{
		number = 0; inumb = 0;
		for (i = 0; i < M; i++)
		{
			if (A[i][j] > 0)
			{
				number += A[i][j];
				inumb += 1;
			}
		}
		numbermatrix[j] = (number / inumb);
	}

	cout << endl;
	for (i = 0; i < N; i++)
		cout << numbermatrix[i] << "\t";
	cout << endl;

	return 0;
}

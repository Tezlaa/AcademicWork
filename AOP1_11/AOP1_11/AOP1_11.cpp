#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j, N, M, imax, jmax, imin, jmin, max, min;

	cout << "Length matrix (N) :"; cin >> N;
	cout << "Elevation matrix (M) :"; cin >> M;

	float** a = new float* [N];

	for (i = 0; i < N; i++)
		a[i] = new float[N];

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			a[i][j] = -10 + rand() % 21;
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}

	min = a[0][0];

	for (j = 0; j < M; j++)
	{
		max = a[0][j];
		imax = 0; jmax = 0;

		for (i = 0; i < N; i++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				imax = i;
				jmax = j;
			}
		}
		cout << max << " ";

		if (max <= min)
		{
			min = max;
			imin = imax;
			jmin = jmax;
		}
		
	}

	cout << endl << imin << "-" << jmin << ": " << min << endl;



	delete[]a;
	return 0;
}
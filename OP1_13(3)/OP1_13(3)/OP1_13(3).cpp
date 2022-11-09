#include <iostream>
#include <iomanip>
using namespace std;


void search_max(int**, int);

void search_max(int** matrix, int m)
{
	int i, j, max;

	max = *(*(matrix + (m-2)) + (m-1));

	for (i = 0; i < m - 1; i++)
	{
		for (j = i + 1; j < m; j++)
		{
			if (i<j && i + j > m - 1 && *(*(matrix + i) + j) > max)
			{
				max = *(*(matrix + i) + j);
			}
		}
	}
	cout << max;
}

int main()
{
	int m, i, j;
	float number;

	cout << "Length matrix (M) :"; cin >> m;

	int** matrix = new int* [m];

	for (i = 0; i < m; i++)
		*(matrix + i) = new int[m];

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			*(*(matrix + i) + j) = -10 + rand() % 41;
			cout << setw(5) << *(*(matrix + i) + j);
		}
		cout << endl;
	}

	cout << endl;
	search_max(matrix, m);

	return 0;
}
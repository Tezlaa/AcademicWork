#include <iostream>
using namespace std;

int main()
{
	int t, age;
	float result;
	const int n = 10;

	cin >> age;
	int* m = new int[age];

	for (t = 1; t <= age; t++)
	{
		m[t] = 0 + rand() % 1000;

		cout << m[t] << "\t";

		result = m[t] / (n * t);

		cout << "AGE " << t << " - " << result << " Off\n";
	}



	return 0;
}
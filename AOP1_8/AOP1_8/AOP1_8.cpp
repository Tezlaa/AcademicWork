#include <iostream>
using namespace std;

int main()
{
	int age, i;
	float result;

	const int n = 10;

	cin >>age;

	float* t = new float[age];
	float* m = new float[age];

	for (i = 1; i <= age; i++)
	{
		t[i] = 1 + rand() % 12;
		cout << t[i] << " \n";
	}

	for (i = 1; i <= age; i++)
	{
		m[i] = 0 + rand() % 1000;

		cout << m[i] << "\t";

		result = m[i] / (n * t[i]);

		cout << "AGE " << i << " - " << result << " Off\n";
	}



	return 0;
}
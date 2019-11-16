#include <iostream>
#include <math.h>
using namespace std;
void prime1(int n)
{
	bool flag = false;
	int count = 0;
	for (int i = 2; i<n - 1; i++)
	{
		count++;
		if (n%i == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << n << " is not Prime number " << endl;
		cout << "Time Taken: " << count << endl;
	}
	else
	{
		cout << n << " is prime number " << endl;
		cout << "Time Taken: " << count << endl;
	}
}
void prime2(int n)
{
	bool flag = false;
	int count = 0;
	for (int i = 2; i<sqrt(double(n)); i++)
	{
		count++;
		if (n%i == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << n << " is not Prime number " << endl;
		cout << "Time Taken: " << count << endl;
	}
	else
	{
		cout << n << " is prime number " << endl;
		cout << "Time Taken: " << count << endl;
	}
}

int main()
{
	int n;

	cout << "Enter a number to find the Prime Number:" << endl;

	cin >> n;

	cout << "\n*************************************" << endl;

	cout << "1st Algorithm\n" << endl;

	prime1(n);

	cout << "*************************************" << endl;
	cout << "\n*************************************" << endl;

	cout << "2nd Algorithm\n" << endl;

	prime2(n);

	cout << "*************************************" << endl;
	system("pause");

	return 0;

}

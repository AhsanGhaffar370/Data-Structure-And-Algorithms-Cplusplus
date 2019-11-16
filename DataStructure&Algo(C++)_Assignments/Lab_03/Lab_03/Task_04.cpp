/*
#include<iostream>
using namespace std;
int Binary_ser(int a[], int size, int value);

int main()
{

	int const size = 10;
	int a[size] = { 11,22,33,36,45,52,57,60,64,78 }, b[size] = { 0 }, temp = 0, x = 36, y = 45, z = 52;

	cout << "Array Elements:" << endl;

	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";

	cout << "\n\n";

	cout << "\nThe Value at the Location '";
	Binary_ser(a, size, x);
	cout << "' is: " << x;


	cout << "\nThe Value at the Location '";
	Binary_ser(a, size, y);
	cout << "' is: " << y;

	cout << "\nThe Value at the Location '";
	Binary_ser(a, size, z);
	cout << "' is: " << z << "\n\n";

	system("pause");
	return 0;

}

int Binary_ser(int a[], int size, int value)
{
	int lb = 0, ub = size - 1, mid, position = 0;

	bool found = false;

	while (!found && lb <= ub)
	{
		mid = (lb + ub) / 2;
		if (a[mid] == value)
		{
			found = true;
			position = mid;
		}
		else if (a[mid]>value)

			ub = mid - 1;

		else

			lb = mid + 1;
	}
	return position;
}*/
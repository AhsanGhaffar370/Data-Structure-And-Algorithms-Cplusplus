/*
#include<iostream>
using namespace std;
int Binary_ser(int a[], int size, int value);
void delete1(int a[], int size, int loc);
int main()
{

	int const size = 10;
	int a[size] = { 11,22,33,36,45,52,57,60,64,78 }, b[size] = { 0 }, x = 45, y = 78, temp1 = 0, temp2 = 0;

	cout << "Array Elements:" << endl;

	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";

	cout << "\n\n";

	temp1 = Binary_ser(a, size, x);

	cout << "\nThe Position of the value '" << x << "' is: " << temp1;

	temp2 = Binary_ser(a, size, y);

	cout << "\n\nThe Position of the value '" << y << "' is: " << temp2;

	delete1(a, size, temp1);

	delete1(a, size - 1, temp2);

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
}

void delete1(int a[], int size, int loc)
{
	for (int j = loc; j<size; j++)

		a[j] = a[j + 1];

	cout << "\n\nArray with Deleted value: " << endl;

	for (int i = 0; i<size - 1; i++)

		cout << "[" << a[i] << "],";

	cout << "\n\n";
}*/
/*
#include<iostream>
using namespace std;
int Binary_ser(int a[], int size, int value);
void Inser_Sort(int a[], int size);
void bubble(int a[], int size);
void selection_sort(int a[], int size);


int main()
{

	int const size = 10;
	int a[size] = { 10,4,11,25,19,33,77,52,1,63 }, b[size] = { 0 }, temp = 0, x = 52, y = 33;

	cout << "UnSorted Array:" << endl;

	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";

	cout << "\n\n";

	bubble(a, size);

	cout << "\nThe Position of the value '" << x << "' is: ";
	Binary_ser(a, size, x);

	cout << "\n\nThe Position of the value '" << y << "' is: ";
	Binary_ser(a, size, y);

	system("pause");
	return 0;

}

void Inser_Sort(int a[], int size)
{
	int temp = 0;

	for (int i = 0; i<size; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (a[j]<a[j - 1])
			{
				temp = a[j];

				a[j] = a[j - 1];

				a[j - 1] = temp;
			}
		}
	}
	cout << "\nSorted Array:" << endl;
	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";

	cout << "\n\n";

}


int Binary_ser(int a[], int size, int value)
{
	int counter = 0, lb = 0, ub = size - 1, mid, position = 0;

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
		counter++;
	}
	return position;
}

void bubble(int a[], int size)
{
	int temp;

	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	cout << "\nBubble sort";
	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";
}

void selection_sort(int a[], int size)
{
	int temp, loc, min;

	for (int i = 0; i<size; i++)
	{
		min = a[i];
		loc = i;
		for (int j = i + 1; j<size; j++)
		{
			if (min>a[j])
			{
				min = a[j];
				loc = j;
			}
		}
		temp = a[i];
		a[i] = a[loc];
		a[loc] = temp;
	}

	cout << "\nSelection sort:";
	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";
}*/
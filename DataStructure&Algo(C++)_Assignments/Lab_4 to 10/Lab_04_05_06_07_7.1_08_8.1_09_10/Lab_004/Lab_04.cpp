/*
#include<iostream>
using namespace std;
void input_arr(int arr[], int size);
void insertion_sort(int a[], int size);
void bubble_sort(int a[], int size);
void selection_sort(int a[], int size);
int main()
{
	int const size = 10;
	int a[size], b[size], c[size];

	cout << "Enter 10 values for Array(A):" << endl;
	input_arr(a, size);

	bubble_sort(a, size);

	cout << "\n\nEnter 10 values for Array(B):" << endl;
	input_arr(b, size);

	insertion_sort(b, size);


	cout << "\n\nEnter 10 values for Array(C):" << endl;
	input_arr(c, size);

	selection_sort(c, size);

	cout << "\n\n";
	system("pause");
	return 0;

}
void input_arr(int arr[], int size)
{
	for (int i = 0; i<size; i++)
		cin >> arr[i];
}

void insertion_sort(int a[], int size)
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
	cout << "\nInsertion Sort:" << endl;
	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";

	cout << "\n\n";

}


void bubble_sort(int a[], int size)
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

	cout << "\nBubble sorte:" << endl;
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

	cout << "\nSelection sort:" << endl;
	for (int i = 0; i<size; i++)

		cout << "[" << a[i] << "],";
}
*/
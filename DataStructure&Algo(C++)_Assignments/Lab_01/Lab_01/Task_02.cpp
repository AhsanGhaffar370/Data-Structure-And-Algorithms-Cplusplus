#include <iostream>
using namespace std;

//create a function to print an array in ascending order:
void Array_Sort(int arr[])
{
	int temp;

	//Use nested for loop to set an array in ascending order:
	for (int i = 0; i<10; i++)
	{
		for (int j = i + 1; j<10; j++)
		{
			//if array element 1 is greater than array element 2 than swap these numbers
			if (arr[i]>arr[j])
			{

				temp = arr[i];

				arr[i] = arr[j];

				arr[j] = temp;

			}
		}
	}


	//Print the sorted array:
	cout << "\nSorted Array in Ascending Order:\n";

	for (int i = 0; i<10; i++)
	{
		cout << arr[i];

		cout << endl;
	}
}
int main()
{
	int arr[10];

	//take input of array from user:
	for (int i = 0; i<10; i++)
	{
		cout << "Enter Element " << i + 1 << ": ";
		cin >> arr[i];

	}

	//Call Array_Sort function which prints sorted array:
	Array_Sort(arr);
	cout << "\n";

	system("pause");

	return 0;
}

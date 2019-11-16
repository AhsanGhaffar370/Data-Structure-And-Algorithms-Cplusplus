
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	//Declaring Variable:
	int i, j, k;
	int const r1 = 2, c1 = 3, r2 = 3, c2 = 4;

	//Declaring Arrays:	
	int a[r1][c1], b[r2][c2], c[r1][c2], sum = 0;

	//The Whole Program is Skipped If Column1 is Not Equal to Row2: 
	if (c1 != r2)
	{
		cout << "Matrix Multiplication is not Possible" << endl;
		return 0;
	}

	cout << "\nEnter Values Of Matrix A:" << "\n\n";

	//Taking Input Of Matrix A Values from User:
	for (i = 0; i<r1; i++)
	{
		for (j = 0; j<c1; j++)
		{
			cout << "Enter[" << i << "][" << j << "] :";
			cin >> a[i][j];
		}
	}

	cout << "\nEnter Values Of Matrix B:" << "\n\n";

	//Taking Input Of Matrix B Values from User:
	for (i = 0; i<r2; i++)
	{
		for (j = 0; j<c2; j++)
		{
			cout << "Enter[" << i << "][" << j << "] :";
			cin >> b[i][j];
		}
	}
	
		/*Apply Nested For loop To calculate Multiplication Of
		Matrix A & B And Store It In Matrix C:*/

		for (i = 0; i<r1; i++)
		{
			for (j = 0; j<c2; j++)
			{
				for (k = 0; k<r2; k++)
				{
					sum += a[i][k] * b[k][j];
				}
				c[i][j] = sum;
				sum = 0;
			}
		}

	cout << "\n Matrix A" << endl << "\n";
	//Prints Matrix A:
	for (i = 0; i<r1; i++)
	{
		cout << "\t";

		for (j = 0; j<c1; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	cout << "\n Matrix B" << endl << "\n";

	//Prints Matrix B:
	for (i = 0; i<r2; i++)
	{
		cout << "\t";

		for (j = 0; j<c2; j++)
		{
			cout << setw(4) << b[i][j];
		}
		cout << endl;
	}

	cout << "\nMultiplication Of Matrix A & B:" << endl;
	cout << "\n Matrix C" << endl << "\n";

	//Prints Multiplication Of Matrix A & Matrix B:
	for (i = 0; i<r1; i++)
	{
		cout << "\t";

		for (j = 0; j<c2; j++)
		{
			cout << setw(5) << c[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}


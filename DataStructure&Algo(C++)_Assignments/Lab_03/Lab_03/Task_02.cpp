/*
#include<iostream>
using namespace std;
void Part_A(int A[], int B[], int X, int Y);
void Part_B(int A[], int B[]);

int main()
{
	int X = 2, Y = -5, A[] = { 16,-6,7 }, B[] = { 4,2,-3 };

	Part_A(A, B, X, Y);

	Part_B(A, B);

	system("pause");

	return 0;
}

void Part_A(int A[], int B[], int X, int Y)
{
	int temp[3] = { 0 };

	for (int i = 0; i<3; i++)
	{
		A[i] *= X;
		B[i] *= Y;
	}

	cout << "The [Array(A)*X] answer is:" << endl;

	for (int i = 0; i<3; i++)

		cout << A[i] << endl;

	cout << "\nThe [Array(B)*Y] answer is:" << endl;

	for (int i = 0; i<3; i++)

		cout << B[i] << endl;


	for (int i = 0; i<3; i++)
	{
		temp[i] += A[i];
		temp[i] += B[i];
	}

	cout << "\n\n[(Array(A)*X)+(Array(B)*Y)] answer is: " << endl;

	for (int i = 0; i<3; i++)

		cout << temp[i] << endl;

}

void Part_B(int A[], int B[])
{
	int temp2[3] = { 0 };

	for (int i = 0; i<3; i++)
	{
		A[i] *= B[i];

		temp2[i] += A[i];
	}

	cout << "\n\nArray(A)*Array(B) answer is: " << endl;

	for (int i = 0; i<3; i++)

		cout << temp2[i] << endl;
}*/
#include <iostream>
using namespace std;

//create a function to Print the Smallest Number:
int smallest(int a, int b, int c)
{

	//Use if else condition to return the smallest one:
	if (a<b && a<c)
	{
		return a;
	}

	else if (b<a && b<c)
	{
		return b;
	}

	else if (c<a && c<b)
	{
		return c;
	}
}
int main()
{
	//Declaring variables:
	int a, b, c;

	//Taking Input from user:
	cout << "Enter any three Integers" << endl;

	cin >> a >> b >> c;

	cout << "\nThe Smallest Number is: ";

	cout << smallest(a, b, c) << endl << "\n";


	system("pause");
	return 0;

}

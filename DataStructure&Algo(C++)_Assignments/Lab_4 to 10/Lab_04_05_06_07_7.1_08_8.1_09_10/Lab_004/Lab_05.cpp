/*
#include <iostream>
#include <cstdlib>
using namespace std;
int const siz = 6;
int stack[siz], top = -1;


bool isFull()
{
	bool flag = false;
	if (top == siz - 1)
	{
		return !flag;
	}
	else
	{
		return flag;
	}
}

bool isEmpty()
{
	bool flag = false;
	if (top == -1)
	{
		return !flag;
	}
	else
	{
		return flag;
	}
}

void push(int value)
{
	if (isFull())
	{
		cout << "\nStack Overflow" << endl;
	}
	else
	{
		cout << "\nValue has been inserted:" << endl;
		top++;
		stack[top] = value;
	}
}

void pop()
{
	if (isEmpty())
	{
		cout << "\nStack Underflow" << endl;
	}
	else
	{
		cout << "\nValue Has Been Deleted: " << endl;
		stack[top] = NULL;
		top--;
	}
}

void peek()
{
	cout << "The Peek Value is: " << stack[top] << endl;
}

void display()
{
	if (isEmpty())
	{
		cout << "\nStack Underflow" << endl;
	}
	else
	{
		cout << "\nThe Stack Values are :" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << stack[i] << endl;
		}
	}
}
int main()
{
	int choice, value;
	char ch;
	do
	{
		cout << "\n1.push\n2.pop\n3.peek\n4.display" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nEnter any integer value for insertion:" << endl;
			cin >> value;
			push(value);
		}
		else if (choice == 2)
		{
			pop();
		}
		else if (choice == 3)
		{
			peek();
		}
		else if (choice == 4)
		{
			display();
		}

		cout << "\nEnter y to continue and n to exit: ";
		cin >> ch;
	} while (ch != 'n');
	system("pause");
}
*/
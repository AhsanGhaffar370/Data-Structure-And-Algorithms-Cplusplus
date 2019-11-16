/*We can use both methods  
  1.insert at end with delete at end
  2.insert at front with delete at front
  but we use the 2nd one because the time complexity of 2nd one is less than 1st method
*/
/*
#include <iostream>
#include <cstdlib>
using namespace std;
struct stack {
	int id;
	stack *next;
}; stack *top = NULL;

bool isEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

void push(int id)
{
	stack *new1 = new stack;
	new1->id = id;
	new1->next = NULL;
	stack *temp;

	if (top == NULL)
	{
		top = new1;
		cout << "node becomes the head of insert at front function:" << endl;
	}

	else {
		new1->next = top;
		top = new1;
		cout << "\nNode inserted at front:" << endl;
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
		stack *temp;
		temp = top;
		top = top->next;
		delete(temp);
		cout << "\nNode has been deleted from front:\n\n" << endl;
	}
}

void peek()
{
	cout << "The Peek Value is: " << top->id << endl;
}

void display()
{
	if (isEmpty())
	{
		cout << "\nStack Underflow" << endl;
	}
	else
	{
		stack *temp = top;
		while (temp != NULL) {
			cout << "ID: " << temp->id << endl;
			temp = temp->next;
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
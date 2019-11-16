/*
#include <iostream>
using namespace std;
void enque(int value);
void deque(int value);
bool isfull();
bool isempty();
void display();
int findsize();
int front = -1;
int rear = -1;
int const siz = 6;
int arr[siz];

int main()
{
	int c, a, b;
	char d;

	do
	{
		cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Size\nEnter any of the above:" << endl;
		cin >> c;

		if (c == 1)
		{
			cout << "\nEnter the insertion value: " << endl;
			cin >> a;
			enque(a);
		}
		else if (c == 2)
		{
			cout << "\nEnter the value you want to delete: " << endl;
			cin >> b;
			deque(b);
		}
		else if (c == 3)
		{
			display();
		}
		else if (c == 4)
		{
			cout << "\nThe Size of Queue is: " << findsize();
		}

		cout << "\nEnter Y to continue and N to exit:" << endl;
		cin >> d;

	} while (d != 'n');

	system("pause");
	return 0;
}

bool isfull()
{
	bool flag = false;

	if (rear == siz - 1)
	{
		cout << "\nQueue is Full:" << endl;
		flag = true;
	}
	else
	{
		flag = false;
	}
	return flag;
}

bool isempty()
{
	bool flag = false;

	if (front == -1 && rear == -1)
	{
		cout << "\nQueue is Empty:" << endl;
		flag = true;
	}
	else
	{
		flag = false;
	}

	return flag;
}
void enque(int value)
{
	if (isfull())
	{
		cout << "\n" << endl;
	}

	else if (front == -1 && rear == -1) {
		front++;
		rear++;
		arr[rear] = value;
	}
	else {
		rear++;
		arr[rear] = value;
	}
}
void deque(int value) {

	if (isempty())
	{
		cout << "\n" << endl;
	}
	else if (front == rear) {
		front--;
		rear--;
	}
	else
	{
		front = front++;
	}
}
void display()
{
	if (isempty())
	{
		cout << "\nQueue is empty" << endl;
	}

	cout << "\nThe Queue Values are:" << endl;
	for (int i = front; i <= rear; i++)
	{
		cout << "\n" << arr[i] << endl;
	}
}

int findsize()
{
	int size1 = rear - front;
	size1 = size1++;

	return size1;
}
*/
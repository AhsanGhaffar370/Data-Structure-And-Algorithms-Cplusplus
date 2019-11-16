
#include <iostream>
using namespace std;
void enque(int id);
void deque();
bool isempty();
void display();

struct queue {
	string name;
	int id;
	queue *next;
}; queue *front = NULL;
   queue *rear  = NULL;

bool isempty()
{
	if (front == NULL && rear == NULL)
		return true;
	else
		return false;
}

void enque(int id)
{
	queue *new1 = new queue;
	new1->id = id;
	new1->next = NULL;

	if (front == NULL && rear == NULL)
	{
		front = rear = new1;
		cout << "node becomes the head of insert at front function:" << endl;
	}

	else {
		rear->next = new1;
		rear = new1;
		cout << "\nNode inserted at front:" << endl;
	}
}
void deque() {

	if (isempty())
	{
		cout << "\n" << endl;
	}
	else
	{
		queue *temp = front;
		front = front->next;
		delete(temp);
		cout << "\nNode has been deleted from front:\n\n" << endl;
	}
}
void display()
{
	if (isempty())
	{
		cout << "\nQueue is empty" << endl;
	}
	else {
		queue *temp = front;
		while (temp != NULL) {
			cout << "ID: " << temp->id << endl;
			temp = temp->next;
		}
	}
}

int main()
{
	int c, a;
	char d;

	do
	{
		cout << "\n1.Enqueue\n2.Dequeue\n3.Display\nEnter any of the above:" << endl;
		cin >> c;

		if (c == 1)
		{
			cout << "\nEnter the insertion value: " << endl;
			cin >> a;
			enque(a);
		}
		else if (c == 2)
		{
			deque();
		}
		else if (c == 3)
		{
			display();
		}

		cout << "\nEnter Y to continue and N to exit:" << endl;
		cin >> d;

	} while (d != 'n');

	system("pause");
	return 0;
}

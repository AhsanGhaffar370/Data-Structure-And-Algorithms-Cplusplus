/*
#include <iostream>
using namespace std;
void insert_end(int id);
void insert_front(int id);
void insert_anypos(int pos, int id);
void delete_end();
void delete_front();
void delete_anypos(int pos);
bool search(int id);
int search_position(int id);
void display();
void update(int id);
void isempty();
int siz();

struct node {
	string name;
	int id;
	node *next;
	node *prev;
}; node *head = NULL;

void insert_end(int id)
{
	node *new1 = new node;
	new1->id = id;
	new1->next = NULL;
	new1->prev = NULL;
	node *temp;

	if (head == NULL)
	{
		head = new1;
	}

	else {
		temp = head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new1;
		new1->prev = temp;
	}
	cout << "\nID is inserted at end:\n" << endl;
}

void insert_front(int id) {
	node *new1 = new node;
	new1->next = NULL;
	new1->prev = NULL;
	node *temp;

	if (head == NULL)
	{
		head = new1;
	}

	else {
		new1->next = head;
		head->prev = new1;
		head = new1;
	}
	cout << "\nID inserted at front:" << endl;
}

void insert_anypos(int pos, int id)
{
	node *new1 = new node;
	new1->id;
	new1->next = NULL;
	new1->prev = NULL;
	node *temp;

	if (head == NULL) {
		head = new1;
	}

	else if (pos == 1)
	{
		insert_front(id);
	}

	else if (pos != 1 && pos != siz()) {
		temp = head;
		new1->next = temp->next;
		new1->prev = temp;
		temp->next->prev = new1;
		temp->next = new1;
	}
	else if (pos == siz())
	{
		insert_end(id);
	}

	else
		cout << "\nEnter correct Position for insertion of ID:\n" << endl;

	if(pos>=1 && pos<=siz())
	   cout << "\nID inserted at your desired location\n" << endl;
}

void delete_end() {

	node *temp;
	temp = head;

	while (temp->next != NULL) 
		temp = temp->next;

	temp->prev->next = NULL;
	delete(temp);
	cout << "\nID has been deleted from end:\n\n" << endl;
}
 
void delete_front() {
	node *temp;
	temp = head;
	head = head->next;
	delete(temp);
	head->prev = NULL;
	cout << "\nID has been deleted from front:\n\n" << endl;
}

void delete_anypos(int pos)
{
	node *temp = head;
	node *temp1;

	if (pos == 1) {
		delete_front();
	}

	else if (pos != 1 && pos != siz()) {
		
		for (int i = 1; i<pos; i++)
		{
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete(temp);
		}
	}
	else if (pos == siz()) {
		delete_end();
	}

	else
		cout << "\nEnter correct Position for Deletion of ID:\n" << endl;

	if(pos>=1 && pos<=siz())
		cout << "\nID has been deleted from mid:\n\n" << endl;

}

int siz() {
	node *temp = head;
	int count = 1;
	while (temp->next != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}
bool search(int id)
{
	node *temp;
	temp = head;
	bool flag = false;

	if (temp == NULL)
		cout << "\nlink list underflow:\n\n" << endl;

	else {
		for (int i = 0; i<siz(); i++) {
			if (temp->id == id) {
				flag = true;
				break;
			}

			else
				temp = temp->next;
		}
		if (flag == true)
			cout << "\nValue found\n" << endl;

		else if (flag == false)
			cout << "\nValue not found:" << "\n\n" << endl;

	}
}int search_position(int id)
{
	node *temp;
	node *siz_temp = head;
	temp = head;
	int siz = 1, count = 1, pos = -1;
	bool flag = false;

	if (temp == NULL)
		cout << "\nlink list underflow:\n\n" << endl;

	else {
		while (siz_temp->next != NULL) {
			siz_temp = siz_temp->next;
			siz++;
		}
		for (int i = 0; i<siz; i++) {
			if (temp->id == id) {
				flag = true;
				break;
			}

			else
				temp = temp->next;

			count++;
		}
		if (flag == true) {
			cout << "\nValue found at Position: ";
			return count;
		}


		else if (flag == false)
			return pos;

	}
}

void display() {
	node *temp = head;
	cout << "\nDISPLAY" << endl;
	cout << "ID: " << temp->id << endl;
	while (temp->next != NULL) {
		temp = temp->next;
		cout << "ID: " << temp->id << endl;
	}
}

void isempty() {
	node *temp = head;
	if (head == NULL)
		cout << "\nLink list is Empty(Underflow)\n" << endl;

	else
		cout << "\nLink list is not empty:\n" << endl;
}

void update(int id)
{
	node *temp = head;
	while (temp->next != NULL)
	{
		if (temp->id == id)
		{
			temp->id = id;
			break;
		}

		else {
			temp = temp->next;
		}
	}
}


int main()
{
	char c;
	int choice, value, pos;

	do {
		cout << "\n\n============================" << endl;
		cout << "    LINK LIST IMPLEMENTATION  " << endl;
		cout << "============================" << endl;

		cout << "\n1-    Insert an element at End       " << endl;
		cout << "2-    Insert an element at Front       " << endl;
		cout << "3-    Insert an element at Any position       " << endl;
		cout << "4-    Delete an element at End      " << endl;
		cout << "5-    Delete an element at Front      " << endl;
		cout << "6-    Delete an element at Any position      " << endl;
		cout << "7-    Search an element         " << endl;
		cout << "8-    Search Position of an element         " << endl;
		cout << "9-    Display list         " << endl;
		cout << "10-    Update list         " << endl;
		cout << "11-    Is list Empty        " << endl;
		cout << "12-    Exit        \n" << endl;
		cout << "choose any one from these above options: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter an element for insertion at end : ";
			cin >> value;

			insert_end(value);
		}

		else if (choice == 2) {
			cout << "Enter an element for insertion at front : ";
			cin >> value;

			insert_front(value);
		}

		else if (choice == 3) {
			cout << "Enter an element position for insertion : ";
			cin >> pos;
			cout << "Enter the ID for Insertion: ";
			cin >> value;

			insert_anypos(pos, value);
		}

		else if (choice == 4) {
			cout << "Id delete from end:" << endl;
			delete_end();
		}

		else if (choice == 5) {
			cout << "Id delete from front:" << endl;
			delete_front();
		}

		else if (choice == 6) {
			cout << "Enter ID position for deletion:" << endl;
			cin >> pos;
			delete_anypos(pos);
		}
		else if (choice == 7) {
			cout << "Enter an element for Searching: ";
			cin >> value;

			cout << search(value);
		}
		else if (choice == 8) {
			cout << "Enter an element for Search Position of ID: ";
			cin >> value;

			cout << search_position(value);
		}
		else if (choice == 9) {

			display();
		}
		else if (choice == 10) {
			cout << "\nUPDATE" << endl;
			cout << "enter the ID for override the previous: ";
			cin >> value;

			update(value);
		}
		else if (choice == 11) {
			isempty();
		}
		else if (choice == 12) {
			exit(0);
		}

		cout << "\nPress 'y' to continue and ''n' to exit" << endl;
		cin >> c;
	} while (c == 'Y' || c == 'y');
	return 0;


}
*/
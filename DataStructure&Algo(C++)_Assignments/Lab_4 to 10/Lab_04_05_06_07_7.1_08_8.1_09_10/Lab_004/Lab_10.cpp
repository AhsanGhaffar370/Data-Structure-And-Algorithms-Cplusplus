/*
#include<iostream>
#include<string>
using namespace std;

struct treenode {
	int id;
	treenode *left;
	treenode *right;

}; treenode *root = NULL;

bool add_record(int id);
bool delete_record(int id, treenode *&);
void update_record(int id);
bool search_record(int id);
bool display_record(treenode *nodeptr);
void max(treenode *nodeptr);
void min(treenode *nodeptr);

//INSERT RECORD IN TEL DICTIONARY Function:
bool add_record(int id)
{
	treenode *new1 = new treenode;
	treenode *nodeptr;
	//bool flag = true;

	new1->id = id;
	new1->left = NULL;
	new1->right = NULL;

	if (root == NULL) {
		root = new1;
		return true;
	}
	else
	{
		nodeptr = root;
		while (nodeptr != NULL)
		{
			if (id < nodeptr->id)
			{
				if (nodeptr->left != NULL)
					nodeptr = nodeptr->left;

				else {
					nodeptr->left = new1;
					return true;
					break;
				}
			}//End of IF:

			else if (id > nodeptr->id)
			{
				if (nodeptr->right != NULL)
					nodeptr = nodeptr->right;

				else {
					nodeptr->right = new1;
					return true;
					break;
				}
			}//End of Else if

			else if (id == nodeptr->id) {
				return false;
				break;
			}//End of Else if
		}//End of While:
	}//End Of Outer Most Else:
}//End of add_record Function:

 //Delete record from Tel dictionary Function
bool delete_record(int id, treenode *&nodeptr)
{
	//Search contact from record for deletion of record:
	if (search_record(id) == true)
	{
		//Find the location of record for deletion through recursion:
		if (id < nodeptr->id)
			delete_record(id, nodeptr->left);

		else if (id > nodeptr->id)
			delete_record(id, nodeptr->right);

		//After find location use if else conditions for deletin of record from tree:
		else
		{
			treenode *temp;
			treenode *temp1;

			//Delte record which have only left child:
			if (nodeptr->right == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->left;
				delete(temp);
			}

			//delete record which have only right child:
			else if (nodeptr->left == NULL)
			{
				temp = nodeptr;
				nodeptr = nodeptr->right;
				delete(temp);
			}

			//delete record which have both childs:
			else
			{
				temp = nodeptr->right;
				while (temp->left != NULL)
					temp = temp->left;

				temp->left = nodeptr->left;
				temp1 = nodeptr;
				nodeptr = nodeptr->right;
				delete(temp1);
			}
		}//End of outer most else:
		return true;             //if record deleted return true
	}//End of outer most if:
	else
		return false;
}//End of delete_record function

 //Search Record from Tel Dictionary Function:
bool search_record(int id)
{
	treenode *temp = root;
	bool flag = false;

	while (temp != NULL)
	{
		if (temp->id == id) {
			flag = true;
			break;
		}

		else if (id < temp->id)
			temp = temp->left;

		else if (id > temp->id)
			temp = temp->right;
	}//End of While:

	if (flag == true)
		return flag;

	else
		return flag;
}// End of search_record Function

 //Update Record form Dictionary Function:
void update_record(int id)
{
	treenode *temp = root;
	bool flag = false;
	long long int up_id;

	while (temp != NULL)
	{
		if (temp->id == id)
		{
			cout << "Enter Contact number to override this id: ";
			cin >> up_id;

			if (search_record(up_id) == true)
				cout << "\nThis contact number is already in the Record!!!" << endl;
			else
			{
				delete_record(id, root);
				add_record(up_id);
				flag = true;
				break;
			}
		}//End of Outer most IF:

		else if (id < temp->id)
			temp = temp->left;

		else if (id > temp->id)
			temp = temp->right;

	}//End of Outer most while:

	if (flag == true) {
		cout << "\n*****************************" << endl;
		cout << " RECORD UPDATED SUCCESSFULLY" << endl;
		cout << "*****************************\n" << endl;
	}
	else
		cout << "\nRecord not found which you want to update!!!" << endl;
}//End of update_record Function

 //Display All records of Dictionary:
bool display_record(treenode *nodeptr)
{
	bool flag = false;
	if (nodeptr != NULL)
	{
		display_record(nodeptr->left);
		cout << "******" << endl;
		cout << nodeptr->id << endl;
		cout << "******" << endl;
		display_record(nodeptr->right);
		return true;
	}
	if (flag == false)
		return false;
}//End of display_record Function:


void min(treenode *nodeptr)
{
	if (nodeptr->left != NULL)
		min(nodeptr->left);

	else if (nodeptr->left == NULL) {
		cout << "\nMinimum: " << nodeptr->id << endl;
	}
}

void max(treenode *nodeptr)
{
	if (nodeptr->right != NULL)
		max(nodeptr->right);

	else if (nodeptr->right == NULL) {
		cout << "Maximum: " << nodeptr->id << endl;
	}
}
int main()
{
	int id;
	char c;
	int choice;

	do {
		cout << "\n============================" << endl;
		cout << "    BINARY SEARCH TREE " << endl;
		cout << "============================" << endl;
		cout << "1-    ADD NEW ID   " << endl;
		cout << "2-    DELETE ID      " << endl;
		cout << "3-    UPDATE ID        " << endl;
		cout << "4-    SEARCH ID    " << endl;
		cout << "5-    DISPLAY ID   " << endl;
		cout << "6-    MAXIMUM & MINIMUM     " << endl;
		cout << "7-    Exit        " << endl;
		cout << "choose any one from the above options: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "\n===================" << endl;
			cout << "  ADD NEW ID" << endl;
			cout << "===================\n" << endl;

			cout << "Enter ID for insertion: ";
			cin >> id;

			if (add_record(id) == true) {
				cout << "\n***************************" << endl;
				cout << "ID ADDED SUUCCESSFULLY" << endl;
				cout << "***************************\n" << endl;
			}
			else
				cout << "\nDuplicate ID don't allowed!!! " << endl;
		}

		else if (choice == 2)
		{
			cout << "\n===================" << endl;
			cout << "   DELETE ID" << endl;
			cout << "===================\n" << endl;

			cout << "\nEnter ID num to deletion of Record: ";
			cin >> id;

			if (delete_record(id, root) == true) {
				cout << "\n***************************" << endl;
				cout << "ID DELETED SUCCESSFULLY" << endl;
				cout << "***************************\n" << endl;
			}
			else
				cout << "\nID Not Found Which you wants to Delete!!!" << endl;
		}

		else if (choice == 3) {
			cout << "\n===================" << endl;
			cout << "  UPDATE ID" << endl;
			cout << "===================\n" << endl;

			cout << "Enter ID number which you wants to update: ";
			cin >> id;

			update_record(id);
		}

		else if (choice == 4)
		{
			cout << "\n===================" << endl;
			cout << "  SEARCH ID" << endl;
			cout << "===================\n" << endl;

			cout << "Enter ID number to Search a Record: ";
			cin >> id;

			if (search_record(id) == true)
				cout << "\nID FOUND:" << endl;
			else
				cout << "\nID NOT FOUND:" << endl;
		}

		else if (choice == 5)
		{
			cout << "\n===================" << endl;
			cout << "  DISPLAY ALL" << endl;
			cout << "===================\n" << endl;

			if (display_record(root) == false)
				cout << "RECORD EMPTY" << endl;
		}

		else if (choice == 6) {
			cout << "\n=====================" << endl;
			cout << "  MAXIMUM & MINIMUM" << endl;
			cout << "=====================\n" << endl;
			max(root);
			min(root);
		}

		else if (choice == 7)
		{
			system("pause");
			exit(0);
		}

		cout << "\nPress 'y' to continue and 'n' to exit: ";
		cin >> c;

	} while (c == 'Y' || c == 'y');

	system("pause");
	return 0;
}
*/
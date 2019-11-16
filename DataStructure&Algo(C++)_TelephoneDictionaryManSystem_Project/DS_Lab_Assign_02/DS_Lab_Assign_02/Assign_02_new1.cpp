#include<iostream>
#include<string>
using namespace std;

struct treenode {
	string name;
	long long int cont;
	string address;
	treenode *left;
	treenode *right;

}; treenode *root = NULL;

bool add_record(string name, long long int cont, string address);
bool delete_record(long long int cont, treenode *&);
void update_record(long long int cont);
bool search_record(long long int cont);
bool display_record(treenode *nodeptr);

//INSERT RECORD IN TEL DICTIONARY Function:
bool add_record(string name, long long int cont, string address)
{
	treenode *new1 = new treenode;
	treenode *nodeptr;
	//bool flag = true;

	new1->name = name;
	new1->cont = cont;
	new1->address = address;
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
			if (cont < nodeptr->cont)
			{
				if (nodeptr->left != NULL)
					nodeptr = nodeptr->left;

				else {
					nodeptr->left = new1;
					return true;
					break;
				}
			}//End of IF:

			else if (cont > nodeptr->cont)
			{
				if (nodeptr->right != NULL)
					nodeptr = nodeptr->right;

				else {
					nodeptr->right = new1;
					return true;
					break;
				}
			}//End of Else if

			else if (cont == nodeptr->cont) {
				return false;
				break;
			}//End of Else if
		}//End of While:
	}//End Of Outer Most Else:
}//End of add_record Function:

 //Delete record from Tel dictionary Function
bool delete_record(long long int cont, treenode *&nodeptr)
{
	//Search contact from record for deletion of record:
	if (search_record(cont) == true)
	{
		//Find the location of record for deletion through recursion:
		if (cont < nodeptr->cont) 
			delete_record(cont, nodeptr->left);
	
		else if (cont > nodeptr->cont)
			delete_record(cont, nodeptr->right);

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
bool search_record(long long int cont)
{
	treenode *temp = root;
	bool flag = false;

	while (temp != NULL)
	{
		if (temp->cont == cont) {
			flag = true;
			break;
		}

		else if (cont < temp->cont)
			temp = temp->left;

		else if (cont > temp->cont)
			temp = temp->right;
	}//End of While:

	if (flag == true)
		return flag;

	else
		return flag;
}// End of search_record Function

 //Update Record form Dictionary Function:
void update_record(long long int cont)
{
	treenode *temp = root;
	bool flag = false;
	long long int up_cont;
	string up_name, up_address;

	while (temp != NULL)
	{
		if (temp->cont == cont)
		{
			cout << "\nEnter Name for Record Updation : ";
			cin >> up_name;
			cout << "Enter Contact number to override this id: ";
			cin >> up_cont;
			cout << "Enter Address for Record Updation: ";
			cin >> up_address;

			if (search_record(up_cont) == true)
				cout << "\nThis contact number is already in the Record!!!" << endl;
			else
			{
				delete_record(cont, root);
				add_record(up_name, up_cont, up_address);
				flag = true;
				break;
			}
		}//End of Outer most IF:

		else if (cont < temp->cont)
			temp = temp->left;

		else if (cont > temp->cont)
			temp = temp->right;

	}//End of Outer most while:

	if (flag == true) {
		cout << "\n***************************" << endl;
		cout << "\nRECORD UPDATED SUCCESSFULLY" << endl;
		cout << "***************************\n" << endl;
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
		cout << "\n********************" << endl;
		cout << nodeptr->name << endl;
		cout << nodeptr->cont << endl;
		cout << nodeptr->address <<"\n"<< endl;
		cout << "********************\n" << endl;
		display_record(nodeptr->right);
		return true;
	}
	if (flag == false)
		return false;
}//End of display_record Function:

int main()
{
	long long int cont;
	string name, address;
	char c;
	int choice;

	do {
		cout << "\n\n============================" << endl;
		cout << "    LINK LIST IMPLEMENTATION  " << endl;
		cout << "============================" << endl;

		cout << "\n1-    ADD NEW CONTACT   " << endl;
		cout << "2-    DELETE CONTACT      " << endl;
		cout << "3-    UPDATE CONTACT        " << endl;
		cout << "4-    SEARCH CONTACt    " << endl;
		cout << "5-    VIEW ALL CONTACTS   " << endl;
		cout << "6-    Exit        \n" << endl;
		cout << "choose any one from the above options: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "\n===================" << endl;
			cout << "  ADD NEW CONTACT" << endl;
			cout << "===================\n" << endl;

			cout << "\nEnter name for insertion: ";
			cin >> name;
			cout << "Enter contact for insertion: ";
			cin >> cont;
			cout << "Enter address for insertion: ";
			cin >> address;

			if (add_record(name, cont, address) == true) {
				cout << "\n***************************" << endl;
				cout << "RECORD ADDED SUUCCESSFULLY" << endl;
				cout << "***************************\n" << endl;
			}
			else
				cout << "\nDuplicate Record don't allowed!!! " << endl;
		}

		else if (choice == 2)
		{
			cout << "\n===================" << endl;
			cout << "   DELETE CONTACT" << endl;
			cout << "===================\n" << endl;

			cout << "\nEnter Contact num to deletion of Record: ";
			cin >> cont;

			if (delete_record(cont, root) == true) {
				cout << "\n***************************" << endl;
				cout << "RECORD DELETED SUCCESSFULLY" << endl;
				cout << "***************************\n" << endl;
			}
			else
				cout << "\nRecord Not Found Which you wants to Delete!!!" << endl;
		}

		else if (choice == 3) {
			cout << "\n===================" << endl;
			cout << "  UPDATE CONTACT" << endl;
			cout << "===================\n" << endl;

			cout << "Enter Contact num of Record which you wants to update: ";
			cin >> cont;

			update_record(cont);
		}

		else if (choice == 4)
		{
			cout << "\n===================" << endl;
			cout << "  SEARCH CONTACT" << endl;
			cout << "===================\n" << endl;

			cout << "\nEnter Contact num to Search a Record: ";
			cin >> cont;

			if (search_record(cont) == true)
				cout << "\nRECORD FOUND:" << endl;
			else
				cout << "\nRECORD NOT FOUND:" << endl;
		}

		else if (choice == 5)
		{
			cout << "\n===================" << endl;
			cout << "  DISPLAY CONTACTS" << endl;
			cout << "===================\n" << endl;

			if (display_record(root) == false)
				cout << "RECORD EMPTY" << endl;
		}

		else if (choice == 6)
		{
			system("pause");
			exit(0);
		}

		cout << "\n\nPress 'y' to continue and 'n' to exit: ";
		cin >> c;

	} while (c == 'Y' || c == 'y');

	system("pause");
	return 0;
}
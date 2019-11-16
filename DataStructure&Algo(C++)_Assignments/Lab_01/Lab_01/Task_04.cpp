#include <iostream>
using namespace std;

//create a structure of Student to which have student info :

struct  student
{
	int age, stdID;

	char name[30];

};

int main() {

	// create an object of student :

	student *ptr, std;

	//saves the object of student in ptr:
	ptr = &std;
	cout << "Enter Student Full name : ";
	cin.get((*ptr).name, 30);

	cout << "Enter Student ID : ";
	cin >> (*ptr).stdID;

	cout << "Enter Student age : ";
	cin >> (*ptr).age;

	cout << "\nFull Information of Student: " << endl;

	cout << "\nID: " << (*ptr).stdID << endl;

	cout << "Name: " << (*ptr).name << endl;

	cout << "Age: " << (*ptr).age << "\n\n";

	system("pause");

	return 0;
}

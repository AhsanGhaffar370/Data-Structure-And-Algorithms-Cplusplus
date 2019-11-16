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
	student std;

	//take input of student id,name & age using structure:
	cout << "Enter Student Full name : ";
	cin.get(std.name, 30);

	cout << "Enter Student ID : ";
	cin >> std.stdID;

	cout << "Enter Student age : ";
	cin >> std.age;

	//Print student Information :
	cout << "\nFull Information of Student: " << endl;

	cout << "\nID: " << std.stdID << endl;

	cout << "Name: " << std.name << endl;

	cout << "Age: " << std.age << "\n\n";

	system("pause");

	return 0;
}


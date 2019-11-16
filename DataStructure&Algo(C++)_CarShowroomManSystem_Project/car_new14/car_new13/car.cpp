#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include<dos.h>
#include <Windows.h>
using namespace std;

//////////////////////           ADMIN REQUIREMENTS FOR HIMSELF          //////////////////////////////
void admin_login();
void emp_main_for_admin();
void admin_car_main();
void emp_car_main();
void admin_portal();

//////////////////////           EMPLOYEE REQUIREMENTS FOR ADMIN          //////////////////////////////
void emp_login();
void emp_portal();
void add_emp(string name, long int sal);
void delete_emp(int id);
void display_emp();
bool search_emp(int id);
void update_emp(int id);
int emp_siz();
void add_emp_from_file(int id, string name, long int sal);
void emp_file_to_list();

////////////////////          CAR REQUIREMENTS FOR ADMIN & EMPLOYEE       ///////////////////////////
int const maintain = 100;
int maintenance();
void add_car(string name, string comp, int model, long int price);
int search_Pos(int id, int chassis);
bool search_car(int chassis);
void update_car(int chassis);
void display_car();
int car_siz();
void add_car_from_file(int chassis, string name, string comp, int model, long int price);
void car_file_to_list();

///////////////////            SOLD CAR REQUIREMENTS FOR ADMIN & EMPLOYEE        //////////////////////
void sold_car(int chassis);
void sold_car_record(int chassis, string car_name, string comp, int model, long int price, string cus_name, long long int cont);
void display_sold_car_rec();
bool search_sold_car(int chassis);
int sold_car_siz();
void sold_car_file_to_list();
void add_sold_car_from_file(int chassis, string car_name, string cmpny, int model, long int act_price, long int sld_price, long int prft_mrgn, string cus_name, long long int cont);

////////////////////////////////////////////////////////
///////////          STRUCTURES             ////////////
////////////////////////////////////////////////////////
struct employee {
	int id;
	string name;
	long int sal;

	employee *next;
	employee *prev;
}; employee *emp_head = NULL;

struct car {
	string name;
	string comp;
	int model;
	int chassis;
	long int price;

	car *next;
	car *prev;
}; car *car_head = NULL;

struct sold_car_rec {
	string cus_name, car_name, comp;
	long int act_price, sld_price, prft_mrgn;
	long long int cont;
	int chassis, model;

	sold_car_rec *next;
	sold_car_rec *prev;
}; sold_car_rec *sold_head = NULL;

int main()
{              ////////////////////MAIN()
	system("Color b");
	emp_file_to_list();
	car_file_to_list();
	sold_car_file_to_list();

	int choice = 0;
	system("cls");
	cout << "\n************  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ************" << endl;
	cout << "**********                                                          **********" << endl;
	cout << "********                                                              ********" << endl;
	cout << "******\t\t\t\CAR SHOWROOM MANAGEMENT SYSTEM\t\t\t******" << endl;
	cout << "********                                                              ********" << endl;
	cout << "**********                                                          **********" << endl;
	cout << "************  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ************" << endl;

	cout << "\n\t\t   ************************************" << endl;
	cout << "\t\t   *                                  *" << endl;
	cout << "\t\t   *  Press 1 FOR [ ADMIN LOGIN ]     *" << endl;
	cout << "\t\t   *  Press 2 FOR [ EMPLOYEE LOGIN ]  *" << endl;
	cout << "\t\t   *  Press 3 FOR [ EXIT ]            *" << endl;
	cout << "\t\t   *                                  *" << endl;
	cout << "\t\t   ************************************" << endl;
	cin >> choice;

	if (choice == 1)
		admin_login();
	else if (choice == 2)
		emp_login();
	else if (choice == 3)
		exit(0);
	else {
		cout << "\n\n\t\t      x------x----x------x-----x-----x" << endl;
		cout << "\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
		cout << "\t\t      x------x----x------x-----x-----x\n" << endl;
		Sleep(2000);
		main();
	}
	system("pause");
}


/////////////////////////////////////////////////////////////////////////////////////////////
////////////////                      ADMIN REQUIREMENTS                      //////////////
////////////////                ADMIN REQUIREMENTS FOR HIMSELF                //////////////
////////////////////////////////////////////////////////////////////////////////////////////

void admin_login()
{
	string adnme, pswrd;

	char ch;
	do
	{
		system("cls");
		cout << "\n\t\t   ************************************" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   *           ADMIN LOGIN            *" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   ************************************" << endl;
		cout << "\n\t\t      USERNAME : ";
		cin >> adnme;
		cout << "\t\t      PASSWORD   : ";
		cin >> pswrd;
		if (adnme == "admin" && pswrd == "12")
			admin_portal();

		else
		{
			cout << "\n\n\t    x---------x----------x----------x--------x-------x-----x" << endl;
			cout << "\t      XXXXX   Username OR Password is incorrect!!!   XXXXX" << endl;
			cout << "\t    x---------x----------x----------x--------x-------x-----x" << endl;
		}
		cout << "\n\t\t        Do you Want to Login again " << endl;
		cout << "\t   Press 'y' for YES  OR  'Any key' for Back to Main Portal ";
		cin >> ch;

	} while (ch == 'y');
	main();
}

void admin_portal()
{
	int choice = 0;
	system("cls");
	cout << "\n\t\t    *************************************" << endl;
	cout << "\t\t    ******                         ******" << endl;
	cout << "\t\t    ******** !!  ADMIN PORTAL !! ********" << endl;
	cout << "\t\t    ******                         ******" << endl;
	cout << "\t\t    *************************************" << endl;
	cout << "\n\n\n\t\t  ****************************************" << endl;
	cout << "\t\t  *                                      *" << endl;
	cout << "\t\t  *  Press 1. FOR [ CAR FUNCTIONS ]      *" << endl;
	cout << "\t\t  *  Press 2. FOR [ EMPLOYEE FUNCTIONS ] *" << endl;
	cout << "\t\t  *  Press 3. FOR [ LOGOUT ]             *" << endl;
	cout << "\t\t  *                                      *" << endl;
	cout << "\t\t  ****************************************" << endl;

	cin >> choice;
	if (choice == 1) {
		system("cls");
		admin_car_main();

	}
	else if (choice == 2)
		emp_main_for_admin();
	else if (choice == 3)
		main();
	else {
		cout << "\n\n\t\t      x------x----x------x-----x-----x" << endl;
		cout << "\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
		cout << "\t\t      x------x----x------x-----x-----x\n" << endl;
		Sleep(2000);
		admin_portal();
	}
}

void emp_main_for_admin() {
	char ch, c, chc;
	string name;
	int  id;
	long int sal;

	do {
		system("cls");
		cout << "\n\t\t    *************************************" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    ******* EMPLOYEE REQUIREMENTS *******" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *************************************" << endl;
		cout << "\n\n\n\t\t  ****************************************" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  *  Press 1. FOR [ ADD EMPLOYEE ]       *" << endl;
		cout << "\t\t  *  Press 2. FOR [ DELETE EMPLOYEE ]    *" << endl;
		cout << "\t\t  *  Press 3. FOR [ SEARCH EMPLOYEE ]    *" << endl;
		cout << "\t\t  *  Press 4. FOR [ UPDATE EMPLOYEE ]    *" << endl;
		cout << "\t\t  *  Press 5. FOR [ EMPLOYEE RECORDS ]   *" << endl;
		cout << "\t\t  *  Press 6. FOR [ BACK TO PORTAL ]     *" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  ****************************************" << endl;
		cout << "\n\t\t  Choose Any ONE From The Above Options: ";
		cin >> ch;

		if (ch == '1') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           ADD EMPLOYEE           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t      Enter Employee Name:   ";
			cin >> name;
			cout << "\n\t\t      Enter Employee SALARY: ";
			cin >> sal;
			add_emp(name, sal);
		}
		else if (ch == '2') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *          DELETE EMPLOYEE         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t   Enter ID to searh employee for DELETION: ";
			cin >> id;

			if (search_emp(id) == true)
			{
				employee *temp = emp_head;
				for (int i = 1; i < search_Pos(id, -1); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   **************************" << endl;
				cout << "\t\t\t   *    ID:     " << temp->id << endl;
				cout << "\t\t\t   *    NAME:   " << temp->name << endl;
				cout << "\t\t\t   *    SALARY: " << temp->sal << endl;
				cout << "\t\t\t   **************************" << endl;

				cout << "\n\t\t      Do you Want to DELETE this Employee " << endl;
				cout << "\t\t    Press 'y' for YES  OR  'Any key' for NO ";
				cin >> chc;

				if (chc == 'y')
					delete_emp(id);
				else
					emp_main_for_admin();
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t   XX !! EMPLOYEE RECORD NOT EXISTED !! XX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}

		else if (ch == '3') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *          SEARCH EMPLOYEE         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t   Enter Employee ID for Searching: ";
			cin >> id;

			if (search_emp(id) == true) {
				employee *temp = emp_head;
				for (int i = 1; i <search_Pos(id, -1); i++)
					temp = temp->next;

				cout << "\n\n\t\t   *********************************" << endl;
				cout << "\t\t   *      ! EMPLOYEE FOUND !       *" << endl;
				cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				cout << "\t\t   *  ID:     " << temp->id << endl;
				cout << "\t\t   *  NAME:   " << temp->name << endl;
				cout << "\t\t   *  SALARY: " << temp->sal << endl;
				cout << "\t\t   *********************************" << endl;
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t    XXXX !!! CAR RECORD NOT FOUND !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}

		}

		else if (ch == '4') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           UPDATE EMPLOYEE        *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\tEnter Employee ID which you wants to UPDATE: ";
			cin >> id;
			update_emp(id);
		}

		else if (ch == '5') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           EMPLOYEE RECORD        *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_emp();

		}
		else if (ch == '6')
			admin_portal();

		else
		{
			cout << "\n\n\t\t      x------x------x------x------x------x" << endl;
			cout << "\t\t        XXXX !!! Invalid Choice !!! XXXX" << endl;
			cout << "\t\t      x------x------x------x------x------x\n" << endl;
			Sleep(2000);
			emp_main_for_admin();
		}

		cout << "\n\t Press 'y' to continue OR  'Any key' to return to Admin portal : ";
		cin >> c;
	} while (c == 'y');
	admin_portal();
}

void admin_car_main() {
	char ch, c, chc;
	string name, comp;
	int model, chassis;
	long int price;

	do {
		system("cls");
		cout << "\n\t\t    *************************************" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *******      CAR DETAILS      *******" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *************************************" << endl;
		cout << "\n\n\n\t\t  ****************************************" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  *  Press 1. FOR [ ADD CAR ]            *" << endl;
		cout << "\t\t  *  Press 2. FOR [ SELL CAR ]           *" << endl;
		cout << "\t\t  *  Press 3. FOR [ SEARCH CAR ]         *" << endl;
		cout << "\t\t  *  Press 4. FOR [ SEARCH SOLD CAR ]    *" << endl;
		cout << "\t\t  *  Press 5. FOR [ UPDATE CAR ]         *" << endl;
		cout << "\t\t  *  Press 6. FOR [ CARS RECORD ]        *" << endl;
		cout << "\t\t  *  Press 7. FOR [ SOLD CARS RECORD ]   *" << endl;
		cout << "\t\t  *  Press 8. FOR [ BACK TO PORTAL ]     *" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  ****************************************" << endl;
		cout << "\n\t\t  Choose Any ONE From The Above Options: ";
		cin >> ch;

		if (ch == '1') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             ADD CAR              *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t     Enter CAR Name         : ";
			cin >> name;
			cout << "\n\t\t     Enter CAR Company Name : ";
			cin >> comp;
			cout << "\n\t\t     Enter CAR Model        : ";
			cin >> model;
			cout << "\n\t\t     Enter CAR Price        : ";
			cin >> price;

			add_car(name, comp, model, price);
		}
		else if (ch == '2') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SELL CAR             *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t Enter Car Chassis_No which you want to Sold: ";
			cin >> chassis;

			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;

				cout << "\n\t\t      Do you Want to SOLD this CAR " << endl;
				cout << "\t\t    Press 'y' for YES  OR  'Any key' for NO ";
				cin >> chc;

				if (chc == 'y')
					sold_car(chassis);
				else
					admin_car_main();
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t   XXXX !!! CAR RECORD NOT EXISTED !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}
		else if (ch == '3') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SEARCH CAR           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t     Enter Car chassis no for Searching: ";
			cin >> chassis;
			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t      XXXX !!! CAR RECORD FOUND !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}
		else if (ch == '4') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *          SEARCH SOLD CAR         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "Enter Car chassis no for Searching: ";
			cin >> chassis;

			if (search_sold_car(chassis) == true) {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t   XXXX !!! CAR RECORD NOT EXISTED !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t    XXXX !!! CAR RECORD NOT FOUND !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}
		else if (ch == '5') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             UPDATE CAR           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t   Enter Chassis no of CAR for UPDATE: ";
			cin >> chassis;

			update_car(chassis);
		}
		else if (ch == '6') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           CAR RECORD             *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_car();
		}
		else if (ch == '7') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *         SOLD CAR RECORD          *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_sold_car_rec();
		}
		else if (ch == '8')
			admin_portal();

		else
		{
			cout << "\n\t\t      x------x----x------x-----x-----x" << endl;
			cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
			cout << "\n\t\t      x------x----x------x-----x-----x" << endl;
			Sleep(2000);
			admin_car_main();
		}
		cout << "\n\t Press 'y' to continue OR  'Any key' to return to Admin portal : ";
		cin >> c;
	} while (c == 'y');
	admin_portal();
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX   END OF ADMIN REQUIREMENTS   XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//



///////////////////////////////////////////////////////////////////////////////////////
////////////////                      EMPLOYEE REQUIREMENTS               //////////////
////////////////                   EMPLOYEE REQUIREMENTS FOR ADMIN       ///////////////
///////////////////////////////////////////////////////////////////////////////////////
void emp_login()                ////////////Employee LOGIN /////////////////
{
	string empname, pass;
	char ch;
	do
	{
		system("cls");
		cout << "\n\t\t   ************************************" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   *          EMPLOYEE LOGIN          *" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   ************************************" << endl;

		cout << "\n\t\t      USERNAME : ";
		cin >> empname;
		cout << "\t\t      PASSWORD   : ";
		cin >> pass;
		if (empname == "employee" && pass == "1234")
			emp_portal();

		else {
			cout << "\n\n\t    x---------x----------x----------x--------x-------x-----x" << endl;
			cout << "\t      XXXXX   Username OR Password is incorrect!!!   XXXXX" << endl;
			cout << "\t    x---------x----------x----------x--------x-------x-----x" << endl;
		}

		cout << "\n\t\t        Do you Want to Login again " << endl;
		cout << "\t   Press 'y' for YES  OR  'Any key' for Back to Main Portal ";
		cin >> ch;

	} while (ch == 'y');
	main();
}

void emp_portal()
{
	system("cls");
	int choice;
	cout << "\n\t\t    ****************************************" << endl;
	cout << "\t\t    ******                            ******" << endl;
	cout << "\t\t    ******** !!  EMPLOYEE PORTAL !! ********" << endl;
	cout << "\t\t    ******                            ******" << endl;
	cout << "\t\t    ******************************************\n" << endl;
	cout << "\t\t    ******************************" << endl;
	cout << "\t\t    *                            *" << endl;
	cout << "\t\t    * Enter 1 for Car functions  *" << endl;
	cout << "\t\t    * Enter 2 for Logout         *" << endl;
	cout << "\t\t    *                            *" << endl;
	cout << "\t\t    ******************************" << endl;
	cin >> choice;
	if (choice == 1)
		emp_car_main();

	else if (choice == 2)
		main();
	else {
		cout << "\n\n\t\t      x------x----x------x-----x-----x" << endl;
		cout << "\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
		cout << "\t\t      x------x----x------x-----x-----x\n" << endl;
		Sleep(2000);
		emp_portal();
	}

}

void emp_car_main() {
	char ch, c, chc;
	int chassis;

	do
	{
		system("cls");
		cout << "\n\t\t    *************************************" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *******      CAR DETAILS      *******" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *************************************" << endl;
		cout << "\n\n\n\t\t  ****************************************" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  *  Press 1. FOR [ SELL CAR ]           *" << endl;
		cout << "\t\t  *  Press 2. FOR [ SEARCH CAR ]         *" << endl;
		cout << "\t\t  *  Press 3. FOR [ SEARCH SOLD CAR ]    *" << endl;
		cout << "\t\t  *  Press 4. FOR [ CARS RECORD ]        *" << endl;
		cout << "\t\t  *  Press 5. FOR [ SOLD CARS RECORD ]   *" << endl;
		cout << "\t\t  *  Press 6. FOR [ BACK TO PORTAL ]     *" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  ****************************************" << endl;
		cout << "\n\t\t  Choose Any ONE From The Above Options: ";
		cin >> ch;


		if (ch == '1') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SELL CAR             *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\tEnter Chassis No of car which you want to Sold: ";
			cin >> chassis;

			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;

				cout << "\n\t\t      Do you Want to SOLD this CAR " << endl;
				cout << "\t\t    Press 'y' for YES  OR  'Any key' for NO ";
				cin >> chc;

				if (chc == 'y')
					sold_car(chassis);
				else
					emp_car_main();
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t   XXXX !!! CAR RECORD NOT EXISTED !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}
		else if (ch == '2') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SEARCH CAR           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t     Enter Car chassis no for Searching: ";
			cin >> chassis;
			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t    XXXX !!! CAR RECORD NOT FOUND !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}
		else if (ch == '3') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *         SEARCH SELL CAR          *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t   Enter Car chassis no for Searching: ";
			cin >> chassis;

			if (search_sold_car(chassis) == true) {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t      XXXX !!! CAR RECORD FOUND !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
			else {
				cout << "\n\n\t\t x------x-------x------x------x------x------x" << endl;
				cout << "\t\t   XXXX !!! CAR RECORD NOT FOUND !!! XXXX" << endl;
				cout << "\t\t x------x-------x------x------x------x------x\n" << endl;
			}
		}

		else if (ch == '4') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *       DISPLAY CAR RECORD         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_car();
		}

		else if (ch == '5') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *     DISPLAY SOLD CAR RECORD      *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_sold_car_rec();
		}
		else if (ch == '6')
			emp_portal();

		else
		{
			cout << "\n\n\t\t      x------x----x------x-----x-----x" << endl;
			cout << "\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
			cout << "\t\t      x------x----x------x-----x-----x\n" << endl;
			Sleep(2000);
			emp_car_main();
		}
		cout << "\n\t Press 'y' to continue OR  'Any key' to return to Employee portal: ";
		cin >> c;
	} while (c == 'Y' || c == 'y');
	emp_portal();
}

void add_emp(string name, long int sal)                    ////////////ADD Employee
{
	int id;
	bool flag = false;
	do
	{
		cout << "\n\t\t      Enter Employee ID:   ";
		cin >> id;

		if (search_emp(id) != true)
		{
			if (id >= 0 && sal >= 0)
			{
				//Add student in file:
				ofstream f_out("Employee.txt", ios::out | ios::app);

				if (f_out.fail()) {
					cerr << "\n\t\t      Error in Opening Employee File:" << endl;
					exit(1);
				}
				else {
					f_out << "\n" << id << " ";
					f_out << name << " ";
					f_out << sal << endl;
					f_out.close();
				}

				//Add employee in link list:
				employee *emp1 = new employee;
				emp1->id = id;
				emp1->name = name;
				emp1->sal = sal;
				emp1->next = NULL;
				emp1->prev = NULL;
				employee *temp;

				if (emp_head == NULL)
					emp_head = emp1;

				else {
					temp = emp_head;

					while (temp->next != NULL)
						temp = temp->next;

					temp->next = emp1;
					emp1->prev = temp;
				}
				cout << "\n\n\t\t   ***********************************" << endl;
				cout << "\t\t   * ! EMPLOYEE ADDED SUCCESSFULLY ! *" << endl;
				cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				cout << "\t\t   *     ID     : " << id << endl;
				cout << "\t\t   *     NAME   : " << name << endl;
				cout << "\t\t   *     SALARY : " << sal << endl;
				cout << "\t\t   *                                 *" << endl;
				cout << "\t\t   ***********************************" << endl;
				flag = true;
			}
			else {
				cout << "\n\n\t\t x------x------x------x------x------x------x------x" << endl;
				cout << "\n\t\t   XXX !! Please Enter correct information !! XXX" << endl;
				cout << "\n\t\t x------x------x------x------x------x------x------x" << endl;
				break;
			}
		}
		else {
			cout << "\n\t\t  x------x------x------x------x------x------x------x" << endl;
			cout << "\t\t    This ID already assigned to another Employee" << endl;
			cout << "\t\t    !! Please ReEnter the ID for this Employee !!" << endl;
			cout << "\t\t  x------x------x------x------x------x------x------x" << endl;
		}
	} while (flag != true);
}

bool search_emp(int id)                    ////////////SEARCH Employee
{
	bool flag = false;
	//Search employee record from link list:
	employee *temp;
	temp = emp_head;

	for (int i = 0; i<emp_siz(); i++)
	{
		if (temp->id == id) {
			flag = true;
			break;
		}
		else
			temp = temp->next;
	}

	return flag;
}

void update_emp(int id)                   ////////////UPDATE Employee
{
	string up_name;
	int up_id;
	long int up_sal;
	bool flag = false;

	if (search_emp(id) == true)
	{
		cout << "\n\n\t\tEnter Updated Name : ";
		cin >> up_name;
		cout << "\n\t\tEnter Updated Salary : ";
		cin >> up_sal;
		do
		{
			cout << "\n\t\tEnter Updated ID     : ";
			cin >> up_id;

			if (search_emp(up_id) != true || up_id == id)
			{
				if (up_sal >= 0 && up_id >= 0)
				{
					//UPDATE employee record from file
					employee *temp1 = emp_head;
					int pos = search_Pos(id, -1);
					for (int i = 1; i <pos; i++)
						temp1 = temp1->next;

					ifstream f_in;
					f_in.open("Employee.txt");
					if (f_in.fail()) {
						cerr << "\n\t\t   Error in Updating employee:" << endl;
						exit(1);
					}
					else {
						string line;
						ofstream f_out;
						f_out.open("temp.txt");
						int t_id = id;
						while (getline(f_in, line)) {
							//Convert string to integar for comparing:
							int int_l;
							std::istringstream(line) >> int_l;

							if (int_l != id) {
								f_out << line << endl;
							}
							else if (int_l == t_id) {
								f_out << (temp1->id = up_id) << " ";
								f_out << (temp1->name = up_name) << " ";
								f_out << (temp1->sal = up_sal) << "\n" << endl;
								t_id = -1;
							}
						}
						f_in.close();
						f_out.close();
						remove("Employee.txt");
						rename("temp.txt", "Employee.txt");
					}
					flag = true;
					cout << "\n\n\t\t   ******************************************" << endl;
					cout << "\t\t   *  EMPLOYEE RECORD UPDATED SUCCESSFULLY  *" << endl;
					cout << "\t\t   ******************************************" << endl;
				}
				else {
					cout << "\n\n\t\t   x------x------x------x------x------x------x------x" << endl;
					cout << "\t\t     XXX !! Please Enter correct information !! XXX" << endl;
					cout << "\t\t   x------x------x------x------x------x------x------x" << endl;
					update_emp(id);
				}
			}
			else {
				cout << "\n\tx-----x------x------x------x------x------x------x-------x------x------x" << endl;
				cout << "\t  !!ID which you want tp update is already assigned to another customer!!" << endl;
				cout << "\t x-----x------x------x------x------x------x------x-------x------x------x" << endl;
			}
		} while (flag != true);
	}
	else {
		cout << "\n\n\t\t      x------x-------x------x------x------x------x-----x" << endl;
		cout << "\t\t         XXXX !!! EMPLOYEE RECORD NOT EXISTED !!! XXXX" << endl;
		cout << "\t\t      x------x-------x------x------x------x------x-----x\n" << endl;
	}
}

void delete_emp(int id)                     ////////////DELETE Employee
{
	//Delete record from file:
	ifstream f_in;
	f_in.open("Employee.txt");

	if (f_in.fail()) {
		cerr << "\t\t      Error in deleting employee:" << endl;
		exit(1);
	}
	else {
		string line;
		ofstream f_out;
		f_out.open("temp.txt");

		while (getline(f_in, line)) {
			//Convert string to int for comapring:
			int int_l;
			std::istringstream(line) >> int_l;

			if (int_l != id)
				f_out << line << endl;
		}
		f_in.close();
		f_out.close();
		remove("Employee.txt");
		rename("temp.txt", "Employee.txt");
	}

	//delete employee record from link list:
	employee *temp = emp_head;
	employee *temp1 = NULL;
	int pos = search_Pos(id, -1);

	if (temp->next == NULL) {
		delete(temp);
		emp_head = NULL;
	}
	else if (pos == 1) {
		//if pos==1 delete node from front:
		employee *temp = emp_head;
		emp_head = emp_head->next;
		delete(temp);
		emp_head->prev = NULL;
	}
	else if (pos != 1 && pos != emp_siz()) {
		for (int i = 1; i<pos; i++)
		{
			temp = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete(temp);
	}
	else if (pos == emp_siz()) {
		////if pos==(complete size of list) apply delete node from end:
		employee *temp;
		temp = emp_head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		delete(temp);
	}
	cout << "\n\t\t************************************************" << endl;
	cout << "\t\t* !! Employee has been Deleted Successfully !! *" << endl;
	cout << "\t\t************************************************" << endl;
}

void display_emp() {                        /////////////////DISPLAY EMPLOYEE
	employee *temp = emp_head;
	if (temp != NULL) {
		while (temp != NULL) {
			cout << "\n\t\t       ***********************" << endl;
			cout << "\t\t           ID:     " << temp->id << endl;
			cout << "\t\t           NAME:   " << temp->name << endl;
			cout << "\t\t           SALARY: " << temp->sal << "\n" << endl;
			cout << "\t\t       ***********************" << endl;
			temp = temp->next;
		}
	}
	else {
		cout << "\n\n\t\t      x------x-------x------x------x------x------x-----x" << endl;
		cout << "\t\t          XXXX !!! EMPLOYEE RECORD IS EMPTY !!! XXXX" << endl;
		cout << "\t\t      x------x-------x------x------x------x------x-----x\n" << endl;
	}
}

void emp_file_to_list()    //Add Employee from file to lnk list
{
	string f_name;
	int f_id;
	long int f_sal;

	ifstream myfile("Employee.txt");
	while (myfile.eof() == NULL)
	{
		myfile >> f_id;
		myfile >> f_name;
		myfile >> f_sal;
		if (search_emp(f_id) != true)
			add_emp_from_file(f_id, f_name, f_sal);
	}
	myfile.close();
}

void add_emp_from_file(int id, string name, long int sal)  //Add Employee from file to lnk list
{
	employee *emp1 = new employee;
	emp1->id = id;
	emp1->name = name;
	emp1->sal = sal;
	emp1->next = NULL;
	emp1->prev = NULL;
	employee *temp;
	if (id >= 0)
	{
		if (emp_head == NULL)
			emp_head = emp1;
		else {
			temp = emp_head;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = emp1;
			emp1->prev = temp;
		}
	}
}

int emp_siz() {                         /////////////////SIZE OF ISSUED_BOOKS RECORD
	employee *temp = emp_head;
	int count = 1, null = 0;
	//Find size of link list:
	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	else
		return null;
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX  END OF EMPLOYEE REQUIREMENTS XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////                      CAR REQUIREMENTS                         //////////////
////////////////           CAR REQUIREMENTS FOR ADMIN & EMPLOYEE              //////////////
////////////////////////////////////////////////////////////////////////////////////////////
void add_car(string name, string comp, int model, long int price)  ////////////ADD CAR
{
	int chassis;
	char con, man;
	bool flag = false;
	SYSTEMTIME a;
	GetLocalTime(&a);

	do
	{
		cout << "\n\t\t     Enter CAR Chassis No   :    ";
		cin >> chassis;
		cout << "\t\t   ************************************\n" << endl;
		cout << "\n\t\t     This car condition is USED or UN_USED" << endl;
		cout << "\t\t     Press 'y' for 'used' OR 'n' for 'unused': ";
		cin >> con;
		if (con == 'y' || con == 'Y') {
			price += maintain;
			cout << "\n\t\tx------x-----x-------x--------x--------x-----x" << endl;
			cout << "\t\tWithout maintenance You can't Sold this car to" << endl;
			cout << "\t\t customer, You have to pay 100$ for tunning:" << endl;
			cout << "\t\tx------x-----x-------x--------x--------x-----x" << endl;
			cout << "\n\n\t\t     DO you want extra maintenance for this car: " << endl;
			cout << "\t\t     Press 'y' for YES  OR  'n' for NO: ";
			cin >> man;
			if (man == 'y' || man == 'Y') {
				price += maintenance();
			}
			cout << "\n\t\t   x------x-----x-------x--------x--------x-----x" << endl;
			cout << "\t\t   |         CaAR MAINTAINED SUCCESSFULLY       | " << endl;
			cout << "\t\t   |  Now this car is ready to sold to customer |" << endl;
			cout << "\t\t   x------x-----x-------x--------x--------x-----x" << endl;
		}
		if (search_car(chassis) != true)
		{
			if (chassis >= 0 && model <= a.wYear)
			{
				//Add CAR in file:
				ofstream f_out("car_rec.txt", ios::out | ios::app);

				if (f_out.fail()) {
					cerr << "\t\t\tError in Opening Car Record File:" << endl;
					exit(1);
				}
				else {
					f_out << chassis << "   " << name << "   " << comp << "   ";
					f_out << model << "   " << price << "\n" << endl;
					f_out.close();
				}

				//Add CAR in link list:
				car *car1 = new car;
				car1->chassis = chassis;
				car1->name = name;
				car1->comp = comp;
				car1->model = model;
				car1->price = price;

				car1->next = NULL;
				car1->prev = NULL;
				car *temp;

				if (car_head == NULL)
					car_head = car1;

				else {
					temp = car_head;
					while (temp->next != NULL)
						temp = temp->next;

					temp->next = car1;
					car1->prev = temp;
				}
				cout << "\n\n\t\t   ***********************************" << endl;
				cout << "\t\t\t   *   !! CAR ADDED SUCCESSFULLY !!  *" << endl;
				cout << "\t\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				cout << "\t\t\t   *    CAR Chassis_no : " << chassis << endl;
				cout << "\t\t\t   *    CAR NAME       : " << name << endl;
				cout << "\t\t\t   *    CAR Company    : " << comp << endl;
				cout << "\t\t\t   *    CAR MODEL      : " << model << endl;
				cout << "\t\t\t   *    CAR Price      : " << price << endl;
				cout << "\t\t\t   ***********************************" << endl;
				flag = true;
			}
			else {
				cout << "\n\n\t\t   x------x------x------x------x------x------x" << endl;
				cout << "\t\t      XXX !! In_correct information !! XXX" << endl;
				cout << "\t\t   x------x------x------x------x------x------x" << endl;
				break;
			}
		}
		else {
			cout << "\n\t\t  x------x------x------x------x------x------x------x-----x" << endl;
			cout << "\t\t  !! This Chassis_no is already assigned to another Car !!" << endl;
			cout << "\t\t    !! Please ReEnter Chassis_no for this Car !!" << endl;
			cout << "\t\t  x------x------x------x------x------x------x------x-----x" << endl;
		}
	} while (flag != true);
}

bool search_car(int chassis)                    ////////////SEARCH car
{
	bool flag = false;
	//Search car record from link list:
	car *temp;
	temp = car_head;

	for (int i = 0; i<car_siz(); i++)
	{
		if (temp->chassis == chassis) {
			flag = true;
			break;
		}
		else
			temp = temp->next;
	}
	return flag;
}

void update_car(int chassis)                   ////////////UPDATE Employee
{
	string up_name, up_comp;
	int up_model;
	long int up_price;
	bool flag = false;

	if (search_car(chassis) == true)
	{
		cout << "\n\t\t   Enter Updated Name for Car: ";
		cin >> up_name;
		cout << "\t\t   Enter Updated Company Name for car: ";
		cin >> up_comp;
		cout << "\t\t   Enter Updated Model No for Car: ";
		cin >> up_model;
		cout << "\t\t   Enter Updated Price for car: ";
		cin >> up_price;

		//UPDATE employee record from file
		car *temp1 = car_head;
		int pos = search_Pos(-1, chassis);
		for (int i = 1; i <pos; i++)
			temp1 = temp1->next;

		ifstream f_in;
		f_in.open("car_rec.txt");
		if (f_in.fail()) {
			cerr << "Error in Updating car:" << endl;
			exit(1);
		}
		else {
			string line;
			ofstream f_out;
			f_out.open("temp.txt");
			int t_chassis = chassis;

			while (getline(f_in, line)) {
				//Convert string to int for comapring:
				int int_l;
				std::istringstream(line) >> int_l;

				if (int_l != chassis)
					f_out << line << endl;

				else if (int_l == t_chassis) {
					f_out << chassis << "   ";
					f_out << (temp1->name = up_name) << "   ";
					f_out << (temp1->comp = up_comp) << "   ";
					f_out << (temp1->model = up_model) << "   ";
					f_out << (temp1->price = up_price) << "\n" << endl;
					t_chassis = -1;
				}
			}
			f_in.close();
			f_out.close();
			remove("car_rec.txt");
			rename("temp.txt", "car_rec.txt");
		}
		flag = true;
		cout << "\n\n\t\t   *************************************" << endl;
		cout << "\t\t   *  CAR RECORD UPDATED SUCCESSFULLY  *" << endl;
		cout << "\t\t   *************************************" << endl;
	}
	else {
		cout << "\n\n\t\t      x------x-------x------x------x------x------x-----x" << endl;
		cout << "\t\t           XXXX !!! CAR RECORD NOT EXISTED !!! XXXX" << endl;
		cout << "\t\t      x------x-------x------x------x------x------x-----x\n" << endl;
	}
}

void display_car() {                        /////////////////DISPLAY EMPLOYEE
	car *temp = car_head;

	if (temp != NULL) {
		while (temp != NULL) {
			cout << "\n\t\t       *****************************" << endl;
			cout << "\t\t         Chassis No:  " << temp->chassis << endl;
			cout << "\t\t         Car Name:    " << temp->name << endl;
			cout << "\t\t         Car Company: " << temp->comp << endl;
			cout << "\t\t         Model No:    " << temp->model << endl;
			cout << "\t\t         Car Price:   " << temp->price << endl;
			cout << "\t\t       *****************************\n" << endl;
			temp = temp->next;
		}
	}
	else {
		cout << "\n\n\t\t      x------x-------x------x------x------x------x-----x" << endl;
		cout << "\t\t          XXXX !!! CAR RECORD IS EMPTY !!! XXXX" << endl;
		cout << "\t\t      x------x-------x------x------x------x------x-----x\n" << endl;
	}

}

int maintenance()
{
	int ch, hp = 10, af = 5, cp = 20, bp = 15, wb = 10, sg = 60, ff = 5, ec = 20, db = 30, mr = 80, others;
	char  choice;
	string part;
	int total = 0;
	do
	{
		cout << "\n\t\t   *******************************************" << endl;
		cout << "\t\t   SPAREPARTS                           PRICE" << endl;
		cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout << "\t\t   1. Hose Pipes                         10 $ " << endl;
		cout << "\t\t   2. Air Filter                         5  $ " << endl;
		cout << "\t\t   3. Clutch Plate                       20 $ " << endl;
		cout << "\t\t   4. Brake Pads                         15 $ " << endl;
		cout << "\t\t   5. Wiper Blades                       10 $ " << endl;
		cout << "\t\t   6. Steering Gearbox & Boots           60 $ " << endl;
		cout << "\t\t   7. Fuel Filter                        5  $ " << endl;
		cout << "\t\t   8. Engine Coolant                     20 $ " << endl;
		cout << "\t\t   9. Drive Belts                        30 $ " << endl;
		cout << "\t\t   10.Mirrors                            80 $ " << endl;
		cout << "\t\t   11.Other parts                             " << endl;
		cout << "\t\t   *******************************************" << endl;
		cout << "\n\t\t   Chosse any one Option for maintenance: ";
		cin >> ch;
		if (ch == 1) {
			total += hp;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t          XXXX !!! Hose Pipes inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 2) {
			total += af;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t          XXXX !!! Air Filter inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 3) {
			total += cp;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t          XXXX !!! Hose Pipes inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
			cout << "\n\t\t   Clutch Plate inserted:" << endl;
		}
		else if (ch == 4) {
			total += bp;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t          XXXX !!! Brake Pads inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 5) {
			total += wb;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t          XXXX !!! Wiper Blades inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 6) {
			total += sg;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t      XX ! Steering Gearbox & Boots inserted ! XX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 7) {
			total += ff;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t         XXXX !!! Fuel Filter inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 8) {
			total += ec;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t        XXXX !!! Engine Coolant inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
			cout << "\n\t\t   Engine Coolant inserted:" << endl;
		}
		else if (ch == 9) {
			total += db;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t         XXXX !!! Drive Belts inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
			cout << "\n\t\t   Drive Belts inserted:" << endl;
		}
		else if (ch == 10) {
			total += mr;
			cout << "\n\t\t      x------x-------x------x------x------x------x" << endl;
			cout << "\t\t          XXXX !!! Mirrors inserted !!! XXXX" << endl;
			cout << "\t\t      x------x-------x------x------x------x------x\n" << endl;
		}
		else if (ch == 11) {
			cout << "\n\t\t   Enter sparepart name which you wants to insert in car: ";
			cin >> part;
			cout << "\t\t   Enter " << part << " part price: ";
			cin >> others;
			total += others;
			cout << "\n\t\t      x------x-------x------x------x------x" << endl;
			cout << "\t\t         !!! " << part << " inserted !!!" << endl;
			cout << "\t\t      x------x-------x------x------x------x\n" << endl;

		}
		else {
			cout << "\n\t\t      x-----x-------x------x------x------x-----x" << endl;
			cout << "\t\t           XXXX !!! INVALID CHOICE !!! XXXX" << endl;
			cout << "\t\t      x-----x-------x------x------x------x-----x\n" << endl;
			Sleep(2000);
			maintenance();
		}

		cout << "\n\t\t  Do you want more Maintenance; " << endl;
		cout << "\t\t  Press 'y' to continue 'Any key' to Exit: ";
		cin >> choice;
	} while (choice == 'y');

	return total;
}

int search_Pos(int id, int chassis)                          /////Search CAR Record Position:
{
	int count = 1, pos = -1;
	if (chassis == -1)
	{
		//for searching employee position:
		employee *temp = emp_head;
		bool flag = false;

		if (temp == NULL)
			flag = false;
		else {
			for (int i = 0; i<emp_siz(); i++) {
				if (temp->id == id) {
					flag = true;
					break;
				}
				else
					temp = temp->next;
				count++;
			}
		}
		if (flag == true)
			return count;
		else if (flag = false)
			return pos;
	}

	else if (id == -1)
	{
		//for searching car position:
		car *temp = car_head;
		bool flag = false;

		if (temp == NULL)
			flag = false;
		else {
			for (int i = 0; i<car_siz(); i++) {
				if (temp->chassis == chassis) {
					flag = true;
					break;
				}
				else
					temp = temp->next;
				count++;
			}
		}
		if (flag == true)
			return count;
		else if (flag = false)
			return pos;
	}
}

int car_siz() {                         /////////////////SIZE OF car RECORD
	car *temp = car_head;
	int count = 1, null = 0;

	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	else
		return null;
}

void car_file_to_list()    //Add car from file to lnk list
{
	string name, comp;
	int chassis, model;
	long int price;

	ifstream myfile("car_rec.txt");
	while (!myfile.eof()) {
		myfile >> chassis;
		myfile >> name;
		myfile >> comp;
		myfile >> model;
		myfile >> price;

		if (search_car(chassis) != true)
			add_car_from_file(chassis, name, comp, model, price);
	}
	myfile.close();
}

void add_car_from_file(int chassis, string name, string comp, int model, long int price)//Add car from file to lnk list
{
	car *car1 = new car;
	car1->chassis = chassis;
	car1->name = name;
	car1->comp = comp;
	car1->model = model;
	car1->price = price;
	car1->next = NULL;
	car1->prev = NULL;
	car *temp;

	if (chassis >= 0)
	{
		if (car_head == NULL)
			car_head = car1;
		else {
			temp = car_head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = car1;
			car1->prev = temp;
		}
	}
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX    END OF CAR REQUIREMENTS    XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//




/////////////////////////////////////////////////////////////////////////////////////////////
////////////////                    SOLD  CAR REQUIREMENTS                     //////////////
////////////////         SOLD CAR REQUIREMENTS FOR ADMIN & EMPLOYEE            //////////////
////////////////////////////////////////////////////////////////////////////////////////////
void sold_car(int chassis)                     ////SOLD CAR 
{
	string cus_name;
	long long int cont;

	car *temp2 = car_head;
	int pos = search_Pos(-1, chassis);
	for (int i = 1; i < pos; i++)
		temp2 = temp2->next;

	cout << "\n\t\t     Enter Customer name  : ";
	cin >> cus_name;
	cout << "\n\t\t     Enter Contact Number : +92";
	cin >> cont;

	sold_car_record(chassis, temp2->name, temp2->comp, temp2->model, temp2->price, cus_name, cont);

	//Delete record from file:
	ifstream f_in;
	f_in.open("car_rec.txt");

	if (f_in.fail()) {
		cerr << "\n\t\t    Error in deleting Car record from file:" << endl;
		exit(1);
	}
	else {
		string line;
		ofstream f_out;
		f_out.open("temp.txt");

		while (getline(f_in, line)) {
			//Convert string to int for comapring:
			int int_l;
			std::istringstream(line) >> int_l;

			if (int_l != chassis)
				f_out << line << endl;
		}
		f_in.close();
		f_out.close();
		remove("car_rec.txt");
		rename("temp.txt", "car_rec.txt");
	}

	//delete car record from link list:
	car *temp = car_head;
	car *temp1 = NULL;

	if (temp->next == NULL) {
		delete(temp);
		car_head = NULL;
	}
	else if (pos == 1) {
		//if pos==1 delete node from front:
		car *temp = car_head;
		car_head = car_head->next;
		delete(temp);
		car_head->prev = NULL;
	}
	else if (pos != 1 && pos != car_siz()) {
		for (int i = 1; i < pos; i++)
		{
			temp = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete(temp);
	}
	else if (pos == car_siz()) {
		////if pos==(complete size of list) apply delete node from end:
		car *temp;
		temp = car_head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		delete(temp);
	}
}

void sold_car_record(int chassis, string car_name, string comp, int model, long int price, string cus_name, long long int cont)  ////////////ADD CAR
{
	long int profit = (price * 5) / 100;
	long int sold_price = (price + profit);
	//Add SOLD_CAR in file:
	ofstream f_out("sold_car_rec.txt", ios::out | ios::app);

	if (f_out.fail()) {
		cerr << "\n\t\t    Error in Opening Car Record File:" << endl;
		exit(1);
	}
	else {
		f_out << "\n" << chassis;
		f_out << "    " << car_name;
		f_out << "    " << comp;
		f_out << "    " << model;
		f_out << "    " << price;
		f_out << "    " << sold_price;
		f_out << "    " << profit;
		f_out << "    " << cus_name;
		f_out << "    " << cont << "\n" << endl;


		f_out.close();
	}

	//Add Sold CAR in link list:
	sold_car_rec *scar1 = new sold_car_rec;
	scar1->chassis = chassis;
	scar1->car_name = car_name;
	scar1->comp = comp;
	scar1->model = model;
	scar1->act_price = price;
	scar1->sld_price = sold_price;
	scar1->prft_mrgn = profit;
	scar1->cus_name = cus_name;
	scar1->cont = cont;
	scar1->next = NULL;
	scar1->prev = NULL;
	sold_car_rec *temp;

	if (sold_head == NULL)
		sold_head = scar1;

	else {
		temp = sold_head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = scar1;
		scar1->prev = temp;
	}
	cout << "\n\t\t   *********************************" << endl;
	cout << "\t\t                RECEIPT            " << endl;
	cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "\t\t       Owner Name     : " << cus_name << endl;
	cout << "\t\t       Contact Number :  +92" << cont << endl;
	cout << "\t\t       Chassis No     : " << chassis << endl;
	cout << "\t\t       Car Name       : " << car_name << endl;
	cout << "\t\t       Car Company    : " << comp << endl;
	cout << "\t\t       Car Model      : " << model << endl;
	cout << "\t\t       Car Sold Price : " << sold_price << endl;
	cout << "\t\t   *********************************\n" << endl;
}

void sold_car_file_to_list()    //Add car from file to lnk list
{
	string car_name, comp, cus_name;
	int chassis, model;
	long int act_price, sld_price, prft_mrgn;
	long long int cont;
	ifstream infile("sold_car_rec.txt");
	while (!infile.eof()) {
		infile >> chassis;
		infile >> car_name;
		infile >> comp;
		infile >> model;
		infile >> act_price;
		infile >> sld_price;
		infile >> prft_mrgn;
		infile >> cus_name;
		infile >> cont;

		if (search_sold_car(chassis) != true)
			add_sold_car_from_file(chassis, car_name, comp, model, act_price, sld_price, prft_mrgn, cus_name, cont);
	}
	infile.close();
}

void add_sold_car_from_file(int chassis, string car_name, string cmpny, int model, long int act_price, long int sld_price, long int prft_mrgn, string cus_name, long long int cont) {
	sold_car_rec *car2 = new sold_car_rec;
	car2->cus_name = cus_name;
	car2->cont = cont;
	car2->chassis = chassis;
	car2->car_name = car_name;
	car2->comp = cmpny;
	car2->model = model;
	car2->act_price = act_price;
	car2->sld_price = sld_price;
	car2->prft_mrgn = prft_mrgn;

	car2->next = NULL;
	car2->prev = NULL;
	sold_car_rec *temp;

	if (chassis >= 0)
	{
		if (sold_head == NULL)
			sold_head = car2;
		else {
			temp = sold_head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = car2;
			car2->prev = temp;
		}
	}
}

void display_sold_car_rec() {                        /////////////////DISPLAY EMPLOYEE
	sold_car_rec *temp = sold_head;

	if (temp != NULL) {
		while (temp != NULL) {
			cout << "\n\t\t   *****************************" << endl;
			cout << "\t\t      Chassis No:     " << temp->chassis << endl;
			cout << "\t\t      Car Name:       " << temp->cus_name << endl;
			cout << "\t\t      Car Company:    " << temp->comp << endl;
			cout << "\t\t      Model No:       " << temp->model << endl;
			cout << "\t\t      Car Price:      " << temp->act_price << endl;
			cout << "\t\t      Car Sold price: " << temp->sld_price << endl;
			cout << "\t\t      Profit Margin:  " << temp->prft_mrgn << endl;
			cout << "\t\t   *****************************\n" << endl;
			temp = temp->next;
		}
	}
	else
		cout << "\n\t\t   CAR Record Is Empty!!!" << endl;
}

bool search_sold_car(int chassis)                    ////////////SEARCH car
{
	bool flag = false;
	//Search car record from link list:
	sold_car_rec *temp = sold_head;

	for (int i = 0; i<sold_car_siz(); i++)
	{
		if (temp->chassis == chassis) {
			flag = true;
			break;
		}
		else
			temp = temp->next;
	}
	return flag;
}

int sold_car_siz() {                         /////////////////SIZE OF SOLD CAR RECORD
	sold_car_rec *temp = sold_head;
	int count = 1, null = 0;
	//Find size of link list:
	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	else
		return null;
}
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX  END OF SOLD CAR REQUIREMENT  XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//


/*
#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include<dos.h>
#include <Windows.h>
using namespace std;

//////////////////////           ADMIN REQUIREMENTS FOR HIMSELF          //////////////////////////////
void admin_login();
void emp_main_for_admin();
void admin_car_main();
void emp_car_main();
void admin_portal();

//////////////////////           EMPLOYEE REQUIREMENTS FOR ADMIN          //////////////////////////////
void emp_login();
void emp_portal();
void add_emp(string name, long int sal);
void delete_emp(int id);
void display_emp();
bool search_emp(int id);
void update_emp(int id);
int emp_siz();
void add_emp_from_file(int id, string name, long int sal);
void emp_file_to_list();

////////////////////          CAR REQUIREMENTS FOR ADMIN & EMPLOYEE       ///////////////////////////
int const maintain = 100;
int maintenance();
void add_car(string name, string comp, int model, long int price);
int search_Pos(int id, int chassis);
bool search_car(int chassis);
void update_car(int chassis);
void display_car();
int car_siz();
void add_car_from_file(int chassis, string name, string comp, int model, long int price);
void car_file_to_list();

///////////////////            SOLD CAR REQUIREMENTS FOR ADMIN & EMPLOYEE        //////////////////////
void sold_car(int chassis);
void sold_car_record(int chassis, string car_name, string comp, int model, long int price, string cus_name, long int cont);
void display_sold_car_rec();
bool search_sold_car(int chassis);
int sold_car_siz();
void sold_car_file_to_list();
void add_sold_car_from_file(int chassis, string car_name, string cmpny, int model, long int act_price, long int sld_price, long int prft_mrgn, string cus_name, long int cntct);

////////////////////////////////////////////////////////
///////////          STRUCTURES             ////////////
////////////////////////////////////////////////////////
struct employee {
	int id;
	string name;
	long int sal;
	employee *next;
	employee *prev;
}; employee *emp_head = NULL;

struct car {
	string name;
	string comp;
	int model;
	int chassis;
	long int price;
	car *next;
	car *prev;
}; car *car_head = NULL;

struct sold_car_rec {
	string cus_name, car_name, comp;
	long int cont, act_price, sld_price, prft_mrgn;
	int chassis, model;
	sold_car_rec *next;
	sold_car_rec *prev;
}; sold_car_rec *sold_head = NULL;

int main()
{              ////////////////////MAIN()
	system("Color b");
	emp_file_to_list();
	car_file_to_list();
	sold_car_file_to_list();

	int choice = 0;
	system("cls");
	cout << "\n************  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ************" << endl;
	cout << "**********                                                          **********" << endl;
	cout << "********                                                              ********" << endl;
	cout << "******\t\t\t\CAR SHOWROOM MANAGEMENT SYSTEM\t\t\t******" << endl;
	cout << "********                                                              ********" << endl;
	cout << "**********                                                          **********" << endl;
	cout << "************  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ************" << endl;

	cout << "\n\t\t   ************************************" << endl;
	cout << "\t\t   *                                  *" << endl;
	cout << "\t\t   *  Press 1 FOR [ ADMIN LOGIN ]     *" << endl;
	cout << "\t\t   *  Press 2 FOR [ EMPLOYEE LOGIN ]  *" << endl;
	cout << "\t\t   *  Press 3 FOR [ EXIT ]            *" << endl;
	cout << "\t\t   *                                  *" << endl;
	cout << "\t\t   ************************************" << endl;
	cin >> choice;

	if (choice == 1)
		admin_login();
	else if (choice == 2)
		emp_login();
	else if (choice == 3)
		exit(0);
	system("pause");
}


/////////////////////////////////////////////////////////////////////////////////////////////
////////////////                      ADMIN REQUIREMENTS                      //////////////
////////////////                ADMIN REQUIREMENTS FOR HIMSELF                //////////////
////////////////////////////////////////////////////////////////////////////////////////////

void admin_login()
{
	string adnme, pswrd;

	char ch;
	do
	{
		system("cls");
		cout << "\n\t\t   ************************************" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   *           ADMIN LOGIN            *" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   ************************************" << endl;
		cout << "\n\t\t      USERNAME : ";
		cin >> adnme;
		cout << "\t\t      PASSWORD : ";
		cin >> pswrd;
		if (adnme == "ahsan" && pswrd == "12")
			admin_portal();

		else
		{
			cout << "\n\n\t    ****************************************************" << endl;
			cout << "\t    XXXXX   Username OR Password is incorrect!!!   XXXXX" << endl;
			cout << "\t    ****************************************************" << endl;
		}
		cout << "\n\t\t        Do you Want to Login again " << endl;
		cout << "\t   Press 'y' for YES  OR  'Any key' for Back to Main Portal ";
		cin >> ch;

	} while (ch == 'y');
	main();
}

void admin_portal()
{
	int choice = 0;
	system("cls");
	cout << "\n\t\t    *************************************" << endl;
	cout << "\t\t    ******                         ******" << endl;
	cout << "\t\t    ******** !!  ADMIN PORTAL !! ********" << endl;
	cout << "\t\t    ******                         ******" << endl;
	cout << "\t\t    *************************************" << endl;
	cout << "\n\n\n\t\t  ****************************************" << endl;
	cout << "\t\t  *                                      *" << endl;
	cout << "\t\t  *  Press 1. FOR [ CAR FUNCTIONS ]      *" << endl;
	cout << "\t\t  *  Press 2. FOR [ EMPLOYEE FUNCTIONS ] *" << endl;
	cout << "\t\t  *  Press 3. FOR [ LOGOUT ]             *" << endl;
	cout << "\t\t  *                                      *" << endl;
	cout << "\t\t  ****************************************" << endl;

	cin >> choice;
	if (choice == 1) {
		system("cls");
		admin_car_main();

	}
	else if (choice == 2)
		emp_main_for_admin();
	else if (choice == 3)
		main();
	else {
		cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
		Sleep(2000);
		admin_portal();
	}
}

void emp_main_for_admin() {
	char ch, c, chc;
	string name;
	int  id;
	long int sal;

	do {
		system("cls");
		cout << "\n\t\t    *************************************" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    ******* EMPLOYEE REQUIREMENTS *******" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *************************************" << endl;
		cout << "\n\n\n\t\t  ****************************************" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  *  Press 1. FOR [ ADD EMPLOYEE ]       *" << endl;
		cout << "\t\t  *  Press 2. FOR [ DELETE EMPLOYEE ]    *" << endl;
		cout << "\t\t  *  Press 3. FOR [ SEARCH EMPLOYEE ]    *" << endl;
		cout << "\t\t  *  Press 4. FOR [ UPDATE EMPLOYEE ]    *" << endl;
		cout << "\t\t  *  Press 5. FOR [ EMPLOYEE RECORDS ]   *" << endl;
		cout << "\t\t  *  Press 6. FOR [ BACK TO PORTAL ]     *" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  ****************************************" << endl;
		cout << "\n\t\t  Choose Any ONE From The Above Options: ";
		cin >> ch;

		if (ch == '1') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           ADD EMPLOYEE           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t      Enter Employee Name: ";
			cin >> name;
			cout << "\n\t\t      Enter Employee SALARY: ";
			cin >> sal;
			add_emp(name, sal);
		}
		else if (ch == '2') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *          DELETE EMPLOYEE         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t   Enter ID to searh employee for DELETION: ";
			cin >> id;

			if (search_emp(id) == true)
			{
				employee *temp = emp_head;
				for (int i = 1; i < search_Pos(id, -1); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   **************************" << endl;
				cout << "\t\t\t   *    ID:     " << temp->id << endl;
				cout << "\t\t\t   *    NAME:   " << temp->name << endl;
				cout << "\t\t\t   *    SALARY: " << temp->sal << endl;
				cout << "\t\t\t   **************************" << endl;

				cout << "\n\t\t      Do you Want to DELETE this Employee " << endl;
				cout << "\t\t    Press 'y' for YES  OR  'Any key' for NO ";
				cin >> chc;

				if (chc == 'y')
					delete_emp(id);
				else
					emp_main_for_admin();
			}
			else
				cout << "\n\t\t        !! EMPLOYEE NOT Existed !!" << endl;
		}

		else if (ch == '3') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *          SEARCH EMPLOYEE         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t   Enter Employee ID for Searching: ";
			cin >> id;

			if (search_emp(id) == true) {
				employee *temp = emp_head;
				for (int i = 1; i <search_Pos(id, -1); i++)
					temp = temp->next;

				cout << "\n\n\t\t   *********************************" << endl;
				cout << "\t\t   *      ! EMPLOYEE FOUND !       *" << endl;
				cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				cout << "\t\t   *  ID:     " << temp->id << endl;
				cout << "\t\t   *  NAME:   " << temp->name << endl;
				cout << "\t\t   *  SALARY: " << temp->sal << endl;
				cout << "\t\t   *********************************" << endl;
			}
			else {
				cout << "\n\t\t   *********************************" << endl;
				cout << "\t\t     XXX!! Employee not found !!XXX" << endl;
				cout << "\t\t   *********************************" << endl;
			}

		}

		else if (ch == '4') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           UPDATE EMPLOYEE        *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\tEnter Employee ID which you wants to UPDATE: ";
			cin >> id;
			update_emp(id);
		}

		else if (ch == '5') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           EMPLOYEE RECORD:       *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_emp();

		}
		else if (ch == '6')
			admin_portal();

		else
		{
			cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
			Sleep(2000);
			break;
		}

		cout << "\n\t Press 'y' to continue OR  'Any key' to return to Admin portal : ";
		cin >> c;
	} while (c == 'y');
	admin_portal();
}

void admin_car_main() {
	char ch, c, chc;
	string name, comp;
	int model, chassis;
	long int price;

	do {
		system("cls");
		cout << "\n\t\t    *************************************" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *******      CAR DETAILS      *******" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *************************************" << endl;
		cout << "\n\n\n\t\t  ****************************************" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  *  Press 1. FOR [ ADD CAR ]            *" << endl;
		cout << "\t\t  *  Press 2. FOR [ SELL CAR ]           *" << endl;
		cout << "\t\t  *  Press 3. FOR [ SEARCH CAR ]         *" << endl;
		cout << "\t\t  *  Press 4. FOR [ SEARCH SOLD CAR ]    *" << endl;
		cout << "\t\t  *  Press 5. FOR [ UPDATE CAR ]         *" << endl;
		cout << "\t\t  *  Press 6. FOR [ CARS RECORD ]        *" << endl;
		cout << "\t\t  *  Press 7. FOR [ SOLD CARS RECORD ]   *" << endl;
		cout << "\t\t  *  Press 8. FOR [ BACK TO PORTAL ]     *" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  ****************************************" << endl;
		cout << "\n\t\t  Choose Any ONE From The Above Options: ";
		cin >> ch;

		if (ch == '1') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             ADD CAR              *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t     Enter CAR Name:         ";
			cin >> name;
			cout << "\n\t\t     Enter CAR Company Name: ";
			cin >> comp;
			cout << "\n\t\t     Enter CAR Model:        ";
			cin >> model;
			cout << "\n\t\t     Enter CAR Price:        ";
			cin >> price;

			add_car(name, comp, model, price);
		}
		else if (ch == '2') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SELL CAR              *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t     Enter Car Chassis No of car which you want to Sold: ";
			cin >> chassis;

			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;

				cout << "\n\t\t      Do you Want to SOLD this CAR " << endl;
				cout << "\t\t    Press 'y' for YES  OR  'Any key' for NO ";
				cin >> chc;

				if (chc == 'y')
					sold_car(chassis);
				else
					admin_car_main();
			}
			else
				cout << "\n\t\t        !! CAR NOT Existed !!" << endl;
		}
		else if (ch == '3') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SEARCH CAR           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t     Enter Car chassis no for Searching: ";
			cin >> chassis;
			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;
			}
			else {
				cout << "\n\t\t   *********************************" << endl;
				cout << "\t\t      XXX!! CAR  NOT found !!XXX" << endl;
				cout << "\t\t   *********************************" << endl;
			}
		}
		else if (ch == '4') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *          SEARCH SOLD CAR         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "Enter Car chassis no for Searching: ";
			cin >> chassis;

			if (search_sold_car(chassis) == true)
				cout << "Car Record found:" << endl;
			else
				cout << "Car Record not found:" << endl;
		}
		else if (ch == '5') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             UPDATE CAR           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\t   Enter Chassis no of CAR for UPDATE: ";
			cin >> chassis;

			update_car(chassis);
		}
		else if (ch == '6') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *           CAR RECORD             *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_car();
		}
		else if (ch == '7') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *         SOLD CAR RECORD          *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_sold_car_rec();
		}
		else if (ch == '8')
			admin_portal();

		else
		{
			cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
			Sleep(2000);
			break;
		}
		cout << "\n\t Press 'y' to continue OR  'Any key' to return to Admin portal : ";
		cin >> c;
	} while (c == 'y');
	admin_portal();
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX   END OF ADMIN REQUIREMENTS   XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//



///////////////////////////////////////////////////////////////////////////////////////
////////////////                      EMPLOYEE REQUIREMENTS               //////////////
////////////////                   EMPLOYEE REQUIREMENTS FOR ADMIN       ///////////////
///////////////////////////////////////////////////////////////////////////////////////
void emp_login()                ////////////Employee LOGIN /////////////////
{
	string empname, pass;
	char ch;
	do
	{
		system("cls");
		cout << "\n\t\t   ************************************" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   *          EMPLOYEE LOGIN          *" << endl;
		cout << "\t\t   *                                  *" << endl;
		cout << "\t\t   ************************************" << endl;

		cout << "\n\t\t      USERNAME : ";
		cin >> empname;
		cout << "\t\t      PASSWORD : ";
		cin >> pass;
		if (empname == "ahsan" && pass == "1234")
			emp_portal();

		else {
			cout << "\n\n\t    ****************************************************" << endl;
			cout << "\t    XXXXX   Username OR Password is incorrect!!!   XXXXX" << endl;
			cout << "\t    ****************************************************" << endl;
		}

		cout << "\n\t\t        Do you Want to Login again " << endl;
		cout << "\t   Press 'y' for YES  OR  'Any key' for Back to Main Portal ";
		cin >> ch;

	} while (ch == 'y');
	main();
}

void emp_portal()
{
	system("cls");
	int choice;
	cout << "\n\t\t    ****************************************" << endl;
	cout << "\t\t    ******                            ******" << endl;
	cout << "\t\t    ******** !!  EMPLOYEE PORTAL !! ********" << endl;
	cout << "\t\t    ******                            ******" << endl;
	cout << "\t\t    ******************************************\n" << endl;
	cout << "\t\t    ******************************" << endl;
	cout << "\t\t    *                            *" << endl;
	cout << "\t\t    * Enter 1 for Car functions  *" << endl;
	cout << "\t\t    * Enter 2 for Logout         *" << endl;
	cout << "\t\t    *                            *" << endl;
	cout << "\t\t    ******************************" << endl;
	cin >> choice;
	if (choice == 1)
		emp_car_main();

	else if (choice == 2)
		main();
	else {
		cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
		Sleep(2000);
		emp_portal();
	}

}

void emp_car_main() {
	char ch, c, chc;
	int chassis;

	do
	{
		system("cls");
		cout << "\n\t\t    *************************************" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *******      CAR DETAILS      *******" << endl;
		cout << "\t\t    ******                         ******" << endl;
		cout << "\t\t    *************************************" << endl;
		cout << "\n\n\n\t\t  ****************************************" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  *  Press 1. FOR [ SELL CAR ]           *" << endl;
		cout << "\t\t  *  Press 2. FOR [ SEARCH CAR ]         *" << endl;
		cout << "\t\t  *  Press 3. FOR [ SEARCH SOLD CAR ]    *" << endl;
		cout << "\t\t  *  Press 4. FOR [ CARS RECORD ]        *" << endl;
		cout << "\t\t  *  Press 5. FOR [ SOLD CARS RECORD ]   *" << endl;
		cout << "\t\t  *  Press 6. FOR [ BACK TO PORTAL ]     *" << endl;
		cout << "\t\t  *                                      *" << endl;
		cout << "\t\t  ****************************************" << endl;
		cout << "\n\t\t  Choose Any ONE From The Above Options: ";
		cin >> ch;


		if (ch == '1') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SELL CAR             *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			cout << "\n\t\tEnter Chassis No of car which you want to Sold: ";
			cin >> chassis;

			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;

				cout << "\n\t\t      Do you Want to SOLD this CAR " << endl;
				cout << "\t\t    Press 'y' for YES  OR  'Any key' for NO ";
				cin >> chc;

				if (chc == 'y')
					sold_car(chassis);
				else
					emp_car_main();
			}
			else
				cout << "\n\t\t        !! CAR NOT Existed !!" << endl;
		}
		else if (ch == '2') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *             SEARCH CAR           *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t     Enter Car chassis no for Searching: ";
			cin >> chassis;
			if (search_car(chassis) == true)
			{
				car *temp = car_head;
				for (int i = 1; i < search_Pos(-1, chassis); i++)
					temp = temp->next;

				cout << "\n\n\t\t\t   ****************************" << endl;
				cout << "\t\t\t   *    CAR Chassis: " << temp->chassis << endl;
				cout << "\t\t\t   *    CAR NAME:    " << temp->name << endl;
				cout << "\t\t\t   *    CAR Company: " << temp->comp << endl;
				cout << "\t\t\t   *    CAR MODEL:   " << temp->model << endl;
				cout << "\t\t\t   *    CAR Price:   " << temp->price << endl;
				cout << "\t\t\t   ****************************" << endl;
			}
			else {
				cout << "\n\t\t   *********************************" << endl;
				cout << "\t\t      XXX!! CAR  NOT found !!XXX" << endl;
				cout << "\t\t   *********************************" << endl;
			}
		}
		else if (ch == '3') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *         SEARCH SELL CAR          *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;

			cout << "\n\t\t   Enter Car chassis no for Searching: ";
			cin >> chassis;

			if (search_sold_car(chassis) == true) {
				cout << "\n\t\t   *********************************" << endl;
				cout << "\t\t      XXX!! CAR RECORD found !!XXX" << endl;
				cout << "\t\t   *********************************" << endl;
			}
			else {
				cout << "\n\t\t   *********************************" << endl;
				cout << "\t\t      XXX!! CAR  NOT found !!XXX" << endl;
				cout << "\t\t   *********************************" << endl;
			}
		}

		else if (ch == '4') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *       DISPLAY CAR RECORD         *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_car();
		}

		else if (ch == '5') {
			system("cls");
			cout << "\n\n\t\t   ************************************" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   *     DISPLAY SOLD CAR RECORD      *" << endl;
			cout << "\t\t   *                                  *" << endl;
			cout << "\t\t   ************************************" << endl;
			display_sold_car_rec();
		}
		else if (ch == '6')
			emp_portal();

		else
		{
			cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
			Sleep(2000);
			break;
		}
		cout << "\n\t Press 'y' to continue OR  'Any key' to return to Employee portal: ";
		cin >> c;
	} while (c == 'Y' || c == 'y');
	emp_portal();
}

void add_emp(string name, long int sal)                    ////////////ADD Employee
{
	int id;
	bool flag = false;
	do
	{
		cout << "\n\t\t      Enter Employee ID: ";
		cin >> id;

		if (search_emp(id) != true)
		{
			if (id >= 0 && sal >= 0)
			{
				//Add student in file:
				ofstream f_out("Employee.txt", ios::out | ios::app);

				if (f_out.fail()) {
					cerr << "\n\t\t      Error in Opening Employee File:" << endl;
					exit(1);
				}
				else {
					f_out << "\n" << id << " ";
					f_out << name << " ";
					f_out << sal << "\n" << endl;
					f_out.close();
				}

				//Add employee in link list:
				employee *emp1 = new employee;
				emp1->id = id;
				emp1->name = name;
				emp1->sal = sal;
				emp1->next = NULL;
				emp1->prev = NULL;
				employee *temp;

				if (emp_head == NULL)
					emp_head = emp1;

				else {
					temp = emp_head;

					while (temp->next != NULL)
						temp = temp->next;

					temp->next = emp1;
					emp1->prev = temp;
				}
				cout << "\n\n\t\t   ***********************************" << endl;
				cout << "\t\t   * ! EMPLOYEE ADDED SUCCESSFULLY ! *" << endl;
				cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				cout << "\t\t   *     ID: " << id << endl;
				cout << "\t\t   *     NAME: " << name << endl;
				cout << "\t\t   *     SALARY: " << sal << endl;
				cout << "\t\t   *                                 *" << endl;
				cout << "\t\t   ***********************************" << endl;
				flag = true;
			}
			else {
				cout << "\n\t\t   XXX Please Enter correct information XXX" << endl;
				break;
			}
		}
		else {
			cout << "\n\t\t   *************************************************" << endl;
			cout << "\t\t     This ID already assigned to another Employee" << endl;
			cout << "\t\t     !! Please ReEnter the ID for this Employee !!" << endl;
			cout << "\t\t   *************************************************" << endl;
		}
	} while (flag != true);
}

bool search_emp(int id)                    ////////////SEARCH Employee
{
	bool flag = false;
	//Search employee record from link list:
	employee *temp;
	temp = emp_head;

	for (int i = 0; i<emp_siz(); i++)
	{
		if (temp->id == id) {
			flag = true;
			break;
		}
		else
			temp = temp->next;
	}

	return flag;
}

void update_emp(int id)                   ////////////UPDATE Employee
{
	string up_name;
	int up_id;
	long int up_sal;
	bool flag = false;

	if (search_emp(id) == true)
	{
		cout << "\n\n\t\tEnter Updated Name for Employee Record Updation: ";
		cin >> up_name;
		cout << "\n\t\tEnter Updated Salary for Employee Record Updation: ";
		cin >> up_sal;
		do
		{
			cout << "\n\t\tEnter Updated ID: ";
			cin >> up_id;

			if (search_emp(up_id) != true || up_id == id)
			{
				if (up_sal >= 0 && up_id >= 0)
				{
					//UPDATE employee record from file
					employee *temp1 = emp_head;
					int pos = search_Pos(id, -1);
					for (int i = 1; i <pos; i++)
						temp1 = temp1->next;

					ifstream f_in;
					f_in.open("Employee.txt");
					if (f_in.fail()) {
						cerr << "\n\t\t   Error in Updating employee:" << endl;
						exit(1);
					}
					else {
						string line;
						ofstream f_out;
						f_out.open("temp.txt");
						int t_id = id;
						while (getline(f_in, line)) {
							//Convert string to int for comapring:
							int int_l;
							std::istringstream(line) >> int_l;

							if (int_l != id) {
								f_out << line << endl;
							}
							else if (int_l == t_id) {
								f_out << (temp1->id = up_id) << " ";
								f_out << (temp1->name = up_name) << " ";
								f_out << (temp1->sal = up_sal) << "\n" << endl;
								t_id = -1;
							}
						}
						f_in.close();
						f_out.close();
						remove("Employee.txt");
						rename("temp.txt", "Employee.txt");
					}
					flag = true;
					cout << "\n\n\t\t   ************************************" << endl;
					cout << "\t\t   *  EMPLOYEE  UPDATED SUCCESSFULLY  *" << endl;
					cout << "\t\t   ************************************" << endl;
				}
				else {
					cout << "\n\t\t   XXX ! Please Enter correct updation information ! XXX" << endl;
					break;
				}
			}
			else
				cout << "\n\tID which you want tp update is already assigned to another customer!!!\n" << endl;
		} while (flag != true);
	}
	else {
		cout << "\n\n\t****************************************************************" << endl;
		cout << "\tXXX Employee Record which you want to updated is not existed XXX " << endl;
		cout << "\t****************************************************************" << endl;
	}
}

void delete_emp(int id)                     ////////////DELETE Employee
{
	//Delete record from file:
	ifstream f_in;
	f_in.open("Employee.txt");

	if (f_in.fail()) {
		cerr << "Error in deleting employee:" << endl;
		exit(1);
	}
	else {
		string line;
		ofstream f_out;
		f_out.open("temp.txt");

		while (getline(f_in, line)) {
			//Convert string to int for comapring:
			int int_l;
			std::istringstream(line) >> int_l;

			if (int_l != id)
				f_out << line << endl;
		}
		f_in.close();
		f_out.close();
		remove("Employee.txt");
		rename("temp.txt", "Employee.txt");
	}

	//delete employee record from link list:
	employee *temp = emp_head;
	employee *temp1 = NULL;
	int pos = search_Pos(id, -1);

	if (temp->next == NULL) {
		delete(temp);
		emp_head = NULL;
	}
	else if (pos == 1) {
		//if pos==1 delete node from front:
		employee *temp = emp_head;
		emp_head = emp_head->next;
		delete(temp);
		emp_head->prev = NULL;
	}
	else if (pos != 1 && pos != emp_siz()) {
		for (int i = 1; i<pos; i++)
		{
			temp = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete(temp);
	}
	else if (pos == emp_siz()) {
		////if pos==(complete size of list) apply delete node from end:
		employee *temp;
		temp = emp_head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		delete(temp);
	}
	cout << "\n\t\t**********************************************" << endl;
	cout << "\t\t !! Employee has been Deleted Successfully !!" << endl;
	cout << "\t\t**********************************************" << endl;
}

void display_emp() {                        /////////////////DISPLAY EMPLOYEE
	employee *temp = emp_head;
	if (temp != NULL) {
		while (temp != NULL) {
			cout << "\n\t\t       ***********************" << endl;
			cout << "\t\t          ID:     " << temp->id << endl;
			cout << "\t\t          NAME:   " << temp->name << endl;
			cout << "\t\t          SALARY: " << temp->sal << "\n" << endl;
			cout << "\t\t       ***********************" << endl;
			temp = temp->next;
		}
	}
	else
		cout << "\n\t\t    !!! Employee Record Is Empty !!!" << endl;

}

void emp_file_to_list()    //Add Employee from file to lnk list
{
	string f_name;
	int f_id;
	long int f_sal;

	ifstream myfile("Employee.txt");
	while (myfile.eof() == NULL)
	{
		myfile >> f_id;
		myfile >> f_name;
		myfile >> f_sal;
		if (search_emp(f_id) != true)
			add_emp_from_file(f_id, f_name, f_sal);
	}
	myfile.close();
}

void add_emp_from_file(int id, string name, long int sal)  //Add Employee from file to lnk list
{
	employee *emp1 = new employee;
	emp1->id = id;
	emp1->name = name;
	emp1->sal = sal;
	emp1->next = NULL;
	emp1->prev = NULL;
	employee *temp;
	if (id >= 0)
	{
		if (emp_head == NULL)
			emp_head = emp1;
		else {
			temp = emp_head;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = emp1;
			emp1->prev = temp;
		}
	}
}

int emp_siz() {                         /////////////////SIZE OF ISSUED_BOOKS RECORD
	employee *temp = emp_head;
	int count = 1, null = 0;
	//Find size of link list:
	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	else
		return null;
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX  END OF EMPLOYEE REQUIREMENTS XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//




/////////////////////////////////////////////////////////////////////////////////////////////
////////////////                      CAR REQUIREMENTS                         //////////////
////////////////           CAR REQUIREMENTS FOR ADMIN & EMPLOYEE              //////////////
////////////////////////////////////////////////////////////////////////////////////////////
void add_car(string name, string comp, int model, long int price)  ////////////ADD CAR
{
	int chassis;
	char con, man;
	bool flag = false;

	do
	{
		cout << "\n\t\t     Enter CAR Chassis No:   ";
		cin >> chassis;

		cout << "\n\t\t     This car condition is used or unused:" << endl;
		cout << "\t\t     Press y for 'used' and n for 'unused': ";
		cin >> con;
		if (con == 'y' || con == 'Y') {
			price += maintain;
			cout << "\n\t\tWithout maintenance You can't Sold this car to customer" << endl;
			cout << "\t\t         You have to pay 100$ for tunning" << endl;
			cout << "\n\t\t     DO you want extra maintenance for this car: " << endl;
			cout << "\t\t     Press 'y' for YES  OR  'n' for NO: ";
			cin >> man;
			if (man == 'y' || man == 'Y') {
				price += maintenance();
			}
			cout << "\n\t\t           CaAR MAINTAINED SUCCESSFULLY" << endl;
			cout << "\n\t\t     Now this car is ready to sold to customer " << endl;
		}
		if (search_car(chassis) != true)
		{
			if (chassis >= 0)
			{
				//Add CAR in file:
				ofstream f_out("car_rec.txt", ios::out | ios::app);

				if (f_out.fail()) {
					cerr << "Error in Opening Car Record File:" << endl;
					exit(1);
				}
				else {
					f_out << chassis << "   " << name << "   " << comp << "   ";
					f_out << model << "   " << price << "\n" << endl;
					f_out.close();
				}

				//Add CAR in link list:
				car *car1 = new car;
				car1->chassis = chassis;
				car1->name = name;
				car1->comp = comp;
				car1->model = model;
				car1->price = price;

				car1->next = NULL;
				car1->prev = NULL;
				car *temp;

				if (car_head == NULL)
					car_head = car1;

				else {
					temp = car_head;
					while (temp->next != NULL)
						temp = temp->next;

					temp->next = car1;
					car1->prev = temp;
				}
				cout << "\n\t\t        CAR ADDED SUCCESSFULLY:\n" << endl;
				flag = true;
			}
			else {
				cout << "\n\t\t     Please enter correct information:" << endl;
				break;
			}
		}
		else {
			cout << "\n\t\t     This Chassis number is already assigned to another CAR" << endl;
			cout << "\n\t\t     Please ReEnter the Chassis num for this CAR" << endl;
		}
	} while (flag != true);
}

bool search_car(int chassis)                    ////////////SEARCH car
{
	bool flag = false;
	//Search car record from link list:
	car *temp;
	temp = car_head;

	for (int i = 0; i<car_siz(); i++)
	{
		if (temp->chassis == chassis) {
			flag = true;
			break;
		}
		else
			temp = temp->next;
	}
	return flag;
}

void update_car(int chassis)                   ////////////UPDATE Employee
{
	string up_name, up_comp;
	int up_model;
	long int up_price;
	bool flag = false;

	if (search_car(chassis) == true)
	{
		cout << "\n\t\t   Enter Updated Name for Car: ";
		cin >> up_name;
		cout << "\t\t   Enter Updated Company Name for car: ";
		cin >> up_comp;
		cout << "\t\t   Enter Updated Model No for Car: ";
		cin >> up_model;
		cout << "\t\t   Enter Updated Price for car: ";
		cin >> up_price;

		//UPDATE employee record from file
		car *temp1 = car_head;
		int pos = search_Pos(-1, chassis);
		for (int i = 1; i <pos; i++)
			temp1 = temp1->next;

		ifstream f_in;
		f_in.open("car_rec.txt");
		if (f_in.fail()) {
			cerr << "Error in Updating car:" << endl;
			exit(1);
		}
		else {
			string line;
			ofstream f_out;
			f_out.open("temp.txt");
			int t_chassis = chassis;

			while (getline(f_in, line)) {
				//Convert string to int for comapring:
				int int_l;
				std::istringstream(line) >> int_l;

				if (int_l != chassis)
					f_out << line << endl;

				else if (int_l == t_chassis) {
					f_out << chassis << "   ";
					f_out << (temp1->name = up_name) << "   ";
					f_out << (temp1->comp = up_comp) << "   ";
					f_out << (temp1->model = up_model) << "   ";
					f_out << (temp1->price = up_price) << "\n" << endl;
					t_chassis = -1;
				}
			}
			f_in.close();
			f_out.close();
			remove("car_rec.txt");
			rename("temp.txt", "car_rec.txt");
		}
		flag = true;
	}
	else
		cout << "\t\tCAR Record which you want to updated is not existed!!!" << endl;
}

void display_car() {                        /////////////////DISPLAY EMPLOYEE
	car *temp = car_head;

	if (temp != NULL) {
		while (temp != NULL) {
			cout << "\n\t\t       *****************************" << endl;
			cout << "\t\t         Chassis No:  " << temp->chassis << endl;
			cout << "\t\t         Car Name:    " << temp->name << endl;
			cout << "\t\t         Car Company: " << temp->comp << endl;
			cout << "\t\t         Model No:    " << temp->model << endl;
			cout << "\t\t         Car Price:   " << temp->price << endl;
			cout << "\t\t       *****************************\n" << endl;
			temp = temp->next;
		}
	}
	else
		cout << "\t\t       CAR Record Is Empty!!!" << endl;
}

int maintenance()
{
	int ch, hp = 10, af = 5, cp = 20, bp = 15, wb = 10, sg = 60, ff = 5, ec = 20, db = 30, mr = 80, others;
	char  choice;
	string part;
	int total = 0;
	do
	{
		cout << "\n\t\t   *******************************************" << endl;
		cout << "\t\t   SPAREPARTS                           PRICE" << endl;
		cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout << "\t\t   1. Hose Pipes                         10 $ " << endl;
		cout << "\t\t   2. Air Filter                         5  $ " << endl;
		cout << "\t\t   3. Clutch Plate                       20 $ " << endl;
		cout << "\t\t   4. Brake Pads                         15 $ " << endl;
		cout << "\t\t   5. Wiper Blades                       10 $ " << endl;
		cout << "\t\t   6. Steering Gearbox & Boots           60 $ " << endl;
		cout << "\t\t   7. Fuel Filter                        5  $ " << endl;
		cout << "\t\t   8. Engine Coolant                     20 $ " << endl;
		cout << "\t\t   9. Drive Belts                        30 $ " << endl;
		cout << "\t\t   10.Mirrors                            80 $ " << endl;
		cout << "\t\t   11.Other parts                             " << endl;
		cout << "\t\t   *******************************************" << endl;
		cout << "\n\t\t   Chosse any one Option for maintenance: ";
		cin >> ch;
		if (ch == 1) {
			total += hp;
			cout << "\n\t\t   Hose Pipes inserted:" << endl;
		}
		else if (ch == 2) {
			total += af;
			cout << "\n\t\t   Air Filter inserted:" << endl;
		}
		else if (ch == 3) {
			total += cp;
			cout << "\n\t\t   Clutch Plate inserted:" << endl;
		}
		else if (ch == 4) {
			total += bp;
			cout << "\n\t\t   Brake Pads inserted:" << endl;
		}
		else if (ch == 5) {
			total += wb;
			cout << "\n\t\t   Wiper Blades inserted:" << endl;
		}
		else if (ch == 6) {
			total += sg;
			cout << "\n\t\t   Steering Gearbox & Boots inserted:" << endl;
		}
		else if (ch == 7) {
			total += ff;
			cout << "\n\t\t   Fuel Filter inserted:" << endl;
		}
		else if (ch == 8) {
			total += ec;
			cout << "\n\t\t   Engine Coolant inserted:" << endl;
		}
		else if (ch == 9) {
			total += db;
			cout << "\n\t\t   Drive Belts inserted:" << endl;
		}
		else if (ch == 10) {
			total += mr;
			cout << "\n\t\t   Mirrors inserted:" << endl;
		}
		else if (ch == 11) {
			cout << "\n\t\t   Enter part name which you wants to insert in car: ";
			cin >> part;
			cout << "\t\t   Enter " << part << " part price: ";
			cin >> others;

			cout << "\n\t\t   " << part << " inserted:" << endl;
			total += others;

		}
		else {
			cout << "\n\t\t      XXXX !!! Invalid Choice !!! XXXX" << endl;
			Sleep(2000);
			maintenance();
		}

		cout << "\n\t\t  Do you want more Maintenance; " << endl;
		cout << "\t\t  Press 'y' to continue 'Any key' to Exit: ";
		cin >> choice;
	} while (choice == 'y');

	return total;
}

int search_Pos(int id, int chassis)                          /////Search CAR Record Position:
{
	int count = 1, pos = -1;
	if (chassis == -1)
	{
		//for searching employee position:
		employee *temp = emp_head;
		bool flag = false;

		if (temp == NULL)
			flag = false;
		else {
			for (int i = 0; i<emp_siz(); i++) {
				if (temp->id == id) {
					flag = true;
					break;
				}
				else
					temp = temp->next;
				count++;
			}
		}
		if (flag == true)
			return count;
		else if (flag = false)
			return pos;
	}

	else if (id == -1)
	{
		//for searching car position:
		car *temp = car_head;
		bool flag = false;

		if (temp == NULL)
			flag = false;
		else {
			for (int i = 0; i<car_siz(); i++) {
				if (temp->chassis == chassis) {
					flag = true;
					break;
				}
				else
					temp = temp->next;
				count++;
			}
		}
		if (flag == true)
			return count;
		else if (flag = false)
			return pos;
	}
}

int car_siz() {                         /////////////////SIZE OF car RECORD
	car *temp = car_head;
	int count = 1, null = 0;

	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	else
		return null;
}

void car_file_to_list()    //Add car from file to lnk list
{
	string name, comp;
	int chassis, model;
	long int price;

	ifstream myfile("car_rec.txt");
	while (!myfile.eof()) {
		myfile >> chassis;
		myfile >> name;
		myfile >> comp;
		myfile >> model;
		myfile >> price;

		if (search_car(chassis) != true)
			add_car_from_file(chassis, name, comp, model, price);
	}
	myfile.close();
}

void add_car_from_file(int chassis, string name, string comp, int model, long int price)//Add car from file to lnk list
{
	car *car1 = new car;
	car1->chassis = chassis;
	car1->name = name;
	car1->comp = comp;
	car1->model = model;
	car1->price = price;
	car1->next = NULL;
	car1->prev = NULL;
	car *temp;

	if (chassis >= 0)
	{
		if (car_head == NULL)
			car_head = car1;
		else {
			temp = car_head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = car1;
			car1->prev = temp;
		}
	}
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX    END OF CAR REQUIREMENTS    XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//




/////////////////////////////////////////////////////////////////////////////////////////////
////////////////                    SOLD  CAR REQUIREMENTS                     //////////////
////////////////         SOLD CAR REQUIREMENTS FOR ADMIN & EMPLOYEE            //////////////
////////////////////////////////////////////////////////////////////////////////////////////
void sold_car(int chassis)                     ////SOLD CAR 
{
	string cus_name;
	long int cont;

	car *temp2 = car_head;
	int pos = search_Pos(-1, chassis);
	for (int i = 1; i < pos; i++)
		temp2 = temp2->next;

	cout << "\n\t\t     Enter Customer name: ";
	cin >> cus_name;
	cout << "\n\t\t     Enter Customer Contact Number: ";
	cin >> cont;

	sold_car_record(chassis, temp2->name, temp2->comp, temp2->model, temp2->price, cus_name, cont);

	//Delete record from file:
	ifstream f_in;
	f_in.open("car_rec.txt");

	if (f_in.fail()) {
		cerr << "Error in deleting Car record from file:" << endl;
		exit(1);
	}
	else {
		string line;
		ofstream f_out;
		f_out.open("temp.txt");

		while (getline(f_in, line)) {
			//Convert string to int for comapring:
			int int_l;
			std::istringstream(line) >> int_l;

			if (int_l != chassis)
				f_out << line << endl;
		}
		f_in.close();
		f_out.close();
		remove("car_rec.txt");
		rename("temp.txt", "car_rec.txt");
	}

	//delete car record from link list:
	car *temp = car_head;
	car *temp1 = NULL;

	if (temp->next == NULL) {
		delete(temp);
		car_head = NULL;
	}
	else if (pos == 1) {
		//if pos==1 delete node from front:
		car *temp = car_head;
		car_head = car_head->next;
		delete(temp);
		car_head->prev = NULL;
	}
	else if (pos != 1 && pos != car_siz()) {
		for (int i = 1; i < pos; i++)
		{
			temp = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete(temp);
	}
	else if (pos == car_siz()) {
		////if pos==(complete size of list) apply delete node from end:
		car *temp;
		temp = car_head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		delete(temp);
	}
}

void sold_car_record(int chassis, string car_name, string comp, int model, long int price, string cus_name, long int cont)  ////////////ADD CAR
{
	long int profit = (price * 5) / 100;
	long int sold_price = (price + profit);
	//Add SOLD_CAR in file:
	ofstream f_out("sold_car_rec.txt", ios::out | ios::app);

	if (f_out.fail()) {
		cerr << "Error in Opening Car Record File:" << endl;
		exit(1);
	}
	else {
		f_out << "\n" << chassis;
		f_out << "    " << car_name;
		f_out << "    " << comp;
		f_out << "    " << model;
		f_out << "    " << price;
		f_out << "    " << sold_price;
		f_out << "    " << profit;
		f_out << "    " << cus_name;
		f_out << "    " << cont << "\n" << endl;


		f_out.close();
	}

	//Add Sold CAR in link list:
	sold_car_rec *scar1 = new sold_car_rec;
	scar1->chassis = chassis;
	scar1->car_name = car_name;
	scar1->comp = comp;
	scar1->model = model;
	scar1->act_price = price;
	scar1->sld_price = sold_price;
	scar1->prft_mrgn = profit;
	scar1->cus_name = cus_name;
	scar1->cont = cont;
	scar1->next = NULL;
	scar1->prev = NULL;
	sold_car_rec *temp;

	if (sold_head == NULL)
		sold_head = scar1;

	else {
		temp = sold_head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = scar1;
		scar1->prev = temp;
	}
	cout << "\n\t\t   *********************************" << endl;
	cout << "\t\t                RECEIPT            " << endl;
	cout << "\t\t   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "\t\t       Owner Name:     " << cus_name << endl;
	cout << "\t\t       Contact Number:  +92" << cont << endl;
	cout << "\t\t       Chassis No:     " << chassis << endl;
	cout << "\t\t       Car Name:       " << car_name << endl;
	cout << "\t\t       Car Company:    " << comp << endl;
	cout << "\t\t       Car Model:      " << model << endl;
	cout << "\t\t       Car Sold Price: " << sold_price << endl;
	cout << "\t\t   *********************************\n" << endl;
}

void sold_car_file_to_list()    //Add car from file to lnk list
{
	string car_name, comp, cus_name;
	int chassis, model;
	long int cntct, act_price, sld_price, prft_mrgn;
	ifstream infile("sold_car_rec.txt");
	while (!infile.eof()) {
		infile >> chassis;
		infile >> car_name;
		infile >> comp;
		infile >> model;
		infile >> act_price;
		infile >> sld_price;
		infile >> prft_mrgn;
		infile >> cus_name;
		infile >> cntct;

		if (search_sold_car(chassis) != true)
			add_sold_car_from_file(chassis, car_name, comp, model, act_price, sld_price, prft_mrgn, cus_name, cntct);
	}
	infile.close();
}

void add_sold_car_from_file(int chassis, string car_name, string cmpny, int model, long int act_price, long int sld_price, long int prft_mrgn, string cus_name, long int cntct) {
	sold_car_rec *car2 = new sold_car_rec;
	car2->cus_name = cus_name;
	car2->cont = cntct;
	car2->chassis = chassis;
	car2->car_name = car_name;
	car2->comp = cmpny;
	car2->model = model;
	car2->act_price = act_price;
	car2->sld_price = sld_price;
	car2->prft_mrgn = prft_mrgn;

	car2->next = NULL;
	car2->prev = NULL;
	sold_car_rec *temp;

	if (chassis >= 0)
	{
		if (sold_head == NULL)
			sold_head = car2;
		else {
			temp = sold_head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = car2;
			car2->prev = temp;
		}
	}
}

void display_sold_car_rec() {                        /////////////////DISPLAY EMPLOYEE
	sold_car_rec *temp = sold_head;

	if (temp != NULL) {
		while (temp != NULL) {
			cout << "\n\t\t   *****************************" << endl;
			cout << "\t\t      Chassis No:     " << temp->chassis << endl;
			cout << "\t\t      Car Name:       " << temp->cus_name << endl;
			cout << "\t\t      Car Company:    " << temp->comp << endl;
			cout << "\t\t      Model No:       " << temp->model << endl;
			cout << "\t\t      Car Price:      " << temp->act_price << endl;
			cout << "\t\t      Car Sold price: " << temp->sld_price << endl;
			cout << "\t\t      Profit Margin:  " << temp->prft_mrgn << endl;
			cout << "\t\t   *****************************\n" << endl;
			temp = temp->next;
		}
	}
	else
		cout << "\n\t\t   CAR Record Is Empty!!!" << endl;
}

bool search_sold_car(int chassis)                    ////////////SEARCH car
{
	bool flag = false;
	//Search car record from link list:
	sold_car_rec *temp = sold_head;

	for (int i = 0; i<sold_car_siz(); i++)
	{
		if (temp->chassis == chassis) {
			flag = true;
			break;
		}
		else
			temp = temp->next;
	}
	return flag;
}

int sold_car_siz() {                         /////////////////SIZE OF SOLD CAR RECORD
	sold_car_rec *temp = sold_head;
	int count = 1, null = 0;
	//Find size of link list:
	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	else
		return null;
}

//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXX  END OF SOLD CAR REQUIREMENT  XXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXX                           XXXXXXXXXXXXXXXX//
*/
/**
* @file CustomerTestApp.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Test of Customer Class functions
*
*/


#include <conio.h> //For _getch()
#include "Customer.h" //To use Customer class

void main()
{
	cout << "+---------------+" << endl
		<< "| CUSTOMER TEST |" << endl
		<< "+---------------+" << endl; //Testing Customer

	Customer test; //An initial Customer

	cout << "Testing set functions..." << endl;
	//Setting up properties of the customer
	test.setName("Deniz ATILGAN"); //Sets the name
	test.setAddress("Zafer Mahallesi Gazikemalpasa Sokagi Gunes Evleri No:6/1 Daire:15");
	//Sets the address
	test.setPhone("905335517708"); //Sets the phone
	test.setEmail("denizatilgan_96@hotmail.com"); //Sets the email
	test.setUsername("denizAtilgan007"); //Sets the username
	test.setPassword("a17cb83"); //Sets the password
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "Name: " << test.getName() << endl; //Shows the name
	cout << "Address: " << test.getAddress() << endl; //Shows the address
	cout << "Phone: " << test.getPhone() << endl; //Shows the phone
	cout << "Email: " << test.getEmail() << endl; //Shows the email
	cout << "Username: " << test.getUsername() << endl; //Shows the username

	cout << "Trying to log into denizAtilgan007 with password b17ab83..." << endl;
	//Trying to log in...
	if (test.checkAccount("denizAtilgan007", "b17ab83")) //Checks account
		cout << "Login successful!" << endl; //Successfully logged on
	else
		cout << "Invalid username or password!" << endl; //Invalid login
	cout << "Trying to log into denizAtilgan007 with password a17cb83..." << endl;
	//Trying to log in...
	if (test.checkAccount("denizAtilgan007", "a17cb83")) //Checks account
		cout << "Login successful!" << endl; //Successfully logged on
	else
		cout << "Invalid username or password!" << endl; //Invalid login

	_getch(); //To pause the code
}
/**
* @file CheckTestApp.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Test of Check Class functions
*
*/


#include <conio.h> //For _getch()
#include "Check.h" //To use Check class

void main()
{
	cout << "+------------+" << endl
		<< "| CHECK TEST |" << endl
		<< "+------------+" << endl; //Testing Check

	Check test(0, "!!ERROR!!", "!!ERROR!!"); //An initial Check

	cout << "Testing set functions..." << endl;
	//Setting up properties of the check
	test.setAmount(250); //Setting the amount
	test.setBankID("1784364321"); //Setting the bank ID
	test.setName("Mertcan Kanat"); //Setting the name
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "Amount: " << test.getAmount() << endl; //Shows the amount
	cout << "Bank ID: " << test.getBankID() << endl; //Shows the bank ID
	cout << "Name: " << test.getName() << endl; //Shows the name

	cout << "The payment method is " << test.GetPaymentModel() << "." << endl;
	//Shows the payment method
	test.performPayment(); //Performs the payment

	_getch(); //To pause the code
}
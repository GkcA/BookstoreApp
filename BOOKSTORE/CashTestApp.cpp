/**
* @file CashTestApp.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Test of Cash Class functions
*
*/

#include <conio.h> //For _getch()
#include "Cash.h" //To use Cash class

void main()
{
	cout << "+-----------+" << endl
		<< "| CASH TEST |" << endl
		<< "+-----------+" << endl; //Testing Cash

	Cash test(0); //An initial Cash

	cout << "Testing set functions..." << endl;
	//Setting up properties of the cash
	test.setAmount(1.77); //Setting the amount
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "The payment method is " << test.GetPaymentModel() << "." << endl;
	//Shows the payment method
	test.performPayment(); //Performs the payment

	_getch(); //To pause the code
}
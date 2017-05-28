/**
* @file CreditCardTestApp.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Test of CreditCard Class functions
*
*/

#include <conio.h> //For _getch()
#include "CreditCard.h" //To use CreditCard class

void main()
{
	cout << "+------------------+" << endl
		<< "| CREDIT CARD TEST |" << endl
		<< "+------------------+" << endl; //Testing CreditCard

	CreditCard test(0,"", "!!ERROR!!", "!!ERROR!!"); //An initial CreditCard

	cout << "Testing set functions..." << endl;
	//Setting up properties of the credit card
	test.setAmount(250); //Setting the amount
	test.setNumber("1234567812345678"); //Setting the number
	test.setType("Visa"); //Setting the type
	test.setExpDate("11/23"); //Setting the expiration date
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "Amount: " << test.getAmount() << endl; //Shows the amount
	cout << "Number: " << test.getNumber() << endl; //Shows the number
	cout << "Type: " << test.getType() << endl; //Shows the type
	cout << "Expiration Date: " << test.getExpDate() << endl;
	//Shows the expiration date

	cout << "The payment method is " << test.GetPaymentModel() << "." << endl;
	//Shows the payment method
	test.performPayment(); //Performs the payment

	_getch(); //To pause the code
}
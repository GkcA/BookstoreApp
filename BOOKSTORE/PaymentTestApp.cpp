/**
* @file PaymentTestApp.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Test of Payment Class functions
*
*/

#include <conio.h> //For _getch()
#include "Payment.h" //To use Payment class
#include "CreditCard.h" //To use CreditCard class
#include "Cash.h" //To use Cash class
#include "Check.h" //To use Check class

void TEST_ForAll(Payment* test, double amount)
//Polymorphic testing
{
	cout << "Setting the amount of the payment to "	<< amount << "..." << endl;
	test -> setAmount(amount); //Setting the amount
	cout << "Success! Payment with " << test -> GetPaymentModel() << " costs "
		<< test -> getAmount() << " now!" << endl;
	cout << "Performing payment now..." << endl;
	test -> performPayment(); //Performs the payment
}

void main()
{
	cout << "+--------------+" << endl
		<< "| PAYMENT TEST |" << endl
		<< "+--------------+" << endl; //Testing Payment

	CreditCard *cc = new CreditCard(0, "1234567812345678", "Visa", "07/19");
	cout << "\nUsing a Credit Card..." << endl;
	TEST_ForAll(cc, 250); //Using a Credit Card for polymorphic functions

	Cash *cash = new Cash(0);
	cout << "\nUsing Cash..." << endl;
	TEST_ForAll(cash, 7.99); //Using Cash for polymorphic functions

	Check *check = new Check(0, "Aydin MERTOGLU", "156146354");
	cout << "\nUsing a Check..." << endl;
	TEST_ForAll(check, 100); //Using a Check for polymorphic functions

	_getch(); //To pause the code
}
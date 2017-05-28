/**********************
* Cash.cpp            *
**********************/
/**
* @file Cash.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Implementation of Cash Class functions
*
*/

#include "Cash.h" // Call Cash.h header file for definition member function

/*!
\param amount an double argument.
*/
Cash::Cash(double amount):Payment(amount)
// Constructor function of Cash class - using inheritance relation from
//Payment class constructor function
{
}

/*!
\param no argument.
*/
Cash::~Cash() // Destructor function of Cash class
{
}

/*!
\param no argument.
*/
void Cash::performPayment() // performPayment function for payment operation
{
	bool gate = false; // bool type variable initial value is false
	string money;// string type variable named money - for entrance of money
	//which is payed by customer
	do // starting do - while loop
	{
		cout << "Total Amount : " << getAmount() << endl;
		// To print to screen ' Total Amount: ' and total price value
		cout << "Place your Cash: " << endl;
		// To print to screen ' Place your Cash: '
		getline(cin, money); // Read money value which is entered by customer
		if (stod(money) < getAmount()) {// if money value is less than total
			//price value - stod to convert string to double
			cout << "Payment failed because of insufficient cash\n\n";
			// To print to screen ' Payment failed because of insufficient cash '
			cout << "Press any key to try again!!";
			// To print to screen ' Press any key to try again!! '
			_getch();//Press any key to continue
			system("cls");//clear console
		}
		else // else - money value is bigger than or equal to price value
		{
			cout << "\nPayment Successfully received!\nChange : " <<
				stod(money) - getAmount();
			// To print to screen ' Payment Successfully received! ' and money change 
			gate = true; // bool variable is equal to true
		}
	} while (!gate); // end of do - while loop
}

/*!
\param no argument.
\return "Cash"
*/
string Cash::GetPaymentModel() const
// GetPaymentModel function for getting payment model
{
	return "Cash"; // return string " Cash "
}

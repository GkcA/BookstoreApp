/**********************
* Check.cpp           *
**********************/
/**
* @file Check.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Implementation of Check Class functions
*
*/

#include "Check.h" // Call Check.h header file for definition member function

/*!
\param amount an double argument.
\param name an string argument.
\param bankID an string argument.
*/
Check::Check(double amount, string name, string bankID):Payment(amount) 
{ // Constructor function of Check class - using inheritance relation from Payment
//class constructor function
	setName(name); // Call setName function and to equalize function parameter
	//to class member variable
	setBankID(bankID); // Call setBankID function and to equalize function parameter
	//to class member variable
}

/*!
\param no argument.
*/
Check::~Check() // Destructor function of class
{
}

/*!
\param no argument.
\return m_name -name of check's owner
*/
string Check::getName() const // getName function is getting name of check's owner
{
	return m_name; // return member variable m_name - name of check's owner
}

/*!
\param name an string argument.
*/
void Check::setName(string name) // setName function is setting name of check's owner
{
	m_name = name; // member variable is equal to function parameter
}

/*!
\param no argument.
\return m_bankID - bankID of check's owner
*/
string Check::getBankID() const // getName function is getting bankID of check's owner
{
	return m_bankID; // return member variable m_bankID - bankID of check's owner
}

/*!
\param bankID an string argument.
*/
void Check::setBankID(string bankID)
// setName function is setting bankID of check's owner
{
	m_bankID = bankID; // member variable is equal to function parameter
}

/*!
\param no argument.
*/
void Check::performPayment() // performPayment function for payment operation
{
	cout << "Total Amount : " << getAmount()<<" was paid with check by Customer"
		<< endl; // To print to screen ' Total Amount: ' and total price value
	//and ' was paid with check by Customer '
	cout << "\nPayment Successfully received from " << endl << m_name <<
		"'s Bank Check" << endl; // To print to screen ' Payment Successfully
	//received from ' , name of check's owner and ' 's Bank Check '
}

/*!
\param no argument.
\return "Check"
*/
string Check::GetPaymentModel() const
// GetPaymentModel function for getting payment model
{
	return "Check"; // return string "Check"
}

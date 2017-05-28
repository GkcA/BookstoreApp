/**********************
* CreditCard.cpp      *
**********************/
/**
* @file CreditCard.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Implementation of CreditCard Class functions
*
*/

#include "CreditCard.h" // Call CreditCard.h header file for definition member function

/*!
\param amount an double argument.
\param number an string argument.
\param type an string argument.
\param expDate an string argument.
*/
CreditCard::CreditCard(double amount, string number, string type, string expDate)
	:Payment(amount)
{ // Constructor function of CreditCard class - using inheritance relation from
	//Payment class constructor function
	setNumber(number); // Call setNumber function and to equalize function
	//parameter to class member variable
	setType(type);  // Call setType function and to equalize function parameter
	//to class member variable
	setExpDate(expDate); // Call setExpDate function and to equalize function
	//parameter to class member variable
}

/*!
\param no argument.
*/
CreditCard::~CreditCard() // Destructor function of class
{
}

/*!
\param amount  an double argument.
\return m_number - creditcard number
*/
string CreditCard::getNumber() const
// getNumber function is getting number of credit card
{
	return m_number; // return member variable m_number - number of credit card
}

/*!
\param number an string argument.
*/
void CreditCard::setNumber(string number)
// setName function is setting number of credit card
{
	m_number = number; // member variable is equal to function parameter
}

/*!
\param no argument.
\return m_type - type of credit card
*/
string CreditCard::getType() const // getType function is getting type of credit card
{
	return m_type; // return member variable m_type - type of credit card
}

/*!
\param type an string argument.
*/
void CreditCard::setType(string type) // setType function is setting type of credit card
{
	m_type = type; // member variable is equal to function parameter
}

/*!
\param no argument.
\return m_expDate - expiration date of credit card
*/
string CreditCard::getExpDate() const
// getExpDate function is getting expiration date of credit card
{
	return m_expDate;
	// return member variable m_expDate - expiration date of credit card
}

/*!
\param ExpDate an string argument.
*/
void CreditCard::setExpDate(string ExpDate)
// setExpDate function is setting expiration date of credit card
{
	m_expDate = ExpDate;
	// member variable is equal to function parameter
}

/*!
\param no argument.
*/
void CreditCard::performPayment()
// performPayment function for payment operation
{
	cout << "Total Amount : " << getAmount()<<endl; 
	// To print to screen ' Total Amount: ' and total price value
	cout << "\nPayment Successfully received from "<<endl<<m_type<<" Card with "
		<<"Card Number : "<<m_number<<" "<<endl; 
	// To print to screen ' Payment Successfully received from ',
	//type of credit card and number of credit card
}

/*!
\param no argument.
\return "CreditCard" 
*/
string CreditCard::GetPaymentModel()const
// GetPaymentModel function for getting payment model
{
	return "CreditCard"; // return string "CreditCard"
}

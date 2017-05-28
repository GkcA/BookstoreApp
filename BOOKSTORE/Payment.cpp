/**********************
* Payment.cpp         *
**********************/
/**
* @file Payment.cpp
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Implementation of Payment Class functions
*
*/
#include "Payment.h" // Call Payment.h header file for definition member function

/*!
\param amount an double argument.
*/
Payment::Payment(double amount) // Constructor function of class
{
	setAmount(amount); // Call setAmount function and to equalize function
	//parameter to class member variable
}

/*!
\param no argument.
*/
Payment::~Payment() // Destructor function of class
{
}

/*!
\param no argument.
\return m_amount - payment amount 
*/
double Payment::getAmount() const
// getAmount function is getting payment amount or price
{
	return m_amount; // return member variable - payment amount
}

/*!
\param amount an double argument.
*/
void Payment::setAmount(double amount)
// setAmount function is setting payment amount or price
{
	m_amount = amount; // member variable is equal to function parameter
}
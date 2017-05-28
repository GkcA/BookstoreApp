/**********************
* CreditCard.h        *
**********************/

/**
* @file CreditCard.h 
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Declaration of  CreditCard Class
*
* One of the payment method
*/

#pragma once
#include "Payment.h" // Call Payment.h header for inheritance relation

//! A CreditCard class.
/*!
To make payment via credit card
*/
class CreditCard :
	public Payment // using inheritance relation from Payment class
{
	string m_number; // long type variable for number of credit card
	string m_type; // string type variable for type of credit card
	string m_expDate; // string type variable for expiration date of credit card
public: // public part of class
	//! Constructor function of class
	CreditCard(double amount,string number,string type,string expDate);
	//! Destructor function of class
	~CreditCard();
	//! long type getNumber function for getting number of credit card
	string getNumber()const;
	//! long type setNumber function for setting number of credit card
	void setNumber(string number);
	//! string type getType function for getting type of credit card
	string getType() const;
	//! void type setType function for setting type of credit card
	void setType(string type);
	//! string type getExpDate function for getting expiration date of credit card
	string getExpDate()const;
	//! void type setExpDate function for setting expiration date of credit card
	void setExpDate(string ExpDate);
	//! void type function for payment operation
	void performPayment();
	//! string type function for getting payment model
	string GetPaymentModel()const;
	
}; // end of class


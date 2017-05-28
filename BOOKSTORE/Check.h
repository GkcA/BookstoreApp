/**********************
* Check.h             *
**********************/

/**
* @file Check.h
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Declaration of Check Class
*
* One of the payment method
*/

#pragma once
#include "Payment.h" // Call Payment.h header for inheritance relation

//! A Check class.
/*!
To make payment via check
*/
class Check :
	public Payment // using inheritance relation from Payment class
{
	string m_name; // string type variable for name of check's owner
	string m_bankID; // string type variable for bankID of check's owner
public: // public part of class
	//! Constructor function of class
	Check(double amount,string name,string bankID);
	//! Destructor function of class
	~Check();
	//! string type getName function for getting name of check's owner
	string getName()const;
	//! void type setName function for setting name of check's owner
	void setName(string name);
	//! string type getBankID function for getting bankID of check's owner
	string getBankID()const;
	//! void type setBankID function for setting bankID of check's owner
	void setBankID(string bankID);
	//! void type function for payment operation
	void performPayment();
	//! string type function for getting payment model
    string GetPaymentModel()const;
}; // end of class


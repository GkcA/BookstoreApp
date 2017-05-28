/**********************
* Cash.h              *
**********************/
/**
* @file Cash.h
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Declaration of Cash Class
*
* One of the payment method
*/

#pragma once
#include "Payment.h" // Call Payment.h header for inheritance relation

//! A Cash class.
/*!
To make payment via cash
*/
class Cash :
	public Payment // using inheritance relation from Payment class
{
public: // public part of class
	//! Constructor function of class
	Cash(double amount); 
	//! Destructor function of class
	~Cash();
	//! void type function for payment operation
	void performPayment();
	//! string type function for getting payment model
	string GetPaymentModel()const;
	
}; // end of class


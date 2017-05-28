/**********************
* Payment.h           *
**********************/
/**
* @file Payment.h  
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Declaration of  Payment Class
*
* Abstract Base class of payment methods
*/

#pragma once
#include<string>
#include<iostream>
#include<conio.h> // to use _getch
using namespace std;

//! A Payment class.
/*!
Abstarct class for payment methods
*/

//! defined class named Payment
class Payment 
{
	double m_amount; // double type variable for payment amount
public: // public part of class
	//! Constructor function of class - initial amount value is 0
	Payment(double amount=0);
	//! Destructor function of class
	~Payment();
	//! double type function for getting payment amount
	double getAmount()const;
	//! void type function for setting payment amount
	void setAmount(double amount);
	//! Pure Virtual Function - for payment operation
	virtual void performPayment() = 0;
	//! Pure Virtual Function - for getting payment model
	virtual string GetPaymentModel() const= 0;
}; // end of class
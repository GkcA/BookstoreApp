/**********************
* Customer.h          *
**********************/
/**
* @file Customer.h 
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Declaration of Customer Class
*
* Customers in system
*/
#pragma once
#include <iostream>
#include <string> // call for string operation
#include <sstream> // call for using stringstream
using namespace std;

//! A CreditCard class.
/*!
To create and operate customer
*/
class Customer 
{
private: // private part of class
	long customerID; // long type variable for customer's ID
	string name; // string type variable for name of customer
	string address; // string type variable for adress of customer
	string phone; // string type variable for phone number of customer
	double bonus;
	// double type variable for customer's bonus in customer's account
	string email; // string type variable for e-mail account of customer
	string username; // string type variable for username of customer's account
	string password; // string type variable for password of customer's account
public: // public part of class
	//! Constructor function of class
	Customer();
	//! Destructor function of class
	~Customer();
	//! void type sendBill function for notice of sending bill
	void sendBill() const;
	//! const long type getCustomerID function for getting customer's ID
	const long getCustomerID() const;
	//! void type setCustomerID function for setting customer's ID
	void setCustomerID(const long& custonerID);
	//! const string type getName function for getting customer's name
	const string& getName() const;
	//! void type setName function for setting customer's name
	void setName(const string& name);
	//! const string type getAddress function for getting address of customer
	const string& getAddress() const;
	//! void type setAddress function for setting address of customer
	void setAddress(const string& address);
	//! const string type getPhone function for getting phone number of customer
	const string& getPhone() const;
	//! void type setPhone function for setting phone number of customer
	void setPhone(const string& phone);
	//!const double type getBonus function for getting customer's bonus in customer's account
	const double getBonus() const; 
	//! void type setBonus function for setting customer's bonus in customer's account
	void setBonus(const double& bonus); 
	//! const string type getEmail function for getting e-mail account of customer
	const string& getEmail() const;
	//! void type setEmail function for setting e-mail account of customer
	void setEmail(const string& email);
	//! const string type getUserName function for getting username of customer's account
	const string& getUsername() const; 
	//! void setUserName function for setting username of customer's account
	void setUsername(const string& username);
	//! const string type getPassword function for getting password of customer's account
	const string& getPassword() const;
	//! void type setPassword function for setting password of customer's account
	void setPassword(const string& password);
	//!bool type checkAccount function for controlling username and password
	bool checkAccount(const string& username, const string& password) const;
	//!void type addBonus function for adding bonus to customer's account
	void addBonus(const double& bonus);
	//!void type useBonus function for using bonus from customer's account
	void useBonus(double amount);
}; //end of class
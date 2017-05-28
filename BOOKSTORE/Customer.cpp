/**********************
* Customer.cpp        *
**********************/
/**
* @file Customer.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Implementation of Customer Class functions 
*
*/

#include "Customer.h"

Customer::Customer() // Constructor function of Customer class
{
	customerID = 0; // initial ID number of customer is 0
	name = ""; // initial name of customer
	address = ""; // initial address of customer
	phone = ""; // initial phone number of customer
	email = ""; // initial e-mail account of customer
	username = ""; // initial username of customer
	password = ""; // initial password of customer
	bonus = 0; // initial bonus point of customer
}

Customer::~Customer() // Destructor function of Customer class
{

}

/*!
	\param no argument
*/
void Customer::sendBill() const
{
	cout << "The bill was sent to your e-mail " << email << "." << endl;
	// To print to screen ' The bill was sent to your e-mail '
	//and customer's e-mail account
}

/*!
	\param no argument
	\return customerID (constant long)
*/
const long Customer::getCustomerID() const
{
	return customerID; // return member variable - ID number of customer
}

/*!
	\param customerID (const long&) argument
*/
void Customer::setCustomerID(const long& customerID)
{
	this -> customerID = customerID; // member variable is equal to function parameter
}

/*!
\param no argument
\return name (const string &)
*/
const string& Customer::getName() const
{
	return name; // return member variable - Customer's name
}

/*!
\param name (const string&) argument
*/
void Customer::setName(const string& name)
{
	this -> name = name; // member variable is equal to function parameter
}

/*!
\param no argument
\return address (const string &)
*/
const string& Customer::getAddress() const
{
	return address; // return member variable - Address of customer
}

/*!
\param address (const string&) argument
*/
void Customer::setAddress(const string& address)
{
	this -> address = address; // member variable is equal to function parameter
}

/*!
\param no argument
\return phone (const string &)
*/
const string& Customer::getPhone() const
{
	return phone; // return member variable - Phone number of customer
}

/*!
\param phone (const string&) argument
*/
void Customer::setPhone(const string& phone)
{
	stringstream str;
	// defined stringstream type variable named str to place phone number of customer
	str << "+" << phone.substr(0,2) << "(" << phone.substr(2,3) << ")-" <<
		phone.substr(5, 7);
	// write to str + , two elements after it by starting from zero, ' ( '
	// write to str three elements after it by starting from the second element
	// write to str seven elements after it by starting from the fifth element
	this -> phone = str.str(); // member variable is equal to string part of str
}

/*!
\param no argument
\return bonus (const double)
*/
const double Customer::getBonus() const
{
	return bonus; // return member variable - Bonus point of customer
}

/*!
\param bonus (const double&) argument
*/
void Customer::setBonus(const double& bonus)
{
	this -> bonus = bonus; // member variable is equal to function parameter
}

/*!
\param no argument
\return email (const string&)
*/
const string& Customer::getEmail() const
{
	return email; // return member variable - E-mail account of customer
}

/*!
\param email (const string&) argument
*/
void Customer::setEmail(const string& email)
{
	this -> email = email; // member variable is equal to function parameter
}

/*!
\param no argument
\return username (const string&)
*/
const string& Customer::getUsername() const
{
	return username; // return member variable - User name of customer
}

/*!
\param username (const string&) argument
*/
void Customer::setUsername(const string& username)
{ 
	this -> username = username; // member variable is equal to function parameter
}

/*!
\param no argument
\return password (const string&)
*/
const string& Customer::getPassword() const
{
	return password; // return member variable - Password of customer
}

/*!
\param password (const string&) argument
*/
void Customer::setPassword(const string& password)
{
	this -> password = password; // member variable is equal to function parameter
}

/*!
	\param username (constant string)
	\param password (constant string)
	\return bool
*/
bool Customer::checkAccount(const string& username, const string& password) const
{
	if (this -> username == username && this -> password == password)
	// if member variable user name and password equals function
	//parameters user name and password
		return true; // return true
	else // if not member variable user name and password equals function
	//parameters user name and password
		return false; // return false
}

/*!
	\param bonus (constant double&)
*/
void Customer::addBonus(const double& bonus)
{
	this -> bonus += bonus; // member variable bonus (in account) is equal to
	//itself plus parameter bonus
}

/*!
	\param amount (double)
*/
void Customer::useBonus(double amount)
{
	bonus -= amount; // bonus in account is equal to bonus minus amount of used bonus
}
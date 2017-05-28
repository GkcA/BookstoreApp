/**********************
* Product.cpp         *
**********************/

/**
* @file Product.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Implementation of Product Class functions
*
*/

#include "Product.h" // Call Product.h header file for definition member function

Product::Product(int ID, string name, double price, int quantity)
// Constructor function of class
{
	setID(ID); // Call setID function and to equalize function parameter to
	//class member variable
	setName(name); // Call setName function and to equalize function parameter
	//to class member variable
	setPrice(price); // Call setPrice function and to equalize function parameter
	//to class member variable
	setQuantityOfItem(quantity); // Call setQuantityOfItem function and to equalize
	//function parameter to class member variable
}

Product::~Product() // Destructor function of class
{
}

int Product::getID() const // getID function is getting ID number of product
{
	return ID; // return member variable - ID number of product
}

void Product::setID(int ID) // setID function is setting ID number of product
{
	this->ID=ID; // member variable is equal to function parameter
}

string Product::getName() const // getName function is getting name of product
{
	return name; // return member variable - Name of product
}

void Product::setName(string name) // setName function is setting name of product
{
	this->name = name; // member variable is equal to function parameter
}

double Product::getPrice() const // getPrice function is getting price of product
{
	return price; // return member variable - Price of product
}

void Product::setPrice(double price) // setName function is setting price of product
{
	this->price = price; // member variable is equal to function parameter
}

int Product::getQuantityOfItem() const
// getQuantityOfItem function is getting quantity number of product in system
{
	return  m_quantity; // return member variable - Quantity of product in system
}

void Product::setQuantityOfItem(int quantity)
// setQuantityOfItem function is setting quantity number of product in system
{
	m_quantity = quantity; // member variable is equal to function parameter
}



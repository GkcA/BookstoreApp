/*****************************
* ProductToPurchase.cpp      *
*****************************/
/**
* @file ProductToPurchase.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Implementation of ProductToPurchase Class functions
*
*/

#include "ProductToPurchase.h"
// Call ProductToPurchase.h header file for definition member function

/*!
\param pro an Product pointer argument.
\param qua an int argument.
*/
ProductToPurchase::ProductToPurchase(Product * pro, int qua):product(pro),
	quantity(qua) // Constructor function of class, initial value is setting after ' : '
{
}

/*!
\param no argument.
*/
ProductToPurchase::~ProductToPurchase() // Destructor function of class
{
}

/*!
\param no argument.
\return product - want to purchase.
*/
Product * ProductToPurchase::getProduct() const
// getProduct function is getting product object
{
	return product; // return member object - product object
}

/*!
\param product an Product pointer argument.
*/
void ProductToPurchase::setProduct(Product * product)
// setProduct function is setting product object
{
	this->product = product; // member object is equal to function parameter object
}

/*!
\param no argument.
\return quantity - want to purchase.
*/
int ProductToPurchase::getQuantity() const
// getQuantity function is getting quantity which is purchased
{
	return quantity;
	// return member variable - quantity number of purchased product
}

/*!
\param quantity an integer argument.
*/
void ProductToPurchase::setQuantity(int quantity)
// setQuantity function is setting quantity which is purchased
{
	this->quantity = quantity; // member variable is equal to function parameter object
} 

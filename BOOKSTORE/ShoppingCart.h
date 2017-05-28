/**********************
* ShoppingCart.h      *
**********************/

/**
* @file ProductToPurchase.h
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Declaration of ProductToPurchase Class
*
* Products to purchase from store
*/

#pragma once
#include <vector>
#include "ProductToPurchase.h"
// Call ProductToPurchase.h header for composition relation
#include "Payment.h" // Call Payment.h header for composition relation
#include "Customer.h" // Call Customer.h header for aggregation relation
using namespace std;

//! A ShoppingCart class.
/*!
To add items to shoppingcart
*/
class ShoppingCart 
{
private: // private part of class
	char m_pd[32]; // char type array
	vector <ProductToPurchase*> productsToPurchase; // ProductToPurchase type
	//vector named productsToPurchase to place purchased items from customer
	Payment* paymentMethod; // Payment type object named paymentMethod
	Customer* customer; // Customer type object named customer
	bool isBonusUsed; // bool type variable for controlling using bonus
public: // public part of class
	//! Constructor function of class
	ShoppingCart(Customer* cst);
	//! Destructor function of class
	~ShoppingCart();
	//!function for getting payment method
	const Payment* getPaymentMethod() const;
	//!function for setting payment method
	void setPaymentMethod(Payment* paymentMethod);
	//!function for getting customer
	const Customer* getCustomer() const;
	//!function for setting customer
	void setCustomer(Customer* customer);
	//!function for controlling using bonus
	void setBonusUsed();
	//!function for adding product to shopping cart
	void addProduct(Product* product);
	//!function for removing product from shopping cart
	void removeProduct(Product* product);
	//!function for buying items which is choosen by customer
	void placeOrder();
	//!function for canceling all order
	void cancelOrder();
	//!function for printing products
	void printProducts();
	//!function for showing invoice after shopping
	void showInvoice();
}; // end of class
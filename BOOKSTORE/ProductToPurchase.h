/*************************
* ProductToPurchase.h    *
*************************/

/**
* @file ProductToPurchase.h
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Declaration of ProductToPurchase Class
*
* Products to purchase from store
*/

#pragma once
#include"Product.h" // Call Product.h header for aggregation relation

//! A ProductToPurchase Class.
/*!
ProductToPurchase Class includes an item and its quantity for adding to cart .
*/
class ProductToPurchase // defined class named ProductToPurchase
{
private: // private part of class
	Product* product; // Product type object named product
	int quantity; // integer variable for quantity which is purchased
public: // public part of class
	//! Constructor function of class
	ProductToPurchase(Product* pro = NULL,int qua=0);
	//! Destructor function of class
	~ProductToPurchase(); 
	//!function for getting product
	Product* getProduct()const; 
	//! function for setting product
	void setProduct(Product* product); 
	//! function for getting quantity want to purchase
	int getQuantity()const; 
	//! function for setting quantity want to purchase
	void setQuantity(int quantity);
}; // end of class
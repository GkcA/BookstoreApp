/**********************
* Magazine.h          *
**********************/

/**
* @file Magazine.h
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Declaration of Magazine Class
*
* Magazines in Store
*/

//! A  Magazine Class.
/*!
Magazine Class inherited from Product Class.
*/
#pragma once
#include "Product.h" // Call Product.h header for inheritance relation
class Magazine : // Defined class named Magazine
	public Product // using inheritance relation from Product class
{
	string m_issue; // string type variable for issue date of magazine
	string m_type; // string type variable for type of magazine
	int flag; // integer variable named flag
public: // public part of class
	//! Constructor function of class
	Magazine(int ID, string name, double price, string issue, string type,
		int quantity); 
	// Function parameters are magazine's ID,magazine's name,magazine's price,
	//magazine's issue date,magazine's type and quantity of magazine
	//!Copy constructor function
	Magazine(const Magazine* copyMagazine); 
	//!Destructor function of class
	~Magazine(); 
	//!function for getting issue date of magazine
	string getIssue()const;
	//!function for setting issue date of magazine
	void setIssue(string issue);
	//!function for getting type of magazine
	string getType()const;
	//!function for setting type of magazine
	void setType(string type);
	//!function for printing properties of magazines
	void printProperties(int flag);
	//!function for getting product type
	string getClassName()const;
}; // end of class


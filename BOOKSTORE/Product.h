/**********************
* Product.h           *
**********************/
/**
* @file Product.h
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Declaration of Product Class
*
* Abstract Base class of products in store
*/

#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

//! A  Product Class.
/*!
Product Class base class of Book, Magazine and MusicCD Classes.
*/
class Product // defined class named Product
{
	int ID; // integer variable for ID number of product
	string name; // string variable for name of product
	double price; // double variable for price of product
	int m_quantity; // integer variable for quantity of product
public: // public part of class
	//! Constructor function of class
	Product(int ID,string name,double price,int quantity);
	//!Destructor function of class
	~Product(); 
	//!function for getting ID number of product
	int getID()const; 
	//!function for setting ID number of product
	void setID(int ID); 
	//!function for getting name of product
	string getName()const; 
	//!function for setting name of product
	void setName(string name); 
	//!function for getting price of product
	double getPrice()const; 
	//!function for setting price of product
	void setPrice(double price); 
	//!function for getting quantity of product
	int getQuantityOfItem()const;
	//!function for setting quantity of product
	void setQuantityOfItem(int quantity);
	//!ure Virtual Function - for printing properties of products
	virtual void printProperties(int flag) = 0;
	//!Pure Virtual Function - for getting product type
	virtual string getClassName() const = 0;
}; // end of class


/**********************
* Book.h              *
**********************/

/**
* @file Book.h 
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Declaration of Book Class
*
* Books in store
*/

#pragma once
#include "Product.h" // Call Product.h header for inheritance relation

//! A Book Class.
/*!
 Book Class inherited from Product Class.
*/
class Book : // Defined class named Book
	public Product // using inheritance relation from Product class
{
	string m_author; // String type variable for book's author
	string m_publisher; // String type variable for book's publisher
	int m_page; // Ýnteger type variable for book's page number
public: // public part of class
	//!Constructor function
	Book(int ID, string name, double price, string author, string publisher,
		int page,int quantity); 
	// Function parameters are book's ID, book's name, book's price,
	//book's author, book's publisher, page of book and quantity of book
	//!Copy constructor function	
	Book(const Book*copyBook); 
	//! Destructor function
	~Book(); 
	//!function for printing properties of books
	void printProperties(int flag);
	//! function for getting book's author
	string getAuthor()const;
	//! function for setting book's author
	void setAuthor(string author);
	//! function for getting book's publisher
	string getPublisher()const;
	//!function for setting book's publisher
	void setPublisher(string publisher);
	//! function for getting page of book
	int getPage()const; 
	//! function for setting page of book
	void setPage(int page);
	//! function for getting product type
	string getClassName()const;
}; // end of class


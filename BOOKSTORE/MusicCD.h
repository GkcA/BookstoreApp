/**********************
* MusicCD.h           *
**********************/
/**
* @file MusicCD.h
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Declaration of MusicCD Class
*
* MusicCDs in Store
*/
#pragma once
#include "Product.h" // Call Product.h header for inheritance relation

//! A MusicCD Class.
/*!
MusicCD Class inherited from Product Class.
*/
class MusicCD : // Defined class named MusicCD
	public Product // using inheritance relation from Product class
{
	string m_singer; // string type variable for singer's name of music CD
	string m_type; // string type variable for type of music CD
public: // public part of class
	//! Constructor function of class
	MusicCD(int ID, string name, double price, string singer, string type,
		int quantity); 
	//!Copy constructor function
	MusicCD(const MusicCD * copyCD); 
	//!Destructor function
	~MusicCD(); 
	//!function for getting singer name
	string getSinger()const; 
	//!function for setting singer name
	void setSinger(string singer); 
	//!function for getting type of music CD
	string getType()const; 
	//!function for setting type of music CD
	void setType(string type); 
	//!function for printing properties of music CD's
	void printProperties(int flag); 
	//!function for getting product type
	string getClassName()const;
}; // end of class


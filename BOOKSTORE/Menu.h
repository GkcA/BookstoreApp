/**********************
* Menu.h              *
**********************/

/**
* @file Menu.h
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Declaration of Menu Class
*
* Main part of BookStore
*/

#pragma once
#include"ShoppingCart.h" // Call ShoppingCart.h header for using this class function
#include"Book.h" // Call Book.h header for using this class function
#include"Magazine.h" // Call Magazine.h header for using this class function
#include"MusicCD.h" // Call MusicCD.h header for using this class function
#include"Cash.h" // Call Cash.h header for using this class function
#include"Check.h" // Call Check.h header for using this class function
#include"CreditCard.h" // Call CreditCard.h header for using this class function
#include<fstream> // Call fstream for using file operation

using namespace std;

//! A Menu Class.
/*!
Menu Class main part of bookstore.
*/
class Menu
{
	fstream fileRead;
	// fstream type or file type variable named fileRead - reading from this file
	string getInput; // string type variable named getInput - writing string
	//from file to this variable
	string m_Choice; // string type variable for customer's choice
	bool a_log, c_log; // bool type variables
	//a_log is admin login - c_log is customer login
	ShoppingCart *shopCart; // ShoppingCart type object named shopCart
	Payment *method; // Payment type object named method
	Customer* temp_user; // Customer type object named temp_user
	Customer* ADMIN; // Customer type object named ADMIN
	vector<Customer*> CustomerList;
	// vector Customer type variable named CustomerList for placed customer in system
	vector<Product*> ItemsInSystem;
	// vector Product type variable named ItemsInSystem for placed items in system
	vector<Product*> m_shopping_cart;
	// vector Product type variable named m_shopping_cart for placed items
	//which is bought from customer
	vector<Product*> DESTRUCTOR; // vector Product type variable named DESTRUCTOR
public: // Public part of class
	//! Constructor function of class
	Menu();
	//! Destructor function of class
	~Menu();
	//! void type function for operation of main menu
	void Main_Menu();
	//! void type function for operation of customer menu
	void Customer_Menu();
	//! void type function for operation of item menu
	void Item_Menu();
	//! void type function for operation of shopping menu
	void Shopping_Menu();
	//! void type function for showing all item in system
	void Show_All_Item(bool flag);
	//! void type function for customer login
	void Login();
	//! void type function for customer logout
	void Logout();
	//! void type function for showing customer's order
	void List_Cart();
	//! long type function for assigning ID to customer's randomly
	const long assignIDToCustomer();
	//! bool type function for controlling if username is taken before
	bool checkIfUsernameIsTaken(const string&);
	//! bool type function for controlling if e-mail is used before
	bool checkIfEmailIsInUse(const string&);
	//! bool type function for controlling if phone number is used before
	bool checkIfPhoneIsInUse(const string&);
	//! void type function for clearing console
	void clearConsole();
	//! void type function for adding item to system by admin
	void AddItem();
	//! void type function for deleting item from system by admin
	void DeleteItem();
	//! void type function for adding item to shopping account of customer
	void Add_to_Cart();
	//! void type function for removing item from shopping account of customer
	void RemoveFromCart();
	//! void type function for cancelling all order in customer's account
	void Cancel_Order();
	//! bool type function for opening file
	bool OpenFile(fstream&);
	//! void type function for buying all order in customer's account
	void Place_Order();
	//! string type function to place item name which is choosen from customer
	string Take_Item_Name(vector<Product*> vector);
	//! integer type function to place item quantity which is choosen from customer
	int Take_Item_Quantity(vector<Product*> vector, string name);
	//! bool type function for controlling item name
	bool Check_Item_Name(vector<Product*> vector,string name);
	//! bool type function for controlling item quantity
	bool Check_Item_Quantity(vector<Product*> vector, string name, int quantity);
	//! vector Product type function for sorting product according to types
	vector<Product*> SortbyProductType(vector<Product*> product);
	//! vector Product type function for swap product
	vector<Product*> Swap_Product(vector<Product*> &first,
		vector<Product*>&second, string transfer_product, int quantity);
};

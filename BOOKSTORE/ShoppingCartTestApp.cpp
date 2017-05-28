/**
* @file ShoppingCartTestApp.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Test of ShoppingCart Class functions
*
*/

#include <conio.h> //For _getch()
#include "ShoppingCart.h" //To use ShoppingCart class
#include "Book.h" //To use Book class
#include "Magazine.h" //To use Cash class
#include "MusicCD.h" //To use CreditCard class
#include "Cash.h" //To use Cash class

void main()
{
	cout << "+--------------------+" << endl
		<< "| SHOPPING CART TEST |" << endl
		<< "+--------------------+" << endl; //Testing Product

	cout << "Creating a customer..." << endl;
	Customer *customer = new Customer; //An initial Customer
	customer -> setName("Deniz ATILGAN"); //Sets the name
	customer -> setAddress("Zafer Mahallesi Gazikemalpasa Sokagi Gunes Evleri No:6/1 Daire:15");
	//Sets the address
	customer -> setPhone("905335517708"); //Sets the phone
	customer -> setEmail("denizatilgan_96@hotmail.com"); //Sets the email
	customer -> setUsername("denizAtilgan007"); //Sets the username
	customer -> setPassword("a17cb83"); //Sets the password
	customer -> setBonus(7);
	cout << "Customer has been created!" << endl;

	ShoppingCart test(customer); //An initial ShoppingCart

	cout << "Creating a book..." << endl;
	Product *book = new Book(17, "The Lord of the Rings", 49.55,
		"J. R. R. Tolkien", "Folio Publishing", 1433, 4); //An initial Book
	cout << "Adding the book to the shopping cart..." << endl;
	test.addProduct(book); //Adds the book to the shopping cart

	cout << "Creating a magazine..." << endl;
	Product *magazine = new Magazine(62, "Life Outside the World ", 9.75,
		"7th Issue", "Jupiter Publishing", 11); //An initial Magazine
	cout << "Adding the magazine to the shopping cart..." << endl;
	test.addProduct(magazine); //Adds the magazine to the shopping cart

	cout << "Creating a music CD..." << endl;
	Product *musicCD = new MusicCD(3, "Careless Whisper", 7.55,
		"George Michael", "Smooth Jazz", 7); //An initial MusicCD
	cout << "Adding the music CD to the shopping cart..." << endl;
	test.addProduct(musicCD); //Adds the music CD to the shopping cart

	cout << "Printing products..." << endl;
	test.printProducts(); //Prints the stuff in the cart

	cout << "Removing the magazine..." << endl;
	test.removeProduct(magazine); //Removes the magazine from the cart

	cout << "Printing products..." << endl;
	test.printProducts(); //Prints the stuff in the cart

	cout << "Setting the payment method as cash..." << endl;
	Payment *cash = new Cash(0); //An initial Payment (Method)
	test.setPaymentMethod(cash); //Sets the payment method
	_getch(); //To pause the code

	test.placeOrder(); //Places the order and proceeds to payment

	cout << "Showing invoice..." << endl;
	test.showInvoice(); //Shows the invoice

	_getch(); //To pause the code
}
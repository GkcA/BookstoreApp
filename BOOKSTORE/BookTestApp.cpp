/**
* @file BookTestApp.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Test of Book Class functions
*
*/

#include <conio.h> //For _getch()
#include "Book.h" //To use Book class

void main()
{
	cout << "+-----------+" << endl
		<< "| BOOK TEST |" << endl
		<< "+-----------+" << endl; //Testing Book

	Book test(-1, "!!ERROR!!", 0.00, "!!ERROR!!",
		"!!ERROR!!", -1, -1); //An initial Book

	cout << "Testing set functions..." << endl;
	//Setting up properties of the book
	test.setID(1); //Setting ID
	test.setName("Lord of the Rings"); //Setting the name
	test.setPrice(37.99); //Setting the price
	test.setAuthor("J. R. R. Tolkien");  //Setting the author
	test.setPublisher("Folio Publishing"); //Setting the publisher 
	test.setPage(1432); //Setting the page number
	test.setQuantityOfItem(4); //Setting the quantity
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "Printing properties..." << endl;
	//See if our values have been written
	test.printProperties(-1); //This function itself has the get functions in it

	_getch(); //To pause the code
}
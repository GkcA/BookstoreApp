/**
* @file MagazineTestApp.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Test of Magazine Class functions
*
*/

#include <conio.h> //For _getch()
#include "Magazine.h" //To use Magazine class

void main()
{
	cout << "+---------------+" << endl
		<< "| MAGAZINE TEST |" << endl
		<< "+---------------+" << endl; //Testing Magazine

	Magazine test(0, "!!ERROR!!", 0, "!!ERROR!!", "!!ERROR!!", 0);
	//An initial Magazine

	cout << "Testing set functions..." << endl;
	//Setting up properties of the magazine
	test.setID(17); //Sets the ID
	test.setName("Life Outside the World"); //Sets the name
	test.setPrice(7.99); //Sets the price
	test.setIssue("7th Issue"); //Sets the issue
	test.setType("Astronomy"); //Sets the type
	test.setQuantityOfItem(4); //Sets the quantity
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "You are now looking at " << test.getClassName() << endl;
	//Shows what you are looking at
	test.printProperties(-1); //Prints properties

	_getch(); //To pause the code
}
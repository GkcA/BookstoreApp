/**
* @file MusicCDTestApp.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Test of MusicCD Class functions
*
*/

#include <conio.h> //For _getch()
#include "MusicCD.h" //To use MusicCD class

void main()
{
	cout << "+---------------+" << endl
		<< "| MUSIC CD TEST |" << endl
		<< "+---------------+" << endl; //Testing MusicCD

	MusicCD test(0, "!!ERROR!!", 0, "!!ERROR!!", "!!ERROR!!", 0);
	//An initial MusicCD

	cout << "Testing set functions..." << endl;
	//Setting up properties of the music CD
	test.setID(17); //Sets the ID
	test.setName("Careless Whisper"); //Sets the name
	test.setPrice(4.35); //Sets the price
	test.setSinger("George Michael"); //Sets the singer
	test.setType("Smooth Jazz"); //Sets the type
	test.setQuantityOfItem(2); //Sets the quantity
	cout << "All set functions ran successfully." << endl; //Successful!

	cout << "You are now looking at " << test.getClassName() << endl;
	//Shows what you are looking at
	test.printProperties(-1); //Prints properties

	_getch(); //To pause the code
}
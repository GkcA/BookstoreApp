#include <conio.h> //For _getch()
#include "Product.h" //To use Product class
#include "Book.h" //To use Book class
#include "Magazine.h" //To use Magazine class
#include "MusicCD.h" //To use MusicCD class

void TEST_ForAll(Product* test, string name, int ID, int quantity, double price)
//Polymorphic testing
{
	cout << "Setting the properties of " << test -> getClassName() << "..." << endl;
	test -> setName(name);
	test -> setID(ID);
	test -> setPrice(price);
	test -> setQuantityOfItem(quantity);
	cout << "Successfully done. Printing properties now..." << endl;
	test -> printProperties(-1);
}

void main()
{
	cout << "+--------------+" << endl
		<< "| PRODUCT TEST |" << endl
		<< "+--------------+" << endl; //Testing Product

	Book *book = new Book(0, "!!ERROR!!", 0, "J. R. R. Tolkien",
		"Folio Publishing", 1432, 0);
	cout << "\nUsing a Book..." << endl;
	TEST_ForAll(book, "The Lord of the Rings", 177, 14, 39.95);
	//Using a Book for polymorphic functions

	Magazine *magazine = new Magazine(0, "!!ERROR!!", 0, "7th Issue", 
		"Astronomy", 0);
	cout << "\nUsing a Magazine..." << endl;
	TEST_ForAll(magazine, "Looking Out of World", 8349, 77, 12.35);
	//Using a Magazine for polymorphic functions

	MusicCD *musicCD = new MusicCD(0, "!!ERROR!!", 0, "George Michael", "Smooth Jazz", 0);
	cout << "\nUsing a Music CD..." << endl;
	TEST_ForAll(musicCD, "Careless Whisper", 723, 2, 17.95);
	//Using a Music CD for polymorphic functions

	_getch(); //To pause the code
}
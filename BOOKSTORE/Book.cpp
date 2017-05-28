/**********************
* Book.cpp            *
**********************/
#include "Book.h" // Call Book.h header file for definition member function

/**
* @file Book.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Implementation of Book Class functions
*
*/

/*!
 \param ID an integer argument.
 \param name an string argument.
 \param price an double argument.
 \param author an string argument.
 \param publisher an string argument.
 \param page an int argument.
 \param quantity an int argument.
*/
Book::Book(int ID,string name,double price,string author, string publisher,
		   int page, int quantity):Product(ID,name,price,quantity)
{ // Constructor function of Book class - using inheritance relation from
  //Product class constructor function
	setAuthor(author); // Call setAuthor function and to equalize function
	//parameter to class member variable
	setPublisher(publisher); // Call setPublisher function and to equalize
	//function parameter to class member variable
	setPage(page); // Call setPage function and to equalize
	//function parameter to class member variable
}

/*!
\param ID an constant Book pointer argument.
*/
Book::Book(const Book * copyBook):Product(copyBook->getID(), copyBook->getName(),
										  copyBook->getPrice(),
										  copyBook->getQuantityOfItem())
{ // Copy constructor function - using inheritance relation from
  //Product class constructor function
	setAuthor(copyBook->getAuthor()); // Call setAuthor function and parameters
	//are equal to copy object's variables
	setPublisher(copyBook->getPublisher()); // Call setPublisher function and
	//parameters are equal to copy object's variables
	setPage(copyBook->getPage()); // Call setPage function and parameters are
	//equal to copy object's variables
}

/*!
\param No parameter.
*/
Book::~Book() // Destructor function of Book class
{
}

/*!
\param flag an integer argument.
*/
void Book::printProperties(int flag)
// printProperties function for printing properties of books
{
	if (flag == 0) { // if flag equals 0
		cout << "+--------------------------+" << endl
			// To print to screen +--------------------------+
			 << "| LIST OF AVAILABLE BOOKS  |" << endl
			 // To print to screen | LIST OF AVAILABLE BOOKS  |
			 << "+--------------------------+" << endl << endl;
			// To print to screen +--------------------------+
		flag = 1; // flag is equal to 1
	}
	if (flag == -1)cout << "----- Book -----" << endl;
	// if flag equals -1 -- To print to screen ----- Book -----
		cout << "ID: " << getID() << endl
			// To print to screen ' ID: ' and book's ID
		 << "Name: " << getName() << endl
		 // To print to screen ' Name: ' and book's name
		 << "Author: " << getAuthor() << endl
		 // To print to screen ' Author: ' and book's author
		 << "Publisher: " << getPublisher() << endl
		 // To print to screen ' Publisher: ' and book's publisher
		 << "Page: " << getPage() << endl
		 // To print to screen ' Page: ' and total page number of book
		 << "Price: " << std::fixed << std::showpoint << setprecision(2) << getPrice() << " TL" << endl
		 // To print to screen ' Price: ',book's price and ' TL ' - two precision
		 << "Available Quantity: " << getQuantityOfItem() << endl << endl;
		// To print to screen ' Available Quantity ' and book's quantity in system
}

/*!
\param no argument.
\return  m_author - author name of book.
*/
string Book::getAuthor() const // getAuthor function for getting author of book
{
	return m_author; // return member variable m_author - author name of book
}

/*!
\param author an string argument.
*/
void Book::setAuthor(string author)
// setAuthor function for setting author of book
{
	m_author = author; // member variable is equal to function parameter
}

/*!
\param no argument.
\return m_publisher - publisher of book.
*/
string Book::getPublisher() const
// getPublisher function for getting publisher of book
{
	return m_publisher; // return member variable m_publisher - publisher of book
}

/*!
\param publisher an string argument.
\return m_author - author name of book.
*/
void Book::setPublisher(string publisher)
// setPublisher function for setting publisher of book
{
	m_publisher = publisher; // member variable is equal to function parameter
}

/*!
\param no argument.
\return m_page - total page number of book.
*/
int Book::getPage() const
// getPage function for getting total page number of book
{
	return m_page; // return member variable m_page - total page number of book
}

/*!
\param page an integer argument.
*/
void Book::setPage(int page)
// setPage function for setting total page number of book
{
	m_page = page; // member variable is equal to function parameter
}

/*!
\param no argument.
\return string "Book".
*/
string Book::getClassName() const // getClassName function for getting product type
{
	return "Book"; // return string "Book"
}



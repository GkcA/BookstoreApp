/**********************
* MusicCD.cpp         *
**********************/
#include "MusicCD.h" // Call MusicCD.h header file for definition member function

/**
* @file MusicCD.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Implementation of MusicCD Class functions
*
*/

/*!
\param ID an integer argument.
\param name an string argument.
\param price an double argument.
\param singer an string argument.
\param type an string argument.
\param quantity an int argument.
*/
MusicCD::MusicCD(int ID, string name, double price, string singer, string type,
				 int quantity):Product(ID,name,price,quantity)
{ // Constructor function of MusicCD class - using inheritance relation from
  //Product class constructor function
	setSinger(singer); // Call setSinger function and to equalize function
	//parameter to class member variable
	setType(type); // Call setType function and to equalize function
	//parameter to class member variable
}

/*!
\param ID an constant MusicCD pointer argument.
*/
MusicCD::MusicCD(const MusicCD * copyCD)
	:Product(copyCD->getID(),copyCD->getName(), copyCD->getPrice(),
	copyCD->getQuantityOfItem())
{ // Copy constructor function - using inheritance relation from Product class
  //constructor function
	setSinger(copyCD->getSinger()); // Call setSinger function and parameters are
	//equal to copy object's variables
	setType(copyCD->getType()); // Call setType function and parameters are equal
	//to copy object's variables
}

/*!
\param no argument.
*/
MusicCD::~MusicCD() // Destructor function of class
{
}

/*!
\param no argument.
\return m_singer - Singer of music CD
*/
string MusicCD::getSinger() const
// getSinger function is getting singer of music CD
{
	return m_singer; // return member variable - Singer of music CD
}

/*!
\param singer an string argument.
*/
void MusicCD::setSinger(string singer)
// setSinger function is setting singer of music CD
{
	this->m_singer = singer; // member variable is equal to function parameter
}

/*!
\param no argument.
\return m_type - Type of music CD
*/
string MusicCD::getType() const // getType function is getting type of music CD
{
	return m_type; // return member variable - Type of music CD
}

/*!
\param type an string argument.
*/
void MusicCD::setType(string type) // setType function is setting type of music CD
{
	this->m_type = type; // member variable is equal to function parameter
}

/*!
\param flag an integer argument.
*/
void MusicCD::printProperties(int flag)
// printProperties function for printing properties of music CD's
{
	if (flag == 0) { // if flag equals 0
		cout << "+---------------------------+" << endl
			// To print to screen +---------------------------+
			<< "| LIST OF AVAILABLE MUSIC CD |" << endl
			// To print to screen | LIST OF AVAILABLE MUSIC CD |
			<< "+----------------------------+" << endl << endl;
			// To print to screen +---------------------------+
		flag = 1; // flag is equal to 1
	}
	if (flag == -1)cout << "----- Music CD -----" << endl;
	// if flag equals -1 -- To print to screen ----- Music CD -----
	cout << "ID: " << getID() << endl
		// To print to screen ' ID: ' and music CD's ID
	 << "Name: " << getName() << endl
	 // To print to screen ' Name: ' and music CD's name
	 << "Singer: " << getSinger() << endl
	 // To print to screen ' Singer: ' and music CD's singer
	 << "Type: " << getType() << endl
	 // To print to screen ' Type: ' and music CD's type
	 << "Price: " << std::fixed << std::showpoint << setprecision(2) << getPrice()
	 << " TL" << endl // To print to screen ' Price: ',
	 //music CD's price and ' TL ' - two precision
	 << "Available Quantity: " << getQuantityOfItem() << endl << endl;
	// To print to screen ' Available Quantity ' and music CD's quantity in system
}

/*!
\param no argument.
\return string "MusicCD"
*/
string MusicCD::getClassName()  const
// getClassName function for getting product type
{
	return "MusicCD"; // return string "MusicCD"
}

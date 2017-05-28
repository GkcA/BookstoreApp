/**********************
* Magazine.cpp        *
**********************/
#include "Magazine.h" // Call Magazine.h header file for definition member function

/**
* @file Magazine.cpp
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Implementation of Magazine Class functions
*
*/

/*!
\param ID an integer argument.
\param name an string argument.
\param price an double argument.
\param issue an string argument.
\param type an string argument.
\param quantity an int argument.
*/
Magazine::Magazine(int ID, string name, double price, string issue, string type,
				   int quantity) :Product(ID, name, price,quantity)
{ // Constructor function of Magazine class - using inheritance relation from
  //Product class constructor function
	setIssue(issue); // Call setIssue function and to equalize function
	//parameter to class member variable
	setType(type); // Call setType function and to equalize function parameter
	//to class member variable
	flag = 0; // flag value is 0 initially
}

/*!
\param ID an constant Magazine pointer argument.
*/
Magazine::Magazine(const Magazine * copyMagazine)
	:Product(copyMagazine->getID(),copyMagazine->getName(),
	copyMagazine-> getPrice(), copyMagazine->getQuantityOfItem())
{ // Copy constructor function - using inheritance relation from
  //Product class constructor function
	setIssue(copyMagazine->getIssue());
	// Call setIssue function and parameters are equal to copy object's variables
	setType(copyMagazine->getType());
	// Call setType function and parameters are equal to copy object's variables
}

/*!
\param no argument.
*/
Magazine::~Magazine() // Destructor function of class
{
}

/*!
\param no argument.
\return  m_issue - Issue date of magazine
*/
string Magazine::getIssue() const // getIssue function is getting issue date of magazine
{
	return m_issue; // return member variable - Issue date of magazine
}

/*!
\param issue an string argument.
*/
void Magazine::setIssue(string issue)
	// setIssue function is setting issue date of magazine
{
	m_issue = issue; // member variable is equal to function parameter 
}

/*!
\param no argument.
\return  m_type - Type of magazine
*/
string Magazine::getType() const // getType function is getting type of magazine
{
	return m_type; // return member variable - Type of magazine
}

/*!
\param type an string argument.
*/
void Magazine::setType(string type) // setType function is setting type of magazine
{
	m_type = type; // member variable is equal to function parameter
}

/*!
\param flag an integer argument.
*/
void Magazine::printProperties(int flag)
// printProperties function for printing properties of magazines
{
	if (flag == 0) { // if flag equals 0
		cout << "+----------------------------+" << endl
		// To print to screen +----------------------------+
			 << "| LIST OF AVAILABLE MAGAZINE |" << endl
			 // To print to screen | LIST OF AVAILABLE MAGAZINE |
			 << "+----------------------------+" << endl << endl;
			// To print to screen +----------------------------+
		flag = 1; // flag is equal to 1
	}
	if (flag == -1) cout << "----- Magazine -----" << endl;
	// if flag equals -1 -- To print to screen ----- Magazine -----
	cout << "ID: " << getID() << endl
		// To print to screen ' ID: ' and magazine's ID
	 << "Name: " << getName() << endl
	 // To print to screen ' Name: ' and magazine's name
	 << "Issue: " << getIssue() << endl
	 // To print to screen ' Issue: ' and magazine's issue date
	 << "Type: " << getType() << endl
	 // To print to screen ' Type: ' and magazine's type
	 << "Price: " << std::fixed << std::showpoint << setprecision(2) <<
	 getPrice() << " TL" << endl // To print to screen ' Price: ',magazine's price
	 //and ' TL ' - two precision
	 << "Available Quantity: " << getQuantityOfItem() << endl << endl;
	// To print to screen ' Available Quantity ' and magazine's quantity in system
}

/*!
\param no argument.
\return  string "Magazine"
*/
string Magazine::getClassName()  const // getClassName function for getting product type
{
	return "Magazine"; // return string "Magazine"
}

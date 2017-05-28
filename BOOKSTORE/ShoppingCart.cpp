/************************
* ShoppingCart.cpp      *
************************/

/**
* @file ShoppingCart.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Implementation of ShoppingCart Class functions
*
*/

#include "ShoppingCart.h"
// Call ShoppingCart.h header file for definition member function
#include<time.h> // call for rand function

vector<ProductToPurchase*> toPrint; // ProductToPurchase type vector named toPrint
//- to placed purchased item after purchase operation and using for printing bill for that items

/*!
\param cst an Customer pointer argument.
*/
ShoppingCart::ShoppingCart(Customer * cst):customer(cst)
// Constructor function of class
{
}

/*!
\param no argument.
*/
ShoppingCart::~ShoppingCart() // Destructor function of class
{
	productsToPurchase.clear(); // To clean out productsToPurchase vector
	delete paymentMethod; // To delete payment method object
}

/*!
\param no argument.
\return paymentMethod - method for paying cost of products
*/
const Payment* ShoppingCart::getPaymentMethod() const
// getPaymentMethod function is getting payment method
{
	return paymentMethod; // return member object - paymentMethod object
}

/*!
\param paymentMethod an Payment pointer argument.
*/
void ShoppingCart::setPaymentMethod(Payment* paymentMethod)
// setPaymentMethod function is setting payment method
{
	this -> paymentMethod = paymentMethod;
	// member object is equal to function parameter object
}

/*!
\param no argument.
\return customer - online customer in system 
*/
const Customer* ShoppingCart::getCustomer() const
// getCustomer function is getting customer object
{
	return customer; // return member object - customer object
}

/*!
\param customer an Customer pointer argument.
*/
void ShoppingCart::setCustomer(Customer* customer)
// setCustomer function is setting customer object
{
	this -> customer = customer; // member object is equal to function parameter object
}

/*!
\param no argument.
*/
void ShoppingCart::setBonusUsed() // setBonusUsed function to control using bonus
{
	isBonusUsed = true; // isBonusUsed value is true
}

/*!
\param product an Product Pointer argument.
*/
void ShoppingCart::addProduct(Product* product)
// addProduct function to adding product to shopping cart
{
	ProductToPurchase *tmp=new ProductToPurchase(product, product->getQuantityOfItem());
	// To create ProductToPurchase type object
	productsToPurchase.push_back(tmp);
	// To add purchased item to productToPurchase vector by customer
}

/*!
\param product an Product Pointer argument.
*/
void ShoppingCart::removeProduct(Product* product)
// removeProduct function to removing product from shopping cart
{
	for (int flag = 0; flag < productsToPurchase.size(); flag++)
	// from 0 to productToPurchase vector size
	{
		if (productsToPurchase[flag]->getProduct() == product) // if searching
		//item is equal to any element in productsToPurchase vector
		{
			productsToPurchase.erase(productsToPurchase.begin() + flag);
			// remove searching item from productsToPurchase vector
			break; // break for loop
		}
	}
}

/*!
\param no argument.
*/
void ShoppingCart::placeOrder()
// placeOrder function for buying items which is choosen by customer
{
	double amount = 0;
	// double variable named amount for total price - initial value is 0
	for (int i = 0;i < productsToPurchase.size();i++)
		// from 0 to productsToPurchase vector size
		amount+=(productsToPurchase[i]->getProduct()->getPrice())*(productsToPurchase[i]->getQuantity());
		// amount is equal to price of purchased product multiply purchased quantity

	if (isBonusUsed) { // if customer use bonus point in customer's account
		double bonus; // double variable named bonus
		do { // starting do - while loop
			system("cls"); // Clear console
			cout << "Current Bonus : " << customer->getBonus() << endl; // To print
			//to screen ' Current Bonus : ' and customer's bonus point that time
			cout << "Enter Bonus You want to use : " << endl;
			// To print to screen ' Enter Bonus You want to use : '
			cin >> bonus; // To read entered bonus value by customer
			cin.ignore(); // Ignore cin
		} while ((customer->getBonus() < bonus) || bonus < 0);
		// Loop is continuing if customer's bonus point less than entered bonus
		//value or entered bonus less than 0
		amount -= bonus; // Amount ( total price ) is equal to itself minus bonus
		customer->useBonus(bonus);
		// Call useBonus function and parameter is entered bonus
		isBonusUsed = false; // isBonusUsed value is equal to false
		cout << "Bonus Left : " << customer->getBonus()<<endl; // To print to
		//screen ' Bonus Left : ' and customer's bonus point after using bonus operation
	}
	paymentMethod->setAmount(amount);
	// Call setAmount function for remaining price
	paymentMethod->performPayment();
	// Call performPayment function for printing payment information
	customer->addBonus(paymentMethod->getAmount() * 0.01);
	// Call addBonus function for calculating gained bonus from that shopping
	toPrint = productsToPurchase;
	// toPrint is equal to purchased item or productsToPurchase vector elements
	productsToPurchase.clear(); // To clear productsToPurchase vector

	struct tm newtime; // Defined struct
	__time32_t aclock; // Defined variable for time

	errno_t errNum; // error number 
	_time32(&aclock);   // Get time in seconds
	_localtime32_s(&newtime, &aclock);   // Convert time to struct tm form  

	errNum = asctime_s(m_pd, 32, &newtime); // Print local time as a string
	if (errNum) // if error number is not equal to 0
	{
		printf("Error code: %d", (int)errNum);
		// To print to screen ' Error code: ' and error number
	}
	printf("\nPurchased time: %s\n", m_pd);
	// To print to screen ' Purchased time: ' and purchased time
	customer->sendBill(); // To call sendBill function for printing bill notice
}

/*!
\param no argument.
*/
void ShoppingCart::cancelOrder() // cancelOrder function for cancelling all order
{
	productsToPurchase.clear(); // To clear productsToPurchase vector
}

/*!
\param no argument.
*/
void ShoppingCart::printProducts()
// printProducts function for printing customer's all order
{
	cout << "+--------------------+" << endl;
	// To print to screen +--------------------+
	cout << "  YOUR SHOPPING-CART " << endl;
	// To print to screen   YOUR SHOPPING-CART 
	cout << "+--------------------+" << endl<<endl;
	// To print to screen +--------------------+
	for (int flag = 0; flag < productsToPurchase.size(); flag++)
	// from 0 to productsToPurchase vector size
	{
		productsToPurchase[flag]->getProduct()->printProperties(-1);
		// To call printProperties function and parameter is -1
	}
}

/*!
\param no argument.
*/
void ShoppingCart::showInvoice()
// showInvoice function for printing invoice informations
{
	if (paymentMethod != NULL) { // if paymentMethod does not equal NULL
		int randInvoiceID = 100000 + rand() % 999999;
		// integer random variable for store ID
		cout << "+---------+" << endl; // To print to screen +---------+
		cout << "  COMPANY " << endl;  // To print to screen   COMPANY 
		cout << "+---------+" << endl; // To print to screen +---------+
		cout << "NuzukStore\t\t\tInvoice ID: " << randInvoiceID << "\t\t" <<
			m_pd << "\nMiddle-Earth Street" << "\n07600" << "\n+(90)5068402541"
			<< endl; // To print to screen Store Informations
		cout << "+---------+" << endl; // To print to screen +---------+
		cout << "  BILL TO " << endl;  // To print to screen  BILL TO 
		cout << "+---------+" << endl; // To print to screen +---------+
		cout << customer->getCustomerID() << endl << customer->getName() <<
			endl << customer->getAddress() << endl << customer->getPhone() <<
			endl; // To print to screen customer's informations
		cout << "+-------------+" << endl; // To print to screen +-------------+
		cout << "  DESCRIPTION " << endl;  // To print to screen   DESCRIPTION 
		cout << "+-------------+" << endl; // To print to screen +-------------+
		cout << setw(15) << left <<"ID"<<setw(20) <<"Name\t\t" << setw(10) << "Quantity   " <<
			setw(10) << "Unit Price" << endl; // To print to screen Name Quantity
			//and Unit Price - left and setw shows printing left based
		for (size_t i = 0; i < toPrint.size(); i++) // from 0 to toPrint vector size
		{
			cout << setw(15) << left <<toPrint[i]->getProduct()->getID()<<setw(20)<<
				toPrint[i]->getProduct()->getName() <<"\t\t" << setw(10)
				<< toPrint[i]->getQuantity() << " x " <<
				setw(10) << toPrint[i]->getProduct()->getPrice() << endl;
			// To print to screen purchased product's information
		}
		cout << "+-------------+" << endl; // To print to screen +-------------+
		cout << "Total : " << paymentMethod->getAmount() <<"TL"<< endl;
		// To print to screen ' Total: ' , total price and ' TL '
	}
	else // else - if not paymentMethod equals NULL
		cout << "Invoice does not exist!!.Buy any Product..." << endl // To print
		//to screen ' Invoice does not exist!!.Buy any Product... ' 
		<<"Press any key to continue..."<<endl; // To print to screen
		//' Press any key to continue... '
	_getch(); // _getch() - Stop screen till press any key
}

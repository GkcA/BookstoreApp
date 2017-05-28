/*****************
* Menu.cpp       *
*****************/

/**
* @file Menu.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @date January, 2017
* @Implementation of functions of Menu Class 
*
* Main part of BookStore
*/

#include "Menu.h" // Call Menu.h header file for definition member function and
//using all other functions
#include <ctime> // Call for rand function
#include <conio.h> // Call for _getch()

/*!
\param no argument
*/
Menu::Menu() // Constructor function of class
{
	a_log = false; // bool variable admin_login is false initially
	c_log = false; // bool variable customer_login is false initially
	ADMIN = new Customer; // To create new Customer type object named ADMIN
	ADMIN->setPassword("1234"); // To set admin's password as 1234
	ADMIN->setUsername("ADMIN"); // To set admin's username as ADMIN
	ADMIN->setName("ADMIN"); // To set admin's name as ADMIN
}

/*!
\param no argument
*/
Menu::~Menu() // Destructor function of class
{
}

/*!
\param no argument
*/
void Menu::Main_Menu()
{
	while (true) { // while loop

		if (a_log || c_log) cout << "Online user : " << temp_user->getName() <<
			"\n\n"; // if a_log or c_log is true to print to screen
		//' Online user: ' and customer's name

		cout << "1. Customer" << endl << "2. Item" << endl << "3. Shopping" <<
			endl << ((!a_log && !c_log) ? "4. Login" : "4. Logout") << endl <<
			"5. Quit" << endl << "Choose one : ";
		// To print to screen ' 1.Customer ', ' 2.Item ', ' 3.Shopping ', if a_log
		//and c_log is false print Login but if not
		//print Logout , ' 5.Quit ' and ' Choose one : '
		getline(cin, m_Choice); // To read choice from entered value by customer
		clearConsole(); // Call clearConsole function - To clear screen ( console )
		if (m_Choice == "1") { // if choice equals 1
			Customer_Menu(); // Call Customer_Menu function
		}
		else if (m_Choice == "2") { // if choice equals 2
			Item_Menu(); // Call Item_Menu function
		}
		else if (m_Choice == "3") { // if choice equals 3
			Shopping_Menu(); // Call Shopping_Menu function
		}
		else if (m_Choice == "4") { // if choice equals 4
			(!(a_log || c_log) ? Login() : Logout()); // if a_log and c_log is
			//false call Login function - if a_log or c_log is true call Logout function
		}
		else if (m_Choice == "5") { // if choice equals 5
			exit(0); // Exit program - Close console
		}
		else { // if choice is not equal 1,2,3,4,5
			cout << "Wrong Choice.Please enter 1-5" << endl;
			// To print to screen ' Wrong Choice.Please enter 1-5 '
			_getch(); // _getch() - Stop screen till press any key
		}
		clearConsole();// Call clearConsole function - To clear screen ( console )
	}
}

/*!
\param no argument
*/
void Menu::Customer_Menu()
{
	while (true) { // while loop
		if (a_log || c_log) cout << "Online user : " << temp_user->getName() <<
			"\n\n"; // if a_log or c_log is true to print to screen
			//' Online user: ' and customer's name

		cout << "1. Add a new customer to system" << endl
			// To print to screen ' 1. Add a new customer to system '
			<< "2. Show the customers in the system" << endl
			// To print to screen ' 2. Show the customers in the system '
			<< "3. Back" << endl << "Choose one : ";
		// To print to screen ' 3. Back ' and ' Choose one : '
		getline(cin, m_Choice); // To read choice from entered value by customer
		clearConsole(); // Call clearConsole function - To clear screen ( console )
		if (m_Choice == "1") { // if choice equals 1
			if (a_log || c_log) cout << "Online user : " << temp_user->getName()
				<< "\n\n"; // if a_log or c_log is true to print to screen
			 //' Online user: ' and customer's name

			char* m_temp = new char[67]; // To create dynamic char array
			Customer* newcustomer = new Customer; // To create Customer type object
			cout << "Customer Name : "; // To print to screen ' Customer Name : '
			cin.getline(m_temp, 67);
			// To read from console entered name and write to inside of m_temp
			newcustomer->setName(m_temp);
			// Call setName function - customer object's name is equal to entered name
			cout << "Customer Address : ";
			// To print to screen ' Customer Address : '
			cin.getline(m_temp, 67);
			// To read from console entered address and write to inside of m_temp
			newcustomer->setAddress(m_temp); // Call setAddress function,
			//customer object's address is equal to entered address
			cout << "Customer Phone : "; // To print to screen ' Customer Phone : '
			cin.getline(m_temp, 67);
			// To read from console entered phone number and write to inside of m_temp
			while (!checkIfPhoneIsInUse(m_temp))
				// while - if entered phone number is used another customer, loop continues
			{
				cout << "That phone is already in use! ";
				// To print to screen ' That phone is already in use! '
				cout << "Please enter a different one: " << endl;
				// To print to screen ' Please enter a different one: '
				cin.getline(m_temp, 67); // To read from console entered
				 //phone number and write to inside of m_temp
			}
			newcustomer->setPhone(m_temp); // Call setPhone function - customer
			//object's phone number is equal to entered phone number
			cout << "Customer Email : "; // To print to screen ' Customer Email : '
			cin.getline(m_temp, 67); // To read from console entered e-mail
			//account and write to inside of m_temp
			while (!checkIfEmailIsInUse(m_temp)) // while - if entered e-mail
												 //account is used another customer, loop continues
			{
				cout << "That e-mail is already in use! ";
				// To print to screen ' That e-mail is already in use! '
				cout << "Please enter a different one: " << endl;
				// To print to screen ' Please enter a different one: '
				cin.getline(m_temp, 67); // To read from console entered e-mail
				//account and write to inside of m_temp
			}
			newcustomer->setEmail(m_temp); // Call setEmail function - customer
			 //object's e-mail account is equal to entered e-mail account
			cout << "Customer Username : ";
			// To print to screen ' Customer Username : '
			cin.getline(m_temp, 67);
			// To read from console entered user name and write to inside of m_temp
			while (!checkIfUsernameIsTaken(m_temp)) // while - if entered user
			//name is used another customer, loop continues
			{
				cout << "The username is already taken! ";
				// To print to screen ' The username is already taken! '
				cout << "Please enter a different one: " << endl;
				// To print to screen ' Please enter a different one:  '
				cin.getline(m_temp, 67);
				// To read from console entered user name and write to inside of m_temp
			}
			newcustomer->setUsername(m_temp); // Call setUsername function,
			 //customer object's user name is equal to entered user name
			cout << "Customer Password : ";
			// To print to screen ' Customer Password : '
			cin.getline(m_temp, 67);
			// To read from console entered password and write to inside of m_temp
			newcustomer->setPassword(m_temp); // Call setPassword function,
			//customer object's password is equal to entered password
			newcustomer->setCustomerID(assignIDToCustomer());
			// Call setCustomerID function and assignIDToCustomer function,
			//for assign ID to customer randomly
			CustomerList.push_back(newcustomer);
			// To add new customer to CustomerList vector
		}
		else if (m_Choice == "2") { // if choice equals 2
			if (a_log || c_log) cout << "Online user : " << temp_user->getName()
				<< "\n\n"; // if a_log or c_log is true to print to screen
				//' Online user: ' and customer's name

			for (size_t i = 0; i <CustomerList.size(); i++)
				// from 0 to CustomerList vector size
			{
				cout << "Customer Name : " << CustomerList[i]->getName() << endl;
				// To print to screen ' Customer Name : ' and customers' names
				cout << "Customer Address : " << CustomerList[i]->getAddress() << endl;
				// To print to screen ' Customer Address : ' and customers' address'
				cout << "Customer Phone : " << CustomerList[i]->getPhone() << endl;
				// To print to screen ' Customer Phone : ' and customers' phone numbers
				cout << "Customer Email : " << CustomerList[i]->getEmail() << endl;
				// To print to screen ' Customer Email : ' and customers' e-mail accounts
				cout << "Customer Username : " << CustomerList[i]->getUsername() << endl << endl;
				// To print to screen ' Customer Username : ' and customers' usernames
			}
			_getch(); // _getch() - Stop screen till press any key
		}
		else if (m_Choice == "3") { // if choice equals 3
			Main_Menu(); // Call Main_Menu function
		}
		else { // if choice is not equal 1,2,3
			if (a_log || c_log) cout << "Online user : " << temp_user->getName()
				<< "\n\n"; // if a_log or c_log is true to print to screen
				//' Online user: ' and customer's name

			cout << "Wrong Choice.Please enter 1-3" << endl;
			// To print to screen ' Wrong Choice.Please enter 1-3 '
			_getch(); // _getch() - Stop screen till press any key
		}
		clearConsole();// Call clearConsole function - To clear screen ( console )
	}
}

/*!
\param no argument
*/
void Menu::Item_Menu()
{
	while (true) // while loop
	{
		string m_temp; // string type variable named m_temp to place admin password
		bool gate = false; // bool type variable named gate is false initially
		if (!a_log) { // if a_log is false
			do // start do - while loop
			{
				if (a_log || c_log) cout << "Online user : " << temp_user->getName()
					<< "\n\n"; // if a_log or c_log is true to print to screen
							   //' Online user: ' and customer's name
				if (!gate) // if gate is true
					cout << "Please log in as a admin to continue" << endl <<
					"Admin Password : "; // To print to screen ' Please log in
					//as a admin to continue ' and ' Admin Password : '
				else // else - if gate is false
					cout << "Incorrect password. Please try again or for main " <<
					"menu enter 1" << endl; // To print to screen
					//' Incorrect password. Please try again or for main menu enter 1 '
				getline(cin, m_temp);
				// To read from console entered password and write to inside of m_temp
				if (gate && m_temp == "1") { // if gate and m_temp is 1
					clearConsole();
					// Call clearConsole function - To clear screen ( console )
					Main_Menu(); // Call Main_Menu function
				}
				gate = true; // gate is equal to true
				clearConsole();
				// Call clearConsole function - To clear screen ( console )
			} while (m_temp != ADMIN->getPassword());
			// while - if m_temp is equal to admin's password, loop ends
			a_log = true; // admin_login is equal to true
			c_log = false; // customer_login is equal to false
			temp_user = ADMIN; // To equalize user to ADMIN
			shopCart = new ShoppingCart(temp_user);
			// To create ShoppingCart type object named shopCart for user ADMIN
			clearConsole(); // Call clearConsole function - To clear screen ( console )
			cout << "WELCOME " << temp_user->getName();
			// To print to screen ' WELCOME ' and customer's name ( ADMIN )
			_getch(); // _getch() - Stop screen till press any key
			clearConsole(); // Call clearConsole function - To clear screen ( console )
		}
		if (a_log || c_log) cout << "Online user : " << temp_user->getName()
			<< "\n\n"; // if a_log or c_log is true to print to screen
			 //' Online user: ' and customer's name ( ADMIN )
		cout << "1. Show all items on the system" << endl
			// To print to screen ' 1. Show all items on the system '
			<< "2. Add a new item to system" << endl
			// To print to screen ' 2. Add a new item to system '
			<< "3. Delete an item from system" << endl
			// To print to screen ' 3. Delete an item from system '
			<< "4. Back " << endl // To print to screen ' 4. Back  '
			<< "Choose one : "; // To print to screen ' Choose one : '
		getline(cin, m_Choice); // To read choice from entered value by ADMIN
		if (m_Choice == "1") { // if choice equals 1
			Show_All_Item(true);
			// Call Show_All_Item function for printing all product in the system
			clearConsole();
			// Call clearConsole function - To clear screen ( console )
		}
		else if (m_Choice == "2") AddItem(); // if choice equals 2
		else if (m_Choice == "3") DeleteItem(); // if choice equals 3
		else if (m_Choice == "4") { // if choice equals 4
			clearConsole(); // Call clearConsole function - To clear screen ( console )
			Main_Menu(); // Call Main_Menu function
		}
		else { // if choice is not equal 1,2,3,4
			clearConsole(); // Call clearConsole function - To clear screen ( console )
			cout << "Wrong Choice.Please enter 1-4" << endl;
			// To print to screen ' Wrong Choice.Please enter 1-4 '
		}
		clearConsole(); // Call clearConsole function - To clear screen ( console )
	}
}

/*!
\param no argument
*/
void Menu::Shopping_Menu()
{
	while (true) { // while loop
		clearConsole();
		// Call clearConsole function - To clear screen ( console )
		if (a_log || c_log) cout << "Online user : " << temp_user->getName()
			<< "\n\n"; // if a_log or c_log is true to print to screen
			//' Online user: ' and customer's name
		cout << ((!a_log && !c_log) ? "1. Login" : "1. Logout") << endl
			// if a_log and c_log is false print
			//' Login ' but if not print ' Logout '
			<< "2. Add Product to Shopping Cart" << endl
			// To print to screen ' 2. Add Product to Shopping Cart '
			<< "3. Remove Product from Shopping Cart" << endl
			// To print to screen ' 3. Remove Product from Shopping Cart '
			<< "4. List All Products" << endl
			// To print to screen ' 4. List All Products '
			<< "5. List Shopping Cart" << endl
			// To print to screen ' 5. List Shopping Cart '
			<< "6. Show Bonus" << endl // To print to screen ' 6. Show Bonus '
			<< "7. Use Bonus" << endl // To print to screen ' 7. Use Bonus '
			<< "8. Place Order" << endl
			// To print to screen ' 8. Place Order '
			<< "9. Cancel Order" << endl
			// To print to screen ' 9. Cancel Order '
			<< "10. Show Invoice" << endl
			// To print to screen ' 10. Show Invoice '
			<< "11. Back" << endl  // To print to screen ' 11. Back '
			<< "12. Quit" << endl  // To print to screen ' 12. Quit '
			<< "Choose one : "; // To print to screen ' Choose one :  '
		getline(cin, m_Choice); // To read choice from entered value by customer
		clearConsole();
		// Call clearConsole function - To clear screen ( console )

		if ((!a_log && !c_log) &&
			(m_Choice == "2" || m_Choice == "3" || m_Choice == "5" ||
				m_Choice == "6" || m_Choice == "7" || m_Choice == "8"
				|| m_Choice == "9" || m_Choice == "10"))
		{ // if a_log and c_log is false AND choice is equal to 2 or 3 or
		  //5 or 6 or 7 or 8 or 9 or 10
			cout << "You have no permission to go further please log in" <<
				endl; // To print to screen ' You have no permission to go
			  //further please log in '
			_getch(); // _getch() - Stop screen till press any key
			Shopping_Menu(); // Call Shopping_Menu function
		}
		else if (m_Choice == "1") (!(a_log || c_log) ? Login() : Logout());
		// if choice is 1 - if a_log and c_log is false call Login function,
		//if a_log or c_log is true call Logout function

		else if (m_Choice == "2") Add_to_Cart();
		// if choice is 2 , call Add_to_Cart function

		else if (m_Choice == "3") RemoveFromCart();
		// if choice is 3 , call RemoveFromCart function

		else if (m_Choice == "4") Show_All_Item(false);
		// if choice is 4 , call Show_All_Item function

		else if (m_Choice == "5") { // if choice is 5
			List_Cart(); // Call List_Cart function for printing content
						 //of shopping cart of customer
			_getch(); // _getch() - Stop screen till press any key
		}

		else if (m_Choice == "6") { // if choice is 6
			cout << "Online user : " << temp_user->getName() << "\n\n";
			// To print to screen ' Online user: ' and customer's name
			cout << "You have " << temp_user->getBonus() << " points in your "
				<< "account" << endl; // To print to screen ' You have ' ,
							  //customer's bonus point and ' point in your account '
			_getch(); // _getch() - Stop screen till press any key
			clearConsole(); // Call clearConsole function - To clear screen ( console )
		}

		else if (m_Choice == "7") shopCart->setBonusUsed();
		// if choice is 7 , call setBonusUsed function

		else if (m_Choice == "8") Place_Order();
		// if choice is 8 , call Place_Order function

		else if (m_Choice == "9") Cancel_Order();
		// if choice is 9 , call Cancel_Order function

		else if (m_Choice == "10") { // if choice is 10
			shopCart->showInvoice(); // Call showInvoice function
		}

		else if (m_Choice == "11") Main_Menu();
		// if choice is 11 , call Main_Menu function

		else if (m_Choice == "12") exit(0);
		// if choice is 12 , exit program or close console

		else // choice is not equal to number between 1 and 12
			cout << "Wrong Choice.Please enter 1-12" << endl;
		// To print to screen ' Wrong Choice.Please enter 1-12 '

		clearConsole();
		// Call clearConsole function - To clear screen ( console )
	}
}

/*!
\param no argument
*/
void Menu::Show_All_Item(bool flag)
{
	clearConsole(); // Call clearConsole function - To clear screen ( console )
	if (a_log || c_log) cout << "Online user : " << temp_user->getName()
		<< "\n\n"; // if a_log or c_log is true to print to screen
				   //' Online user: ' and customer's name
	if (ItemsInSystem.size() <= 0)
		// if ItemsInSystem vector size is equal to 0 or less than 0
		cout << "There is no item in the shop";
	// To print to screen ' There is no item in the shop '
	else { // if ItemsInSystem vector size is bigger than 0
		int cnt = 0; // integer variable named cnt is 0 initially
		ItemsInSystem = SortbyProductType(ItemsInSystem);
		// ItemsInSystem vector is equal to sorted ItemsInSystem vector,
		//sorted products according to class name
		string tmp = ItemsInSystem[0]->getClassName(); // string type variable
					//to place first product's ( in ItemsInSystem ) class name
		for (size_t i = 0; i < ItemsInSystem.size(); i++)
			// from 0 to ItemsInSystem vector size
		{
			if (ItemsInSystem[i]->getClassName() != tmp)
				// if ItemsInSystem vector elements' class name is not equal to tmp
				cnt = 0; // cnt is equal to 0
			ItemsInSystem[i]->printProperties(cnt++);
			// ItemsInSystem vector elements call printProperties function
			tmp = ItemsInSystem[i]->getClassName();
			// tmp is equal to ItemsInSystem vector elements' class name
		}
	}
	_getch(); // _getch() - Stop screen till press any key
}

/*!
\param no argument
*/
void Menu::Login()
{
	bool gate = false; // bool type variable named gate for controlling login
	Customer* temp_c = new Customer; // To create new customer
	string m_temp1, m_temp2;
	// Defined two string - m_temp1 for username - m_temp2 for password
	do // starting do - while loop
	{
		if (!gate) cout << "Log In" << endl << "Enter Username : "; // if gate is
					//false - To print to screen ' Log In ' and ' Enter Username: '
		else if (checkIfUsernameIsTaken(m_temp1))
			// Call function - if username is used another customer
			cout << "Invalid username. Please try again or for main menu enter 1"
			<< endl; // To print to screen ' Invalid username. Please try again
					 //or for main menu enter 1 '
		getline(cin, m_temp1);
		// To read from console entered username and write to inside of m_temp1
		if (gate && m_temp1 == "1") {
			// if gate is equal to true AND m_temp1 is equal to 1
			clearConsole();
			// Call clearConsole function - To clear screen ( console )
			Main_Menu(); // Call Main_Menu function
		}
		gate = true; // gate is equal to true
		clearConsole();//clear console
	} while (checkIfUsernameIsTaken(m_temp1) && m_temp1 != "ADMIN");
	// while - if m_temp1 is not used by another customer and m_temp1 is not
	//equal to admin, loop ends
	gate = false; // gate is equal to false
	temp_c->setUsername(m_temp1); // Created customer object's username is equal
			 //to entered user name using setUsername function
	if (m_temp1 == "ADMIN") // if m_temp1 user name equals ADMIN
		temp_c = ADMIN; // Customer is ADMIN
	else { // if m_temp1 user name does not equal ADMIN
		for (size_t i = 0; i < CustomerList.size(); i++)
			// from 0 to CustomerList vector size
		{
			if (CustomerList[i]->getUsername() == m_temp1)
				// if CustomerList elements' user name equals entered username
			{
				temp_c = CustomerList[i];
				// Customer object is equal to CustomerList vector elements
			}
		}
	}
	do
	{
		if (!gate) cout << "Enter Password : ";
		// if gate is false - To print to screen ' Enter Password :  '
		else // else
			cout << "Incorrect password. Please try again or for main menu enter 1"
			<< endl; // To print to scren ' Incorrect password. Please try again or
					 //for main menu enter 1'
		getline(cin, m_temp2);
		// To read from console entered password and write to inside of m_temp2
		if (gate && m_temp2 == "1") {
			// if gate is equal to true AND m_temp1 is equal to 1
			clearConsole();
			// Call clearConsole function - To clear screen ( console )
			Main_Menu(); // Call Main_Menu function
		}
		gate = true; // gate is equal to true
		clearConsole(); // Call clearConsole function - To clear screen ( console )
	} while (!temp_c->checkAccount(m_temp1, m_temp2));
	// while - if username ( m_temp1 ) and password ( m_temp2 ) is equal to
	//customer's username and password,loop ends
	if (temp_c->getUsername() == "ADMIN") // if username equals ADMIN
		a_log = true; // admin_login is equal to true
	else // if username equals anything else
		c_log = true; // customer_login is equal to true
	temp_user = temp_c; // temp_c customer is equal to member object customer
	shopCart = new ShoppingCart(temp_user);
	// To create ShoppingCart type object named shopCart for customer
	clearConsole(); // Call clearConsole function - To clear screen ( console )
	cout << "WELCOME " << temp_user->getName();
	// To print to screen ' WELCOME ' and name of customer
	_getch(); // _getch() - Stop screen till press any key
	clearConsole(); // Call clearConsole function - To clear screen ( console )
}

/*!
\param no argument
*/
void Menu::Logout()
{
	if (a_log || c_log) cout << "Online user : " << temp_user->getName() << "\n\n";
	// if a_log or c_log is true to print to screen ' Online user: ' and customer's name
	a_log = false; // admin_login is equal to false
	c_log = false; // customer_login is equal to false
	Cancel_Order();
	// Call cancel order function for cancelling all order after logout
	temp_user = NULL; // Customer object is equal to NULL
}

/*!
\param no argument
*/
void Menu::List_Cart()
{
	if (a_log || c_log) cout << "Online user : " << temp_user->getName()
		<< "\n\n"; // if a_log or c_log is true to print to screen ' Online user: '
				   //and customer's name
	shopCart->printProducts();
	// Call printProducts function for printing ordered products
}

/*!
\param no argument
*/
const long Menu::assignIDToCustomer()
{
	long ID; // Long type variable named ID to place ID number of customers
	srand((unsigned)time(NULL)); // To use for selecting number randomly
	if (CustomerList.size() == 0) // if CustomerList vector size equals 0
	{
		ID = rand() % LONG_MAX + 0; // ID number is selecting randomly
	}
	else // else - CustomerList vector size different from 0
	{
		ID = rand() % LONG_MAX + 0; // ID number is selecting randomly
		for (int flag = 0; flag < CustomerList.size(); flag++)
			// From 0 to CustomerList vector size
		{
			if (ID == CustomerList[flag]->getCustomerID())
				// if ID number equals any customer in CustomerList vector
			{
				flag = 0; // flag is equal to 0
				ID = rand() % LONG_MAX + 0; // ID number is selecting randomly again
			}
		}
	}

	return ID; // return ID number of customer
}

/*!
\param username an constant string reference argument
\return true
\return false
*/
bool Menu::checkIfUsernameIsTaken(const string& username)
{
	if (CustomerList.size() == 0) // if CustomerList vector size equals 0
		return true; // return true
	else // if CustomerList vector size different from 0
	{
		for (int flag = 0; flag < CustomerList.size(); flag++)
			// From 0 to CustomerList vector size
		{
			if (CustomerList[flag]->getUsername() == username) // if entered
			 //username is equal to CustomerList vector elements' username
				return false; // return false
		}
	}
	return true; // return true
}

/*!
\param email an constant string reference argument
\return true
\return false
*/
bool Menu::checkIfEmailIsInUse(const string& email)
{
	if (CustomerList.size() == 0) // if CustomerList vector size equals 0
		return true; // return true
	else // if CustomerList vector size different from 0
	{
		for (int flag = 0; flag < CustomerList.size(); flag++)
			// From 0 to CustomerList vector size
		{
			if (CustomerList[flag]->getEmail() == email) // if entered e-mail
				//account is equal to CustomerList vector elements' e-mail account
				return false; // return false
		}
	}
	return true; // return true
}

/*!
\param username an constant string reference argument
\return true
\return false
*/
bool Menu::checkIfPhoneIsInUse(const string& phone)
{
	stringstream ph;
	// Defined stringstream type variable named ph to place phone number
	ph << "+" << phone.substr(0, 2) << "(" << phone.substr(2, 3) << ")-" <<
		phone.substr(5, 7); // write to str + , two elements after it by starting from zero, ' ( '
							// write to str three elements after it by starting from the second element
							// write to str seven elements after it by starting from the fifth element
	if (CustomerList.size() == 0) // if CustomerList vector size equals 0
		return true; // return true
	else // if CustomerList vector size different from 0
	{
		for (int flag = 0; flag < CustomerList.size(); flag++)
			// From 0 to CustomerList vector size
		{
			if (CustomerList[flag]->getPhone() == ph.str()) // if entered phone
			//number is equal to CustomerList vector elements' phone number
				return false; // return false
		}
	}
	return true; // return true
}

/*!
\param no argument
*/
void Menu::clearConsole()
{
	system("cls"); // To clear screen 
}

/*!
\param no argument
*/
void Menu::AddItem()
//This part of code is working for just ADMIN
{
	while (true) // while loop
	{
		clearConsole(); // Call clearConsole function - To clear screen ( console )
		if (a_log || c_log) cout << "Online user : " << temp_user->getName() <<
			"\n\n"; // if a_log or c_log is true to print to screen ' Online user: '
					//and customer's name
		cout << "1. Add from File" << endl
			// To print to screen ' 1. Add from File '
			<< "2. Add from Console" << endl
			// To print to screen ' 2. Add from Console '
			<< "3. Back " << endl // To print to screen ' 3. Back '
			<< "Choose one : "; // To print to screen ' Choose one : '
		getline(cin, m_Choice); // To read choice from entered value by customer
		if (m_Choice == "3") { // if choice is 3
			clearConsole();
			// Call clearConsole function - To clear screen ( console )
			Item_Menu(); // Call for Item_Menu function
		}

		else if (m_Choice == "1" || m_Choice == "2") { // if choice is 1 or choice is 2
			string tmp = m_Choice; // Defined string type variable is equal
								   //to customer choice - for another opened menu
			clearConsole(); // Call clearConsole function - To clear screen ( console )
			if (a_log || c_log) cout << "Online user : " << temp_user->getName()
				<< "\n\n"; // if a_log or c_log is true to print to screen
						   //' Online user: ' and customer's name
			cout << "1. Add Book" << ((tmp == "1") ? " (default filename book.txt)" : "") << endl
				// To print to screen ' 1. Add Book '
				<< "2. Add Magazine" << ((tmp == "1") ? " (default filename magazine.txt)" : "") << endl
				// To print to screen ' 2. Add Magazine '
				<< "3. Add MusicCD" << ((tmp == "1") ? " (default filename musiccd.txt)" : "") << endl
				// To print to screen ' 3. Add MusicCD '
				<< "4. Back " << endl // To print to screen ' 4. Back '
				<< "Choose one : "; // To print to screen ' Choose one : '
			getline(cin, m_Choice); // To read choice from entered value by customer
			clearConsole();
			// Call clearConsole function - To clear screen ( console )

			if (m_Choice == "4") { // if choice is 4
				clearConsole();
				// Call clearConsole function - To clear screen ( console )
				Item_Menu(); // Call for Item_Menu function
			}
			else { // if choice is equal to 1 or 2 or 3

				int t_ID; // integer type variable for ID numbers of products
				string t_name; // string type variable for name of products
				double t_price; // double type variable for price of products
								//specific for MusicCD
				string t_singer; // string type variable for singer of Music CD's
				string t_type; // string type variable for type of Music CD's
							   /*specific for Book*/
				string t_author; // string type variable for author of books
				string t_publisher; // string type variable for publisher of books
				int t_page; // integer variable for total page number of books
							//specific for Magazine
				string t_issue; // string type variable for issue date of magazines
				int t_quantity; // integer variable for quantity of products

				if (m_Choice == "1") { // if choice is equal to 1 ( Adding Book )
					if (tmp == "1") {
						// if tmp choice is equal to 1 ( From File )
						if (OpenFile(fileRead)) { // Open file for reading

							getline(fileRead, getInput); // Read data from file
							while (!fileRead.eof() && getInput != "") {
								// while - if loop reaches end of file or
								//data is equal to "", loop ends
								t_ID = stoi(getInput);
								// ID number of books is reading from file
								//stoi to convert string to integer
								getline(fileRead, getInput);
								// Read data from file
								t_name = getInput;
								// Name of books is reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_price = stod(getInput);
								// Price of books is reading from file
								//stod to convert string to double 
								getline(fileRead, getInput); // Read data from file
								t_author = getInput;
								// Author of books is reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_publisher = getInput;
								// Publisher of books is reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_page = stoi(getInput);
								// Total page number of books is reading from file
								//stoi to convert string to integer
								getline(fileRead, getInput); // Read data from file
								t_quantity = stoi(getInput);
								// Quantity of books is reading from file
								//stoi to convert string to integer
								getline(fileRead, getInput);
								// Read data from file
								Book *bk = new Book(t_ID, t_name, t_price,
									t_author, t_publisher, t_page, t_quantity);
								// To create different Book type object at every turn
								ItemsInSystem.push_back(bk);
								// Each bk object is adding to ItemsInSystem vector at every turn
							}
							cout << "Books are added to system properly!";
							// To print to screen ' Books are added to system properly! '
							fileRead.close(); // Close the file
							_getch(); // _getch() - Stop screen till press any key
						}
					}
					else if (tmp == "2")
						// if tmp choice is equal to 2 - ( Adding Book FROM CONSOLE )
					{
						if (a_log || c_log) cout << "Online user : " <<
							temp_user->getName() << "\n\n"; // if a_log or
						//c_log is true to print to screen ' Online user: '
						//and customer's name
						char* m_temp = new char[67]; // To create dynamic
						//char array to place information's of books
						Book *bk = new Book(0, " ", 0.0, " ", " ", 0, 0);
						// To create book object
						cout << "Book's ID : ";
						// To print to screen ' Book's ID : '
						cin.getline(m_temp, 67);// To read from console
						//entered ID number and write to inside of m_temp
						bk->setID(atoi(m_temp)); // Call setID function,
						//book object's ID number is equal to entered ID number,
						//atoi to convert char to integer
						cout << "Book's Name : ";
						// To print to screen ' Book's Name : '
						cin.getline(m_temp, 67);// To read from console entered
						//name and write to inside of m_temp
						bk->setName(m_temp); // Call setName function,
						//book object's name is equal to entered name
						cout << "Book's Price : ";
						// To print to screen ' Book's Price : '
						cin.getline(m_temp, 67); // To read from console
						//entered price and write to inside of m_temp
						bk->setPrice(atof(m_temp)); // Call setPrice function,
						//book object's price is equal to entered price,
						//atof to convert char to float
						cout << "Author of Book : ";
						// To print to screen ' Author of Book : '
						cin.getline(m_temp, 67); // To read from console
						//entered author name and write to inside of m_temp
						bk->setAuthor(m_temp); // Call setAuthor function, 
						 //book object's author name is equal to entered author name
						cout << "Publisher of Book : ";
						// To print to screen ' Publisher of Book : '
						cin.getline(m_temp, 67); // To read from console
						//entered publisher and write to inside of m_temp
						bk->setPublisher(m_temp); // Call setPublisher function,
						  //book object's publisher is equal to entered publisher
						cout << "Total Page Number of Book : ";
						// To print to screen ' Total Page Number of Book : '
						cin.getline(m_temp, 67); // To read from console entered
						 //total page number and write to inside of m_temp
						bk->setPage(atoi(m_temp)); // Call setPage function, 
						 //book object's total page number is equal to entered
						 //total page number - atoi to convert char to integer
						cout << "Quantity of Book : ";
						// To print to screen ' Quantity of Book : '
						cin.getline(m_temp, 67); // To read from console entered
						//quantity and write to inside of m_temp
						bk->setQuantityOfItem(atoi(m_temp));
						// Call setQuantityOfItem function - book object's
						//quantity is equal to entered quantity,
						//atoi to convert char to integer
						ItemsInSystem.push_back(bk);
						// Each bk object is adding to ItemsInSystem vector
						clearConsole();
						// Call clearConsole function - To clear screen ( console )
						cout << "Book is added to system properly!";
						// To print to screen ' Book is added to system properly! '
					}
				}
				else if (m_Choice == "2") { // if choice is equal to 1 ( Adding Magazine ) 
					if (tmp == "1") {
						// if tmp choice is equal to 1 ( From File )
						if (OpenFile(fileRead)) { // Open file for reading

							getline(fileRead, getInput); // Read data from file
							while (!fileRead.eof() && getInput != "") {
								// while - if loop reaches end of file or
								//data is equal to "", loop ends
								t_ID = stoi(getInput);
								// ID number of magazines is reading from file,
								//stoi to convert string to integer
								getline(fileRead, getInput);
								// Read data from file
								t_name = getInput;
								// Name of magazines is reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_price = stod(getInput);
								// Price of magazines is reading from file,
								//stod to convert string to double
								getline(fileRead, getInput); // Read data from file
								t_issue = getInput;
								// Issue date of magazines is reading from file
								getline(fileRead, getInput); // Read data from file
								t_type = getInput;
								// Type of magazines is reading from file
								getline(fileRead, getInput); // Read data from file
								t_quantity = stoi(getInput);
								// Quantity of magazines is reading from file,
								//stoi to convert string to integer
								getline(fileRead, getInput); // Read data from file
								Magazine *mgz = new Magazine(t_ID, t_name, t_price,
									t_issue, t_type, t_quantity); // To create
								 //different Magazine type object at every turn
								ItemsInSystem.push_back(mgz);
								// Each mgz object is adding to ItemsInSystem
								//vector at every turn
							}
							cout << "Magazines are added to system properly!";
							// To print to screen ' Magazines are added to system properly! '
							fileRead.close(); // Close the file
							_getch(); // _getch() - Stop screen till press any key
						}
					}
					else if (tmp == "2")
						// if tmp choice is equal to 2 - ( Adding Magazine FROM CONSOLE )
					{
						if (a_log || c_log) cout << "Online user : " <<
							temp_user->getName() << "\n\n"; // if a_log or
						//c_log is true to print to screen ' Online user: '
						//and customer's name
						char* m_temp = new char[67]; // To create dynamic
						//char array to place information's of magazines
						Magazine *mgz = new Magazine(0, " ", 0.0, " ",
							" ", 0); // To create magazine object
						cout << "Magazine's ID : ";
						// To print to screen ' Magazine's ID : '
						cin.getline(m_temp, 67); // To read from console
						//entered ID number and write to inside of m_temp
						mgz->setID(atoi(m_temp)); // Call setID function,
						//magazine object's ID number is equal to entered
						//ID number - atoi to convert char to integer
						cout << "Magazine's Name : ";
						// To print to screen ' Magazine's Name : '
						cin.getline(m_temp, 67); // To read from console
						//entered name and write to inside of m_temp
						mgz->setName(m_temp); // Call setName function,
						//magazine object's name is equal to entered name
						cout << "Magazine's Price : ";
						// To print to screen ' Magazine's Price : '
						cin.getline(m_temp, 67); // To read from console
						//entered price and write to inside of m_temp
						mgz->setPrice(atof(m_temp)); // Call setPrice function, 
						 //magazine object's price is equal to entered price,
						 //atof to convert char to float
						cout << "Type of Magazine : ";
						// To print to screen ' Type of Magazine : '
						cin.getline(m_temp, 67); // To read from console
						 //entered type and write to inside of m_temp
						mgz->setType(m_temp); // Call setType function, 
						 //magazine object's type is equal to entered type
						cout << "Issue of Magazine : ";
						// To print to screen ' Issue of Magazine : '
						cin.getline(m_temp, 67); // To read from console
						//entered issue date and write to inside of m_temp
						mgz->setIssue(m_temp); // Call setIssue function,
						 //magazine object's issue date is equal to entered issue date
						cout << "Quantity : "; // To print to screen ' Quantity : '
						cin.getline(m_temp, 67); // To read from console
						 //entered quantity and write to inside of m_temp
						mgz->setQuantityOfItem(atoi(m_temp)); // Call
						 //setQuantityOfItem function - magazine object's
						 //quantity is equal to entered quantity - atoi to
						 //convert char to integer
						ItemsInSystem.push_back(mgz); // Each mgz object is
						 //adding to ItemsInSystem vector
						clearConsole(); // Call clearConsole function
						//To clear screen ( console )
						cout << "Magazine is added to system properly!";
						// To print to screen ' Magazine is added to system properly! '
					}
				}
				else if (m_Choice == "3") { // if choice is equal to 3 ( Adding Music CD ) 
					if (tmp == "1") { // if tmp choice is equal to 1 ( From File )

						if (OpenFile(fileRead)) { // Open file for reading

							getline(fileRead, getInput); // Read data from file
							while (!fileRead.eof() && getInput != "") {
								// while - if loop reaches end of file or
								//data is equal to "", loop ends
								t_ID = stoi(getInput); // ID number of music
								 //CDs is reading from file - stoi to convert
								 //string to integer
								getline(fileRead, getInput);
								// Read data from file
								t_name = getInput;
								// Name of music CDs is reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_price = stod(getInput); // Price of music
								 //CDs is reading from file - stod to convert
								 //string to double
								getline(fileRead, getInput);
								// Read data from file
								t_singer = getInput; // Singer of music CDs
								//is reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_type = getInput; // Type of music CDs is
								 //reading from file
								getline(fileRead, getInput);
								// Read data from file
								t_quantity = stoi(getInput); // Quantity of
								 //music CDs is reading from file - stoi to
								 //convert string to integer
								getline(fileRead, getInput);
								// Read data from file
								MusicCD *cd = new MusicCD(t_ID, t_name,
									t_price, t_singer, t_type, t_quantity);
								// To create different Music CD type object
								//at every turn
								ItemsInSystem.push_back(cd); // Each cd object
								//is adding to ItemsInSystem vector at every turn
							}
							cout << "Music CD's are added to system properly!";
							// To print to screen ' Music CD's are added to
							//system properly! '
							fileRead.close(); // Close the file
							_getch();
							// _getch() - Stop screen till press any key
						}
					}
					else if (tmp == "2") // if tmp choice is equal to 2,
								 //( Adding Music CD FROM CONSOLE )
					{
						if (a_log || c_log) cout << "Online user : " <<
							temp_user->getName() << "\n\n"; // if a_log
						//or c_log is true to print to screen
						//' Online user: ' and customer's name
						char* m_temp = new char[67]; // To create dynamic
						//char array to place information's of magazines
						MusicCD *cd = new MusicCD(0, " ", 0.0, " ", " ", 0);
						// To create Music CD object
						cout << "Music CD's ID : "; // To print to screen
						//' Music CD's ID : '
						cin.getline(m_temp, 67); // To read from console
						 //entered price and write to inside of m_temp
						cd->setID(atoi(m_temp)); // Call setID function,
						 //Music CD object's ID number is equal to entered
						 //ID number - atoi to convert char to integer
						cout << "Music CD's Name : ";
						// To print to screen ' Music CD's Name : '
						cin.getline(m_temp, 67); // To read from console
						//entered price and write to inside of m_temp
						cd->setName(m_temp); // Call setName function
						//Music CD object's name is equal to entered name
						cout << "Music CD's Price : "; // To print to screen
						 //' Music CD's Price : '
						cin.getline(m_temp, 67); // To read from console
						//entered price and write to inside of m_temp
						cd->setPrice(atof(m_temp)); // Call setPrice function
						//Music CD object's price is equal to entered price
						//atof to convert char to float
						cout << "Singer : "; // To print to screen ' Singer : '
						cin.getline(m_temp, 67); // To read from console
						//entered price and write to inside of m_temp
						cd->setSinger(m_temp); // Call setSinger function
						//Music CD object's singer is equal to entered singer
						cout << "Type of CD : ";
						// To print to screen ' Type of CD : '
						cin.getline(m_temp, 67); // To read from console entered
						//price and write to inside of m_temp
						cd->setType(m_temp); // Call setType function,
						 //Music CD object's type is equal to entered type
						cout << "Quantity of CD : "; // To print to screen
						 //' Quantity of CD : '
						cin.getline(m_temp, 67); // To read from console entered
						//price and write to inside of m_temp
						cd->setQuantityOfItem(atoi(m_temp));
						// Call setQuantityOfItem function - Music CD object's
						//quantity is equal to entered quantity - atoi to
						//convert char to integer
						ItemsInSystem.push_back(cd); // Each cd object is
								 //adding to ItemsInSystem vector
						clearConsole();
						// Call clearConsole function - To clear screen ( console )
						cout << "Music CD is added to system properly!";
						// To print to screen ' Music CD is added to
						//system properly! '
					}
				}
				else { // if entered another choice value ( except 1,2,3,4 )
					cout << "Wrong Choice.Please enter 1-4" << endl;
					// To print to screen ' Wrong Choice.Please enter 1-4 '
					_getch(); // _getch() - Stop screen till press any key
				}
			}
		}
		else { // if entered another choice value ( except 1,2,3 )
			cout << "Wrong Choice.Please enter 1-3" << endl;
			// To print to screen ' Wrong Choice.Please enter 1-3 '
			_getch(); // _getch() - Stop screen till press any key
		}
	}
}

/*!
\param no argument
*/
void Menu::DeleteItem() // DeleteItem function for deleting products from system
{
	int quantity; // integer variable for deleted product quantity
	clearConsole(); // Call clearConsole function - To clear screen ( console )
	if (a_log || c_log) cout << "Online user : " << temp_user->getName() <<
		"\n\n"; // if a_log or c_log is true to print to screen
		//' Online user: ' and customer's name
	if (ItemsInSystem.size() == 0) { // if ItemsInSystem vector size equals 0
		cout << "There is no item in system";
		// To print to screen ' There is no item in system '
		_getch(); // _getch() - Stop screen till press any key
		clearConsole();
		// Call clearConsole function - To clear screen ( console )
		return; // return
	}
	m_Choice = Take_Item_Name(ItemsInSystem); // m_Choice is equal to be deleted
	//product and to control whether it placed in system or not
	quantity = Take_Item_Quantity(ItemsInSystem, m_Choice); // quantity is equal
	//to be deleted product quantity and to control whether it placed enough
	//number in system or not
	DESTRUCTOR = Swap_Product(ItemsInSystem, DESTRUCTOR, m_Choice, quantity);
	// Call Swap_Product function - For choosen product and quantity to delete
	DESTRUCTOR.clear(); // To clear inside of DESTRUCTOR vector
	_getch(); // _getch() - Stop screen till press any key
	clearConsole(); // Call clearConsole function - To clear screen ( console )
	Item_Menu(); // Call Item_Menu function
}

/*!
\param no argument.
*/
void Menu::Add_to_Cart()
// Add_to_Cart function for adding to shopping cart the products
{
	int m_quantity; // integer variable for ordered products' quantity

	m_Choice = Take_Item_Name(ItemsInSystem); // m_Choice is equal to be purchased
	//product and to control whether it placed in system or not
	m_quantity = Take_Item_Quantity(ItemsInSystem, m_Choice); // quantity is equal
	//to be purchased product and to control whether it placed enough number
	//in system or not

	m_shopping_cart = Swap_Product(ItemsInSystem, m_shopping_cart, m_Choice,
		m_quantity); // m_shopping_cart is equal to be ordered product and
		//ordered quantity delete from ItemsInSystem and add to m_shopping_cart
	shopCart->cancelOrder(); // Call cancelOrder function for cleaning shopCart
	for (size_t i = 0; i < m_shopping_cart.size(); i++)
	// from 0 to m_shooping_cart vector size
	{
		ProductToPurchase Cart(m_shopping_cart[i],
			m_shopping_cart[i]->getQuantityOfItem()); // To create ProductToPurchase
			//type object for purchased product
		shopCart->addProduct(Cart.getProduct());
		// Call addProduct function and getProduct function
	}
	_getch(); // _getch() - Stop screen till press any key
}

/*!
\param no argument.
*/
void Menu::RemoveFromCart()
// RemoveFromCart function for removing from shopping cart the products
{
	int quantity; // integer variable for removing products' quantity
	cout << "Please Choose Product to Remove?\nPlease enter following "
		<< "informations!!\n"; // To print to screen ' Please Choose
		//Product to Remove? ' and ' Please enter following informations!! '
	_getch(); // _getch() - Stop screen till press any key
	List_Cart();
	// Call List_Cart function for printing content of customer's shopping cart
	_getch(); // _getch() - Stop screen till press any key
	m_Choice = Take_Item_Name(m_shopping_cart); // m_Choice is equal to be deleted
	//product and to control whether it placed in shopping cart or not
	quantity = Take_Item_Quantity(m_shopping_cart, m_Choice); // quantity is equal
	//to be deleted product and to control whether it placed enough number in
	//shopping cart or not
	ItemsInSystem=Swap_Product(m_shopping_cart, ItemsInSystem, m_Choice,quantity);
	// ItemsInSystem is equal to be deleted product and deleted quantity,
	//delete from shopping cart and add to ItemsInSystem
	shopCart->cancelOrder(); // Call cancelOrder function for cleaning shopCart
	for (size_t i = 0; i < m_shopping_cart.size(); i++)
	// from 0 to m_shooping_cart vector size
	{
		shopCart->addProduct(m_shopping_cart[i]);
		// shopCart is equal to remained products in shopping cart
	}
	clearConsole(); // Call clearConsole function - To clear screen ( console )
	cout << "PRODUCT WAS SUCCESFULLY REMOVED FROM SHOPPING CART !" << endl;
	// To print to screen ' PRODUCT WAS SUCCESFULLY REMOVED FROM SHOPPING CART ! '
	_getch(); // _getch() - Stop screen till press any key
}

/*!
\param no argument.
*/
void Menu::Cancel_Order() // Cancel_Order function for cancelling all order
{
	for (int i = 0;i < m_shopping_cart.size();i++)
		// from 0 to m_shooping_cart vector size
		ItemsInSystem=Swap_Product(m_shopping_cart, ItemsInSystem,
		m_shopping_cart[i]->getName(), m_shopping_cart[i]->getQuantityOfItem());
	    // All canceled product is adding to ItemsInSystem vector with
		//calling Swap_Product function
	m_shopping_cart.clear(); // To clear inside of m_shopping_cart vector
	shopCart->cancelOrder(); // To cancel all order - Clear inside of shopCart
}

/*!
\param file an fstream argument.
\return isOpen - true or false
*/
bool Menu::OpenFile(fstream &file) // OpenFile function for opening .txt files
{
	string filename; // string type variable for file's name
	bool isOpen = false; // bool type variable isOpen for controlling whether
	//file opens or not - initial value is false
	cout << "Enter a file name : " << endl;
	// To print to screen ' Enter a file name : '
	getline(cin, filename); // To read from console entered file name and write
	//to inside of filename variable
	while (true) { // while loop

		file.open(filename, ios::in); // Entered file opens read mode
		if (!file) // if file does not exist
		{
			cout << "File couldn't be found !!" << endl;
			// To print to screen ' File couldn't be found !! '
			_getch(); // _getch() - Stop screen till press any key
		}
		else { // file exists
			isOpen= true; // isOpen is equal to true
			break; // break
		}
		clearConsole(); // Call clearConsole function - To clear screen ( console )
		cout << "Please try another file or press 1 to go back" << endl;
		// To print to screen ' Please try another file or press 1 to go back '
		getline(cin, filename); // To read from console entered file name and
		//write to inside of filename variable
		if (filename == "1") break; // if entered value is equal to 1 - break
	}
	return isOpen; // return isOpen value
}

/*!
\param no argument.
*/
void Menu::Place_Order() // Place_Order function for buying all order
{
	cout << "Online user : " << temp_user->getName() << "\n\nPayment Methods\n"
		<< "1. Cash\n2. Check\n3. Credit Card\n4. Back\nChoose one : ";
		// To print to screen ' Online user : '	and customer's name
		// To print to screen ' Payment Methods ' , ' 1.Cash ' , ' 2.Check ',
		//' 3.Credit Card ' , ' 4.Back ' and ' Choose one : '
	getline(cin, m_Choice); // To read choice from entered value by customer
	clearConsole(); // Call clearConsole function - To clear screen ( console )
	if (m_Choice == "1") { // if choice is 1
		method = new Cash(0); // Member object is equal to new Cash payment
		shopCart->setPaymentMethod(method);
		// Call setPaymentMethod for setting payment method
		shopCart->placeOrder(); // Call placeOrder function for buying operation
		shopCart->cancelOrder();
		// Call cancelOrder function for clean shopCart after buying operation
		m_shopping_cart.clear(); // To clean shopping cart after buying operation
	}
	else if (m_Choice == "2") { // if choice is 2
		cout << "Enter Your Check Information " << endl; // To print to screen
		//' Enter Your Check Information '
		cout << "Bank ID : "; // To print to screen ' Bank ID : '
		getline(cin, m_Choice);
		// To read bank ID number from entered value by customer
		method = new Check(0,temp_user->getName(),m_Choice); // Member object
		//is equal to new Check payment
		shopCart->setPaymentMethod(method);
		// Call setPaymentMethod for setting payment method
		shopCart->placeOrder(); // Call placeOrder function for buying operation
		shopCart->cancelOrder(); // Call cancelOrder function for clean shopCart
		//after buying operation
		m_shopping_cart.clear(); // To clean shopping cart after buying operation
	}
	else if (m_Choice == "3") { // if choice is 3
		string Cnumber; // string type variable for credit card number
		string Ctype; // string type variable for type of credit card
		string CexpDate; // string type variable for expiration date of credit card
		cout << "Enter Your Credit Card Information " << endl;
		// To print to screen ' Enter Your Credit Card Information '
		cout << "Number : "; // To print to screen ' Number : '
		getline(cin, Cnumber);
		// To read credit card number from entered value by customer
		cout << "Type : "; // To print to screen ' Type : '
		getline(cin, Ctype);
		// To read credit card type from entered value by customer
		cout << "Expiration Date(dd/mm/yy): ";
		// To print to screen ' Expiration Date(dd/mm/yy): '
		getline(cin, CexpDate); // To read expiration date of credit card from
		//entered value by customer
		method = new CreditCard(0, Cnumber,Ctype,CexpDate);
		// Member object is equal to new CreditCard payment
		shopCart->setPaymentMethod(method);
		// Call setPaymentMethod for setting payment method
		shopCart->placeOrder();// Call placeOrder function for buying operation
		shopCart->cancelOrder(); // Call cancelOrder function for clean shopCart
		//after buying operation
		m_shopping_cart.clear(); // To clean shopping cart after buying operation
	}
	else if (m_Choice == "4") { // if choice is 4
		clearConsole();
		// Call clearConsole function - To clear screen ( console )
		Shopping_Menu(); // Call Shopping_Menu function
	}
	else { // if choice is not equal to 1 or 2 or 3 or 4
		cout << "Wrong Choice.Please enter 1-4" << endl; // To print to screen
		//' Wrong Choice.Please enter 1-4 '
		clearConsole(); // Call clearConsole function - To clear screen ( console )
	}
	_getch(); // _getch() - Stop screen till press any key
}

/*!
\param vector an vector<Product*> argument.
\return name
*/
string Menu::Take_Item_Name(vector<Product*> vector)
// Take_Item_Name function for taking adding or removing product name
{
	bool gate = false; // bool type variable is false initially
	string name; // string type variable for product name
	do // do - while loop
	{
		clearConsole(); // Call clearConsole function - To clear screen ( console )
		if (a_log || c_log) cout << "Online user : " << temp_user->getName()
			<< "\n\n"; // if a_log or c_log is true to print to screen
			//' Online user: ' and customer's name
		if (gate) { // if gate is false
			cout << "Invalid item name please try again or press 0 for " <<
				"main menu\n"; // To print to screen ' Invalid item name please
				//try again or press 0 for main menu '
		}
		cout << "Enter name : "; // To print to screen ' Enter name : '
		getline(cin, name); // To read from console the product name

		if (gate && name == "0") { // if gate is false and name is 0
			clearConsole();
			// Call clearConsole function - To clear screen ( console )
			Main_Menu(); // Call Main_Menu function
		}
		gate = true; // gate is equal to true
	} while (!Check_Item_Name(vector, name)); // while - if product name exist
	//in the system , loop ends

	return name; // return product name
}

/*!
\param vector an vector<Product*> argument.
\param name an string argument.
\return quantity
*/
int Menu::Take_Item_Quantity(vector<Product*> vector, string name)
// Take_Item_Quantity function for taking adding or removing product quantity
{
	int quantity; // integer variable for product quantity
	bool gate = false; // bool type variable is false initially
	do // do - while loop
	{
		clearConsole(); // Call clearConsole function - To clear screen ( console )
		if (a_log || c_log) cout << "Online user : " << temp_user->getName()
			<< "\n\n"; // if a_log or c_log is true to print to screen
			//' Online user: ' and customer's name
		if (gate) // if gate is false
			cout << "Invalid item quantity please try again or press 0 for "
			<< "main menu\n"; // To print to screen ' Invalid item quantity
			//please try again or press 0 for main menu '
		cout << "Enter quantity : "; // To print to screen ' Enter quantity : '
		cin >> quantity; // To read from console the product quantity
		cin.ignore(); // ignore cin
		if (gate && quantity == 0) { // if gate is false and quantity is 0
			clearConsole();
			// Call clearConsole function - To clear screen ( console )
			Main_Menu(); // Call Main_Menu function
		}
		gate = true; // gate is equal to true
	} while (!Check_Item_Quantity(vector, name, quantity)); // while - if product
	//quantity is available in the system, loop ends

	return quantity; // return product quantity
}

/*!
\param vector an vector<Product*> argument.
\param name an string argument.
\return true - according to statement
\return false - according to statement
*/
bool Menu::Check_Item_Name(vector<Product*> vector, string name)
	// Check_Item_Name function is controlling whether product exist in system or not
{
	for (size_t i = 0; i < vector.size(); i++) // from 0 to parameter vector size
	{
		if (name == vector[i]->getName()) return true;
		// if product name exist parameter vector's elements' name , return true
	}
	return false; // return false
}

/*!
\param vector an vector<Product*> argument.
\param name an string argument.
\param quantity an integer argument.
\return true - according to statement
\return false - according to statement
*/
bool Menu::Check_Item_Quantity(vector<Product*> vector, string name, int quantity)
// Check_Item_Quantity function is controlling whether
//product quantity is available or not
{
	for (size_t i = 0; i < vector.size(); i++) // from 0 to parameter vector size
	{
		if (name == vector[i]->getName()) {
			// if product name exist parameter vector's elements' name
			if (vector[i]->getQuantityOfItem() >= quantity && quantity > 0)
				// if product quantity in system is bigger than entered quantity
				//AND entered quantity is bigger than 0
				return true; // return true
			
			return false; // return false
		}
	}
	return false; // return false
}

/*!
\param product an vector<Product*> argument.
\return product
*/
vector<Product*> Menu::SortbyProductType(vector<Product*> product)
// SortbyProductType function for sorting products according to class name
{
	int i, j; // integer variable for loops
	vector<Product*>tmp; // Product type vector for using swap operation

		tmp.push_back(product[0]);
		// Parameter vector's first product is adding to tmp vector
		for (i = 1; i < product.size(); i++) {
			// from 0 to parameter vector product size
			j = i; // j is equal to i
			while (j > 0 && product[j - 1]->getClassName() >
				product[j]->getClassName()) { // if j bigger than 0 AND (j-1).
					//element's class name is bigger than j.element's class name,
					//loop continues
				tmp[0] = product[j]; // tmp vector's first product is equal to
				//product vector's j. product
				product[j] = product[j - 1]; // product vector's j. product is
				//equal to product vector's ( j-1 ). product
				product[j - 1] = tmp[0]; // product vector's ( j-1 ). product is
				//equal to tmp vector's first product
				j--; // Decrement j
			}
		}
	return product; // return product vector
}

/*!
\param first an vector<Product*> reference argument.
\param second an vector<Product*> reference argument.
\param transfer_product an string argument.
\param quantity an integer argument.
\return second
*/
vector<Product*> Menu::Swap_Product (vector<Product*>&first,vector<Product*>&second,
									 string transfer_product, int quantity)
									 // Swap_Product function 
{ // First product vector is equal to be deleted or to be added product and
	//deleted or added quantity - delete from or add to shopping cart and add
	//to or delete from second product vector
	bool flag = false; // bool type variable is false initially
	int add; // integer variable for index

	for (size_t i = 0; i < first.size(); i++) // from 0 to first product vector size
	{ 
		if (first[i]->getName() == transfer_product) {
			// if entered transfer_product exists in first product vector
			first[i]->setQuantityOfItem(first[i]->getQuantityOfItem() - quantity);
			// Call setQuantityOfItem function for deleting ordered quantity
			//from first product vector
			add = i; // add is equal to i
			break; // break
		}
	}

	for (size_t i = 0; i < second.size(); i++)
	// from 0 to second product vector size
	{
		if (second[i]->getName() == transfer_product) {
			// if entered transfer_product exists in second product vector
			second[i]->setQuantityOfItem(second[i]->getQuantityOfItem() + quantity);
			// Call setQuantityOfItem function for adding ordered quantity from
			//to second product vector
			flag = true; // flag is true
			break; // break
		}
	}

	if (!flag) { // if flag is true
	
		if (first[add]->getClassName() == "Book")
		// if first product vector's add value class name is equal to "Book"
		{
			Product* temp = new Book(static_cast<Book*>(first[add]));
			// To create Product type Book object - Call copy constructor function
			temp->setQuantityOfItem(quantity);
			// Call setQuantityOfItem function for setting quantity temp object
			second.push_back(temp); // temp is adding to second product vector
		}
		 if (first[add]->getClassName() == "Magazine")
		// if first product vector's add value class name is equal to "Magazine"
		{
			Product* temp = new Magazine(static_cast<Magazine*>(first[add]));
			// To create Product type Magazine object
			//Call copy constructor function
			temp->setQuantityOfItem(quantity); // Call setQuantityOfItem function
			//for setting quantity temp object
			second.push_back(temp); // temp is adding to second product vector
		}
		else if (first[add]->getClassName() == "MusicCD")
		// if first product vector's add value class name is equal to "MusicCD"
		{
			Product* temp = new MusicCD(static_cast<MusicCD*>(first[add]));
			// To create Product type MusicCD object
			//Call copy constructor function
			temp->setQuantityOfItem(quantity);
			// Call setQuantityOfItem function for setting quantity temp object
			second.push_back(temp); // temp is adding to second product vector
		}
	}
	if (first[add]->getQuantityOfItem() == 0)
		// if first product vector's add value product's quantity is equal to 0
		first.erase(first.begin() + add);
		// To clear inside of first product vector from begin to add value
	cout << "Succesfully Transfered !!!" << endl;
	// To print to screen ' Succesfully Transfered !!! '
	return second; // Return second product vector
}
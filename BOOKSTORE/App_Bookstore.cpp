/**********************
* App_Bookstore.cpp   *
**********************/

/**
* @file App_Bookstore.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @Author Mehmet Tuðlacý (mehmettuglaci@outlook.com)
* @Author Ayhan Alper Tokgöz (ayhanalpertokgoz@outlook.com)
* @date January, 2017
* @Implementation of App_Bookstore
*
* Main part of BookStore
*/

#include "Menu.h" // Call Menu.h header file for using member function
#include <conio.h> // Call for _getch()

using namespace std;

void main() // main function
{
	Menu Store; // Create Menu type object for calling function - named Store
	Store.Main_Menu(); // Call Main_Menu function from Menu.h
	_getch(); // _getch() - Stop screen
}
/**
* @file Product_To_Purchase_Test.cpp
* @Author Ahmet Gökçe Bozan (gkca06@gmail.com)
* @date January, 2017
* @Test of ProductToPurchase Class functions
*
*/

#include "ProductToPurchase.h"//To use ProductToPurchase class
#include"Book.h"//To use Book class
#include"Magazine.h"//To use Magazine class
#include"MusicCD.h"//To use MusicCD

void main()
{
	cout << "+--------------------------+" << endl//print text to screen
		<< "| PRODUCT TO PURCHASE TEST |" << endl//print text to screen
		<< "+--------------------------+" << endl;//print text to screen
	Product *testBook=new Book(12345, "TEST BOOK", 9.99, "TEST AUTHOR", "TEST PUBLISHER", 100, 5);//create testBook
	ProductToPurchase *testPTP=new ProductToPurchase();//create testPTP
	testPTP->setProduct(testBook);//assign testBook to testPTP
	cout << "Get Product Test : \n";//print text to screen
	testPTP->getProduct()->printProperties(-1);//print properties of the added item(testBook)
	testPTP->setQuantity(3);//set quantity of the item
	cout << "Get Quantity Test : " << testPTP->getQuantity() << endl << endl;//print quantity

	Product *testMagazine = new Magazine(12346, "TEST MAGAZINE", 9.9, "TEST ISSUE", "TEST TYPE", 6);//create testMagazine
	testPTP->setProduct(testMagazine);//assign testMagazine to testPTP
	cout << "Get Product Test : \n";//print text to screen
	testPTP->getProduct()->printProperties(-1);//print properties of the added item(testMagazine)
	testPTP->setQuantity(4);//set quantity of the item
	cout << "Get Quantity Test : " << testPTP->getQuantity() << endl << endl;//print quantity

	Product *testMusicCD = new MusicCD(123457,"TEST MUSIC CD",8.99,"TEST SINGER","TEST TYPE",7);//create testMusicCD
	testPTP->setProduct(testMusicCD);//assign testMusicCD to testPTP
	cout << "Get Product Test : \n";//print text to screen
	testPTP->getProduct()->printProperties(-1);//print properties of the added item(testMusicCD)
	testPTP->setQuantity(5);//set quantity of the item
	cout << "Get Quantity Test : " << testPTP->getQuantity() << endl << endl;//print quantity
	system("pause");//pause console
}
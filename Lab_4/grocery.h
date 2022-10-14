/* 
 * Luke Scott
 * Lab 4 Grocery List
 * 9/22/2022
 * Dr. Park
*/

#ifndef GROCERY_H
#define GROCERY_H
#include <fstream>

using namespace std;

struct Item
{
	char name[50];
	int id;
	double price;
	double quantity;
	double tax;
	double subtotal;
	Item *next;
};

Item *createItem(ifstream& );

Item *insertItem(Item *, Item *);

Item *searchItem(Item *, int);

Item *deleteItem(Item *, int);

Item *changeItem(ifstream&, Item *, int);

void printReceipt(Item *);

#endif

/* 
 * Luke Scott
 * Lab 4 Grocery Linked List
 * 9/27/2022
 * Dr. Park
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "grocery.h"

using namespace std;

Item *createItem(ifstream& idata)
{
	int itemID;
	char taxability, type;
	double unit = 0.0;	

	Item *newItem = new Item;
	cout << "\nPlease enter the number of the item you wish to order : \n";
	cin >> itemID;
	while (!idata.eof() && itemID != newItem->id)
	{
		idata >> newItem->id >> newItem->name >> taxability >> type >> newItem->price;

		if (idata.eof())
		{
			idata.clear();
			idata.seekg(0);
			cout << "\nPlease enter a valid item number : \n";
			cin >> itemID;
		}

	}

	idata.clear();
	idata.seekg(0);
	
	newItem->quantity = 0.0;
	newItem->tax = 0.0;
	newItem->subtotal = 0.0;
	newItem->next = NULL;

	if (type == 'p')
	{
		cout << "How many pounds would you like? : ";
		cin >> newItem->quantity;
		newItem->subtotal = newItem->quantity * newItem->price;
		if (taxability == 't')
			newItem->tax = newItem->subtotal * 0.06;
	}

	else if (type == 'n')
	{
		cout << "How many units would you like? : ";
		cin >> newItem->quantity;
		newItem->subtotal = newItem->quantity * newItem->price;
		if (taxability == 't')
			newItem->tax = newItem->subtotal * 0.06;
	}

	else if (type == 's')
	{
		newItem->subtotal = newItem->price;
		if (taxability == 't')
			newItem->tax = newItem->subtotal * 0.06;
	}

	newItem->subtotal += newItem->tax;
	return newItem;
}

Item *insertItem (Item *receipt, Item *newItem)
{
	Item *tmp = receipt;

	if (receipt == NULL)
	{
		receipt = newItem;
		return receipt;
	}

	if (newItem->id < receipt->id)
	{
		newItem->next = receipt;
		receipt = newItem;
		return receipt;
	}

	if (tmp->id == newItem->id)
	{
		cout << "\nItem has already been ordered, try changing the quantity of your selection.\n\n";
		return receipt;
	}

	while (tmp->next != NULL && tmp->next->id < newItem->id)
        {
               if (tmp->id == newItem->id) 
		{
                        cout << "\nCannot insert duplicate ID Number.\n\n";
                        return receipt;
                }
                
                tmp = tmp->next;
        }

	if (tmp->next == NULL)
	{
		tmp->next = newItem;
		return receipt;
	}

	if (tmp->next->id > newItem->id)
	{
		newItem->next = tmp->next;
		tmp->next = newItem;
		return receipt;
	}

	return receipt;
}

Item *searchItem (Item *receipt, int ID)
{
	Item *tmp = receipt;
	while (tmp != NULL)
	{
		if (ID == tmp->id)
		{
			cout << "\n\nWe found the item you ordered :\n\n" << tmp->id << " - " << tmp->name << " - " << tmp->price;
			cout << "\n\nThe quantity you ordered was :\n" << tmp->quantity << endl;

			return tmp;
		}
		tmp = tmp->next;
	}

	cout << "\n\nThis item is not on your receipt.\n\n";
	return NULL;
}

Item *deleteItem(Item *receipt, int ID)
{
	Item *tmp, *tmp1;

	tmp = receipt;

	if (receipt->id == ID)
	{
		receipt = receipt->next;
		delete tmp;
		return receipt;
	}

	while (tmp->next != NULL && tmp->next->id < ID)
	{
		tmp = tmp->next;
	}

	if (tmp->next->id == ID)
	{
		tmp1 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp, tmp1;
		return receipt;
	}

	if (tmp->next == NULL)
		cout << "\n\nThere is no item with that ID number on your receipt.\n\n";

	return receipt;
}

Item *changeItem(ifstream& idata, Item *receipt, int ID)
{
	Item *tmp = searchItem(receipt, ID);
	char taxability, type;

	while (idata.eof() && ID != tmp->id)
	{
		idata >> tmp->id >> tmp->name >> taxability >> type >> tmp->price;

		if (idata.eof())
		{
			idata.clear();
			idata.seekg(0);
			cout << "\nPlease enter a valid item number from your receipt : \n";
			return receipt;
		}
	}

	if (type == 's')
	{
		cout << "This item's quantity cannot be changed, try deleting the item instead.\n\n";
		return NULL;
	}

	cout << "What is new quantity you would like to order :\n\n";
	cin >> tmp->quantity;
	
	tmp->subtotal == tmp->price * tmp->quantity;
	if (taxability == 't')
	{
		tmp->tax = tmp->subtotal * 0.06;
		tmp->subtotal += tmp->tax;
	}

	cout << "\n\nThe item has been changed.\n\n";
	return NULL;
}

void printReceipt(Item *receipt)
{
	Item *newItem = receipt;

	cout << "----------" << setw(10) << "Grocery Reciept" << setw(10) << "-----------" << "\n\n\n";

	cout << "Item Number" << setw(20) << "Item Name" << setw(20) << "Unit" << setw(20) << "Unit Price" 
		<< setw(20) << "Tax" << setw(20) << "Subtotal" << endl;

	cout << "------------" << setw(20) << "----------" << setw(20) << "-----" << setw(20) << "------------"
		<< setw(20) << "----" << setw(20) << "----------" << endl;

	while (newItem != NULL)
	{
		cout << newItem->id << setw(30) << newItem->name << setw(20) << newItem->quantity << setw(20) << newItem->price << setw(20)
			<< fixed << setprecision(2) << newItem->tax << setw(20) << fixed << setprecision(2) << newItem->subtotal << endl;
		newItem = newItem->next;
	}
	cout << "\n\n";
}

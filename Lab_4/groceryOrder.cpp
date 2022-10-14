/* 
 * Luke Soctt
 * Lab 4 Linked Grocery List
 * 9/27/2022
 * Dr. Park
*/

#include "grocery.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void menu();

bool validate(int);

void print(Item *);

int main()
{
	ifstream idata;
	
	int input;

	idata.open("item.txt");

	if (!idata)
	{
		cout << "Error: File cannot be read.";
	}

	Item *receipt = NULL;

	while (input != 6)
	{
		menu();
		cin >> input;
		if (validate(input) == 0)
		{
			cout << "\nPlease enter a valid selection.\n";
			menu();
			cin >> input;
		}
		if (validate(input) == 1)
		{
			if (input == 1)
			{
				Item * newItem = createItem(idata);
				receipt = insertItem(receipt, newItem);
			}

			if (input == 2)
			{
				int id;
				cout << "\nEnter the ID Number of the student you would like to delete : \n";
				cin >> id;
				receipt = deleteItem(receipt, id);
			}

			if (input == 3)
				printReceipt(receipt);

			if (input == 4)
			{
				int id;
				cout << "\nEnter the ID Number of the item you would like to search for from your orer: \n";
				cin >> id;
				searchItem(receipt, id);
			}

			if (input == 5)
			{
				int id;
				cout << "\nEnter the ID Number of the item you would like change in your order: \n";
				cin >> id;
				changeItem(idata, receipt, id);
			}

			if (input == 6)
				print(receipt);
		}
	}

	return 0;
}

void menu()
{
	cout << "\n1. Add an item\n2. Delete an item\n3. Print Receipt\n4. Search a node - search a node and print item information\n5. Change an item in your order.\n6. Quit the program\n";
}

bool validate(int input)
{
	if (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)
		return false;
	return true;
}

void print(Item * receipt)
{
	ofstream odata;
	Item * tmp = receipt;
	double total = 0;

	odata.open("Scott_Luke.txt");

	odata << "----------" << setw(10) << "Grocery Receipt" << setw(10) << "----------" << "\n\n\n";
	odata << "Item Number" << setw(20) << "Item Name" << setw(20) << "Unit" << setw(20) << "Unit Price"
		<< setw(20) << "Tax" << setw(20) << "Subtotal" << endl;
	odata << "------------" << setw(20) << "---------" << setw(20) << "-----" << setw(20) << "-----------" << setw(20)
		<< setw(20) << "----" << setw(20) << "--------" << endl;

	while (tmp != NULL)
	{
		odata << tmp->id << setw(30) << tmp->name << setw(20) << tmp->quantity << setprecision(2) << fixed << setw(20)
			<< tmp->price << setprecision(2) << fixed << setw(20) << tmp->tax << setprecision(2) << fixed
			<< setw(20) << tmp->subtotal << endl;
		total += tmp->subtotal;
		tmp = tmp->next;
	}
	odata << "\n\nTotal" << setw(20) << "-----------" << setprecision(2) << fixed <<setw(10) << total << setw(20) << "-----------" << endl;
}

/* 
 * Luke Scott
 * September 13 2022
 * COSC 220
 * Lab 2
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct ItemList
{
	int ItemNumber;
	char ItemName[50];
	char Tax;
	char Type;
	double Price;
};

void Menu();

double Order(ofstream&);

double AddToCart(ItemList, ofstream&);

double Tax(double, ofstream&);


int main()
{	
	ofstream outdata;

	outdata.open("Scott_Luke.txt");

	outdata << "----------" << setw(10) << "Grocery Reciept" << setw(10) << "----------" << "\n\n\n";

	outdata << "Item Number" << setw(20) << "Item Name" << setw(20) << "Unit" << setw(20) << "Unit Price" 
		<< setw(20) << "Tax" << setw(20) << "Subtotal" << endl;

	outdata << "------------" << setw(20) << "----------" << setw(20) << "-----" << setw(20) << "-----------" 
		<< setw(20) << "----" << setw(20) << "--------" << endl;

	int i = 0, MenuInput;
	double CartTotal = 0;

	Menu();

	while (MenuInput != 2)
	{
		cin >> MenuInput;
		if (MenuInput == 1)
		{
			CartTotal += Order(outdata);
			cout << "Your cart total is: " << fixed << setprecision(2) << CartTotal; 
			Menu();
		}
		if (MenuInput != 1 || MenuInput!= 2)
			cout << "Please enter a 1 or 2 : ";
	}

	outdata << "\n\n" << setw(100) << "Total    :     " << fixed << setprecision(2) << CartTotal;

	return 0;
}

void Menu()
{
	cout << endl;
	cout << "Enter 1 to order an item.\nEnter 2 to quit\n";
}

double Order(ofstream& outdata)
{
	ifstream indata;
//	ofstream outdata;

	double ItemCost = 0;
	ItemList Item;

	indata.open("item.txt");
//	outdata.open("Scott_Luke.txt");
/*
	outdata << "Item Number" << setw(20) << "Item Name" << setw(20) << "Unit" 
		<< setw(20) << "Tax" << setw(20) << "Subtotal" << endl;

	outdata << "------------" << setw(20) << "----------" << setw(20) << "-----" << setw(20) << "-----------" 
		<< setw(20) << "----" << setw(20) << "--------" << endl;
*/
	if (!indata)
	{
		cout << "Error: File cannot be read.";
	}

	cout << "Enter item number that you would like to order.\n";

	int InputItemN = 0;
	cin >> InputItemN;

	while (!indata.eof() && InputItemN != Item.ItemNumber)
	{
		indata >> Item.ItemNumber >> Item.ItemName >> Item.Tax >> Item.Type >> Item.Price;

		if (indata.eof())
		{
			indata.clear();
			indata.seekg(0);
			cout << "Please enter a valid item number. : ";
			cin >> InputItemN;
		}
	}

	//cout << Item.ItemNumber << " " << Item.ItemName << " " << Item.Tax << " " << Item.Type << " " << Item.Price;

	//outdata << Item.ItemNumber << setw(20) << Item.ItemName << setw(20);

	ItemCost = AddToCart(Item, outdata);

	return ItemCost;
}

double AddToCart(ItemList Item, ofstream& outdata)
{

	if (Item.ItemNumber < 100)
		outdata << Item.ItemNumber << setw(31) << Item.ItemName << setw(20);
	else if(Item.ItemNumber >= 100)
		outdata << Item.ItemNumber << setw(30) << Item.ItemName << setw(20);

	double itemtotal = 0, p;
	int u;
	if (Item.Type == 'p')
	{
		cout << "How many pounds would you like? : ";
		cin >> p;
		itemtotal = p * Item.Price;
		outdata << p << setw(20) << Item.Price << setw(20);
		if (Item.Tax == 't')
		{
			itemtotal = Tax(itemtotal, outdata);
			return itemtotal;
		}
		outdata << "0.00" << setw(20) << fixed << setprecision(2) << itemtotal << endl;
		return itemtotal;
	}
	else if (Item.Type == 'n')
	{
		
		cout <<"How many units would you like? : ";
		cin >> u;
		itemtotal = u * Item.Price;
		outdata << u << setw(20) << Item.Price << setw(20);
		if (Item.Tax == 't')
		{
			itemtotal = Tax(itemtotal, outdata);
			return itemtotal;
		}
		outdata << "0.00" << setw(20) << fixed << setprecision(2) << itemtotal << endl; 
		return itemtotal;
	}
	else if (Item.Type == 's')
	{
		itemtotal = Item.Price;
		outdata << "1" << setw(20) << Item.Price << setw(20);
		if (Item.Tax == 't')
		{
			itemtotal = Tax(itemtotal, outdata);
			return itemtotal;
		}
		outdata << "0.00" << setw(20) << fixed << setprecision(2) << itemtotal << endl;
		return itemtotal;
	}	
	return itemtotal;
}

double Tax(double total, ofstream& outdata)
{
	double tax = total * 0.06;
	total += tax;
	outdata << setprecision(2) << tax << setw(20) << fixed << setprecision(2) << total << endl;
	return total;
}

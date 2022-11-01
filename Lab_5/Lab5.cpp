/*
 * Luke Scott
 * Lab 5 Linked List with Classes
 * 10/11/2022
 * Dr. Park
*/

#include <iostream>
#include <iomanip>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

bool validate(int);

void menu();

int main()
{
	LinkedList list;
	int input;	

	do {
		menu();
		cin >> input;

		if (input == 1)
			list.insertNode();

		if (input == 2)
			list.searchNode();

		if (input == 3)
			list.printList();

		if (input == 4)
			list.deleteNode();

		if (!validate(input))
			cout << "\nERROR: Enter a validi input!\n";
	}
	while (input != 5);

	return 0;
}

bool validate(int x)
{
	if (x > 0 && x < 6)
		return true;
	return false;
}

void menu()
{
	cout << "\n-----   Menu   -----\n1. Add a student to the list\n2. Search for a student in the list\n3. Print the list\n4. Delete a student from the list\n5. Quit the program\n\n";
}

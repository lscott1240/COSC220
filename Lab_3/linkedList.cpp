/*
 * Luke Scott
 * Lab 3 Linked List
 * 9/20/2022
 * Dr. Park
*/


#include <iostream>
#include "link.h"

using namespace std;

void menu();

bool validate(int);

int main()
{
	int input;

	Node *list = NULL;

	while (input != 5)
	{
		menu();
		cin >> input;
		if (validate(input) == 0)
		{
			cout << "\nPlease enter a valid selection.\n:";
			menu();
			cin >> input;
		}
		if (validate(input) == 1)
		{
			if (input == 1)
			{
				Node *newNode = createNode();
				list = insertNode(list, newNode);
			}
	
			if (input == 2)
			{
				int id;
				cout << "\nEnter the ID Number of the student you would like to delete : \n";
				cin >> id;
				list = deleteNode(list, id);
			}

			if (input == 3)
			{
				printList(list);
			}

			if (input == 4)
			{
				int id;
				cout << "\nEnter the ID Number of the student you would like to search for : \n";
				cin >> id;
				searchNode(list, id);
			}

			if (input == 5)
			{
				return 0;
			}
		}
	}

	return 0;
}

void menu()
{
	cout << "\n1. Insert a node\n2. Delete a node\n3. Print List\n4. Search a node - search a node and print information for a student\n5. Quit the program\n";
}

bool validate(int input)
{
	if (input != 1 && input != 2 && input != 3 && input != 4 && input != 5)
		return false;
	return true;
}

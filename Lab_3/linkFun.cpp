/*
 * Luke Scott
 * Lab 3 Linked List
 * 9/20/2022
 * Dr. Park
*/

#include <iostream>
#include "link.h"

using namespace std;

Node *createNode()
{
	
	Node *newNode = new Node;
	cout << "\nPlease enter the student's last name, first name, and ID Number : \n";
	cin >> newNode->lastName >> newNode->firstName >> newNode->idNumber;
	newNode->next = NULL;
	return newNode;
}

Node *insertNode (Node *list, Node *newNode)
{
	Node *tmp = list;

	// If the list is empty, insert new Node as first element. // 
	
	if (list == NULL)
	{
		list = newNode;
		return list;
	}

	// If the ID Number of new Node is less than the ID Number of the first node in the list, insert new Node as first element. //

	if (newNode->idNumber < list->idNumber)
	{
		newNode->next = list;
		list = newNode;
		return list;
	}

	if (tmp->idNumber == newNode->idNumber)
	{
		cout << "\nCannot insert duplicate ID Number.\n\n";
		return list;
	}
	// Search the list for a Node with ID Number greater than newNode ID Number. //
	
	while (tmp->next != NULL && tmp->next->idNumber < newNode->idNumber)
	{
		// If ID Number of newNode is equal to ID Number already in list, ERROR: return list, DON'T insert new node. //

		if (tmp->idNumber == newNode->idNumber)
		{
			cout << "\nCannot insert duplicate ID Number.\n\n";
			return list;
		}

		tmp = tmp->next;
	}

	if (tmp->next == NULL)
	{
		tmp->next = newNode;
		return list;
	}

	if (tmp->next->idNumber > newNode->idNumber)
	{
		newNode->next = tmp->next;
		tmp->next = newNode;
		return list;
	}

	return list;

}

Node *searchNode (Node *list, int ID)
{
	while (list != NULL)
	{
		if (ID == list->idNumber)
		{
			cout << "\nWe found a match to student:\n\n" << list->firstName << " " << list->lastName << " : " << list->idNumber << endl;
			return NULL;
		}
		list = list->next;
	}
	cout << "\n\nNo match found.\n\n";
	return NULL;                                                                            
}

Node *deleteNode(Node *list, int ID)
{
	Node *tmp, *tmp1;

	tmp = list;

	if (list->idNumber == ID)
	{
		list = list->next;
		delete tmp;
		return list;
	}
	
	while ((tmp->next != NULL) && (tmp->next->idNumber < ID))
	{
		tmp = tmp->next;
	}
	
	if (tmp->next->idNumber == ID)
	{
		tmp1 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp1;
		return list;
	}

	if (tmp->next == NULL)
		cout << "\n\nThere is no student with that ID in the list.\n\n";

	return list;
}

void printList(Node *list)
{
	cout << "\n\n";
	Node *newNode = list;
	while (newNode != NULL)
	{
		cout << newNode->firstName << " " << newNode->lastName << " : " << newNode->idNumber << endl;
		newNode = newNode->next;
	}
	cout << "\n\n";
}

/*
 * Luke Scott
 * Lab 5 Linked List with Classes
 * 10/11/2022
 * Dr. Park
*/

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList()
{
	list = NULL;
}

Node * LinkedList::createNode ()
{
	// Create new Node //
	Node * newNode = new Node();
	
	// Ask for user input for student information //
	cout << "\nPlease enter the student's last name, first name, and Student ID : \n";
	cin >> newNode->lastName >> newNode->firstName >> newNode->id;

	return newNode;
}

Node * LinkedList::searchLocation (int ID)
{
	// Create new tmp Node to move through list //
	Node * tmp = list;

	/*if (list == NULL)
		return tmp;

	// If list is empty or if newNode id is L.T. first node in list, then return list // 
	if (ID < list->id)
		return tmp;
*/
	if (ID == list->id || list == NULL)
		return list;

	// Move through list to find the correct location for the new Node //
	while (tmp->next != NULL && tmp->next->id < ID)
		tmp = tmp->next;

	return tmp;
}

void LinkedList::insertNode()
{
	// Create new Node using utility function //
	Node * newNode = createNode();

	// If list is empty, insert at front of list //
	if (list == NULL)
	{
		list = newNode;
		return;
	}

	// Find new location //
	Node * tmp = searchLocation(newNode->id);

	// If newNode id is L.T. searchLocation node in list, then insert node before // 
	if (newNode->id < tmp->id)
	{
		newNode->next = list;
		list = newNode;
	}

	// If at end of list, insert node at end //
	else if (tmp->next == NULL && newNode->id != tmp->id)
		tmp->next = newNode;

	// If matching id is found, Duplication Error! //
	else if (newNode->id == tmp->id || newNode->id == tmp->next->id)
	{
		cout << "Duplication Error!\n";
		return;
	}

	else
	{
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}

void LinkedList::deleteNode ()
{	
	// If list is empty, do nothing //
	if (list == NULL)
	{
		cout << "\nList is empty.\n";
		return;
	}

	// Declare an int node id and ask for user input //
	int id;
	cout << "Enter the ID of the student you would like to delete : ";
	cin >> id;

	// Create node and search for it using searchLocation //
	Node * tmp = searchLocation(id);
	Node * deleteNode = NULL;

	// Check if id is = current node or next node.  Return if not //
	if ((tmp->next == NULL && tmp->id != id) || (tmp->id != id && tmp->next->id != id))
	{
		cout << "No match found.\n";
		return;
	}

	// If id is found as first node, delete //
	else if (tmp->id == id)
	{
		deleteNode = tmp;
		list = tmp->next;
		delete deleteNode;
	}

	// If id is found at next node, delete //
	else
	{
		deleteNode = tmp->next;
		tmp->next = tmp->next->next;
		delete deleteNode;
	}
}

void LinkedList::searchNode ()
{
	// Retrieve student id from user input //
	int id;
	cout << "Enter a student ID you would like to search for.\n";
	cin >> id;

	// If list is empty, do nothing //
	if (list == NULL)
	{
		cout << "\nList is empty.\n";
		return;
	}

	// Create node and search for it using searchLocation //
	Node * tmp = searchLocation(id);

	// Check if id is found on current node or next node //
	if ((tmp->next == NULL && tmp->id != id) || (tmp->next->id != id && tmp->id != id))
	{
		cout << "No match found.\n";
		return;
	}

	cout << "\nNode information :\n";
	
	// Check if next node matches id //
	if (tmp->next->id == id)
		tmp->next->printNode();

	// Check if current node matches id //
	else
		tmp->printNode();
}

void LinkedList::printList ()
{
	// If list is empty, tell user //
	if (list == NULL)
	{
		cout << "\nList is empty.\n";
		return;
	}

	// Declare new tmp node equal to list //
	Node * tmp = list;

	cout << "List Information:\n";

	// Print out each node in the list //
	while (tmp != NULL)
	{
		tmp->printNode();
		tmp = tmp->next;
	}	
}

LinkedList::~LinkedList()
{
	Node *tmp, *tmp1;

	tmp = list;
	tmp1 = NULL;

	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		delete tmp1;
	}
}

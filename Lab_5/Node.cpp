/*
 * Luke Scott
 * Lab 5 Linked Lists with Classes
 * 10/11/2022
 * Dr. Park
*/

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

Node::Node()
{
	lastName[0] = ' ';
	firstName[0] = ' ';
	id = 0;
	next = NULL;
}

void Node::printNode()
{
	cout << firstName << " " << lastName << " : " << id << "\n"; 
}

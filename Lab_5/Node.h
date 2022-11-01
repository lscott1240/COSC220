/*
 * Luke Scott
 * Lab 5 Linked List with Classes
 * 10/11/2022
 * Dr. Park
*/

#ifndef NODE_H
#define NODE_H

class Node
{
	private:
		char lastName[20];
		char firstName[20];
		int id;
		Node * next;

	public:
		Node();
		void printNode();
		friend class LinkedList;
};

#endif

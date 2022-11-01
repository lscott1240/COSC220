/* 
 * Luke Scott
 * Lab 5 Linked List with Classes
 * 10/11/2022
 * Dr. Park
*/

#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
	private:
		Node * list;
		Node * searchLocation (int);
		Node * createNode ();
	public:
		LinkedList ();
		~LinkedList();
		void insertNode ();
		void deleteNode ();
		void printList ();
		void searchNode ();
};

#endif

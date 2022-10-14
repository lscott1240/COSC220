/* Luke Scott
 * Lab 3 Linked List
 * 9/20/2022
 * Dr. Park
*/

#ifndef LINK_H
#define LINK_H

struct Node
{
	char lastName[20];
	char firstName[20];
	int idNumber;
	Node *next;
};

Node *createNode();

Node *insertNode(Node *, Node *);

Node *searchNode(Node *, int);

Node *deleteNode(Node *, int);

void printList(Node *);

#endif

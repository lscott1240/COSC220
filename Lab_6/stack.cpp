/*
 * Luke Scott
 * Lab 6 Linked List with Stack
 * 10/25/2022
 * Dr. Park
*/

#include "stack.h"
#include "student.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack(int size)
{
	top = nullptr;
	maxSize = size;
	numNodes = 0;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	if (numNodes == 0)
		return true;
	else
		return false;
}

template <class T>
bool Stack<T>::isFull() const
{
	if (numNodes == maxSize)
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::push (const T d)
{
	if (isFull() == true)
	{
		cout << "\n\nError : Stack is full.\n\n";
	}

	StackNode<T> * newNode = new StackNode<T>;
	newNode->next = top;
	newNode->data = d;
	top = newNode;
	numNodes++;
}

template <class T>
void Stack<T>::pop()
{
	if (isEmpty() == true)
	{
		cout << "\n\nError : Stack is empty.\n\n";
		return;
	}

	StackNode<T> * tmp;
	tmp = top;
	if (top->next == nullptr)
		top = nullptr;
	else
		top = top->next;
	delete tmp;
	numNodes--;
}

template <class T>
T Stack<T>::topStack() const
{
	if (isEmpty() == true)
		cout << "\n\nError : Stack is empty.\n\n";

	return top->data;
}

template <class T>
Stack<T>::~Stack()
{
	StackNode<T> * tmp, * tmp1;

	tmp = top;
	tmp1 = nullptr;

	while (tmp != nullptr)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		delete tmp1;
	}
}


/*
 * Luke Scott
 * Lab 6 Linked List with Stack
 * 10/25/2022
 * Dr. Park
*/

#ifndef STACK_H
#define STACK_H

template <class T>
struct StackNode
{
	T data;
	StackNode<T> *next;
};

template <class T>
class Stack
{
	private:
		StackNode<T> *top;
		int maxSize;
		int numNodes;
	
	public:
		Stack (int = 5);
		~Stack();
		bool isEmpty() const;
		bool isFull() const;
		void push(const T);
		void pop();
		T topStack() const;
};

#endif

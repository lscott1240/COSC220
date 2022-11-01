/*
 * Luke Scott
 * Lab 6 Linked List with Stack
 * 10/25/2022
 * Dr. Park
*/

#include <iostream>
#include "student.h"
#include "stack.h"

using namespace std;

void menu();

bool validateStack(int);

bool validateMenu(int);

int main()
{
	int input;

	do {
		cout << "\nPlease choose the type of stack you want to create.\n1. Student Stack\n2. Integer Stack\n";
		cin >> input;

		if ( input != 1 && input != 2 ) 
			cout << "\nError, please enter a valid input.\n";
	}
	while (!validateStack(input));

	if (input == 1)
	{
		Stack<Students*> sstack;
		do {
			menu();
			cin >> input;

			if (input == 1)
			{
				Students * newStudent = new Students;
				sstack.push(newStudent);
			}

			if (input == 2)
				sstack.pop();

			if (input == 3)
			{
				if ((sstack.isEmpty()) == true)
					cout << "\nError, stack is empty!\n";
				else
				{
					Students * topStudent = sstack.topStack();
					topStudent->printStudent();
				}
			}

			if (!validateMenu(input))
				cout << "\nError, please enter a valid input.\n";
		}
		while (input != 4);
	}

	if (input == 2)
	{
		Stack<int> istack;
		do {
			menu();
			cin >> input;

			if (input == 1)
			{
				int p;
				cout << "\nEnter the number you would like to push :\n";
				cin >> p;
				istack.push(p);
			}

			if (input == 2)
				istack.pop();

			if (input == 3)
			{
				if ((istack.isEmpty()) == true)
					cout << "\nError, stack is empty!\n";
				else
				{
					int x = istack.topStack();
					cout << "\nInteger on the top of stack : " << x << "\n";
				}
			}

			if (!validateMenu(input))
				cout << "\nError, please enter a valid input.\n";
		}
		while (input != 4);
	}

	return 0;
}

void menu()
{
	cout << "\n-----   Menu   -----\n1. push() : Push new data to the top of the stack\n2. pop() : Pop data from the top of the stack\n3. topStack() : Display data on the top of the stack\n4. Quit\n\n";
}

bool validateStack(int input)
{
	if ( input > 0 && input < 3)
		return true;
	return false;
}

bool validateMenu(int input)
{
	if (input > 0 && input < 5)
		return true;
	return false;
}

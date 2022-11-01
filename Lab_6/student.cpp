/*
 * Luke Scott
 * Lab 6 Linked List with Stack
 * 10/25/2022
 * Dr. Park
*/

#include "student.h"
#include <iostream>

using namespace std;

Students::Students()
{
	cout << "\n\nPlease enter student's last name, first name, and ID number :\n";
	cin >> lastName >> firstName >> ID;
}

void Students::printStudent()
{
	cout << "\n\nStudent information : \nID - " << ID << " : " << lastName << ", " << firstName << "\n";
}

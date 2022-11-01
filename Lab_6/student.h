/*
 * Luke Scott
 * Lab 6 Linked List with Stack
 * 10/25/2022
 * Dr. Park
*/

#ifndef STUDENTS_H
#define STUDENTS_H

struct Students
{
	char lastName[20];
	char firstName[20];
	int ID;
	Students();
	void printStudent();
};

#endif

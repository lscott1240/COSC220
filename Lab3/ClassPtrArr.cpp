/*
  ClassPtrArr.cpp
  Dynamically allocated array of pointers to ThreeDimPt objects.
  Lab 8, COSC-220 Spring 2003
  Created: April 7, 2001
  Current: March 26, 2003
*/

#include "ThreeDimPt.h"

#include <iostream>


/* GetNumbPts
 * Prompts for and returns an int value.
 * Enforces the value being positive.
 */
int GetNumbPts();

/* MakeThreeDimPtArray
 * Constructs an array of pointers to ThreeDimPt objects.
 * Each pointer points to a dynamically allocated ThreeDimPt object.
 * The array is of length size.
 * Returns a pointer to the first element of the array.
 */
ThreeDimPt ** MakeThreeDimPtArray(int size);


int main()
{
  int nPts = GetNumbPts();
  int i;
  ThreeDimPt ** ptr; 

  ptr = MakeThreeDimPtArray(nPts);

  // Assign values to the x, y, and z members of each ThreeDimPt 
  // object on the array as follows:
  //   x = i, y = 2 * i,  z = 3 * i

  // Write your code here.

  for (int i = 0; i<nPts; i++)
  {
    ptrArr[i].SetX(i);
    ptrArr[i].SetY(i*2);
    ptrArr[i].SetZ(i*3);

  }

  // Print each of the ThreeDimPt objects in the array.

  // Write your code here.

  for( int i=0; i < nPts; i++)
  {
    cout << ptr[i]->GetX() << " " << ptr[i]->GetY() << " " << ptr[i]->GetZ() << endl;
  }

  return 0;
}

// Write your definition here
ThreeDimPt ** MakeThreeDimPtArray(int size)
{
   ThreeDimPt **arr = new ThreeDimPt*[size];
}


int GetNumbPts()
{
  using namespace std;
  int n;

  cout << "How many points? ";
  cin >> n;

  while (n < 0)
    {
      cout << "Number can't be negative" << endl;
      cout << "How many points? ";
      cin >> n;
    }

  return n;
}




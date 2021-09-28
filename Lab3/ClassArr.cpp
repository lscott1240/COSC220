/*
  ClassArr.cpp
  Dynamically allocated array of ThreeDimPt objects.
  Lab 10, COSC-220
  Created: April 7, 2001
  Current: November 5, 2001
*/

#include "ThreeDimPt.h"

#include <iostream>


/* GetNumbPts
 * Prompts for and returns an int value.
 * Enforces the value being positive.
 */
int GetNumbPts();

/* MakeThreeDimPtArray
 * Constructs an array of ThreeDimPt objects.
 * Array is of length size.
 * Returns a pointer to the first element of the 
 * array.
 */
ThreeDimPt * MakeThreeDimPtArray(int size);

int main()
{
  int nPts = GetNumbPts();
  int i;

  ThreeDimPt * ptArr;  // array of ThreeDimPt objects

  ptArr = MakeThreeDimPtArray(nPts);

  // Set the x, y, and z values of each ThreeDimPt in the
  // array as x = i,  y = 2 * i,  z = 3 * i;
  //
  // Write your code here:

  for (int i = 0; i<nPts; i++)
  {
    ptrArr[i].SetX(i);
    ptrArr[i].SetY(i*2);
    ptrArr[i].SetZ(i*3);

  }

  // Print the array.
  // 
  // Write your code here:

  for (int i = 0; i < nPts; i++)
  {
    cout << ptr[x]->GetX() << " " << ptr[x]->GetY()
  }
  
  return 0;
}


// Uncomment and define the function.
ThreeDimPt * MakeThreeDimPtArray(int size)
{
  ThreeDimPt **arr = new ThreeDimPt*[size];

  return arr;
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

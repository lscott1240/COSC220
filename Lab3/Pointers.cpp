/*
  Pointers.cpp
  COSC-220 Lab 9
  Based on a lab designed by Thomas Horseman

  Thomas Anastasio
  Created: April 8, 2001
  Current: March 20, 2003
*/

#include <iostream>
#include <stddef.h>     // for NULL definition

int main()
{
  using namespace std;

  int int1 = 1, int2 = 2, int3 = 3;
  double dub1 = 1.0, dub2 = 2.0, dub3 = 3.0;
  float flt1 = 1.0f;
  char chr1 = 'a', chr2 = 'b';

  //////////////////////////////////////////////////////////////////	
  // 1. Experiment with storage sizes and addresses of various data
  // types.
  //////////////////////////////////////////////////////////////////	
  //  A.  Add statements to print the addresses of each of the 9
  //  variables declared above and record the addresses. 
  //  B.  Add statements to print the sizes (in bytes) of each of the
  //  9 variables  (use the sizeof operator).
  //  C.  Add statements to print the sizes of the addresses of the 9
  //  variables (again, use the sizeof operator).
	
  //  Write your code here:

  cout << "Variables: " << &int1 << ", " << &int2 << ", " << &int3 << ", " << &dub1 << ", " << &dub2 << ", " << &dub3 << ", " << &flt1 << ", " << &chr1 << ", " << &chr2 << endl; 
  cout << "Size of Variables: " << sizeof(int1) << ", " << sizeof(int2) << ", " << sizeof(int3) << ", " << sizeof(dub1) << ", " << sizeof(dub2) << ", " <<
        sizeof(dub3) << ", " << sizeof(flt1) << ", " << sizeof(chr1) << ", " << sizeof(chr2) << endl;

  cout << "Size of Addresse: " << sizeof(&int1) << ", " << sizeof(&int2) << ", " << sizeof(&int3) << ", " << sizeof(&dub1) << ", " << sizeof(&dub2) << ", " <<
        sizeof(&dub3) << ", " << sizeof(&flt1) << ", " << sizeof(&chr1) << ", " << sizeof(&chr2) << endl;

  cout << "-----------------------------------------" << endl << endl;

  // Record your results here:
  //  
  //  Variable  Address   Size   Address-Size
  //   int1 - 0x7fffffffdf88 - 4 - 8
  //   int2 - 0x7fffffffdf8c - 4 - 8
  //   int3 - 0x7fffffffdf90 - 4 - 8
  //   dub1 - 0x7fffffffdf98 - 8 - 8
  //   dub2 - 0x7fffffffdfa0 - 8 - 8
  //   dub3 - 0x7fffffffdfa8 - 8 - 8
  //   flt1 - 0x7fffffffdf94 - 4 - 8
  //   chr1 - ab - 1 - 8
  //   chr2 - b - 1 - 8


  // How many bytes of storage is allocated for each data type?  How
  // many bytes is allocated for each pointer (address). Notice that
  // the data types are not necessarily the same size, but the
  // pointers are.

  // Memory for data types: INT = 4, DOUBLE = 8, FLOAT = 4, CHAR = 1
  // Memory for address : 8

  // Did the address of the char variables print as you expected?  If
  // not, why not?   You can force the printed output to be
  // interpreted as a pointer by coercing it (casting) to void* like
  // this:
  //    cout << (void *) &chr1;
  //
  // Run the program again, using the coercion for the char
  // pointers. Record your data.

  // Write your modified code here:

  cout << "Variables: " << &int1 << ", " << &int2 << ", " << &int3 << ", " << &dub1 << ", " << &dub2 << ", " << &dub3 <<
       ", " << &flt1 << ", " << (void *) &chr1 << ", " << (void *) &chr2 << endl; 
  cout << "Size of Variables: " << sizeof(int1) << ", " << sizeof(int2) << ", " << sizeof(int3) << ", " << sizeof(dub1) << ", " << sizeof(dub2) << ", " <<
        sizeof(dub3) << ", " << sizeof(flt1) << ", " << sizeof(chr1) << ", " << sizeof(chr2) << endl;

  cout << "Size of Addresse: " << sizeof(&int1) << ", " << sizeof(&int2) << ", " << sizeof(&int3) << ", " << sizeof(&dub1) << ", " << sizeof(&dub2) << ", " <<
        sizeof(&dub3) << ", " << sizeof(&flt1) << ", " << sizeof(&chr1) << ", " << sizeof(&chr2) << endl;

  cout << "-----------------------------------------" << endl << endl;


  // Record your results here:
  //  
  //  Variable  Adress  Size  Address-Size
  //     chr1 - 0x7fffffffdf86 - 1 - 8
  //     chr2 - 0x7fffffffdf87 - 1 - 8

  //////////////////////////////////////////////////////////////////	
  // 2. Experiment with pointer variables.
  //////////////////////////////////////////////////////////////////	
  //   A. Declare pointer vaiables intPtr1, intPtr2, intPtr3, dubPtr1,
  //   dubPtr2, dubPtr3, fltPtr1, chrPtr1, and chrPtr2 so that they
  //   can be used to point to the  appropriate variables.  Assign the
  //   address of the appropriate variable to them and print their
  //   values.  (The char pointers will have to be coerced as before
  //   for printing).

  //  Write your code here:
	
  int *intPtr1, *intPtr2, *intPtr3; double *dubPtr1, *dubPtr2, *dubPtr3; float *fltPtr1; char *chrPtr1, *chrPtr2;

  intPtr1 = &int1;
  intPtr2 = &int2;
  intPtr3 = &int3;
  dubPtr1 = &dub1;
  dubPtr2 = &dub2;
  dubPtr3 = &dub3;
  fltPtr1 = &flt1;
  chrPtr1 = &chr1;
  chrPtr2 = &chr2;

  cout << "Pointer Variable Values: " << intPtr1 << ", " << intPtr2 << ", " << intPtr3 << ", " << dubPtr1 << ", " << dubPtr2 << ", " << dubPtr3 << 
        ", " << fltPtr1 << ", " << (void *) chrPtr1 << ", " << (void *) chrPtr2 << endl; 
  
  cout << "-----------------------------------------" << endl << endl;

  //  Report your results here:
  // 
  //   Pointer  Printed
  //  Variable   Value
  //   intPtr1 - 0x7fffffffdf88
  //   intPtr2 - 0x7fffffffdf8c
  //   intPtr3 - 0x7fffffffdf90
  //   dubPtr1 - 0x7fffffffdf98
  //   dubPtr2 - 0x7fffffffdfa0
  //   dubPtr3 - 0x7fffffffdfa8
  //   fltPtr1 - 0x7fffffffdf94
  //   chrPtr1 - 0x7fffffffdf86
  //   chrPtr2 - 0x7fffffffdf87

  // How do the values of the pointers compare to the values of the
  // addresses you got in the previous experiment?

  // 
  // The values of the pointers are identical to the values of the address in the previous experiment
  //
  //

  //////////////////////////////////////////////////////////////////	
  //  3. Experiments with NULL pointers and with dereferencing
  //////////////////////////////////////////////////////////////////	
  //   A. Assign NULL to fltPtr1, then print the value of fltPtr1.
  //   B. Accessing the storage locations through the relevant
  //   pointers, assign the following values and print them.
  //       int1  12
  //       int2  22
  //       dub1  10.1
  //       dub2  20.2
  //       flt1  30.3

  // Write your code here:

  // fltPtr1 = NULL;
  // cout << "Value of Float Pointer 1 (After NULL change): " << fltPtr1 << endl;

  // *intPtr1 = 12;
  // *intPtr2 = 22;
  // *dubPtr1 = 10.1;
  // *dubPtr2 = 20.2;
  // *fltPtr1 = 30.3;

  // cout << "New Values :" << *intPtr1 << ", " << *intPtr2 << ", " << *dubPtr1 << ", " << *dubPtr2 << ", " << *fltPtr1 << endl;

  // Your program should have terminated with a run-time error.
  // What error was reported?
  //
  // Error : Segmentation Fault
  //
  // Why did it occur?
  //
  // fltPtr1 was assigned to NULL, then encountered an error when trying to reassign the value to 30.3 

  //   C.  Fix the problem and repeat.

  // Write your code here:

  *intPtr1 = 12;
  *intPtr2 = 22;
  *dubPtr1 = 10.1;
  *dubPtr2 = 20.2;
  *fltPtr1 = 30.3;

  cout << "New Values :" << *intPtr1 << ", " << *intPtr2 << ", " << *dubPtr1 << ", " << *dubPtr2 << ", " << *fltPtr1 << endl;

  cout << "-----------------------------------------" << endl << endl;

  //////////////////////////////////////////////////////////////////	
  //  4. Experiments with pointer arithmetic
  //////////////////////////////////////////////////////////////////	
  //    A.  Print the values of intPtr2, (intPtr2+1) and
  //    (intPtr2-1). Did you get what you expected? 

  // Write your code here:
	
  cout << "Pointer Arithmetic : " << *intPtr2 << ", " << (*intPtr2+1) << ", " << (*intPtr2-1) << endl;

  // Write your explanation here:
  //
  // Yes the program peformed as expected
  //
  //
  //
  //


  //   B. Print the value of intPtr1.
  //   C. Use the increment operator to increment intPtr1. 
  //   D. Print the value of intPtr1 again.  
  //   E. Print the value of the memory location pointed to by
  //   intPtr1.  Explain what is happening.
	
  // Write your code here:

  cout << "Int 1 : " << *intPtr1 << endl;
  *intPtr1++;
  cout << "Increment Operator on Int 1: " << *intPtr1 << endl;
  cout << "Int 1 Pointer : " << intPtr1 << endl;

  // Write your explanation here.
  //
  // The Increment operator is adding 10 to int1 instead of 1
  // 
  //

  cout << "-----------------------------------------" << endl << endl;


  //////////////////////////////////////////////////////////////////	
  //  5. Experiments with dynamic allocation
  //////////////////////////////////////////////////////////////////	
  //   A.  Use the new operator to dynamically allocate an integer.
  //   B.  Assign the number 6000 to the new location.
  //   C.  Print the address of this new location.
  //   D.  Print the value stored in the new location.
  //   E.  Comment on the address of the new location compared to the
  //   addresses seen in part 2.

  //  Write your code here:

  int * dynamicint;
  dynamicint = new int;
  *dynamicint = 6000;
  cout << "Dynamic Int : " << dynamicint << ", " << *dynamicint << endl;
  
  //  Write your results and comments here:
  //  
  //  new location address = 0x55555556c2c0
  //  contents of new location = 6000

  //  Comment: The address looks different than the addresses found in previous experiments as it contains "5's" instead of "f's"
  //  

  //  F.  Use the new operator to allocate an array of size 10 of
  //  doubles.  Fill the array with 10.0,20.0,...100.0 and print the array.

  // Write your code here:

  double arr[10] = { 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0};
  double *ptr = &arr[10];

  cout << "Dynamic Array: ";

  for (int i = 0; i < 10; i++)
  {
      cout << *ptr;
      ptr++;
  }

  //double arr[10];
  //double value = 10.0;

  //for (int i = 0; i < 10; i++)
  //{
  //  arr[i] = value;
  //  cout << arr[i] << endl;
  //  value+=10.0;
  //}

  return 0;
}

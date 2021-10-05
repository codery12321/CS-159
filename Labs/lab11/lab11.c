/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. dong296@purdue.edu
*  3. sui13@purdue.edu
*
*  Lab #:11
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab:Tuesday, 9:30, Virtual
*
*  Program Description:Given a positive integer representing the size of an integer data set, accept input of that data set, and display the data sorted by odd and even with one additional requirement, an index that stores an odd value at the time of input must store an odd value after the data is sorted with the same requirement holding for even values.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getSize();
void getArray(int*, int);
void sort(int*, int);
int isEven(int);
void printArray(int*, int);

int main()
{
  int *data; //data from user
  int size; //size of array

  size  = getSize();
  data = (int*)malloc(sizeof(int) * size);
  getArray(data, size);
  sort(data,size);
  printArray(data, size);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getSize
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:get size of the input array
*
***************************************************************************/
int getSize()
{
  int size; // the size of the input array

  printf("Enter data set size -> ");
  scanf("%d", &size);

  return size;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getArray
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int *data //data from user input
*    2.int size //size from user input
*
*  Function Description:get the array from user input
*
***************************************************************************/
void getArray(int *data, int size)
{
  int i; //for loop iterator

  printf("Enter %d integer values -> ", size);
  for(i = 0; i < size; i++)
  {
    scanf("%d", data + i);
  }

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:sort
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int *data //data from user input
*    2.int size // size of array
*
*  Function Description:loop through the array, find the next even/odd number, swap it with the current if that element is smaller repeat until the end of the array, repeat for the next element
*
***************************************************************************/
void sort(int *data, int size)
{

  int i; // for pointer
  int j; // for pointer
  int k; // for pointer
  int temp; // temporary variable

  for (i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
    //if the current element is larger the next element, swap them
      for(k = j + 1; k < size; k++)
      {
        if (* (data + j) > * (data + k) && isEven(* (data + j)) == isEven(* (data + k)))
        {
          temp = * (data + j);
          * (data + j) = * (data + k);
          * (data + k) = temp;
        }
      }
    }
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:isEven
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int num //number to be evaluated
*
*  Function Description:check if value is even or not
*
***************************************************************************/
int isEven(int num)
{
  int temp; // temporary variable

  if (num % 2 == 0)
  {
    temp = 1;
  }
  else
  {
    temp = 0;
  }
  return temp;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:printArray
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int *data //data from user input
*    2.int size // size of array
*
*  Function Description:print the output
*
***************************************************************************/
void printArray(int *data, int size)
{
  int i; // for pointer

  printf("\nFinal data set order:");
  for (i = 0; i < size; i++)
  {
    printf(" %d", * (data + i));
  }

  printf("\n");

}

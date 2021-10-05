/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. sui13@purdue.edu
*  3. dong296@purdue.edu (delete line if no third partner)
*
*  Lab #:08
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: Given a range of non-negative decimal (base 10) integer values as input display the smallest value in the range that represent the largest change in odd and even digits when comparing the decimal value to its octal (base 8) equivalent.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Function Declarations
void input(int *, int *);
int largestChange (int, int, int, int *, int *);
int compareChanges(int, int, int*);
int compareDigit(int, int);
int conversion(int);
int checkDigit(int,int);
void output(int, int, int, int, int, int);

int main()
{
  // Local Declarations (User Input Variables)
  int start; //user-input starting decimal value
  int end; //user-input ending decimal value
  int changeO; // the largest odd digit change:
  int changeE; // the largest even digit change:
  int decimalO; // the decimal value where the largest change is
  int decimalE; // the decimal value where the largest change is
  int octalO; // the octal value where the largest change is
  int octalE; // the octal value where the largest change is

  // Executable Statements (Calculate Structure)
  input(&start, &end);
  changeO = largestChange(start, end, 0, &decimalO, &octalO);
  changeE = largestChange(start, end, 1, &decimalE, &octalE);
  output(changeO, decimalO, octalO, changeE, decimalE, octalE);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *tempStart // the starting decimal
*    2. int *tempEnd // the ending decimal
*
*  Function Description: input neccessary values.
*
***************************************************************************/
void input(int *tempStart, int *tempEnd)
{
  int start; //start number
  int end; //end number

  do
  {
    printf("\nEnter starting decimal value -> ");
    scanf("%d", &start);
    if(start < 0)
    {
      printf("\nError! The decimal value provided should be non-negative.\n\n");
    }
  } while (start < 0);

  do
  {
    printf("Enter ending decimal value -> ");
    scanf("%d", &end);

    if(end <= start)
    {
      printf("\nError! The ending value provided should be greater than %d\n\n", start);
    }
  } while (end <= start);

  *tempStart = start;
  *tempEnd = end;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:largestChange
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int start //the start number
*    2.int end //the end number
*    3.int option //odd or even number
*    4.int *returnDecimal //the decimal with largest change
*    5.int *returnOctal //the octal with largest change
*
*  Function Description: return the numbers with the largest change
*
***************************************************************************/
int largestChange (int start, int end, int option, int *returnDecimal, int *returnOctal)
{
  int i; //value to start with and ++ every time
  int iOctal; //octal value of i
  int change; //change in even / odd digits
  int largest; //largest change in even / odd digits
  int old; //old octal value
  int new; // the octal value
  int update; //is 1 if needs an update; is 0 if doesnt need update

  update = 0;
  largest = 0;

  for (i = start; i < end; i++)
  {
    iOctal = conversion(i);
    old = checkDigit(i,option);  //number of odd / even digit for i
    new = checkDigit(iOctal,option); //number of odd / even digit for iOctal
    change = compareDigit(old, new);
    largest = compareChanges(largest, change, &update); //get the largest even / odd digit change

    if (update == 1) // get corresponding base 10 / base 8 values of that largest digit change
    {
      *returnDecimal = i;
      *returnOctal = iOctal;
    }
  }

  return largest;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: conversion
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int input //the input from user
*
*  Function Description: convert decimal to octal
*
***************************************************************************/
int conversion(int input)
{
  int output; //output base 8 value
  int n; //temporary number used to count digits

  output = 0;
  n = 0;

  //parameter: input is user input number
  while (input != 0 )
  {

    output += ( input % 8 ) * pow (10, n);
    input /= 8;
    n++;

  }

  return output;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:checkDigit
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int num //the number of digits
*    2.int option // whether it is odd or even
*
*  Function Description:check the number of digits
*
***************************************************************************/
int checkDigit(int num, int option)
{
  // Local Declarations (User Input Variables)
  int digitO; // number of digits that are even
  int digitE; // number of digits that are odd
  int digit; // number of digits
  int temp; // temporary integer used to store variable

  digitO = 0;
  digitE = 0;

  //Get User Input
  while(num > 0)
  {
    temp = num % 10;

    if(temp % 2 == 1)
    {
      digitO++;
    }

    else
    {
      digitE++;
    }
    num /= 10;
  }

  digit = digitO * (1 - option) + digitE * option;

  // Return Output
  return digit;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:compareDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int old //old number
*    2.int new //new number
*
*  Function Description:compare the change in digits
*
***************************************************************************/
int compareDigit(int old, int new)
{
  //option: is 0 when comparing odd and 1 when comparing even
  // Local Declarations (User Input Variables)
  int change; //change in the number of odd/even digits between input/output

  // Executable Statements (Calculate Structure)
  change = old - new;

  // Return Output
  return change;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:compareChanges
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int change //change for old value
*    2.int newChange //change for new value
*    3.int *update //update whether largest change is changed or not
*
*  Function Description:compare the changes between different numbers
*
***************************************************************************/
int compareChanges(int change, int newChange, int *update)
{
  int largestChange; //the largest change that appeared

  if (abs(newChange) > abs(change))
  {
    largestChange = newChange;
    *update = 1;
  }

  else
  {
    largestChange = change;
    *update = 0;
  }

  return largestChange;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:output
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int changeO // change for odd number
*    2.int decimalO //decimal for odd number
*    3.int octalO //octal for odd number
*    4.int changeE //change for even number
*    5.int decimalE //decimal for even number
*    6.int octalE //octal for even number
*
*  Function Description:print the output
*
***************************************************************************/
void output(int changeO, int decimalO, int octalO, int changeE, int decimalE, int octalE)
{
  // Print output
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-Change-Decimal-=-Octal-");
  printf("\nLargest odd digit change:      ");

  if(changeO > 0)
  {
    printf(" ");
  }

  printf("%d", changeO);
  printf("%8d", decimalO);
  printf("%8d", octalO);
  printf("\nLargest even digit change:     ");

  if(changeE > 0)
  {
    printf(" ");
  }

  printf("%d", changeE);
  printf("%8d", decimalE);
  printf("%8d\n", octalE);

}

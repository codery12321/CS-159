/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*
*  Lab Exam #: 03
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: Given as input a numbering system for odd integers and a second numbering system for even integers, accept as input a data set consisting of up to 20 non-negative integers and display the conversion of all odd numbers to the specified numbering system followed by the even numbers to the second specified numbering system.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>
#define SET 20

//Function Declarations
int getDataLength(int []);
int getEven();
int getOdd();
void loopInput(int [], int, int, int);
int conversion(int, int);
void dispBase(int);

int main()
{
  //Local Declarations
  int dataSet[SET] = {}; //data set for integers
  int baseO; //base for odd numbers
  int baseE; //base for even numbers

  //Statements
  baseO = getOdd();
  baseE = getEven();
  loopInput(dataSet, getDataLength(dataSet), baseO, baseE);
  return 0;

}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:dispBase
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int base // the base from user input
*
*  Function Description: displays the name of the base for output
*
***************************************************************************/
void dispBase(int base)
{
  switch(base)
  {
    case 2: printf("Binary");
            break;
    case 3: printf("Ternary");
            break;
    case 4: printf("Quaternary");
            break;
    case 5: printf("Quinary");
            break;
    case 6: printf("Senary");
            break;
    case 7: printf("Septenary");
            break;
    case 8: printf("Octal");
            break;
    case 9: printf("Nonary");
            break;
  }
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:loopInput
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dataset[] \\ dataset from input
*    2.int length \\gets the length of the array
*    3.int baseO \\base of odd number
*    4.int baseE \\base of even number
*
*  Function Description: loops the input from user and goes through the array
*
***************************************************************************/
void loopInput(int dataSet[], int length, int baseO, int baseE)
{
  int index; //for loop iterator
  int numO; //number of odd integers
  int numE; //number of even integers

  numO = 0;
  numE = 0;

  printf("\n");
  dispBase(baseO);
  printf(" values: ");
  for(index = 0; index < length; index++)
  {
    if ((dataSet[index] % 2) == 1) //for odd number
    {
      printf("%d ", conversion(dataSet[index], baseO));
      numO++;
    }
  }
  if (numO == 0)
  {
    printf("None");
  }

  printf("\n");
  dispBase(baseE);
  printf(" values: ");
  for(index = 0; index < length; index++) //for even number
  {
    if((dataSet[index] % 2) == 0)
    {
      printf("%d ", conversion(dataSet[index], baseE));
      numE++;
    }
  }
  if (numE == 0)
  {
    printf("None");
  }
  printf("\n");
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:conversion
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int value \\ value that needs conversion
*    2.int base \\base the number needs to be converted to
*
*  Function Description:converts a number to the desired base
*
***************************************************************************/
int conversion(int value, int base)
{
  int newNum; //new converted number
  int num; //iterator

  newNum = 0;
  num = 0;

  while(value != 0)
  {
    newNum += ( value % base ) * pow (10, num);
    value /= base;
    num++;
  }
  return newNum;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:getEven
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:get base for even numbers from user input
*
***************************************************************************/
int getEven()
{
  int even; //base for even numbers

  do
  {
    printf("Enter base for even numbers -> ");
    scanf("%d", &even);

    if(even < 2 || even > 9)
    {
      printf("\nError! Base must be in the range from 2 to 9.\n");
      printf("\n");
    }

  } while(even < 2 || even > 9);

  return even;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:getOdd
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:gets base for odd numbers from user input
*
***************************************************************************/
int getOdd()
{
  int odd; //base for odd numbers

  do
  {
    printf("Enter base for odd numbers -> ");
    scanf("%d", &odd);

    if(odd < 2 || odd > 9)
    {
      printf("\nError! Base must be in the range from 2 to 9.\n");
      printf("\n");
    }

  } while(odd < 2 || odd > 9);

  return odd;

}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:getDataLength
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dataSet[] \\get input from user for integers
*
*  Function Description:gets input from user for integers
*
***************************************************************************/
int getDataLength(int dataSet[])
{
  int len; //length of array
  len = 0;

  printf("Enter up to %d integer values -> ", SET);

  while((len <= SET - 1) && (dataSet[len - 1] != -1))
  {
    scanf("%d", &dataSet[len]);

    len++;
  }
  return(len - 1);

}

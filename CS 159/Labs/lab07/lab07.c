/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. dong296@purdue.edu
*  3. sui13@purdue.edu (delete line if no third partner)
*
*  Lab #:7
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description:Given a non-negative decimal (base 10) integer value as input display the octal (base 8) equivalent.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

//Function Declarations
int input();
int compareDigit(int,int,int,int,int);
int conversion(int);
int checkDigit(int,int);
void output();

int main()
{
    // Local Declarations (User Input Variables)
    int decimal; //decimal input from user
    int octal; //octal number converted from decimal
    int oldO;  //old odd numbers
    int oldE; //old even numbers
    int newO; //new odd numbers
    int newE; //new even numbers
    int changeO; //change in odd numbers
    int changeE; //change in even numbers

    // Executable Statements (Calculate Structure)
    decimal = input();
    octal = conversion(decimal);
    oldO = checkDigit(decimal, 0);
    oldE = checkDigit(decimal, 1);
    newO = checkDigit(octal, 0);
    newE = checkDigit(octal, 1);
    changeO = compareDigit(oldE, oldO, newE, newO, 0);
    changeE = compareDigit(oldE, oldO, newE, newO, 1);
    output(octal, changeO, changeE);

    return 0;
}

int input()
{
  // Local Declarations (User Input Variables)
  int num;

  //Get User Input
  do
  {
    printf("Enter decimal value -> ");
    scanf("%d",&num);
    if(num < 0)
    {
      printf("Error! The decimal value provided should be non-negative.\n\n");
    }
  }while(num < 0);

  // Print Output
  return num;
}

int compareDigit(int oldE, int oldO, int newE, int newO, int option)
{
    // Local Declarations (User Input Variables)
    int change;

    // Executable Statements (Calculate Structure)
    change = (oldO - newO) * (1 - option) + (oldE - newE) * option;

    // Return Output
    return change;
}

int conversion(int input)
{
  printf("\nbase 10: %d", input);
  int output = 0;
  int n = 0;

  //parameter: input is user input number
  while ( input != 0 )
  {
    output += ( input % 8 ) * pow (10, n);
    input /= 8;
    n++;
  }

  printf("\nbase 8: %d", output);
  return output;
}

int checkDigit(int num, int option)
{
    // Local Declarations (User Input Variables)
    int digitO;
    int digitE;
    int digit;
    int temp;

    //Get User Input
    digitO = 0;
    digitE = 0;
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

void output(int octal, int changeO, int changeE)
{
    // Print output
    printf("\nOctal equivalent: %d", octal);
    printf("\nOdd digit change: ");
    if(changeO > 0)
    {
        printf("+");
    }
    else if(changeO < 0)
    {
        printf("-");
    }
    printf("%d", changeO);
    printf("\nEven digit change: ");
    if(changeE > 0)
    {
        printf("+");
    }
    else if(changeE < 0)
    {
        printf("-");
    }
    printf("%d\n", changeE);
}

/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #:07
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:tuesday, 9:30, Virtual
*
*  Program Description:The user will specify whether they wish the data set to be (1) sorted by the count of the number of applications of the above steps necessary to reach 1 or (2) sorted by the first power of two encountered during the application of the above steps. The positive integer data set will follow that includes at least one value with a maximum number of 35 values.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>
#define SET 35

//Function Declarations
int getDataLength(int []);
int getOption();
void dispOption(int);
int option1(int, int);
int option2(int, int);
void final(int, int, int []);
void calc(int, int [], int);

int main()
{
  //Local Declarations
  int dataSet[SET] = {}; //dataSet from user input
  int option; //option from user input
  int len; //length of dataset

  //Statements
  option = getOption();
  len = getDataLength(dataSet);
  final(option, len, dataSet);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:final
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int option //option from user input
*    2.int length //length of dataset
*    3.int dataSet[] //array of data set
*
*  Function Description:the final loop that outputs the answer
*
***************************************************************************/
void final(int option, int length, int dataSet[])
{
  printf("\n");
  printf("Sorted data by ");
  dispOption(option);
  printf(": ");
  calc(option, dataSet, length);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:calc
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int option //option from user input
*    2.int dataSet[] //array of dataset
*    3.int length //length of dataset
*
*  Function Description:calculate the given data
*
***************************************************************************/
void calc(int option, int dataSet[], int length)
{
  int i; //for loop iterator
  int array[length]; //array of calculated numbers
  int temp; //temporary number
  int j; //for loop iterator
  int pass; //number of passes
  int temp2; //temporary number

  if (option == 1)
  {
    for (pass = 0; pass < length; pass++)
    {
      array[pass] = option1(dataSet[pass], length);
    }
  }
  else
  {
    for (pass = 0; pass < length; pass++)
    {
      array[pass] = option2(dataSet[pass], length);
      printf("%d ", array[pass]);
    }
  }

  for(i = 0; i < length; ++i)
  {
    for(j = i + 1; j < length; ++j)
    {
      //sort in ascending order
      if(array[i] > array[j])
      {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        temp2 = dataSet[i];
        dataSet[i] = dataSet[j];
        dataSet[j] = temp2;
      }

      //if the calculated number is the same
      //order it in ascending order of the original dataset
      else if((array[i] == array[j]) && (dataSet[i] > dataSet[j]))
      {
        temp2 = dataSet[i];
        dataSet[i] = dataSet[j];
        dataSet[j] = temp2;
      }
    }
  }

  for (i = 0; i < length; i++)
  {
    printf("%d ", dataSet[i]);
  }
  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:option2
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int value //value to be calculated
*    2.int length // length of dataSet
*    3. N/A
*
*  Function Description:calculates option 2
*
***************************************************************************/
int option2(int value, int length)
{
  int exp; //exponent

  while(value > 1)
  {
    exp = log2(value);
    printf("%d ", exp);

    if ((value % 2) == 1) //odd number
    {
      value = (value * 3) + 1;
    }
    else //even number
    {
      value /= 2;
    }

    if(ceil(exp) == floor(exp))
    {
      value = 0;
    }
  }

  return (pow(2, exp));
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:option1
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int value //value to be calculated
*    2.int length //length of dataset
*
*  Function Description:caluates value for option 1
*
***************************************************************************/
int option1(int value, int length)
{
  int count; //the number of times the while loop has done

  count = 0;

  while(value > 1)
  {
    if ((value % 2) == 1) //odd number
    {
      value = (value * 3) + 1;
    }
    else //even number
    {
      value /= 2;
    }
    count++;
  }
  return count;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:dispOption
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int option //option from user input
*
*  Function Description:display the option in words
*
***************************************************************************/
void dispOption(int option)
{
  switch(option)
  {
    case 1: printf("count");
            break;
    case 2: printf("power of two");
            break;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getOption
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:get option from user input and return it
*
***************************************************************************/
int getOption()
{
  int option; //option from user input
  do
  {
    printf("Enter sorting option (1) count or (2) power of two -> ");
    scanf("%d", &option);

    if(option > 2 || option < 1)
    {
      printf("\nError! Enter option 1 or 2 only!\n");
      printf("\n");
    }
  } while(option > 2 || option < 1);

  return option;
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
*    1.int dataSet[] //dataset from user
*
*  Function Description:get dataSet from user and count the number of inputs
*
***************************************************************************/
int getDataLength(int dataSet[])
{
  int len; //length of array
  int i; //for loop iterator

  len = 0;

  printf("Enter up to %d integer values -> ", SET);

  for(i = 0; i < SET; i++)
  {
    scanf("%d", &dataSet[len]);
    len++;
    if(dataSet[i] == -1)
    {
      i = SET;
      len--;
    }
  }
  return (len);
}

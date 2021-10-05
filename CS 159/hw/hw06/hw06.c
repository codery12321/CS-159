/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #:06
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:Tuesday, 9:30, Virtual
*
*  Program Description:Given as input the value of ten years and a desired day of the week, display the months within the first year that begin on the desired day of the week. For the second through the tenth year the desired day of the week will continually be incremented.
*
***************************************************************************/
#include<stdio.h>
#define SET 10

//Function Declarations
void getYears(int[]);
int getDay();
void dispDay(int);
void checkDay(int, int);
int leapYear(int);
int getDayDec31(int);
void loopYears(int []);

int main()
{
  //Local Declarations
  int dataSet[SET] = {}; //the dataset from user input

  //Statements
  getYears(dataSet);
  loopYears(dataSet);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:dispDay
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int day //desired day
*
*  Function Description: display the name of the day
*
***************************************************************************/
void dispDay(int day)
{

  switch (day)
  {
    case 0: printf("Sunday");
            break;
    case 1: printf("Monday");
            break;
    case 2: printf("Tuesday");
            break;
    case 3: printf("Wednesday");
            break;
    case 4: printf("Thursday");
            break;
    case 5: printf("Friday");
            break;
    case 6: printf("Saturday");
            break;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:loopYears
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dataSet[] //the dataset we got from user input
*
*  Function Description: iterate through the years
*
***************************************************************************/
void loopYears(int dataSet[])
{
  int index; //for loop iterator
  int day; //desired day

  day = getDay();

  printf("\nDesired day of the week: ");
  dispDay(day);
  printf("\n");

  for(index = 0; index < SET; index++)
  {
    checkDay(dataSet[index], (day++) % 7);
  }

  printf("\n");

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:checkDay
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int year //year from user input
*    2.int day //the desired day
*
*  Function Description:check if the day of the start of each month matches the desired day
*
***************************************************************************/
void checkDay(int year, int day)
{
  int dec31; //day of december 31st from previous year
  int passedDays; //total number of days passed since dec 31
  int leap; //if it is a leap year or not
  int plus1; //variable for leap year

  dec31 = getDayDec31(year);
  leap = leapYear(year);

  printf("Months in %d starting on ", year);
  dispDay(day);
  printf(": ");

  for(passedDays = 0; passedDays < leap; passedDays++)
  {
    plus1 = leap - 365;

    if(((dec31 + passedDays) % 7) == day)
    {
      if(passedDays == 1)
      {
        printf("January ");
      }
      else if(passedDays == 32)
      {
        printf("February ");
      }
      else if(passedDays == (60 + plus1))
      {
        printf("March ");
      }
      else if(passedDays  == (91 + plus1))
      {
        printf("April ");
      }
      else if(passedDays == (121 + plus1))
      {
        printf("May ");
      }
      else if(passedDays == (152 + plus1))
      {
        printf("June ");
      }
      else if(passedDays == (182 + plus1))
      {
        printf("July ");
      }
      else if(passedDays == (213 + plus1))
      {
        printf("August ");
      }
      else if(passedDays == (244 + plus1))
      {
        printf("September ");
      }
      else if(passedDays == (274 + plus1))
      {
        printf("October ");
      }
      else if(passedDays == (305 + plus1))
      {
        printf("November ");
      }
      else if (passedDays == (365 + plus1))
      {
        printf("December ");
      }
    }
  }
  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:leapYear
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int years //year from user input
*
*  Function Description:check if the year is a leap year
*
***************************************************************************/
int leapYear(int years)
{
  int totalDays; //the total number of days in this year (366 if leap, 365 if not)

  if(((!(years % 4) && (years % 100)) || !(years % 400)) == 1)
  {
    totalDays = 366;
  }
  else
  {
    totalDays = 365;
  }

  return totalDays;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getDayDec31
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int years //the year from user input
*
*  Function Description:get the day of december 31st from previous year
*
***************************************************************************/
int getDayDec31(int years)
{
  int dayDec31; //day of december 31st from previous year

  dayDec31 = ((((years - 1) * 365 + ((years - 1) / 4) - ((years - 1) / 100) + ((years - 1) / 400))) % 7);

  return dayDec31;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getDay
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:get day of week from user
*
***************************************************************************/
int getDay()
{
  int day; //day from user input

  do
  {
    printf("Enter day of week number -> ");
    scanf("%d", &day);

    if(day < 0 || day > 6)
    {
      printf("\nError! Day of the week must be 0 to 6.\n");
      printf("\n");
    }
  } while(day < 0 || day > 6);

  return day;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getYears
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dataSet[] //get the dataset from user and set it as an array
*
*  Function Description:get input of years from user
*
***************************************************************************/
void getYears(int dataSet[])
{
  int index; //for loop iterator

  printf("Enter %d years [1700 - 2100] -> ", SET);

  for(index = 0; index < SET; index++)
  {
    scanf("%d", &dataSet[index]);
  }
}

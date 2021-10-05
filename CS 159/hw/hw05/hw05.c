/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #:05
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:Tuesday, 9:30, Virtual
*
*  Program Description:Given as input the year and occurrence number determine when that week begins and ends. Display the week which will begin on the same day of the week as January 1st of the specified year.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

//Funciton declaration
int inputYear();
int inputOccur();
int getDayJan1(int);
void dispStart(int, int, int, int);
void dispEnd(int, int, int, int);
int daysPassed(int);
int getMonth(int, int);
int getDate(int, int, int);
int newDaysPassed(int);
int checkYear(int, int);
void dispCalendar(int, int, int, int);
int daysInMonth(int, int);

int main()
{
  //Local Declarations
  int year; //year from user input
  int occurence; //occurence from user input
  int dayJan1; //day of week of Jan 1st
  int totalDays; //total days passed since Jan1
  int desiredMonth; //the month the desired day is in
  int date; //the date of the desired day
  int newTotalDays; //the total days passed since Jan 1 for end of week
  int newDesiredMonth; //the month the end of week is on
  int newDate; //the new date the week ends on
  int newYear; //the new year the week ends on
  int daysMonth; //the number of days in the desired month

  //Statements
  year = inputYear();
  occurence = inputOccur();

  dayJan1 = getDayJan1(year);
  totalDays = daysPassed(occurence);
  desiredMonth = getMonth(totalDays, year);
  date = getDate(desiredMonth, totalDays, year);

  newTotalDays = newDaysPassed(occurence);
  newDesiredMonth = getMonth(newTotalDays, year);
  newDate = getDate(newDesiredMonth, newTotalDays, year);
  newYear = checkYear(newTotalDays, year);
  daysMonth = daysInMonth(desiredMonth, year);

  dispStart(dayJan1, desiredMonth, date, year);
  dispEnd((dayJan1 + 6) % 7, newDesiredMonth, newDate, newYear);
  dispCalendar(desiredMonth, dayJan1, date, daysMonth);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:dispCalendar
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int month //desired month
*    2.int dayJan1 //day of week of jan 1
*    3.int date //date of desired day
*    4.int daysInMonth //days in the desired month
*
*  Function Description:display the calendar
*
***************************************************************************/
void dispCalendar(int month, int dayJan1, int date, int daysInMonth)
{
  int i; //for loop
  int j; //for loop

  printf("\n         "); //print the spaces before the month

  //selection structure to display month name
  switch(month)
  {
    case 1: printf(" January ");
            break;
    case 2: printf("February ");
            break;
    case 3: printf("  March ");
            break;
    case 4: printf("  April ");
            break;
    case 5: printf("   May ");
            break;
    case 6: printf("  June ");
            break;
    case 7: printf("  July ");
            break;
    case 8: printf(" August ");
            break;
    case 9: printf("September ");
            break;
    case 10: printf(" October ");
             break;
    case 11: printf("November ");
             break;
    case 12: printf("December ");
             break;
  }

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Sun Mon Tue Wed Thu Fri Sat\n");

  //for loop for determining where to start
  for(i = 0; i < dayJan1; i++) //for the spaces before first date
  {

    printf("    ");

  }

  printf(" ");

  //for loop to determine what to print
  for( j = 1; j <= 7; j++) //iterate through seven days
  {

    if (date <= daysInMonth) //print date if the week ends in the same month
    {
      printf("%-3d", date);
    }

    else //restart from 1 if the week ends in another month
    {
      date = 1;
      printf("%-3d", date);
    }

    if (++i > 6) //if day is a saturday print a new line
    {
      i = 0;
      printf("\n");
      printf(" ");
    }

    else //if not saturday print spaces
    {
      printf(" ");
    }

    date++;

  }

  //print new line after calendar
  printf("\n");

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:daysInMonth
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int month //desired month
*    2.int year //year from user input
*
*  Function Description:count the days in the desired month
*
***************************************************************************/
int daysInMonth(int month, int year)
{
  int leapYear; //if current year is leap year
  int days; //the days in the current month

  //calculate if the current year is a leap year and return 1 or 0
  leapYear = ((!(year % 4) && (year % 100)) || !(year & 400));

  //selection structure to determin the days in the desired month
  if (month == 2)
  {

    if (leapYear == 0)
    {
      days = 28;
    }

    else
    {
      days = 29;
    }
  }

  else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
  {
    days = 30;
  }

  else
  {
    days = 31;
  }

  return days;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:newDaysPassed
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int occurence //occurrence from user
*
*  Function Description:get days passed since jan 1 for end of week line
*
***************************************************************************/
int newDaysPassed(int occurence)
{

  return (7 + ((occurence - 1) * 7)); //the total days passed at end of week

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:dispEnd
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int day //day of jan 1
*    2.int month //desired month
*    3.int date //date of desired day
*    4.int year //year from user input
*
*  Function Description:display the end of week line
*
***************************************************************************/
void dispEnd(int day, int month, int date, int year)
{

  printf("End of week: ");

  //selection structure to determine which day it is
  switch(day)
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

  //selection structure to determine which month it is
  switch(month)
  {
    case 1: printf(" January ");
            break;
    case 2: printf(" February ");
            break;
    case 3: printf(" March ");
            break;
    case 4: printf(" April ");
            break;
    case 5: printf(" May ");
            break;
    case 6: printf(" June ");
            break;
    case 7: printf(" July ");
            break;
    case 8: printf(" August ");
            break;
    case 9: printf(" September ");
            break;
    case 10: printf(" October ");
             break;
    case 11: printf(" November ");
             break;
    case 12: printf(" December ");
             break;
  }

  printf("%d, %d\n", date, year);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dispStart
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int day // day of jan 1st
*    2.int month //the desired month
*    3.int date //the date of the day
*    4.int year // year from user
*
*  Function Description:display the line for start of week
*
***************************************************************************/
void dispStart(int day, int month, int date, int year)
{

  printf("\nStart of week: ");

  //selection structure to determine which day it is
  switch(day)
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

  //selection structure to determine which month it is
  switch(month)
  {
    case 1: printf(" January ");
            break;
    case 2: printf(" February ");
            break;
    case 3: printf(" March ");
            break;
    case 4: printf(" April ");
            break;
    case 5: printf(" May ");
            break;
    case 6: printf(" June ");
            break;
    case 7: printf(" July ");
            break;
    case 8: printf(" August ");
            break;
    case 9: printf(" September ");
            break;
    case 10: printf(" October ");
             break;
    case 11: printf(" November ");
             break;
    case 12: printf(" December ");
             break;
  }

  printf("%d, %d\n", date, year);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:checkYear
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int daysPassed //days passed since jan 1
*    2.int year // year from user
*
*  Function Description: check if the week ends in another year
*
***************************************************************************/
int checkYear(int daysPassed, int year)
{
  int newyear; //check the year for end of week
  int leapYear; //if the current year is leap year

  //calculate if the current year is a leap year and return 1 or 0
  leapYear = ((!(year % 4) && (year % 100)) || !(year & 400));

  //check if the week ends in a new year
  if (leapYear == 0) //if year is not leap year
  {

    if (daysPassed > 365)
    {
      newyear = year + 1; //go to next year
    }
    else
    {
      newyear = year; //remain in the same year
    }
  }

  else //if year is leap year
  {
    if (daysPassed > 366)
    {
      newyear = year + 1; //go to next year
    }
    else
    {
      newyear = year; //remain in the same year
    }
  }

  return newyear; //return the year the week ends on

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getDate
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int month //the month day is one
*    2.int daysPassed //the number of days passed since jan 1st
*    3.int year //the year from user
*
*  Function Description:get the date of the desired day
*
***************************************************************************/
int getDate(int month, int daysPassed, int year)
{
  int date; //date of desired day
  int leapYear; //if current year is leap year

  //calculate if the current year is a leap year and return 1 or 0
  leapYear = ((!(year % 4) && (year % 100)) || !(year & 400));

  //selection structure for the date

  //January
  if (month == 1)
  {
    if (daysPassed < 366)
    {
      date = daysPassed;
    }
    else
    {
      date = daysPassed - 365;
    }

  }

  //February
  else if (month == 2)
  {
    date = daysPassed - 31;
  }

  //March
  else if (month == 3)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 59;
    }
    else
    {
      date = daysPassed - 60;
    }
  }

  //April
  else if (month == 4)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 90;
    }
    else
    {
      date = daysPassed - 91;
    }
  }

  //May
  else if (month == 5)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 120;
    }
    else
    {
      date = daysPassed - 121;
    }
  }

  //June
  else if (month == 6)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 151;
    }
    else
    {
      date = daysPassed - 152;
    }
  }

  //July
  else if (month == 7)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 181;
    }
    else
    {
      date = daysPassed - 182;
    }
  }

  //August
  else if (month == 8)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 212;
    }
    else
    {
      date = daysPassed - 213;
    }
  }

  //September
  else if (month == 9)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 243;
    }
    else
    {
      date = daysPassed - 244;
    }
  }

  //October
  else if (month == 10)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 273;
    }
    else
    {
      date = daysPassed - 274;
    }
  }

  //November
  else if (month == 11)
  {
    if (leapYear == 0)
    {
      date = daysPassed - 304;
    }
    else
    {
      date = daysPassed - 305;
    }
  }

  //December
  else
  {
    if (leapYear == 0)
    {
      date = daysPassed - 334;
    }
    else
    {
      date = daysPassed - 335;
    }
  }

  return date;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getMonth
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int daysPassed //number of days passed since jan 1st
*    2.int year //year from user
*
*  Function Description:determine which month the day is on
*
***************************************************************************/
int getMonth(int daysPassed, int year)
{
  int isLeapYear; //if current year is leap year
  int month; //the desired month

  //calculate if the current year is a leap year and return 1 or 0
  isLeapYear = ((!(year % 4) && (year % 100)) || !(year & 400));

  if (isLeapYear == 0)
  {
    if ((daysPassed >= 0) && (daysPassed <= 31))
    {
      month = 1;
    }
    else if ((daysPassed >= 32) && (daysPassed <= 59))
    {
      month = 2;
    }
    else if ((daysPassed >= 60) && (daysPassed <= 90))
    {
      month = 3;
    }
    else if ((daysPassed >= 91) && (daysPassed <= 120))
    {
      month = 4;
    }
    else if ((daysPassed >= 121) && (daysPassed <= 151))
    {
      month = 5;
    }
    else if ((daysPassed >= 152) && (daysPassed <= 181))
    {
      month = 6;
    }
    else if ((daysPassed >= 182) && (daysPassed <= 212))
    {
      month = 7;
    }
    else if ((daysPassed >= 213) && (daysPassed <= 243))
    {
      month = 8;
    }
    else if ((daysPassed >= 244) && (daysPassed <= 273))
    {
      month = 9;
    }
    else if ((daysPassed >= 274) && (daysPassed <= 304))
    {
      month = 10;
    }
    else if ((daysPassed >= 305) && (daysPassed <= 334))
    {
      month = 11;
    }
    else if ((daysPassed >= 335) && (daysPassed <= 365))
    {
      month = 12;
    }
    else
    {
      month = 1;
    }

  }
  else
  {
    if ((daysPassed >= 0) && (daysPassed <= 31))
    {
      month = 1;
    }
    else if ((daysPassed >= 32) && (daysPassed <= 60))
    {
      month = 2;
    }
    else if ((daysPassed >= 61) && (daysPassed <= 91))
    {
      month = 3;
    }
    else if ((daysPassed >= 92) && (daysPassed <= 121))
    {
      month = 4;
    }
    else if ((daysPassed >= 122) && (daysPassed <= 152))
    {
      month = 5;
    }
    else if ((daysPassed >= 153) && (daysPassed <= 182))
    {
      month = 6;
    }
    else if ((daysPassed >= 183) && (daysPassed <= 213))
    {
      month = 7;
    }
    else if ((daysPassed >= 214) && (daysPassed <= 244))
    {
      month = 8;
    }
    else if ((daysPassed >= 245) && (daysPassed <= 274))
    {
      month = 9;
    }
    else if ((daysPassed >= 275) && (daysPassed <= 305))
    {
      month = 10;
    }
    else if ((daysPassed >= 306) && (daysPassed <= 335))
    {
      month = 11;
    }
    else if ((daysPassed >= 336) && (daysPassed <= 366))
    {
      month = 12;
    }
    else
    {
      month = 1;
    }

  }

  return month; //return the integer for the desired month

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: daysPassed
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int occurence //occurence from user
*
*  Function Description:get the total days passed since jan 1st
*
***************************************************************************/
int daysPassed(int occurence)
{

  return (1 + ((occurence - 1) * 7)); //return the days passed

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getDayJan1
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int year //year from user
*
*  Function Description: get the day Jan 1st is on
*
***************************************************************************/
int getDayJan1(int year)
{

  return ((1 + ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400))) % 7);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputOccur
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:get input from user
*
***************************************************************************/
int inputOccur()
{
  int occurence; //occurence from user input

  printf("Enter occurrence number -> ");
  scanf("%d", &occurence);

  return occurence;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputYear
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:get input from user
*
***************************************************************************/
int inputYear()
{
  int year; //year from user input

  printf("Enter year number -> ");
  scanf("%d", &year);

  return year;

}

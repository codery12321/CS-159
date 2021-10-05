/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #:04
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:Tuesday, 9:30, Virtual
*
*  Program Description:this program will determine the corresponding date when given the year, day of week number and occurrence number.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

//Function Declarations
int getYear();
int getDay();
int getOccur();
void disp(int daysinYear, int week1days, int occurence, int day, int year, int month);
int daysYear(int day, int year);
int dayJan1(int year);
int month(int, int days, int dayJan1, int daysinYear, int occurence);
int week1(int, int);

int main()
{
  //Local Declarations
  int year; //year from user input
  int day; //day from user input
  int occurence; //occurence from user input
  int daysinYear; //number of days in the year
  int dayjan1; //day of January 1st
  int desiredMonth; //the desired month
  int week1days; //the number of days in week 1

  //Statements
  year = getYear();
  day = getDay();
  occurence = getOccur();

  daysinYear = daysYear(day, year);
  dayjan1 = dayJan1(year);
  week1days = week1(dayjan1, day);

  desiredMonth = month(week1days, day, dayjan1, daysinYear, occurence);

  disp(daysinYear, week1days, occurence, day, year, desiredMonth);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:week1
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dayJan1 - the day January 1st is on
*    2.int days - the day from user input
*
*  Function Description: this function calculates the total number of days in the first week
*
***************************************************************************/
int week1(int dayJan1, int days)
{
  int daysweek1; //days in week 1
  if (dayJan1 < days)
  {
    daysweek1 = (1 + (days - dayJan1) % 7); //formula for if day of january 1st is smaller than day
  }
  else if (dayJan1 == days)
  {
    daysweek1 = 0; //the difference between the days is 0
  }
  else
  {
    daysweek1 = ((days - dayJan1) + 7); //formula for if first day of january is larger than day
  }

  return daysweek1;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:month
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int week1days - the number of days in week 1
*    2.int days - the day from user iniput
*    3.int dayJan1 - the day January 1st is on
*    4.int daysinYear - the total number of days in the year
*    5.int occurence - the occurence from user input
*
*  Function Description:this function calculates the desired month
*
***************************************************************************/
int month(int week1days, int days, int dayJan1, int daysinYear, int occurence)
{
  int totalDaysPassed; // the total number of days passed since january 1st
  int Cmonth; //current month

  if (daysinYear == 365) //make sure it's not a leap year
  {
    totalDaysPassed = 7 * (occurence - 1); //calculate days excluding first week
    totalDaysPassed += week1days; //add days in first wee with full weeks

    if ((totalDaysPassed < 32 && totalDaysPassed >= 1) || totalDaysPassed == 0)
    {
      Cmonth = 1;
    }
    else if (totalDaysPassed < 60 && totalDaysPassed >= 32)
    {
      Cmonth = 2;
    }
    else if (totalDaysPassed < 91 && totalDaysPassed >= 60)
    {
      Cmonth = 3;
    }
    else if (totalDaysPassed < 121 && totalDaysPassed >= 91)
    {
      Cmonth = 4;
    }
    else if (totalDaysPassed < 152 && totalDaysPassed >= 121)
    {
      Cmonth = 5;
    }
    else if (totalDaysPassed < 182 && totalDaysPassed >= 152)
    {
      Cmonth = 6;
    }
    else if (totalDaysPassed < 213 && totalDaysPassed >= 182)
    {
      Cmonth = 7;
    }
    else if (totalDaysPassed < 244 && totalDaysPassed >= 213)
    {
      Cmonth = 8;
    }
    else if (totalDaysPassed < 274 && totalDaysPassed >= 244)
    {
      Cmonth = 9;
    }
    else if (totalDaysPassed < 305 && totalDaysPassed >= 274)
    {
      Cmonth = 10;
    }
    else if (totalDaysPassed < 335 && totalDaysPassed >= 305)
    {
      Cmonth = 11;
    }
    else
    {
      Cmonth = 12;
    }
  }

  else
  {
    totalDaysPassed = 7 * (occurence - 1); //calculate the total days excluding the first week
    totalDaysPassed += week1days; //add the days in first week to full weeks

    if ((totalDaysPassed < 32 && totalDaysPassed >= 1) || totalDaysPassed == 0)
    {
      Cmonth = 1;
    }
    else if (totalDaysPassed < 61 && totalDaysPassed >= 32)
    {
      Cmonth = 2;
    }
    else if (totalDaysPassed < 92 && totalDaysPassed >= 61)
    {
      Cmonth = 3;
    }
    else if (totalDaysPassed < 122 && totalDaysPassed >= 92)
    {
      Cmonth = 4;
    }
    else if (totalDaysPassed < 153 && totalDaysPassed >= 122)
    {
      Cmonth = 5;
    }
    else if (totalDaysPassed < 183 && totalDaysPassed >= 153)
    {
      Cmonth = 6;
    }
    else if (totalDaysPassed < 214 && totalDaysPassed >= 183)
    {
      Cmonth = 7;
    }
    else if (totalDaysPassed < 245 && totalDaysPassed >= 214)
    {
      Cmonth = 8;
    }
    else if (totalDaysPassed < 275 && totalDaysPassed >= 245)
    {
      Cmonth = 9;
    }
    else if (totalDaysPassed < 306 && totalDaysPassed >= 275)
    {
      Cmonth = 10;
    }
    else if (totalDaysPassed < 336 && totalDaysPassed >= 306)
    {
      Cmonth = 11;
    }
    else
    {
      Cmonth = 12;
    }

  }

  return Cmonth;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:daysYear
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int day - the day from user input
*    2.int year - year from user input
*
*  Function Description:this function calculate the total number of days in the current year
*
***************************************************************************/
int daysYear(int day, int year)
{
  //Local Declarations
  int dayYear; //gets the number of days in the current year

  //Statements
  dayYear = (365 + ((!(year % 4) && (year % 100)) || !(year % 400))); //calculate the total days in the year

  return dayYear; //return the number of days

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:dayJan1
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int year - year from user input
*
*  Function Description: this function calculates the day january 1st is on
*
***************************************************************************/
int dayJan1(int year)
{

  return ((1 + ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400))) % 7);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: disp
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int occurence - the occurence from user iniput
*    2.int day - the day from user input
*    3.int year - the year from user input
*    4.int month - the month of desired date
*    5.int date - the desired date
*
*  Function Description:this function displays the output
*
***************************************************************************/
void disp(int daysinYear, int week1days, int occurence, int day, int year, int month)
{
  printf("\nDesired occurrence #%d of ", occurence); //print the occurence

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

  printf(" in %d: ", year); //print the year

  switch(month)
  {
    case 1: printf("January");
            break;
    case 2: printf("February");
            break;
    case 3: printf("March");
            break;
    case 4: printf("April");
            break;
    case 5: printf("May");
            break;
    case 6: printf("June");
            break;
    case 7: printf("July");
            break;
    case 8: printf("August");
            break;
    case 9: printf("September");
            break;
    case 10: printf("October");
            break;
    case 11: printf("November");
            break;
    case 12: printf("December");
            break;
  }

  {
    int totalDaysPassed; //total number of days passed

    if (daysinYear == 365) //for normal years
    {

      totalDaysPassed = 7 * (occurence - 1); //calculate the full weeks
      totalDaysPassed += week1days; //add week 1 days with full weeks

      switch(month)
      {
        case 1:  printf(" %d\n", totalDaysPassed + 1);
                 break;
        case 2:  printf(" %d\n", totalDaysPassed - 31);
                 break;
        case 3:  printf(" %d\n", totalDaysPassed - 58);
                 break;
        case 4:  printf(" %d\n", totalDaysPassed - 90);
                 break;
        case 5:  printf(" %d\n", totalDaysPassed - 120);
                 break;
        case 6:  printf(" %d\n", totalDaysPassed - 151);
                 break;
        case 7:  printf(" %d\n", totalDaysPassed - 181);
                 break;
        case 8:  printf(" %d\n", totalDaysPassed - 212);
                 break;
        case 9:  printf(" %d\n", totalDaysPassed - 243);
                 break;
        case 10:  printf(" %d\n", totalDaysPassed - 273);
                  break;
        case 11:  printf(" %d\n", totalDaysPassed - 303);
                  break;
        case 12:  printf(" %d\n", totalDaysPassed - 334);
                  break;
      }
    }

    else
    {

      totalDaysPassed = 7 * (occurence - 1); //calculates the full weeks
      totalDaysPassed += week1days; //full weeks + first week

      switch(month)
      {

        case 1: printf(" %d\n", totalDaysPassed);
                break;
        case 2: printf(" %d\n", totalDaysPassed - 31);
                break;
        case 3: printf(" %d\n", totalDaysPassed - 60);
                break;
        case 4: printf(" %d\n", totalDaysPassed - 90);
                break;
        case 5: printf(" %d\n", totalDaysPassed - 120);
                break;
        case 6: printf(" %d\n", totalDaysPassed - 151);
                break;
        case 7: printf(" %d\n", totalDaysPassed - 181);
                break;
        case 8: printf(" %d\n", totalDaysPassed - 212);
                break;
        case 9: printf(" %d\n", totalDaysPassed - 243);
                break;
        case 10: printf(" %d\n", totalDaysPassed - 273);
                 break;
        case 11: printf(" %d\n",totalDaysPassed - 304);
                 break;
        case 12: printf(" %d\n", totalDaysPassed - 335);
                 break;
      }
    }
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getYear
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:this function gets the input from user.
*
***************************************************************************/
int getYear()
{
  //Local Declarations
  int year; //the year from user input

  //Statements
  printf("Enter year number -> ");
  scanf("%d", &year);

  return year;

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
*  Function Description: this function gets input from user
*
***************************************************************************/
int getDay()
{
  //Local Declarations
  int day; //the day from user input

  //Statements
  printf("Enter day of week number -> ");
  scanf("%d", &day);

  return day;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getOccur
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.N/A
*
*  Function Description:This function gets the input from the user
*
***************************************************************************/
int getOccur()
{
  //Local Declarations
  int occurence; //the occurence from user input

  //Statements
  printf("Enter occurrence number -> ");
  scanf("%d", &occurence);

  return occurence;
}

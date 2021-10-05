/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*
*  Lab #: Lab Exam 01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: This program will calculate the radius or apothem and area of the inscribed figure when the user inputs a selections and area of the inscribed figure
*
***************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  //Local Declarations
  double option; //stores the option that the user chooses
  double area; //stores the area that the user inputted
  double radiusFin; //stores the total of the radius
  double areaIns; //stores the area of the inscribed figure
  double angle; //stores the angle in degrees
  double radians; //stores the angle in radians
  double apothem3; //stores the apothem for option 3
  char figureInscribed; //stores the character for the shape of the inscribed figure
  double coefApo; //stores the coefficient of the apothem for option 3
  double coefRadius; //stores the coefficient of the radius for option 1 and 2
  double radius; //stores the radius of the cicle
  double areaTri;  //stores the area of the triangle for option 1
  double areaSquare; //stores the area of the square for option 2
  double areaCir; //stores the area of the circle for option 3

  //Statements
  printf("Enter desired option -> ");
  scanf("%lf", &option);
  printf("Enter area of figure -> ");
  scanf("%lf", &area);

  coefApo = ((int) abs(option - 3) % (int) option) / abs(option - 3); //calculates the coefficient for option 3
  coefRadius = ((2 - (2 % (int) option)) / 2); //calculates the coefficient for option 1 and 2

  figureInscribed = (coefRadius * ('U' - option)) + ((coefApo) * ('U' - (option + (18 - option)))); //calculates the character for the inscribed figure

  angle = 180 / option; //calculates the angle
  radians = angle * (M_PI / 180); //converts the angle to radians

  radius = sqrt(area) / sqrt(M_PI); //calculates the radius for option 1 and 2
  apothem3 = (sqrt(area / (tan(radians) * option))); // calculates the apothem for option 3
  radiusFin = (coefRadius * (radius)) + (coefApo * (apothem3)); //calculates the final radius for output

  areaTri = ((pow(radius, 2) * 3 * sqrt(3)) / 4); //calculates the area of the inscribed triangle
  areaSquare = pow(2 * radius, 2) / 2; //calculates the area for the inscribed square
  areaCir = (radiusFin * radiusFin) * M_PI; //calculates the area of the inscribed circle
  areaIns = (coefRadius * areaTri) + (coefRadius * areaSquare) + (coefApo * areaCir); //calculates the area of the inscribed figure depening on user input

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nRadius/Apothem of figure with area given:%10.1f\n", radiusFin);
  printf("Area of inscribed figure [%c]: %.1f\n",figureInscribed, (double) areaIns);

  return 0;
} //main

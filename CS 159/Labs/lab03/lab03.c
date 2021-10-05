/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. zhu995@purdue.edu
*
*  Lab #: 03
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday 9:30 Virtual
*
*  Program Description: We are to write a program that calculate and display both the radius and area of the circle, the side length and area of the regular polygon.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>
int main(void)

{
  //Local Declarations
  double option; //stores the option that the user chose
  double pSides; //stores the user input of polygon side length
  double apothem; //stores the apothem of the polygon
  double areaC; //stores the area of the circle
  double angle; //stores the angle of the triangles
  double polySL; //stores the side length of the polygon
  double polyArea; //stores the area of the polygon
  double radians; //stores the angle in radians
  double radius1; //stores the radius when user chose option 1
  double radius2; //stores the radius when user chose option 2
  double radiusT; //stores the radius total for output

  //Statements
  printf("1. Polygon inside of circle\n");
  printf("2. Circle inside of polygon\n");
  printf("Select your option -> ");
  scanf("%lf", &option);
  printf("Enter number of polygon sides -> ");
  scanf("%lf", &pSides);
  printf("Enter length of polygon apothem -> ");
  scanf("%lf", &apothem);

  angle = 180 / pSides; //calculates the angle
  radians = angle * (M_PI / 180); //converts the angle from degree to radians
  radius2 = (option - 1) * apothem; //calculates the radius if user chose option 2
  radius1 = (2 - option) * (apothem / cos(radians)); //calculates the radius if user chose option 1
  radiusT = (radius1 + radius2); //calculates the radius sum
  areaC = M_PI * pow(radiusT, 2); //calculates the area of the circle
  polySL = (radius2 * 2 * tan(radians)) + (radius1 * 2 * sin(radians)); //calculates the side lengths of the polygon
  polyArea = pSides * (0.5 * polySL * apothem); //calculates the area of the polygon

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Circle Radius:%17.2f", radiusT);
  printf("\nCircle Area:%19.2f", areaC);
  printf("\nPolygon Side Length:%11.2f", polySL);
  printf("\nPolgon Area:%19.2f", polyArea);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
} //main

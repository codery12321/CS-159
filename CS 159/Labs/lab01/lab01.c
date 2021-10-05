/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. zhu995@purdue.edu
*  Lab #: 01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30-11:20AM, DISTANCE
*
*  Program Description: We are asked to calculate the area of that circle along with the length of a side and area of a regular pentagon inscribed in the circle using the pythagorean Thearom.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>
#define PI 3.1416

int main (void)
{

  //Local Declarations
  float pentagonSL; //Calculates side length of pentagon
  float radius; //gets the radius from user input
  float heightT; //stores the height of the triangle
  float areaT; //sotres the area of one triangle
  float areaPent; //sotres the area of the pentagon
  float areaCircle; //stores the area of the circle
  float PathTher; // sotres the value of the squares of radius and half base length of the triangle

  //Statements

  printf("\nPlease enter the value of the radius -> ");
  scanf("%f", &radius);

  pentagonSL = 2 * radius * sin (PI / 5); //The formula given for calculating the side length of the pentagon
  PathTher = pow(radius, 2) - pow((pentagonSL / 2), 2); //using the pathegoream theorom to derive the height of one triangle
  heightT = sqrt(PathTher); //from above, we have the value of height of triangle that is squared, here we have to square root it
  areaT = (pentagonSL * heightT) / 2; //calculates the area of triangle using 1/2 * base * height = area of a triangle
  areaPent = 5 * areaT; //calculates the area of the pentagon by summing the 5 triangles' area
  areaCircle = PI * pow(radius, 2); //calculates the area of the circle using the radius given by user in put and formula pi * radius^2 = area of a circle

  printf("\nCircle Area: %0.2f", areaCircle);
  printf("\nPentagon side: %0.2f", pentagonSL);
  printf("\nPentagon area: %0.2f\n", areaPent);

  return 0;
} // main

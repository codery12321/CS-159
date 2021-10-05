/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. zhu995@purdue.edu
*
*  Lab #:02
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday 9:30 Tuesday Virtual
*
*  Program Description: we are asked to find the area of the small circle, area and side length of the hexagon, area of the large circle, and the area and side length of the pentagon.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

int main()
{
  //Local Declarations
  double smallR; //stores the radius of small circle we got from the user
  double areaSC; //stores the area of the small circle
  double areaHex; //stores the area of the hexagon
  double areaLC; //stores the area of the large circle
  double areaPent; //stores the area of the pentagon
  double hyp; //stores the hypotenuse of the triangle from splitting the hexagon into 12 triangles
  double base; //stores the base of the triangle from splitting the hegaon into 12 triangles
  double areaTri; //stores the area of the trangle from splitting the hexagon into 12 triangles
  double hypPent; //stores the hypotenuse of the triangles from the pentagon
  double basePent; //stores the base of the triangles from the pentagon
  double angleHex; //stores the angle of the triangles in the hexagon
  double anglePent; //stores the angle of the triangles in the pentagon
  double pentSL; //stores the side length of the pentagon
  double hexSL; //stores the side length of the hexagon

  //Statements
  printf("Enter the radius of the small circle -> ");
  scanf("%lf", &smallR);

  areaSC = M_PI * pow(smallR, 2); //calculates the area of the small circle using the radius given by user
  angleHex = 30 * (M_PI / 180); //converts the degrees into radians
  hyp = smallR / cos(angleHex); //calculates the hypotenuse of the triangles in the hexagon
  base = sqrt(pow(hyp, 2) - pow(smallR, 2)); //calculates the base using the pythagorean thereom
  areaTri = (0.5) * base * smallR; //calculates the area of one triangle in the hexagon
  areaHex = 12 * areaTri; //calulates the total area of the hexagon
  hexSL = base * 2; //calulcates the side length of the hexagon
  areaLC = M_PI * pow(hyp, 2); //caluclates the area of the large ircle using the hypotenuse of the triangles in the hexagon
  anglePent = 36 * (M_PI / 180); //converts degrees into radians
  hypPent = hyp / cos(anglePent); //calculates the hypotenuse of the triangles in the pentagon
  basePent = sqrt(pow(hypPent, 2) - pow(hyp, 2)); //calculates the base using the pythagorean thereom
  areaPent = ((0.5) * basePent * hyp) * 10; //calculates the total area of the pentagon
  pentSL = basePent * 2; //calculates the side length of the pentagon

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nArea of small circle:        %8.2f", areaSC);
  printf("\nHexagon side length:         %8.2f", hexSL);
  printf("\nArea of hexagon:             %8.2f", areaHex);
  printf("\nArea of large circle:        %8.2f", areaLC);
  printf("\nPentagon side length:        %8.2f", pentSL);
  printf("\nArea of pentagon:            %8.2f", areaPent);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
} //main

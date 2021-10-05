/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*
*  Lab #:05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: This program will calculate the measures of its three internal angles and the areas of the three quadrilaterals created when a perpendicular lines are connected from the incenter to each side of the triangle.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

//Function Declarations
double getInput(char coord, int num);
double distance(double pt1x, double pt1y, double pt2x, double pt2y);
double incenterX(double dist1, double dist2, double dist3, int x1, int x2, int x3);
double incenterY(double dist1, double dist2, double dist3, int y1, int y2, int y3);
double incircleR(double dist1, double dist2, double dist3);
double internalAngle(double dist1, double dist2, double dist3);
double baseTri(double radius, double angle);
double areaQuad(double base, double radius);
double calcMinutes(double angle);
double calcSec(double angle, double minutes);
void disp(double area1, double area2, double area3, double angle1, double minutes1, double seconds1, double angle2, double minutes2, double seconds2, double angle3, double minutes3, double seconds3);

int main()
{
  //Local Declarations
  double x1; //stores the 1st x coordinate
  double x2; //stores the 2nd x coordinate
  double x3; //stores the 3rd x coordinate
  double y1; //stores the 1st y coordinate
  double y2; //stores the 2nd y coordinate
  double y3; //stores the 3rd y coordinate
  double dist1; //stores the distance
  double dist2; //stores the distance
  double dist3; //stores the distance
  double centerX; //stores the x coordinate of the incenter
  double centerY; //stores the y coordinate of the incenter
  double radius; //stores the radius of the incircle
  double angle1; //stores the internal angle 1
  double angle2; //stores the internal angle 2
  double angle3; //stores the internal angle 3
  double area1; //stores the area of quadrilateral 1
  double area2; //stores the area of quadrilateral 2
  double area3; //stores the area of quadrilateral 3
  double base1; //stores the base of triangle
  double base2; //stores the base of triangle
  double base3; //stores the base of triangle
  double min1; //stores the minute
  double min2; //stores the minute
  double min3; //stores the minute
  double sec1; //stores the seconds
  double sec2; //stores the seconds
  double sec3; //stores the seoncds

  //Statements
  x1 = getInput('X', 1);
  y1 = getInput('Y', 1);
  x2 = getInput('X', 2);
  y2 = getInput('Y', 2);
  x3 = getInput('X', 3);
  y3 = getInput('Y', 3);

  dist1 = distance(x1, y1, x2, y2);
  dist2 = distance(x2, y2, x3, y3);
  dist3 = distance(x3, y3, x1, y1);

  centerX = incenterX(dist1, dist2, dist3, x1, x2, x3);
  centerY = incenterY(dist1, dist2, dist3, y1, y2, y3);

  radius = incircleR(dist1, dist2, dist3);

  angle3 = internalAngle(dist3, dist1, dist2);
  angle2 = internalAngle(dist2, dist3, dist1);
  angle1 = internalAngle(dist1, dist2, dist3);

  base1 = baseTri(radius, angle1);
  base2 = baseTri(radius, angle2);
  base3 = baseTri(radius, angle3);

  area1 = areaQuad(base1, radius);
  area2 = areaQuad(base2, radius);
  area3 = areaQuad(base3, radius);

  min1 = calcMinutes(angle1);
  min2 = calcMinutes(angle2);
  min3 = calcMinutes(angle3);

  sec1 = calcSec(angle1, min1);
  sec2 = calcSec(angle2, min2);
  sec3 = calcSec(angle3, min3);

  disp(area1, area2, area3, angle1, min1, sec1, angle2, min2, sec2, angle3, min3, sec3);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:disp
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1 - the angle
*    2.double minutes1 - the minutes
*    3.double seconds1 - the seconds
*    4.double angle2 - the angle
*    5.double minutes2 - the minutes
*    6.double seconds2 - the seconds
*    7.double angle3 - the angle
*    8.double minutes3 - the minutes
*    9.double seconds3 - the seconds
*    10.double area1 - the area
*    11.double area2 - the area
*    12.double area3 - the area
*
*  Function Description: this function prints the output in a formatted manner
*
***************************************************************************/
void disp(double area1, double area2, double area3, double angle1, double minutes1, double seconds1, double angle2, double minutes2, double seconds2, double angle3, double minutes3, double seconds3)
{
  printf("\nInternal triangle angles: %.0d%c%c %.0f' %.2f\", %.0d%c%c %.0f' %.2f\", %.0d%c%c %.0f' %.2f\"\n", (int) angle1, 0xC2, 0xB0, minutes1, seconds1, (int) angle2, 0xC2, 0xB0, minutes2, seconds2, (int) angle3, 0xC2, 0xB0, minutes3, seconds3);
  printf("Area of quadrilaterals: %.2f, %.2f, %.2f\n", area1, area2, area3);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:calcSec
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle - the angle of internal angles of triangles
*    2.double minutes - the minute second of the final output
*
*  Function Description: this function calculates the seconds section for the final output
*
***************************************************************************/
double calcSec(double angle, double minutes)
{
  //Local Declaration
  double seconds; //stores the seconds

  //Statements
  seconds = (3600 * (angle - (int) angle - (minutes / 60)));
  return seconds;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:calcMinutes
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle - the internal angles of the triangle
*
*  Function Description: this function calculates the minutes section
*
***************************************************************************/
double calcMinutes(double angle)
{
  //Local Declarations
  double minutes; //stores the minutes

  //Statements
  minutes = 60 * (angle - (int) angle);

  return (int) minutes;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: areaQuad
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double radius - the radius of incircle
*    2.double base - the base of each triangle
*
*  Function Description: calculates the area of the quadrilateral
*
***************************************************************************/
double areaQuad(double base, double radius)
{
  //Local Declarations
  double area; //stores the area of the quadrilateral

  //Statements
  area = base * radius;

  return area;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:baseTri
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double radius - radius of incircle
*    2.double angle - the angle of the internal angles
*
*  Function Description: this function calculates the base of the triangle that are half of the quadrilaterals
*
***************************************************************************/
double baseTri(double radius, double angle)
{
  //Local Declarations
  double base; //stores the base of the triangle
  double anglehalf; //stores the angle divided in half

  //Statemens
  anglehalf = (M_PI / 180) * (angle / 2);
  base = (radius / tan(anglehalf));

  return base;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:internalAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double dist1 - the distance between two points
*    2.double dist2 - the distance between two points
*    3.double dist3 - the distance between two points
*
*  Function Description: this function calculates the three internal angles
*
***************************************************************************/
double internalAngle(double dist1, double dist2, double dist3)
{
  //Local Declarations
  double angle; //stores the angle
  double calc; //stores the calculation

  //Statements
  calc = (pow(dist3, 2) + pow(dist1, 2) - pow(dist2, 2)) / (2 * dist3 * dist1);
  angle = acos(calc) * (180 / M_PI);

  return angle;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:incircleR
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double dist1 - distance between two points
*    2.double dist2 - distance between two points
*    3.double dist3 - distance between two points
*
*  Function Description: this function calculates the radius of the incircle
*
***************************************************************************/
double incircleR(double dist1, double dist2, double dist3)
{
  //Local Declaration
  double incircleR; //stores the radius of the incircle
  double semiperimeter; //stores the semiperimeter
  double areaTriangle; //stores the area of the whole triangle

  //Statements
  semiperimeter = (dist1 + dist2 + dist3) / 2;
  areaTriangle = sqrt(semiperimeter * (semiperimeter - dist1) * (semiperimeter - dist2) * (semiperimeter - dist3));
  incircleR = areaTriangle / semiperimeter;

  return incircleR;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:incenterY
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double dist1 - the distance between points
*    2.double dist2 - the distance between points
*    3.double dist3 - the distance between points
*    4.int y1 - y coordinate of point 1
*    5.int y2 - y coordinate of point 2
*    6.int y3 - y coordinate of point 3
*
*  Function Description: This function returns the Y coordinate of the incenter
*
***************************************************************************/
double incenterY(double dist1, double dist2, double dist3, int y1, int y2, int y3)
{
  //Local Declarations
  double incenterY; //stores the y coordinate of incenter

  //Statements
  incenterY = ((dist2 * y1) + (dist3 * y2) + (dist1 * y3)) / (dist1 + dist2 + dist3);

  return incenterY;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: incenterX
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double dist1 - the distance between two points
*    2.double dist2 - the distance between two points
*    3.double dist3 - the didstance between two points
*    4.int x1 - x coordinate of point 1
*    5.int x2 - x coordinate of point 2
*    6.int x3 - x coordinate of point 3
*
*  Function Description: This function calculates the x coordinate of the incenter of the triangle
*
***************************************************************************/
double incenterX(double dist1, double dist2, double dist3, int x1, int x2, int x3)
{
  //Local Declarations
  double incenterX; //Stores the x coordinate of incenter

  //Statements
  incenterX = ((dist2 * x1) + (dist3 * x2) + (dist1 * x3)) / (dist1 + dist2 + dist3);

  return incenterX;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: distance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double pt1x - the x coordinate for point 1
*    2.double pt1y - the y coordinate for point 1
*    3.double pt2x - the x coordinate for point 2
*    4.double pt2y - the y coordinate for point 2
*
*  Function Description: calculates sthe distance between two point and returns it.
*
***************************************************************************/
double distance(double pt1x, double pt1y, double pt2x, double pt2y)
{
  //Local Declarations
  double dist; //stores the distance between points

  //Statements
  dist = sqrt(pow(pt2x - pt1x, 2) + pow(pt2y - pt1y, 2));

  return dist;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. char coord - gets x or y
*    2. int num - the number of points
*
*  Function Description: gets the input from user
*
***************************************************************************/
double getInput(char coord, int num)
{
  //Local Declaration
  double pt; //stores the user input
  //Statements
  printf("Enter %c coordinate #%d -> ", coord, num);
  scanf("%lf", &pt);

  return pt;
}

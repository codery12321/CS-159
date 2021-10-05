/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. zhu995@purdue.edu
*  3. jiang488@purdue.edu
*
*  Lab #:06
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab:  Tuesday, 9:30, Virtual
*
*  Program Description: This program will calculate the location of orthocenter, circumcenter, and the location of the center of the nine point circle and whether that point is inside of outside of the triangle when given three points that will always create a triangle with a positive area.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

//Function Declarations
double getInput(char coord, double num);
double distance(double pt1x, double pt1y, double pt2x, double pt2y);
double internalAngle(double dist1, double dist2, double dist3);
double orthoY(double y1, double y2, double y3, double angleA, double angleB, double angleC);
double orthoX(double x1, double x2, double x3, double angleA, double angleB, double angleC);
double circumX(double x1, double x2, double x3, double angleA, double angleB, double angleC);
double circumY(double y1, double y2, double y3, double angleA, double angleB, double angleC);
double ninePointX(double orthox, double circumx);
double ninePointY(double orthoy, double circumy);
double areaTri(double x1, double x2, double x3, double y1, double y2, double y3);
void isInside(double area, double A1, double A2, double A3, double ninepointx, double ninepointy);

int main()
{
  //Local Declarations
  double x1; //the input for x for point 1
  double x2; //the input for x for point 2
  double x3; //the input for x for point 3
  double y1; //the input for y for point 1
  double y2; //the input for y for point 2
  double y3; //the input for y for point 3
  double dist1; //the distance between points
  double dist2; //the distance between points
  double dist3; //the distance between points
  double angle1; //the angle for triangle
  double angle2; //the angle for triangle
  double angle3; //the angle for triangle
  double orthocenterX; // the x coordinate for orthocenter
  double orthocenterY; //the y coordinate for orthocenter
  double circumcenterX; //the x coordinate for the circumcenter
  double circumcenterY; //the y coordinate for the circumcenter
  double x9point; // the x coordinate for the nune point circle center
  double y9point; //the y coordinate for the nine point circle center
  double area; // the area for the whole triangle
  double A1; //the area for small triangle
  double A2; //the area for small triangle
  double A3; // the area for small triangle

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

  angle1 = internalAngle(dist1, dist2, dist3);
  angle2 = internalAngle(dist2, dist3, dist1);
  angle3 = internalAngle(dist3, dist1, dist2);

  orthocenterX = orthoX(x1, x2, x3, angle1, angle2, angle3);
  orthocenterY = orthoY(y1, y2, y3, angle1, angle2, angle3);

  circumcenterX = circumX(x1, x2, x3, angle1, angle2, angle3);
  circumcenterY = circumY(y1, y2, y3, angle1, angle2, angle3);

  x9point = ninePointX(orthocenterX, circumcenterX);
  y9point = ninePointY(orthocenterY, circumcenterY);

  area = areaTri(x1, x2, x3, y1, y2, y3);
  A1 = areaTri(x9point, x2, x3, y9point, y2, y3);
  A2 = areaTri(x1, x9point, x3, y1, y9point, y3);
  A3 = areaTri(x1, x2, x9point, y1, y2, y9point);

  printf("\nCoordinates of orthocenter: %.2f, %.2f\n", orthocenterX, orthocenterY);
  printf("Coordinates of circumcenter: %.2f, %.2f\n", circumcenterX, circumcenterY);
  isInside(area, A1, A2, A3, x9point, y9point);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:isInside
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double area - the area of whole triangle
*    2.double A1 - area of small triangle
*    3.double A2 - area of small triangle
*    4.double A3 - area of small triangle
*    5.double x9point - nine point center
*    6.double y9point - nine point center
*
*  Function Description:this function prints out if the point is inside or outside of the triangle
*
***************************************************************************/
void isInside(double area, double A1, double A2, double A3, double ninepointx, double ninepointy)
{
  if (fabs(area - (A1 + A2 + A3)) <= 0.001)
  {
    printf("The nine point circle center: %.2f, %.2f is inside of the triangle.\n", ninepointx, ninepointy);
  }
  else
  {
    printf("The nine point circle center: %.2f, %.2f is outside of the triangle.\n", ninepointx, ninepointy);
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: areaTri
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double x1 - x coordinate of point 1
*    2.double x2 - x coordinate of point 2
*    3.double x3 - x coordinate of point 3
*    4.double y1 - y coordinate of point 1
*    5.double y2 - y coordinate fo point2
*    6.double y3 - y coordinate of point 3
*
*  Function Description:this function calculates the area of the triangle
*
***************************************************************************/
double areaTri(double x1, double x2, double x3, double y1, double y2, double y3)
{
  return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: ninePointY
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double orthoy - y coordinate for orthocenter
*    2.double circumy - y coordinate for circumcenter
*
*  Function Description: this function calculates the y coordinate for the nine point circle center
*
***************************************************************************/
double ninePointY(double orthoy, double circumy)
{
  //Local declarations
  double pointY; //stores the y coordinate of the nine point circle center
  //Statements
  pointY = (orthoy + circumy) / 2;
  return pointY;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: ninePointX
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double orthox - the x coordinate for orthocenter
*    2.double circumx - the x coordinate for circumcenter
*
*  Function Description:this function calculates the x coordinate for the nine point circle center
*
***************************************************************************/
double ninePointX(double orthox, double circumx)
{
  //Local Declarations
  double pointX; //stores the x coordinate of the nine point circle center

  //Statements
  pointX = (orthox + circumx) / 2;

  return pointX;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:circumY
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double y1 - point 1
*    2.double y2 - point 2
*    3.double y3 - pooint 3
*    4.double angleA - angle for triangle
*    5. double angleB - angle for triangle
*    6. double angleC - angle for triangle
*
*  Function Description:this function calculates the y coordinate for the circumcenter
*
***************************************************************************/
double circumY(double y1, double y2, double y3, double angleA, double angleB, double angleC)
{
  //Local Declarations
  double y; //stores the y coordinate of the circumcenter
  double rad1; //stores the angles in radians
  double rad2; //stores the angle in radians
  double rad3; //stores the angle in radians

  //Statements
  rad1 = angleA * M_PI / 180;
  rad2 = angleB * M_PI / 180;
  rad3 = angleC * M_PI / 180;

  y = (y1 * sin(2 * rad1) + y2 * sin(2 * rad2) + y3 * sin(2 * rad3)) / (sin(2 * rad1) + sin(2 * rad2) + sin(2 * rad3));

  return y;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:circumX
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double x1 - point 1
*    2.double x2 - point 2
*    3.double x3 - point 3
*    4. double angleA - angle 1
*    5.double angleB - angle 2
*    6.double angleC - angle 3
*
*  Function Description: this function calculates the x coordinate of the circumcenter
*
***************************************************************************/
double circumX(double x1, double x2, double x3, double angleA, double angleB, double angleC)
{
  //Local Declarations
  double x; //stores the x coordinate for the circumcenter
  double rad1; //stores the angle in radians
  double rad2; //stores the angle in radians
  double rad3; //stores the angle in radians

  //Statements
  rad1 = angleA * M_PI / 180;
  rad2 = angleB * M_PI / 180;
  rad3 = angleC * M_PI / 180;

  x = (x1 * sin(2 * rad1) + x2 * sin(2 * rad2) + x3 * sin(2 * rad3)) / (sin(2 * rad1) + sin(2 * rad2) + sin(2 * rad3));

  return x;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:orthoY
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double y1 - point 1
*    2.double y2 - point 2
*    3.double y3 - point 3
*    4.double angleA - angle for triangle
*    5.double angleB - angle for triangle
*    6.double angleC - angle for triangle
*
*  Function Description:this function calculates the y coordinate for the orthocenter
*
***************************************************************************/
double orthoY(double y1, double y2, double y3, double angleA, double angleB, double angleC)
{
  //Local Declaration
  double y; //stores the y coordinate of the orthocenter
  double rad1; //stores the angle in radians
  double rad2; //stores the angle in radians
  double rad3; //stores the angle in radians

  //Statements
  rad1 = angleA * M_PI / 180;
  rad2 = angleB * M_PI / 180;
  rad3 = angleC * M_PI / 180;

  y = (y1 * tan(rad1) + y2 * tan(rad2) + y3 * tan(rad3)) / (tan(rad1) + tan(rad2) + tan(rad3));

  return y;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthoX
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double x1 - point 1
*    2.double x2 - point 2
*    3.double x3 - point 3
*    4.double angleA - angle for triangle
*    5. double angleB - angle for triangle
*    6.double angleC - angle for triangle
*
*  Function Description: this function calculates the x coordinate for the orthocenter
*
***************************************************************************/
double orthoX(double x1, double x2, double x3, double angleA, double angleB, double angleC)
{
  //Local Declarations;
  double x; //stores the x coordinate of the orthocenter
  double rad1; //stores the angle in radians
  double rad2; //stores the angle in radians
  double rad3; //stores the angle in radians

  //Statements
  rad1 = angleA * M_PI / 180;
  rad2 = angleB * M_PI / 180;
  rad3 = angleC * M_PI / 180;
  x = (x1 * tan(rad1) + x2 * tan(rad2) + x3 * tan(rad3)) / (tan(rad1) + tan(rad2) + tan(rad3));

  return x;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: internalAngle
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double dist1 - the distance ebtween two points
*    2.double dist2 - the distance between two points
*    3.double dist3 - the distance between two points
*
*  Function Description:this function calculates the three internal angles
*
***************************************************************************/
double internalAngle(double dist1, double dist2, double dist3)
{
  //Local Declarations
  double angle; //stores the angle
  double calc; //stores the calculation

  //Statemments
  calc = (pow(dist3, 2) + pow(dist1, 2) - pow(dist2, 2)) / (2 * dist3 * dist1);
  angle = acos(calc) * (180 / M_PI);

  return angle;
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
*  Function Description: this funtion calculates the distance between the points
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
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. char coord - gets x or y
*    2.int num - the number of points
*
*  Function Description: this function gets the input from the user
*
***************************************************************************/
double getInput(char coord, double num)
{
  //Local Declaration
  double pt; //stores the input from user
  //Statements
  printf("Enter %c coordinate #%.0f -> ", coord, num);
  scanf("%lf", &pt);

  return pt;
}

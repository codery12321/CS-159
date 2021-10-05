/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*  2. zhu995@purdue.edu
*  3. jiang488@purdue.edu
*  Lab #:04
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: We are asked to find the distance between points and the coordinate of the incenter found within the triangle created when gievn three points that will always create a triangle with a positive area.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

//Function Declarations
int getInput(char coord, int num);
double distance(double pt1x, double pt1y, double pt2x, double pt2y);
double incenterX(double dist1, double dist2, double dist3, int x1, int x2    , int x3);
double incenterY(double dist1, double dist2, double dist3, int y1, int y2, int y3);
void dispDist(int pt1, int pt2, double dist);
void dispIncenter(double incenterX, double incenterY);

int main()
{
  //Local Declarations
  double x1; //stores the 1st x coordinate
  double x2; //stores the 2nd x coordinate
  double x3; //stores the 3rd x coordinate
  double y1; //stores the 1st y coordinate
  double y2; //stores the 2nd y coordinate
  double y3; //stores the 3rd y coordinate
  double dist1; //stores the distance between point 1 and 2
  double dist2; //stores the distance between point 2 and 3
  double dist3; //stores the distance between point 3 and 1
  double centerX; //stores the x coordinate for incenter
  double centerY; //stores the y coordinate for incenter

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

  printf("\n");
  dispDist(1, 2, dist1);
  dispDist(2, 3, dist2);
  dispDist(3, 1, dist3);
  dispIncenter(centerX, centerY);
  return 0;
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
*    1. double dist1 - get the data of distance between points
*    2. double dist2 - the data of distance between points
*    3. double dist3 - the data of distance between points
*    4. int x1 - x coordinate of point 1
*    5. int x2 - x coordinate of point 2
*    6. int x3 - x coordinate of point 3
*
*  Function Description: This function calculates the incenter of the triangle
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
*  Name of Function: incenterY
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double dist1 - the distance between points
*    2. double dist2 - the distance between points
*    3. double dist3 - the distance between points
*    4. int y1 - y coordinate of point 1
*    5. int y2 - y coordinate of point 2
*    6. int y3 - y coordinate of point 3
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
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. char coord - x or y depending on user input
*    2. int numb - 1 2 or 3 depending on user input
*
*  Function Description: It prints out the input gotten from the user in a certain format.
*
***************************************************************************/
int getInput(char coord, int num)
{
  //Local Declaration
  int pt; //stores the user input
  //Statements
  printf("Enter %c coordinate #%d -> ", coord, num);
  scanf("%d", &pt);
  return pt;
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
*    1. double pt1x - the x coordinate for point 1
*    2. double pt1y - the y coordinate for point 1
*    3. double pt2x - the x coordinate for point 2
*    4. double pt2y - the y coordinate for point 2
*
*  Function Description: calculates the distance between two points and returns it
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
*  Name of Function: dispDist
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int pt1 - point number
*    2. int pt2 - point number
*    3. double dist - distance between the two points
*
*  Function Description: This function displays the result in a formatted manner
*
***************************************************************************/

void dispDist(int pt1, int pt2, double dist)
{
  printf("Distance from point %d to point %d: %.2f\n", pt1, pt2, dist);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dispIncenter
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double incenterX - gets the x coordinate of the incenter
*    2. double incentery - gets the y coordinate of the incenter
*
*  Function Description: Displays the location of the incenter in a formatted manner
*
***************************************************************************/
void dispIncenter(double incenterX, double incenterY)
{
  printf("Location of incenter: %.2f, %.2f\n", incenterX, incenterY);
}

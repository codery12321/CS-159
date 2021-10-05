/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: This program will calculate the time for a projectile to reach maximum height, the maximum height reacher, the time to hit the ground and the totl distance traveled.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>
#define GRAV 9.8

//Function Declarations
double getHeight();
double getVI();
double getAngle();
void disp(double time, double MaxHeight, double timeHG, double totalDist);
double timeMH(double angle, double VI);
double MaxH(double angle, double VI, double time, double Height);
double timeHG(double angle, double VI, double height);
double totalD(double angle, double VI, double timeHitGround);

int main()
{
  //Local Declarations
  double Height; //the height of launch
  double VI; //the initial velocity
  double Angle; //the angle to the horizontal in degrees
  double time; //the time to maximum height
  double MaxHeight; //the maximum height reacher
  double timeHitGround; //the time for the object to hit ground
  double totalDistance; //the total distance traveled

  //Statements
  Height = getHeight();
  VI = getVI();
  Angle = getAngle();
  time = timeMH(Angle, VI);
  MaxHeight = MaxH(Angle, VI, time, Height);
  timeHitGround = timeHG(Angle, VI, Height);
  totalDistance = totalD(Angle, VI, timeHitGround);

  disp(time, MaxHeight, timeHitGround, totalDistance);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: totalD
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle - the angle to horizontal in degrees
*    2.double VI - initial velocity
*    3.double timeHitGround - time to hit ground
*
*  Function Description: This function calculates the total distance traveled.
*
***************************************************************************/
double totalD(double angle, double VI, double timeHitGround)
{
  //Local Declarations
  double distance; //the toal distance traveled
  double angleRad; //the angle in radians

  //Statements
  angleRad = angle * (M_PI / 180);
  distance = VI * cos(angleRad) * timeHitGround;

  return distance;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: timeHG
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle - angle to horizontal in degrees
*    2.double VI - initial velocity
*    3.double height - initial height gotten from user
*
*  Function Description: this function calculates teh time to hit ground.
*
***************************************************************************/
double timeHG(double angle, double VI, double height)
{
  //Local Declarations
  double angleRad; //the angle in radians
  double timeHitGround; //the time for the object to hit ground

  //Statements
  angleRad = angle * (M_PI / 180);
  timeHitGround = 0.1020405 * (sqrt((pow(sin(angleRad), 2) * pow(VI, 2)) + (19.6 * height)) + (sin(angleRad) * VI));

  return timeHitGround;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: MaxH
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double angle - the angle to the horizontal in degreees
*    2. double VI - the initial velocity
*    3. double time - the time needed to get to maximum height
*    4. double Height - the height of launch
*
*  Function Description: this function calculates the maximum height the projectile reachs
*
***************************************************************************/
double MaxH(double angle, double VI, double time, double Height)
{
  //Local Declarations
  double MaxHeight; //the maximum height the projectile reaches
  double angleRad; //stores the angle that's converted to radians

  //Statements
  angleRad = angle * (M_PI / 180);
  MaxHeight = Height + (pow(VI, 2) * pow(sin(angleRad), 2)) / (2 * GRAV);

  return MaxHeight;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: timeMH
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Angle - the angle to the horizontal in degrees
*    2. double VI - the initial velocity
*
*  Function Description: Calculates the time to reach max height
*
***************************************************************************/
double timeMH(double Angle, double VI)
{
  //Local Declaration
  double angleRad; //store the degree that's converted to radians
  double time; //the calculated time to reach maximum height

  //Statements
  angleRad = Angle * (M_PI / 180);
  time = (VI * sin(angleRad)) / GRAV;

  return time;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: disp
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double time - the time needed to get to max height
*    2. double MaxHeight - the maximum height reached
*    3. double timeHG - the time to hit ground
*    4. double totalDist - the total distance traveled
*
*  Function Description: Displays output in a formatted manner
*
***************************************************************************/
void disp(double time, double MaxHeight, double timeHG, double totalDist)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nTime to max height:%20.2f s", time);
  printf("\nMaximum height reached:%16.2f m", MaxHeight);
  printf("\nTime to hit ground:%20.2f s", timeHG);
  printf("\nTotal distance traveled:%15.2f m",totalDist);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getAngle
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*
*  Function Description:Gets the angle in degrees from the user
*
***************************************************************************/
double getAngle()
{
  //Local Declaration
  double angleDeg; //the angle to the horizontal in degrees
  //Statement
  printf("Enter angle to the horizontal [degrees] -> ");
  scanf("%lf", &angleDeg);

  return angleDeg;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getVI()
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*
*  Function Description: gets the initial velocity from user
*
***************************************************************************/
double getVI()
{
  //Local Declaration
  double VI; //the initial velocity
  //Statements
  printf("Enter initial velocity [m/s] -> ");
  scanf("%lf", &VI);

  return VI;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getHeight()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.  N/A
*
*  Function Description: This function gets the height input from user.
*
***************************************************************************/
double getHeight()
{
  //Local Declaration
  double height; //the height of launch
  //Statements
  printf("\nEnter height of launch [m] -> ");
  scanf("%lf", &height);

  return height;
}

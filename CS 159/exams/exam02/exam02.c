/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3633@purdue.edu
*
*  Lab Exam #: 02
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description:This program will calculate the location of the orthocenter and create a triangle that connects the orthocenter to the end points of the largest side in the triangle. It will also display the internal angles of this new triangle and display whether it is isosceles, scalene, or equilateral and whether it is acute, obtuse, or right..
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

//Function declarations
void input(double *, double *, double *, double *, double *, double *);
double internalAngle(double dist1, double dist2, double dist3);
double distance(double pt1x, double pt1y, double pt2x, double pt2y);
double orthoY(double pty1, double pty2, double pty3, double angleA, double angleB, double angleC);
double orthoX(double ptx1, double ptx2, double ptx3, double angleA, double angleB, double angleC);
double angleClass(double, double, double);
void disp(double, double, double, double orthocenterX, double orthocenterY, int shape, int angleclass);
double newAngleA(double angle1, double angle2, double angle3, double dist1, double dist2, double dist3, double angleclass);
double newAngleB(double, double, double, double, double, double, double);
double newAngleC(double, double, double, double, double, double, double);
double newAngleClass(int, double, double, double);
double newShape(double, double, double);
double angleOutput1(double, double, double);
double angleOutput2(double, double, double);
double angleOutput3(double, double, double);

int main()
{
  //Local Declaration
  double ptx1; //point 1 x coordinate
  double pty1; //point 1 y coordinate
  double ptx2; //point 2 x coordinate
  double pty2; //point 2 y coordinate
  double ptx3; //point 3 x coordinate
  double pty3; //point 3 y coordinate
  double dist1; //distance between points
  double dist2; //distance between points
  double dist3; //distance between points
  double angle1; //original angle 1
  double angle2; //original angle 2
  double angle3; //original angle 3
  double orthocenterX; //x coordinate of orthocenter
  double orthocenterY; //y coordinate of orthocenter
  double angleclass; //original angle classfication
  double newAngle1; //new angle 1
  double newAngle2; //new angle 2
  double newAngle3; //new angle 3
  double newclass; //new angle classfication
  double newshape; //new shape
  double finalAngle1; //final angle for output
  double finalAngle2; //final angle for output
  double finalAngle3; //final angle for output

  //Statements
  input(&ptx1, &pty1, &ptx2, &pty2, &ptx3, &pty3);

  dist1 = distance(ptx1, pty1, ptx2, pty2);
  dist2 = distance(ptx2, pty2, ptx3, pty3);
  dist3 = distance(ptx3, pty3, ptx1, pty1);

  angle1 = internalAngle(dist1, dist2, dist3);
  angle2 = internalAngle(dist2, dist3, dist1);
  angle3 = internalAngle(dist3, dist1, dist2);

  orthocenterX = orthoX(ptx1, ptx2, ptx3, angle1, angle2, angle3);
  orthocenterY = orthoY(pty1, pty2, pty3, angle1, angle2, angle3);

  angleclass = angleClass(angle1, angle2, angle3);

  newAngle1 = newAngleA(angle1, angle2, angle3, dist1, dist2, dist3, angleclass);
  newAngle2 = newAngleB(angle1, angle2, angle3, dist1, dist2, dist3, angleclass);
  newAngle3 = newAngleC(angle1, angle3, angle2, dist1, dist2, dist3, angleclass);

  newclass = newAngleClass((int) angleclass, newAngle1, newAngle2, newAngle3);
  newshape = newShape(newAngle1, newAngle2, newAngle3);

  finalAngle1 = angleOutput1(newAngle1, newAngle2, newAngle3);
  finalAngle2 = angleOutput2(newAngle1, newAngle2, newAngle3);
  finalAngle3 = angleOutput3(newAngle1, newAngle2, newAngle3);

  disp(finalAngle1, finalAngle2, finalAngle3, orthocenterX, orthocenterY, newshape, newclass);

  return 0;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:angleOutput1
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double newAngle1 - angle for new triangle
*    2.double newAngle2 - angle for new triangle
*    3.double newAngle3 - angle for new triangle
*
*  Function Description:organizes the angles for output
*
***************************************************************************/
double angleOutput1(double newAngle1, double newAngle2, double newAngle3)
{
  double firstAngle; //angle for slot 1

  if ((newAngle1 < newAngle2) && (newAngle1 < newAngle3))
  {
    firstAngle = newAngle1;
  }
  else if ((newAngle2 < newAngle1) && (newAngle2 < newAngle3))
  {
    firstAngle = newAngle2;
  }
  else if ((newAngle3 < newAngle1) && (newAngle3 < newAngle2))
  {
    firstAngle = newAngle3;
  }
  else
  {
    firstAngle = newAngle1;
  }

  return firstAngle;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:angleOutput2
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double newAngle1 - new angle for triangle
*    2.double newAngle2 - angle for new triangle
*    3.double newAngle3 - angle for new triangle
*
*  Function Description:organizes the angle from small to largest
*
***************************************************************************/
double angleOutput2(double newAngle1, double newAngle2, double newAngle3)
{
  double secondAngle; //second angle for slot 2

  if (((newAngle1 < newAngle2) && (newAngle1 > newAngle3)) || ((newAngle1 > newAngle2) && (newAngle1 < newAngle3)))
  {
    secondAngle = newAngle1;
  }
  else if (((newAngle2 < newAngle3) && (newAngle2 > newAngle1)) || ((newAngle2 > newAngle3) && (newAngle2 < newAngle1)))
  {
    secondAngle = newAngle2;
  }
  else if (((newAngle3 < newAngle1) && (newAngle3 > newAngle2)) || ((newAngle3 > newAngle1) && (newAngle3 < newAngle2)))
  {
    secondAngle = newAngle3;
  }
  else if (newAngle3 == newAngle1)
  {
    secondAngle = newAngle3;
  }
  else
  {
    secondAngle = newAngle2;
  }

  return secondAngle;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:angleOutput3
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double newAngle1 - angle for new triangle
*    2.double newAngle2 - angle for new triangle
*    3.double newAngle3 - angle for new triangle
*
*  Function Description:outputs the 3rd angle
*
***************************************************************************/
double angleOutput3(double newAngle1, double newAngle2, double newAngle3)
{
  double thirdAngle; //final output for slot number 3

  if ((newAngle1 > newAngle2) && (newAngle1 > newAngle3))
  {
    thirdAngle = newAngle1;
  }
  else if ((newAngle2 > newAngle3) && (newAngle2 > newAngle1))
  {
    thirdAngle = newAngle2;
  }
  else if ((newAngle3 > newAngle2) && (newAngle3 > newAngle1))
  {
    thirdAngle = newAngle3;
  }
  else if (newAngle1 == newAngle2)
  {
    thirdAngle = newAngle1;
  }
  else
  {
    thirdAngle = newAngle3;
  }

  return thirdAngle;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:newShape
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double newAngle1 - angle of new triangle
*    2.double newAngle2 - angle of new triangle
*    3.double newAngle3 - angle of new triangle
*
*  Function Description:determine shape of new triangle
*
***************************************************************************/
double newShape(double newAngle1, double newAngle2, double newAngle3)
{
  double newshape; //new shape

  if ((newAngle1 == newAngle2) && (newAngle2 == newAngle3))
  {
    newshape = 1;
  }
  else if (((int) newAngle1 == (int) newAngle2) || ((int) newAngle2 == (int) newAngle3) || ((int) newAngle3 == (int) newAngle1))
  {
    newshape = 2;
  }
  else
  {
    newshape = 3;
  }

  return newshape;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:newAngleClass
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.int angleclass - old angle classification
*    2.double newAngle1 - angle of new triangle
*    3.double newAngle2 - angle of new triangle
*    4.double newAngle3 - angle of new triangle
*
*  Function Description:determines the new angle classification
*
***************************************************************************/
double newAngleClass(int angleclass, double newAngle1, double newAngle2, double newAngle3)
{
  double newclass; //new triangle angle classfication

  if (((int)newAngle1 > 90) || ((int)newAngle2 > 90) || ((int)newAngle3 > 90))
  {
    newclass = 3;
  }
  else if (angleclass == 2)
  {
    newclass = 2;
  }
  else
  {
    newclass = 1;
  }

  return newclass;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:angleClass
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1 - angle of triangle
*    2.double angle2 - angle of triangle
*    3.double angle3 0 angle of triangle
*
*  Function Description: determines the angle classification
*
***************************************************************************/
double angleClass(double angle1, double angle2, double angle3)
{
  double angleclass; //original triangle angle classification

  if (((int) angle1 < 90) && ((int)angle2 < 90) && ((int) angle3 < 90))
  {
    angleclass = 1;
  }
  else if (((int) angle1 == 90) || ((int)angle2 == 90) || ((int)angle3 == 90))
  {
    angleclass = 2;
  }
  else
  {
    angleclass = 3;
  }
  return angleclass;
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
*    1.double newAngle1 - new angle
*    2.double newAngle2 - new angle
*    3.double newAngle3 - new angle
+    4.double orthocenterX - x of orthocenter
*    5.double orthocenterY - y of orthocenter
*    6.int shape - shape of triangle
*    7.int angleclass - angle classificcation of triangle
*
*  Function Description:displays output
*
***************************************************************************/
void disp(double newAngle1, double newAngle2, double newAngle3, double orthocenterX, double orthocenterY, int shape, int angleclass)
{
  printf("\nCoordinates of orthocenter: %.2f, %.2f\n", orthocenterX, orthocenterY);
  printf("Internal triangle angles: %.1f, %.1f, %.1f\n", newAngle1, newAngle2, newAngle3);

  printf("Triangle Type: ");

  switch(shape)
  {
    case 1:  printf("Equilateral");
             break;
    case 2:  printf("Isosceles");
             break;
    case 3:  printf("Scalene");
             break;
  }
  switch(angleclass)
  {
    case 1:  printf(" acute\n");
             break;
    case 2:  printf(" right\n");
             break;
    case 3:  printf(" obtuse\n");
             break;
  }

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:newAngleA
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1 - angle of original triangle
*    2.double angle2 - angle of original triangle
*    3.double angle3 - angle of original triangle
*    4.double dist1 - distance between vertices
*    5.double dist2 - distance between vertices
*    6.double dist3 - distance between vertices
*    7.double angleclass - angle classification
*
*  Function Description:calculate the new angle
*
***************************************************************************/
double newAngleA(double angle1, double angle2, double angle3, double dist1, double dist2, double dist3, double angleclass)
{
  double newAngle1; //new angle number 1

  if ((int) angleclass == 1)
  {
    if ((angle3 == angle1) && (angle2 != angle1))
    {
      newAngle1 = 90 - angle1;
    }
    else if ((dist1 > dist2) && (dist1 > dist3))
    {
      newAngle1 = 90 - angle2;
    }
    else if ((dist2 > dist1) && (dist2 > dist3))
    {
      newAngle1 = 90 - angle2;
    }
    else
    {
      newAngle1 = 90 - angle2;
    }
  }
  else if ((int)angleclass == 3)
  {
    if (angle1 == angle2)
    {
      newAngle1 = 90 - angle1;
    }
    else
    {
      newAngle1 = 180 - angle1;
    }
  }
  else
  {
    newAngle1 = angle1;
  }

  return newAngle1;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:newAngleB
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1 - angle of original triangle
*    2.double angle2 - angle of original triangle
*    3.double angle3 - angle of original triangle
*    4.double dist1 - distance between vertices
*    5.double dist2 - distance between vertices
*    6.double dist3 - distance between vertices
*    7.double angleclass - angle classification
*
*  Function Description:calculate the new angle
*
***************************************************************************/

double newAngleB(double angle1, double angle2, double angle3, double dist1, double dist2, double dist3, double angleclass)
{
  double newAngle2; //new angle number 2

  if ((int)angleclass == 1)
  {
    if ((angle3 == angle1) && (angle2 != angle1))
    {
      newAngle2 = 180 - angle2;
    }
    else if ((dist1 > dist2) && (dist1 > dist3))
    {
      newAngle2 = 90 - angle1;
    }
    else if ((dist2 > dist1) && (dist2 > dist3))
    {
      newAngle2 = 90 - angle1;
    }
    else
    {
      newAngle2 = 90 - angle1;
    }
  }
  else if ((int)angleclass == 3)
  {
    if (angle1 == angle2)
    {
      newAngle2 = 90 - angle2;
    }
    else
    {
      newAngle2 = 90 - angle3;
    }
  }
  else
  {
    newAngle2 = angle2;
  }

  return newAngle2;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:newAngleC
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double angle1 - angle of original triangle
*    2.double angle2 - angle of original triangle
*    3.double angle3 - angle of original triangle
*    4.double dist1 - distance between vertices
*    5.double dist2 - distance between vertices
*    6.double dist3 - distance between vertices
*    7.double angleclass - angle classification
*
*  Function Description:calculate the new angle
*
***************************************************************************/
double newAngleC(double angle1, double angle3, double angle2, double dist1, double dist2, double dist3, double angleclass)
{
  double newAngle3; //new angle number 3

  if ((int) angleclass == 1)
  {
    if ((angle1 == angle3) && (angle1 != angle2))
    {
      newAngle3 = 90 - angle3;
    }
    else if ((dist1 > dist2) && (dist1 > dist3))
    {
      newAngle3 = 180 - angle3;
    }
    else if ((dist2 > dist1) && (dist2 > dist3))
    {
      newAngle3 = (180 - angle3);
    }
    else
    {
      newAngle3 = (180 - angle3);
    }
  }
  else if ((int)angleclass == 3)
  {
    if (angle1 == angle2)
    {
      newAngle3 = 180 - angle3;
    }
    else
    {
      newAngle3 = (90 - angle2);
    }
  }
  else
  {
    newAngle3 = angle3;
  }

  return newAngle3;
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
*    1.double pty1 - point 1 y
*    2.double pty2 - point 2 y
*    3.double pty3 - point 3 y
*    4.double angleA - angle of original triangle
*    5.double angleB - angle of original triangle
*    6.double angleC - angle of original triangle
*
*  Function Description:calculates the orthocenter
*
***************************************************************************/
double orthoY(double pty1, double pty2, double pty3, double angleA, double angleB, double angleC)
{
  double orthocentery; //stores the y coordinate of the orthocenter
  double rad1; //stores the angle in radians
  double rad2; //stores the angle in radians
  double rad3; //stores the angle in radians

  rad1 = angleA * M_PI / 180;
  rad2 = angleB * M_PI / 180;
  rad3 = angleC * M_PI / 180;

  orthocentery = (pty1 * tan(rad1) + pty2 * tan(rad2) + pty3 * tan(rad3)) / (tan(rad1) + tan(rad2) + tan(rad3));

  return orthocentery;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:orthoX
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double ptx1 - point 1 x
*    2.double ptx2 - point 2 x
*    3.double ptx3 - point 3 x
*    4.double angleA - angle of original triangle
*    5.double angleB - angle of original triangle
*    6.double angleC - angle of original triangle
*
*  Function Description:calculates the x coordinate of orthocenter
*
***************************************************************************/
double orthoX(double ptx1, double ptx2, double ptx3, double angleA, double angleB, double angleC)
{
  double orthocenter_x; //stores the x coordinate of the orthocenter
  double rad1; //stores the angle in radians
  double rad2; //stores the angle in radians
  double rad3; //stores the angle in radians
  double newX; //new X

  rad1 = angleA * M_PI / 180;
  rad2 = angleB * M_PI / 180;
  rad3 = angleC * M_PI / 180;

  orthocenter_x = (ptx1 * tan(rad1) + ptx2 * tan(rad2) + ptx3 * tan(rad3)) / (tan(rad1) + tan(rad2) + tan(rad3));

  if ((int) orthocenter_x == 0)
  {
    newX = 0.00;
  }
  else
  {
    newX = orthocenter_x;
  }

  return newX;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:internalAngle
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double dist1 - distance 1
*    2.double dist2 - distance 2
*    3.double dist3 - distance 3
*
*  Function Description:calculate the internal angle for the original triangle
*
***************************************************************************/
double internalAngle(double dist1, double dist2, double dist3)
{
  double angle; //stores the angle
  double calc; //stores the calculation

  calc = ((pow(dist3, 2) + pow(dist1, 2) - pow(dist2, 2)) / (2 * dist3 * dist1));
  angle = acos(calc) * (180 / M_PI);

  return angle;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:distance
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double pt1x - x coordinate of point 1
*    2.double pt1y - y coordinate of point 1
*    3.double pt2x - x coordinate of point 2
*    4.double pt2y - y coordinate of point 2
*
*  Function Description:get the distance between points
*
***************************************************************************/
double distance(double pt1x, double pt1y, double pt2x, double pt2y)
{
  double dist; //stores the distance between points

  dist = sqrt(pow(pt2x - pt1x, 2) + pow(pt2y - pt1y, 2));

  return dist;

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:input
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double *ptx1 - point 1 x
*    2.double *pty1 - point 1 y
*    3.double *ptx2 - point 2 x
*    4.double *pty2 - point 2 y
*    5.double *ptx3 - point 3 x
*    6.double *pty3 - point 3 y
*
*  Function Description:this function gets input from user
*
***************************************************************************/
void input(double *ptx1, double *pty1, double *ptx2, double *pty2, double *ptx3, double *pty3)
{

  printf("Enter point #1 -> ");
  scanf("%lf %lf", ptx1, pty1);
  printf("Enter point #2 -> ");
  scanf("%lf %lf", ptx2, pty2);
  printf("Enter point #3 -> ");
  scanf("%lf %lf", ptx3, pty3);

}

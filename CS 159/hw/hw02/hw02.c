/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #:2
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30, Virtual
*
*  Program Description: we are asked to calculate the resulting tension on each cable connecting the aircraft and the acceleration of the glider, given the mass of an airplane, the amount of forward force produced by its propellers, and the mass of the two gliders it is towing.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

int main (void)
{
  //local declarations
  double accel; //store the calulated acceleration
  double mass_airplane; //store the given mass of the airplane
  double mass_glider1; //store the given mass of glider 1
  double mass_glider2; //store the given mass of glider 2
  double force; //store the given force
  double totalMass; //store the total mass of the system
  double tension1; //store the calculated tension for rope between airplane and glider 1
  double tension2; //store the calculated tension for rope between glider 1 and glider 2
  double width_force; //store the width for output for force
  double width; //store the width which is calculated as the number of digits in the force input plus six

  //Statements
  printf("Enter mass of airplane (kg) -> ");
  scanf("%lf", &mass_airplane);
  printf("Enter mass of glider #1 (kg) -> ");
  scanf("%lf", &mass_glider1);
  printf("Enter mass of glider #2 (kg) -> ");
  scanf("%lf", &mass_glider2);
  printf("Enter force produced by propellers (N) -> ");
  scanf("%lf", &force);

  totalMass = mass_airplane + mass_glider1 + mass_glider2; //calculated the total mass of the system
  accel = force / totalMass; //calculate the acceleration of the system
  tension2 = (mass_glider2 * force) / totalMass; //calculate the tension between glider 1 and glider 2
  tension1 = ((mass_glider1 + mass_glider2) * force) / totalMass; //calculates the tension between glider 1 and the airplane
  width_force = log10(force) + 1; //count the number of digits in the force
  width = width_force + 6; //count the width modifier

  printf("\nAcceleration: %.2f m/s^2", accel);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nResulting tension on cable #1:%*.2f Newtons", (int) width, tension1);
  printf("\nResulting tension on cable #2:%*.2f Newtons", (int) width, tension2);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
} //main

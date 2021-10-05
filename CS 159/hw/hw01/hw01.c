/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3633@purdue.edu
*
*  Homework #: 01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday 9:30-11:20AM DISTANCE OL
*
*  Program Description: Given the mass of the airplane, the amount of forward force produced by its propellers, and the mass of the glider it is towing, we are asked to  calculate the resulting tension on the cable connecting the two aircraft and the acceleration of the glider.
*
***************************************************************************/
#include<stdio.h>
int main (void)
{
  //Local Declarations
  float accel; // stores the accelerations calculated
  float mass_airplane; //stores the mass of the airplane given by the user
  float mass_glider; // stores the mass of the glider given
  float force; //stores the force given
  float totalMass; //stores the calculated total mass of system
  float tensionTotal; //stores the final calculated tension

  //Statements
  printf("Enter mass of airplane (kg) -> ");
  scanf("%f", &mass_airplane);
  printf("Enter mass of glider (kg) -> ");
  scanf("%f", &mass_glider);
  printf("Enter force produced by the propellers (N) -> ");
  scanf("%f", &force);

  totalMass = mass_airplane + mass_glider; //calculates the total mass of system by adding mass of airplane and mass of glider together
  accel = force / totalMass; //calculates the acceleration
  tensionTotal = force * (mass_glider / totalMass); //calculates the resulting tension on the cable connecting the two airgraft and the acceleration of the glider.

  printf("\nResulting tension: %0.2f Newtons", tensionTotal);
  printf("\nAcceleration of glider: %0.2f m/s^2\n", accel);

  return 0;
} //main

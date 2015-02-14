/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 *	Assignment #2
 *
 *	Calculate projectile flight duration
 */

#include <stdio.h>  /* scanf, printf definitions */
#include <math.h>	/* math definitions */
#define G 32.17

/* function prototype */
void displayInstructions(void);	/* displays the instructions for the user */
void displayResults(double time, double height); /* Displays the results */

int
main(void) {
	double theta;		/* input - angle of elevation in radians */
	double distance;	/* input - distance to target in feet */
	double velocity;	/* input - projectile velocity in ft/sec */
	double time;		/* output - time of flight in seconds */
	double height;		/* output - height at impact */
	
	/* Display instructions to user */
	displayInstructions();
	
	/* Prompt user for input */
	printf("Enter the angle of elevation in radians> ");
	scanf("%lf", &theta);
	printf("Enter the distance to the target in feet> ");
	scanf("%lf", &distance);
	printf("Enter the projectile velocity in ft/sec> ");
	scanf("%lf", &velocity);
	
	/* Calculate the time of flight and the height at impact */
	time = distance / (velocity * cos(theta));
	height = (velocity * sin(theta) * time) - ((G * pow(time, 2))/2);
	
	/* Output the results */
	displayResults(time, height);
	return (0);
}

/* Display the initial instructions for the program */
void
displayInstructions(void) {
	printf("This program computes the duration of a projectile's flight\n");
	printf("and its height above the ground when it reaches the target.\n");
	printf("To use this program, enter the angle, the distance, and\n");
	printf("the velocity after each prompt.\n \n");
	
	return;
}


/* Takes time and height as input and prints them to the screen */
void
displayResults(double time, double height) {
	printf("The time of flight is %.3f seconds\n", time);
	printf("The height at impact is %.3f feet\n", height);
}
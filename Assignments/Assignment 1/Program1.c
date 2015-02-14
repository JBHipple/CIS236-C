/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 *	Assignment #1
 *
 *	Create a program that converts a temperature from Fahrenheit to Celsius
 */
 
#include <stdio.h>  /* scanf, printf definitions */

int
main(void) {
	int fahrenheit; /* temperature in Fahrenheit */
	double celsius; /* converted temperature to Celsius */
	
	/* Take input for fahrenheit */
	printf("Enter the temperature in Fahrenheit> ");
	scanf("%d", &fahrenheit);
	
	/* Convert the temperature to Celsius */
	celsius = (5.0 / 9.0) * (fahrenheit - 32);
	
	/* Output the result */
	printf("That equals %.2f Celsius\n", celsius);
	
	return (0);
}

/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 * 	Assignment #5
 *
 *	Calculate charge based on power used.
 */

#include <stdio.h>	/* scanf, printf definitions */

/* function prototypes */
void getData(int *cnum, int *kwh);					/* Gets input, using pointers for output variables */
double calculateCharge(int kwh);					/* Calculates and returns charge based on kwh input */
void printResults(int cnum, int kwh, double charge);/* Prints results to screen */
char promptContinue(void);							/* Prompts user if they have more data */

int
main(void) {
	/* Variable declarations */
	int customerNumber; 	/* Stores the customer's number */
	int kwhUsed;			/* Stores the amount of kilowatt hours used */
	int numOfCustomers = 0;	/* Stores the number of customers */
	int totalKwh = 0;		/* Stores total kwh used */
	double customerCost;	/* Stores the total cost to customer */
	double totalCost = 0.0; /* Stores running total of cost */
	char loopFlag = 'y';	/* Stores value used to determine if loop should continue */
	
	/* Loop through input and calculation until loopFlag = 'y' */
	while (loopFlag == 'y') {
		getData(&customerNumber, &kwhUsed);
		customerCost = calculateCharge(kwhUsed);
		printResults(customerNumber, kwhUsed, customerCost);
		numOfCustomers++;
		totalKwh += kwhUsed;
		totalCost += customerCost;
		loopFlag = promptContinue();
	}
	
	/* Print totals */
	printf("\n=============================================================================\n\n");
	printf("Total Customers: %d     Total KWH Used: %d     Total Charges: %.2f\n", numOfCustomers, totalKwh, totalCost);
	printf("\n--------------------------------");
	
	return (0);
}

/* Prompts user for customerNumber and kwhUsed
 * Pre:  cnum and kwh are pointers to customerNumber and kwhUsed
 * Post: User prompted data is stored in output variables via
 * 		 pointer variables
 */
void
getData(int *cnum, int *kwh) {
	char discard;	/* Stores space to be discarded */

	printf("\nEnter Customer Number and kwH: ");
	scanf("%d %d", cnum, kwh);
}

/* Calculates charge basd on kwhUsed */
double
calculateCharge(int kwh) {
	double charge;	/* holds return value, for simplicity */
	
	/* Calculate charge when kwh is over 1000 */
	if (kwh > 1000) {
		charge = ((kwh - 1000) * .05) + 75;
	}
	/* Calculate charge when kwh is not over 1000 but over 600 */
	else if (kwh > 600) {
		charge = ((kwh - 600) * .06) + 51;
	}
	/* Calculate charge when kwh is not over 600 but over 300 */
	else if (kwh > 300) {
		charge = ((kwh - 300) * .08) + 27;
	}
	/* Calculate charge when kwh is not over 300 */
	else {
		charge = kwh * .09;
	}
	
	/* return the value */
	return (charge);
}

/* Prints customer info and charge to screen */
void
printResults(int cnum, int kwh, double charge) {
	printf("\nCustomer Num: %d           KWH Used: %d           Charge:  %.2f\n\n", cnum, kwh, charge);
}

/* Prompts user if they have more data, returns Y if yes, N if no. */
char
promptContinue(void) {
	char tempChar;	/* Stores character input before return */
	char dumpChar;	/* clears scanf buffer */

	printf("Do you have more data? (y/n)>");
	scanf("%c%c", &dumpChar, &tempChar);
	if (tempChar == 'y' || tempChar == 'Y') {
		return ('y');
	}
	else {
		return ('n');
	}
}
/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 * 	Assignment #6
 *
 *	Take input and increment array based on range of values
 */
 
 #include <stdio.h> /* input, output functions */
 
 /* function prototypes */
 void updateRange(int numAccidents, int range[]);  	/* Increments array index corresponding with range numAccidents falls into */
 void displayRange(int range[]);					/* Displays range array */
 
 int
 main(void) {
	/* Variable declarations */
	int range[6] = {0, 0, 0, 0, 0, 0};	/* Stores array of ranges of values */
	int numAccidents;					/* Takes input of number of accidents */
	
	/* Priming input */
	printf("Enter an accident count (negative to end): ");
	scanf("%d", &numAccidents);
	
	/* Process data while sentinel not entered */
	while (numAccidents >= 0) {
		updateRange(numAccidents, range);
		printf("Enter an accident count (negative to end): ");
		scanf("%d", &numAccidents);
	}
	
	/* Output results */
	displayRange(range);
	
	return (0);
 }
 
 /* takes numAccidents, finds correct range, increments value */
 void
 updateRange(int numAccidents, int range[]) {
	/* increment the correct index of range[] corresponding to the correct range */
	if (numAccidents < 100) {
		range[0]++;
	}
	else if (numAccidents < 200) {
		range[1]++;
	}
	else if (numAccidents < 300) {
		range[2]++;
	}
	else if (numAccidents < 400) {
		range[3]++;
	}
	else if (numAccidents < 500) {
		range[4]++;
	}
	else {
		range[5]++;
	}
	
	return;
 }
 
 /* Displays the results */
 void
 displayRange(int range[]) {
	printf("\n  Range  Frequency\n\n");
	printf("  0- 99\t\t%2d\n", range[0]);
	printf("100-199\t\t%2d\n", range[1]);
	printf("200-299\t\t%2d\n", range[2]);
	printf("300-399\t\t%2d\n", range[3]);
	printf("400-499\t\t%2d\n", range[4]);
	printf("500 or above\t%2d\n", range[5]);
	
	return;
 }
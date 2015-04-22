/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 * 	Assignment #9-2
 *
 *	Take input from binary file, process, and output to screen
 */
 
 #include <stdio.h>			/* input, output functions */
 #define MAX_ARR_SIZE	25 	/* Size of array holding household structs */
 
 typedef struct {
	int id;			/* Holds household ID*/
	int income;		/* Holds household income */
	int numMembers;	/* Holds number of household members */
} household_t;

/* Function Prototyes */
int fillArray(household_t houseList[], FILE *infile);
void printArray(int count, household_t houseList[]);
double averageIncome(int count, household_t houseList[]);
void aboveAverage(int count, double average, household_t houseList[]);
double poverty(int count, household_t houseList[]);

int
main(void) {
	int count;							/* Holds number of household_t's in houseList minus 1 */
	household_t houseList[MAX_ARR_SIZE];	/* Array of household_t structs */
	double average;							/* Holds the average income of all valid household_t's */
	double povertyPercent;					/* Holds percentage of households below poverty */
	FILE *infile;							/* The file to input from */
	
	/* Open the file */
	infile = fopen("household.dat", "rb");
	
	/* Fill the array with data from file */
	count = fillArray(houseList, infile);
	if (count == -1) {
		printf("Error: File is empty");
		return (0);
	}
	
	/* Print the array */
	printArray(count, houseList);
	
	/* Calculate the average income and print to screen */
	average = averageIncome(count, houseList);
	printf("\nThe Average Household Income is $%8.2f\n\n", average);
	
	/* List the households above the average income */
	aboveAverage(count, average, houseList);
	
	/* Calculate the percentage of houses under the poverty line and output */
	povertyPercent = poverty(count, houseList);
	printf("\nThe Percentage of Houses Below the Poverty Level is %%%6.2f", (povertyPercent * 100));
	
	/* close the file and end the program */
	fclose(infile);
	return (0);
}

/* Reads data from infile and saves to array of household_t structs */
/* Returns int containing the number of files read in */
int
fillArray(household_t houseList[], FILE *infile) {
	int inputData;	/* Holds data from input to pass to struct */
	int status = 1; /* Used to determine if at end of file */
	int i = -1;
	
	/* Loop through reading data from file, saving to structs */
	/* Uses i to increment through array, and passes to main as count */
	status = fread(&inputData, sizeof (int), 1, infile);
	while (status != 0) {
		i++;
		houseList[i].id = inputData;
		fread(&houseList[i].income, sizeof (int), 1, infile);
		fread(&houseList[i].numMembers, sizeof (int), 1, infile);
		status = fread(&inputData, sizeof (int), 1, infile);
	}
	
	return (i);
}

/* Prints the contents of the array to the screen */
void
printArray(int count, household_t houseList[]) {
	/* Print header */
	printf("Identification Number\tAnnual Income\tHousehold Members\n");
	
	/* Loop through array and print each record */
	for (int i = 0; i <= count; i++) {
		printf("\t%4d\t\t  $%6d\t\t%d\n", houseList[i].id, houseList[i].income, houseList[i].numMembers);
	}
	printf("\n");
	return (0);
}

/* Calculates the average income among households in array */
double
averageIncome(int count, household_t houseList[]) {
	int total = 0; 	/* Holds running total of all households */
	double average;	/* holds calculated average income */
	
	/* Loop through array and increment total for each record */
	for (int i = 0; i <= count; i++) {
		total += houseList[i].income;
	}
	
	/* calculate average, casting total to a double and adding one to count (which is 1 less than the actual count) */
	average = (double)total / (count + 1);
	
	return (average);
}

/* Lists the houses above the average income */
void
aboveAverage(int count, double average, household_t houseList[]) {
	/* Print headers */
	printf("Houses with above average income:\n\n");
	printf("Identification Number\tAnnual Income\n");
	
	/* Loop through array and print each record with income > average */
	for (int i = 0; i <= count; i++) {
		if (houseList[i].income > average) {
			printf("\t%4d\t\t  $%6d\n", houseList[i].id, houseList[i].income);
		}
	}
	printf("\n");
	return (0);
}

/* Calculates the percentage of households under the poverty level */
double
poverty(int count, household_t houseList[]) {
	int numPoverty = 0;	/* Holds number of households under poverty level */
	double povertyPercent; /* Holds percentage of poverty */
	
	/* Loop through array, increment numPoverty if record has income below calculated poverty level */
	for (int i = 0; i <= count; i++) {
		double thisPoverty;
		thisPoverty = 7500 + (950 * (houseList[i].numMembers - 2));
		if ((double)houseList[i].income < thisPoverty) {
			numPoverty++;
		}
	}
	
	/* Calculate poverty level and return */
	povertyPercent = (double)numPoverty / (count + 1);
	
	return (povertyPercent);
}
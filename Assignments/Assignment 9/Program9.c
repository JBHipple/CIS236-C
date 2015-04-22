/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 * 	Assignment #9-1
 *
 *	Take input into struct and output to binary file
 */
 
 #include <stdio.h> 	/* input, output functions */
 
 /* Function Prototypes */
 void takeInput(FILE *outfile, int items);  /* Takes input and writes it to file */
 
 int
 main(void) {
	int items; 		/* number of items to input */
	FILE *outfile;	/* pointer to file used for output */
	
	/* Prompt use for number of records to input */
	printf("How many records will you be entering? (1-25) ");
	scanf("%d", &items);
	
	/* Check if value is between 1 and 25 */
	while ((items < 1 ) || (items > 25)) {
		if(items < 1) {
			printf("\n***Number of records must be higher than 0***\n\n");
		}
		else {
			printf("\n***Number of records must be less than 25***\n\n");
		}
		printf("How many records will you be entering? (1-25) ");
		scanf("%d", &items);
	}
	
	/* Open the file for output in binary */
	outfile = fopen("household.dat", "wb");
	
	/* Call function to take input and write to file */
	takeInput(outfile, items);
	
	/* Close the file and inform the user the data has been saved */
	fclose(outfile);
	printf("\nData has been successfully saved in household.dat");
 
	return (0);
 }
 
 /* Takes input of a file pointer and a number of items */
 /* Loops for each item, prompting for input, then writing the input to file */
 void
 takeInput(FILE *outfile, int items) {
	int inputData;	/* Holds data from input before saving to file */
	
	/* Loop through for each item, taking input and writing to binary file */
	for (int i = 1; i <= items; i++) {
		printf("\nWhat is the house identification number? ");
		scanf("%d", &inputData);
		fwrite(&inputData, sizeof (int), 1, outfile);
		printf("What is the household annual income? ");
		scanf("%d", &inputData);
		fwrite(&inputData, sizeof (int), 1, outfile);
		printf("How many menbers are in the household? ");
		scanf("%d", &inputData);
		fwrite(&inputData, sizeof (int), 1, outfile);
	}
	
	return (0);
 }
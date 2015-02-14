/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 *	Assignment #2
 *
 *	Calculate projectile flight duration
 */
 
 #include <stdio.h> /* scanf, printf definitions */
 
 /* function prototypes */
 int getTemp(void);		/* prompts user for temperature input */
 
 int
 main(void) {
	/* Variable declarations */
	int inputTemp;		/* Stores the most recent input temp */
	int tempCount;		/* Stores a running count of the number of temperatures input */
	int tempTotal;		/* Stores the running sum of all temperatures */
	int hotDays;		/* Stores a count of days with temp 85 or higher */
	int pleasantDays; 	/* Stores a count of days with temp in range 60-84 */
	int coldDays;		/* Stores a count of days with temp less than 60 */
	double averageTemp;	/* Stores the calculated average of all temperatures */
	
	/* reset values */
	tempCount = 0;
	tempTotal = 0;
	hotDays = 0;
	pleasantDays = 0;
	coldDays = 0;
	
	/* Take priming input */
	inputTemp = getTemp();
	
	/* Enter while loop, while input does not equal sentinel value */
	while (inputTemp != -99) {
		/* increment hotDays when temp is 85 or over */
		if (inputTemp >= 85) {
			hotDays++;
		}
		/* increment coldDays when temp is under 60 */
		else if (inputTemp < 60) {
			coldDays++;
		}
		/* increment pleasantDays when temp is 60-84 (the resulting range) */
		else {
			pleasantDays++;
		}
		
		/* increment the tempCount and add input to tempTotal */
		tempCount++;
		tempTotal += inputTemp;
		
		/* Prompt user and take input */
		inputTemp = getTemp();
	}
	
	/* Output hot, cold, and pleasant day totals */
	printf("\nThe number of hot days is %d.\n", hotDays);
	printf("The number of pleasant days is %d.\n", pleasantDays);
	printf("The number of cold days is %d.\n\n", coldDays);
	
	/* Calcuate and output average temperature */
	averageTemp = (double)tempTotal / (double)tempCount;
	printf("The average temperature is %.2f", averageTemp);
	
	/* end program */
	return (0);
 }
 
 /* getTemp
  * Prompts user for input.
  * Input is returned
  */
 int
 getTemp(void) {
	int inputTemp;	/* holds user's input to be returned */
	
	/* Prompt user and take input */
	printf("Enter the temperature (-99 to stop):");
	scanf("%d", &inputTemp);
	
	/* Return value to calling function */
	return(inputTemp);
 }
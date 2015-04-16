/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 * 	Assignment #8
 *
 *	Take input and increment array based on range of values
 */
 
 #include <stdio.h>  /* input, output functions */
 #include <string.h> /* string functions */
 
 /* Function Prototypes */
void two_ele_subs(char theString[]);  /* Prints 2-element subsets of passed string */

int
main(void) {
	char theString[40]; /* Holds string input */
	int eofFlag = 0;	/* Holds return value of string scan, -1 represents EOF */
	
	/* Take priming input */
	printf("Enter a string: ");
	eofFlag = scanf("%s", theString);
	
	/* While EOF character not entered, call function, then ask for more input */
	while (eofFlag != -1) {
		two_ele_subs(theString);
		printf("\n\nEnter a string: ");
		eofFlag = scanf("%s", theString);
	}
	
	return (0);
}

/* Takes input of string, recursively moves through string and prints all 2 letter combinations */
void
two_ele_subs(char theString[]) {
	/* Find length of the string */
	int stringLength = 0;
	stringLength = strlen(theString);
	
	/* StringLength of less than 2 means no pairs can exist anymore, stop recursive calls */
	if (stringLength < 2) {
		return (0);
	}
	/* Loop through the string, starting with 2nd character, and print each pair of first letter and */
	/* other letters, then recursively call function with string starting with 2nd character of original string */
	else {
		for (int i = 1; i < stringLength; i++) {
			printf("[%c,%c]\n", theString[0], theString[i]);
		}
		two_ele_subs(&theString[1]);
		return (0);
	}
}
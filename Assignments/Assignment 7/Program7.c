/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 * 	Assignment #7
 *
 *	Take input into parallel arrays, sort arrays, keeping originals intact, output both
 */
 
 #include <stdio.h> /* input, output functions */
 #include <string.h> /* string functions */
 
 /* function prototypes */
 /* void sortArrays(int sortedList[], char names[]); /* creates a separate array of indexes of sorted order */
 /* void outputOriginalArrays(int numPeople, char names[], int ages[]); /* outputs original lists */
 /* void outputSortedArrays(int numPeople, int sortedList[], char names[], int ages[]); /* output sorted lists */
 
 int
 main(void) {
	int numPeople; /* input, number of people in list */
	char clear[80];
	char input[40];
	
	printf("Enter number of people (0..50)\n>");
	scanf("%d", &numPeople);
	
	gets(clear);
	
	
	char names[numPeople][40];
	int ages[numPeople];
	int sortedList[numPeople];
	int wtf;
	
	for (int i = 0; i < numPeople; i++) {
		printf("\nEnter name %d (lastname, firstname): ", i + 1);
		gets(names[i]);
		printf("Enter age %d: ", i + 1);
		scanf("%d", &ages[i]);
		scanf("%c", &clear[0]);
		sortedList[i] = i;
	}
	
	printf("\nOriginal List\n");
	printf("---------------------------\n");
	for (int i = 0; i < numPeople; i++) {
		printf("%-20s\t\t\t%d\n", names[i], ages[i]);
	}

	
	/* sortArrays */
	int minIndex = 0;
	int temp;
	for (int i = 0; i < numPeople; i++){
		minIndex = i;
		for (int j = i + 1; j < numPeople; j++){
			if (strcmp(names[sortedList[j]], names[sortedList[minIndex]]) < 0) {
				minIndex = j;
			}
		}
		if (i != minIndex) {
			temp = sortedList[i];
			sortedList[i] = sortedList[minIndex];
			sortedList[minIndex] = temp;
		}
	}
	
	
	printf("\nAlphabetized List\n");
	printf("---------------------------\n");
	for (int i = 0; i < numPeople; i++) {
		printf("%-20s\t\t\t%d\n", names[sortedList[i]], ages[sortedList[i]]);
	}
	
	
	printf("\nOriginal List\n");
	printf("---------------------------\n");
	for (int i = 0; i < numPeople; i++) {
		printf("%-20s\t\t\t%d\n", names[i], ages[i]);
	}
	
	return (0);
}
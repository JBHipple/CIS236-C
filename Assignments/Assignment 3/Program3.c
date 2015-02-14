/*
 *	Joshua Hipple
 *	CIS 236 - W1
 *
 *	Assignment #3
 *
 *	
 */
 
 #include <stdio.h> /* scanf, printf definitions */
 #define LOW_DISCOUNT .10
 #define HIGH_DISCOUNT .12
 #define SALES_TAX .05
 
 /* function prototypes */
 char getTeacher(void);		/* finds out if user is a teacher */
 double getPurchases(void);	/* gets number of purchases */
 double calcDiscount(double purchases, char isTeacher);  /* determines if a discount should be used and applies it, returning discount amount */
 
 int
 main(void) {
	char isTeacher;	/* input - flag for teacher's discount */
	double purchases;	/* input - number of purchases made */
	double discountAmount;	/* output - amount of discount */
	double subTotal;		/* output - total before tax */
	double taxTotal;		/* output - total tax assessed */
	double total;			/* output - total of purchase */
	
	/* get input from user for isTeacher and purchases insert blank line start displaying */
	isTeacher = getTeacher();
	purchases = getPurchases();
	printf("Purchases after return %f\n", purchases);
	printf("\n");
	printf("Total Purchases         $%.2f\n", purchases);

	
	/* find total, apply discount and tax display output as it is calculated*/
	discountAmount = calcDiscount(purchases, isTeacher);
	subTotal = purchases - discountAmount;
	printf("Discounted Total         %.2f\n", subTotal);
	taxTotal = subTotal * SALES_TAX;
	printf("Sales Tax (5%%)           %.2f\n", taxTotal);
	total = subTotal + taxTotal;
	printf("Total                    %.2f", total);
	
	return (0);
 }
 
 /* Find out if user is a teacher, if input is invalid call again */
 char
 getTeacher(void) {
	char is_Teacher;
	char bufferClear;
 
	printf("Is customer a teacher (Y/N)?> ");
	scanf("%c", &is_Teacher);
	
	/* returns isTeacher if input is valid, otherwise calls getTeacher recursively to get valid input */
	if ((is_Teacher == 'Y' || is_Teacher == 'y') || (is_Teacher == 'N' || is_Teacher == 'n')) {
		return (is_Teacher);
	}
	else {
		printf("\nInvalid input: Must enter Y or N.\n");
		return(getTeacher());
	}
 }
 
 /* Gets amount of purchases */
 double
 getPurchases(void) {
	double purchases;
	
	printf("Enter total purchases: ");
	scanf("%lf", &purchases);
	printf("purchases before return %f\n", purchases);
	
	return (purchases);
 }
 
 /* Calculate discount amount and return it */
 double
 calcDiscount(double purchases, char isTeacher) {
	double discountAmount; 
	
	if (isTeacher == 'Y' || isTeacher == 'y'){
		if (purchases >= 100) {
			discountAmount = purchases * HIGH_DISCOUNT;
			printf("Teacher's discount(12%%)  %.2f\n", discountAmount);
			return (discountAmount);
		}
		else {
			discountAmount = purchases * LOW_DISCOUNT;
			printf("Teacher's discount(10%%)  %.2f\n", discountAmount);
			return (discountAmount);
		}
	}
	else {
		printf("Teacher's discount(0%%)   0\n");
		return (0);
	}
 }
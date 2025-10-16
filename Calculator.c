#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int z = 0;
	char value1[99];
	char value2[99];
	char operator[2];

	printf("Please enter the first value! :");
	scanf("%98s", value1);
	printf("Enter the second value");
	scanf("%98s", value2);
	printf("Now select the operator, + - / * :");

	scanf("%1s", operator);
	int num1 = atoi(value1);
	int num2 = atoi(value2);

	if (operator[0] == '+') {
		z = num1 + num2;
		printf("%i", z);
	}
	else if (operator[0] == '-') {
		z = num1 - num2;
		printf("%i", z);
	}
	else if (operator[0] == '/') {
		z = num1 / num2;
		printf("%i", z);
	}
	else if (operator[0] == '*') {
		z = num1 * num2;
		printf("%i", z);
	}
	else {
		printf("Please restart the program and enter a valid value and/or operator");
	}
	return 0;
}
// Use of if statements shown above, if(operator[0] == '+' { it basically says, if said operator is equal to + then do division, which is shown in the following line, as is the same for every other else if satement, with their correspondent functional operator
//Atoi is a from the stdlib libary, and it's purpose is to read a repressantation of a whole number from a string, and return the value, in this case, it reads char value1 and char value2, stores is as an integer into int num1 and num2, shown, 17 and 18.

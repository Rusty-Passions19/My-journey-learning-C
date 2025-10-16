#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Calculator() {
	int a;
	int b;
	char Operator;
	printf("Please choose the first number!: \n");
	scanf("%i", &a);
	printf("Please choose the second number!: \n");
	scanf("%i", &b);
	printf("Choose an operator, for addition +, for subtraction -, for division /, for multiplication *: \n");
	scanf(" %c", &Operator);
	if (Operator == '+') {
		printf("%i\n", a + b);
	}
	else if (Operator == '-') {
		printf("%i\n", a - b);
	}
	else if (Operator == '/') {
		printf("%i\n", a / b);
	}
	else if (Operator == '*') {
		printf("%i\n", a * b);
	}
}

void ASCII() {
	char c;
	int Integer;
	printf("Hello and welcome to the ASCII program!\n ");
	printf("Please enter a single character, you would like to convert into it's integer counterpart!: \n");
	scanf(" %c", &c);
	printf("%i\n", c);

	printf("Now enter a digit!: \n");
	scanf(" %i", &Integer);
	printf("%c", Integer);
}

void Temp() {
	float Temp;
	char Choice;
	printf("Welcome to the temp conversion program\n");
	printf("Enter the current temprature, so the digits of it, ie 20 30 etc, and then the format you would like to convert it to, C for celsius, or F for the other thing: \n");
	scanf("%f %c", &Temp, &Choice);
	if (Choice == 'C') {
		printf("%f", (Temp - 32) * 5 / 9);
	}
	else if (Choice == 'F') {
		printf("%f", (Temp * 9 / 5) + 32);
	}
}

int main() {
	int Option;
	printf("Menu launching...\n");
	printf("1: Calculator!\n");
	printf("2: ASCII conversion!\n");
	printf("3: Temp conversion!\n");
	printf("Please select a choice!\n");
	printf("Select a number for the correlating option, 1 for calculator etc!\n");
	scanf("%i", &Option);
	if (Option == 1) {//If staetement, so when choice is equal to 1
		Calculator(); //We call the calculator function
	}
	else if (Option == 2) {
		ASCII();
	}
	else if (Option == 3) {
		Temp();
	}
}

// & serves the same purpose as in Rust, let's us mute the variable/integer or refference it.
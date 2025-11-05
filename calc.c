#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h> // Needed to use strcmp
void ADDITION()
{
	int a;
	int b;
	printf("Please enter the first value \n");
	scanf("%d", &a);
	printf("Please enter the second value \n");
	scanf("%d", &b);
	int y = a + b;
	printf("%d \n", y);
}
void SUBTRACTION()
{
	int c;
	int d;
	printf("Please enter the first value \n");
	scanf("%d", &c);
	printf("Please enter the second value \n");
	scanf("%d", &d);
	int x = c - d;
	printf("%d \n", x);
}
void MULTIPLICATION()
{
	int e;
	int f;
	printf("Please enter the first value \n");
	scanf("%d", &e);
	printf("Please enter the second value \n");
	scanf("%d", &f);
	int h = e * f;
	printf("%d \n", h);
}
void DIVISION()
{
	double g;
	double i;
	printf("Please enter the first value \n");
	scanf("%lf", &g);
	printf("Please enter the second value \n");
	scanf("%lf", &i);
	double z = g / i;
	printf("%lf\n", z); 
}
int main()
{
	char mode[20];
	printf("Please select a mode, addition for addition, subtraction for subtraction, multiplication for multiplication, division for divsion, or you can alternatively use their following respective symbols + - * / \n");
	scanf("%19s", mode);
	if (strcmp(mode, "+") == 0 || strcmp(mode, "addition") == 0)
{
	ADDITION();
}
	else if (strcmp(mode, "-") == 0 || strcmp(mode, "subtraction") == 0) 
{
	SUBTRACTION();
}
	else if (strcmp(mode, "*") ==0 || strcmp(mode, "multiplication") ==0)
{
	MULTIPLICATION();
}
	else if (strcmp(mode, "/") ==0 || strcmp(mode, "division") == 0)
{
	DIVISION();
}
	return 0;
}

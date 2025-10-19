#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // for calling the fucntion srand (pseudo random generated number)
#include <time.h> //includes the pesudo number generator, since C can't actually generate a random number, it seeds it from the clock.
//Notes initially I had declared int randomnumber; before srand(time(NULL)); and I tried to make it equal to ran() % valMax +1;, but the function doesn't xist yet, so of course it throws an error.
int main()
{
	int valMax = 60; // 0 - 60
	int guess;
	srand(time(NULL)); //srand will take a value, from the time so it's a function calling time, NULL is leaving the pointer as 0
	int randomnumber = rand() % valMax + 1; //Modulos operator here will divide the clock value, by valMax +1, otherwise the value would be ricidulosuly enormous. (changed the order, srand should be called first, and then declare int randomnumber;
	printf("Welcome to the geussing game, the range is between 0-60 :) ! \n");
	//printf("%d", randomnumber); We don't actually want to print the random number, ohterwise what's the point in guessing when the user already knows!
	printf("Please enter your guess!: \n");
	scanf("%d", &guess);

	while (guess != randomnumber)
	{
		printf("Try again, you'll get hints after this try, if you get it wrong again :): \n");
		scanf("%d", &guess);
		if (guess > randomnumber) //Nested if statements and else if statements within this while loop, alternatively could've just went with if statements alone, but I wanted to integrate both the while loop and the if/else if statemetns together.
		{
			printf("You guessed too high!: \n");
		}
		else if (guess < randomnumber)
		{
			printf("You guesed to low, try again!: \n");
		}
	}
	printf("Congratulations, you won!");
}
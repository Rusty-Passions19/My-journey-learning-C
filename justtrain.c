#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void register_user(char username[10][32], char password[10][32], int *count)
{
	char newusername[99] = {
			      };
	char newpassword[99] = {
			       };
	printf("Please enter a username!:\n");
	fgets(newusername, 99, stdin); //scanf alternative for char
	newusername[strcspn(newusername, "\n")] = '\0'; //removes the trail lines
	printf("Now please enter a password!:\n"); 
	fgets(newpassword, 99, stdin);
	newpassword[strcspn(newpassword, "\n")] = '\0'; //removes trail lines.
	strcpy(username[*count], newusername); // strcpy(location, source) so the source is taken from, and moved into location. So essentially you're moving one string into another)
	strcpy(password[*count], newpassword); // Moving newpassword into password's 2d string array.
	(*count)++; //pointer added here so it increments to the original value
	printf("Welcome %s!:\n", username[*count-1]);
}
void logins(char username[10][32], char password[10][32], int *count)
{
	//int *count;
	//char username[10][17] = {

	                   	//"Default_User" //This would be in position index, [0][0], there are 10 slots for each row, and 17 rows.
				//};
	//char password[10][17] = {
		                 //"Default_Password" //This would be in position index [0][0]
				//};
	char x[10][32];
	char y[10][32];
	int userinput;
	printf("To login to an existing account type 1, to register, type 2!\n");
	scanf("%d", &userinput);
	getchar(); //Always use getchar after a scanf, to clear the input buffer.
	if (userinput ==2)
	{
		register_user(username, password, count); //Correction use count alone not * or &
	}
	else if (userinput == 1)
	{
		printf("Please enter your username!:\n");
		fgets(x[0], 32, stdin); //Reads up to 16 chars in str x, corrections made, used fgets instead of scanf for strings.
		x[0][strcspn(x[0], "\n")] = '\0';  // Remove trailing newline(removes the \n), because otherwise the comparison doesn't work, it'll read the default input to include \n, essentially, it'll be default_user =default_user\n, but these are not the same, hence the printfunction won't actually work.
		if (strcmp(username[0], x[0]) ==0) //Used strcmp, and also specificed the index, the default starting index is 0 (primary condition)
		{
			printf("Welcome: %s\n", username[0]); //%s for strings
		}							      //
		else if(strcmp(username[0], x[0]) != 0) //secondary condition
		{
			printf("Username incorrect\n");
			printf("Please enter your username again!:\n");
			fgets(x[0], 32, stdin);
			x[0][strcspn(x[0], "\n")] = '\0';
			if (strcmp(username[0], x[0]) == 0) 
					{
						printf("Welcome %s\n", username[0]);
					}
		}

		printf("Enter password! %s:\n", username[0]); 
		fgets(y[0], 32, stdin);
		y[0][strcspn(y[0], "\n")] = '\0'; //clearing the trail lines
		if (strcmp(password[0], y[0]) == 0) // primary conditiom
				{
					printf("Password correct, signing in...\n");
				}
		else if (strcmp(password[0], y[0]) != 0) //secondary condition
		{
			printf("Password incorrect, please enter the password again!:\n");
			fgets(y[0], 32, stdin); //reads up to 16 chars in string x, (we don't use scanf for chars/strings)
			y[0][strcspn(y[0], "\n")] = '\0'; //removing trail lines

		}
		//else if (userinput == 2)
		//{
		//	register_user(username, password, count); //When calling a function, you just include the names of the function and not the type, like I don't type in char username, i just type username, and not int *count, but just * count. Correction, it's &count, when pointsers are typed into a called function, you reference them.
		//}
		//I commented this out because it's been nested into the other loops, hence this block won't be executed properly
	}

}
int main(void)
{
	char username [10][32] =
	{
		"Default_User"
	};
	char password[10][32] =
	{
		"Default_Password"
	};
	int count = 1;


	logins(username, password, &count);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // so we can use isspace and isalpha

typedef enum
{
	Token_OBrace, //O for open
	Token_CBrace, //C for close
	Token_OPara, //Thought I'd clarify lol
	Token_CPara,
	Token_SemiColon,
	Token_Return,
	Token_Int,
	Token_Main, 
		
}TokenID;

void LexicalAnaylsis(FILE *fptr)
{
	char ch;
	char string[50]; //This is used for int, return, main, since ch can only take a single character :(
	int integers; //So we can use this to assign 42 to token Token_Int
	TokenID token;
	while ((ch = fgetc(fptr)) != EOF)
	{
		if (isspace(ch)) continue; //Here we are skipping spaces, so they don't count as a token
		
		if (ch == '{') token = Token_OBrace;
		else if (ch == '}') token = Token_CBrace;
		else if (ch == '(') token = Token_OPara;
		else if (ch == ')') token = Token_CPara;
		else if (ch == ';') token = Token_SemiColon;
		else if (integers == 42) token = Token_Int;
		else if (isalpha(ch))
		{
			int i = 0; // An integer to keep track of where we are putting characters in the string.
			string[i++] = ch; //The first character of string goes into 0, and we increment by 1 so the next value is stored as 1, and then the following letter is 2, and so on.
			while ((ch = fgetc(fptr)) != EOF && isalpha(ch))
			{
				string[i++] = ch;
			}
			string[i] = '\0'; //terminating the string, it ends here.
			if (strcmp(string, "return") == 0) token = Token_Return;
			else if (strcmp(string, "main") == 0) token = Token_Main;
			if (ch != EOF) ungetc(ch, fptr);
		}
	}
}

int main()
{
	FILE *fptr;
	fptr = fopen("/mnt/c/Users/Username/Desktop/tokens.txt", "w+"); //w+ allows me to write and read the file, so we're able to use while(fgets(contents, sizeof(contents), fptr) != NULL)
	if (fptr == NULL)
	{
		printf("Failed to create file");
		return 1;
	}
	char contents[1024] = {0};
	fprintf(fptr, "{ } ( ) ; int return main 42");
	rewind(fptr); // rewinds the file back to the start, so we're able to read it, hence using the w+
	while (fgets(contents, sizeof(contents), fptr) != NULL)
	{
		printf("%s", contents);
	}
	fclose(fptr);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // so we can use isspace and isalpha
// The lexical anaylsis, also called the scanner or tokenizer, is the phase of the compiler that breaks up the string (ie the source code) into a list of tokens.
// A token is the smallest unit the parser can understand, if a program is like a paragraph, tokens are like individual words. Many tokens are individual words, seperated by whitespace. Variable names, keywords, and constants, and puncutation like braces are all example of tokens.
//List of tokens in the return_2.c file from earlier.
// int keyword
// Id (identifier) "main"
//( Open parantheses
//) Close parantheses
//{ Open brace
//} Close brace
// return keyword
//Constant "2"
//Semicolon ;
//Here are all the tokens your lexical anaylsis needs to recognise, and the regular expression defining them (listed above)
// {
// }
// \(
// \)
// Semicolon ;
// return keyword return
//udebtufuer [a-zA-Z]\w*
//integer literal [0-9]+
//First task is to write a lex function, that accepts a file, and returns a list of tokens.
// Let's get into it.
// So now I have completed half a step, or I'd like to call it that, I have created FILE *fptr, and then used the fptr = fopen() function, to write and read the file, thanks to "w+"
// This part is fun, since I am going into this for the first time (the file part was easier since I know file handling, and basic file functions) :D
// I'll start by making a typedef enum, and then list each token specifically.
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
//Ok I have decided how I am going to do this, thanks to the fundamentals I learnt from the C programming language book, by Brian Kernighan
//I'll first by making a function called LexicalAnaylsis
void LexicalAnaylsis(FILE *fptr)
{
	char ch;
	char string[50]; //This is used for int, return, main, since ch can only take a single character :(
	int integers; //So we can use this to assign 42 to token Token_Int
	TokenID token;
	while ((ch = fgetc(fptr) != EOF))
{
	if (isspace(ch)) continue; //Here we are skipping spaces, so they don't count as a token
	
	if (ch == '{') token = Token_OBrace;
	else if (ch == '}') token = Token_CBrace;
	else if (ch == '(') token = Token_OPara;
	else if (ch == ')') token = Token_CPara;
	else if (ch == ';') token = Token_SemiColon;
	else if (integers == 42) token = Token_Int;
	else if (isalpha(ch)); // (isalpha(ch)) checks if ch is = alphabetical characters, A-Z
}
	int i = 0; // An integer to keep track of where we are putting characters in the string.
	string[i++] = ch; //The first character of string goes into 0, and we increment by 1 so the next value is stored as 1, and then the following letter is 2, and so on.
	while (ch = fgetc(fptr) != EOF && isalpha(ch)) 
{
	string[i++] = ch;
}
	    string[i] = '\0'; //terminating the string, it ends here.
	if (strcmp(string, "return") == 0) token = Token_Return;
	else if (strcmp(string, "main") == 0) token = Token_Main;	
}
int main()
{
	FILE *fptr;
	fptr = fopen("/mnt/c/Users/Yahya/Desktop/tokens.txt", "w+"); //w+ allows me to write and read the file, so we're able to use while(fgets(contents, sizeof(contents), fptr) != NULL)
	// {
	// 	printf("%s", contents);
	// }
	if (fptr == NULL)
{
	printf("Failed to create file");
}
	char contents [1024] = {0};
	fprintf(fptr, "{ } ( ) ; int return main 42");
	rewind(fptr); // rewinds the file back to the start, so we're able to read it, hence using the w+
	while (fgets(contents, sizeof(contents), fptr) != NULL)
{
	printf("%s", contents);
}
	fclose(fptr);
	return 0;
  
}

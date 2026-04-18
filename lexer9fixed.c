#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef enum
{
	Token_Main,
	Token_Int,
	Token_OBrace,
	Token_CBrace,
	Token_SemiColon,
	Token_OPara,
	Token_CPara,
	Token_Return,
}Tokens;
void lexer(FILE *fptr)
{
	char ch; //For single characters
	char string[50]; //For int, return, main
	Tokens token;
	while ((ch = fgetc(fptr)) != EOF) //Essentially says, while the file is not end of life, ie still running, fgetc, (meaning get char, and then assign ot to ch, and we're getting these chars from the file fptr.
	{
		if (isspace(ch)) continue; //We are skipping spaces so they are not counted as a character.
	       else if (ch == '{') {token = Token_OBrace; printf("Token_OBrace\n");} // { } after the conditions, so the assignment, and the functions can both be used in conjunction, ie if(condition) {execution; function;)
	       else if (ch == '}') {token = Token_CBrace; printf("Token_CBrace\n");}
	       else if (ch == ';') {token = Token_SemiColon; printf("Token_SemiColon\n");}
	       else if (ch == '(') {token = Token_OPara; printf("Token_OPara\n");}
	       else if (ch == ')') {token = Token_CPara; printf("Token_CPara\n");} 	
		else if (isalpha(ch))
		{
			int i = 0; //To keep track of the characters within a "string"
			string[i++] = ch; //Incrementing each time, so each string vanlue is stored in a position, like 1, then 2, etc.
			while ((ch = fgetc(fptr)) != EOF && isalpha(ch))
			{
				string[i++] = ch;
			}
			string[i] = '\0'; //terminating the string.
			if (strcmp(string, "return") == 0) {token = Token_Return; printf("Token_Return\n");} //SACMOTPLA (LATROL:24)
			else if (strcmp(string, "main") ==0) {token = Token_Main; printf("Token_Main\n");}
			else if (strcmp(string, "int") ==0) {token = Token_Int;   printf("Token_Int\n");}
			if (ch != EOF) ungetc(ch, fptr);
		}
	}
}
int main()
{

	char contents[999];
	FILE *fptr;
	fptr = fopen("C:\\Users\\Yahya\\Desktop\\Tokenx.txt", "w+"); // w+ just means that we are creating and writing to a file. Correction made, I mistakely put \\ after the filename, this is wrong, and it will treat the file as if its a path, and then it won't create the file.
	if (fptr == NULL) //To check for errors, like if the file did not create
	{
		printf("Failed to create the file\n");
		return 1; //Returning 1 means, outputting that there was an error.
	}
	fprintf(fptr, "main int { } ; ( ) return");
	rewind(fptr); //To rewind the file back to the start, + allows us to use w+
	lexer(fptr); //Lexer is called here specifically, because, after the file rewinds back, then you want the void function to read and tokenize the tokens. :D ps don't forget to include the fptr, which we call in the function lexer when we created it, and then once we call it here, we still need to include fptr, but without the type, just fptr
	rewind(fptr); //Rewinding twice, because after we call the function lexer, the file reaches end of life, so we need to rewind it so that fgets can actually get the content stored inside of fptr.
	fgets(contents, sizeof(contents), fptr);
       	//To get the content of the file then transfer it onto our char string contents
	printf("%s", contents);
	fclose(fptr);
	return 0;
}

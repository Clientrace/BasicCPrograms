#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

main(void)
{
	char word[100], result[100];
	printf("Enter a word:\n");
	gets(word);
	strcpy(result,word);
	strrev(result);
	if(strcmp(result,word)==0)
	{
		printf("Palindrome!");
	}
	else
	printf("Not a panlindrome!");
	
	getch();
}

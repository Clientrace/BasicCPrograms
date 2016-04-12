#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string>
main (void)
{
	int count=0,pick;
	char pick2,temp[50],word[50];
	puts("String concerto:\n1-vowels to asterisk\n2-character count\n3-Opish");
	scanf("%d",&pick);
	switch(pick)
	{
		case 1: {
				puts("enter a word:\n");
				scanf("%s",&word);
				strrev(word);
				for(int i=0; i<=strlen(word); i++)
				{
					temp[i]=tolower(word[i]);
					if(temp[i]=='a'||temp[i]=='e'||temp[i]=='i'||temp[i]=='o'||temp[i]=='u')
					{
						word[i]='*';
					}
				}
				for(int i=0; i<strlen(word); i++)
				{
					printf("%c",word[i]);
				}
			break;
		}
		case 2: {
				puts("Enter a word:\n");
				scanf("%s",&word);
				for(int i=0; i<strlen(word); i++)
				{
						if(word[i]==word[i+1])
						{
							count++;
							i++;
						}
				}
				printf("Times repeated: %d\n",count);
				printf("Words repeated: ");
				for(int i=0; i<strlen(word); i++)
				{
						if(word[i]==word[i+1])
						{
							printf("%c",word[i]);
							i++;
						}
				}
			break;
		}
		case 3: {
				scanf("%c");
				printf("English word:\n");
				gets(word);
				printf("Opish:\n");
				for(int i=0; i<strlen(word); i++)
				{
					if(isdigit(word[i])==false)
					{
						temp[i]=tolower(word[i]);
						printf("%c",word[i]);
						if(temp[i]!='a'&&temp[i]!='e'&&temp[i]!='i'&&temp[i]!='o'&&temp[i]!='u'&&temp[i]!='\0'&&temp[i]!=' '&&ispunct(word[i])==false)
						{
							if(word[i]!=word[i+1])
							{
								printf("op");
							}

						}
					}
				}
				getch();
}
}
}

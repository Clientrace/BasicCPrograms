#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void piglatin()
{
	START:
	system("cls");
	char choice;
	bool vowels=false;
	char word[50];
	char temp[50];
	cout << "Piglatin Converter:\n\n\n" << "Enter a word:\n";
	cin >> word;
	if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u')
	{
		cout << word << "yay";
	}
	else
	{
		for(int i=0; i<strlen(word); i++)
		{
			strlwr(word);
			switch(word[i])
			{
				case 'a': {
					system("cls");
					cout << "new word:\n";
					strncpy(temp,word,i);
					cout << word << " -----> " << strchr(word,'a') << temp << "ay";
					i=strlen(word);
					vowels=true;
					break;
				}
				case 'e': {
					system("cls");
					cout << "new word:\n";
					strncpy(temp,word,i);
					cout << word << " -----> " << strchr(word,'e') << temp << "ay";
					i=strlen(word);
					vowels=true;
					break;
				}
				case 'i': {
					system("cls");
					cout << "new word:\n";
					strncpy(temp,word,i);
					cout << word << " -----> " << strchr(word,'i') << temp << "ay";
					i=strlen(word);
					vowels=true;
					break;
				}
				case 'o': {
					system("cls");
					cout << "new word:\n";
					strncpy(temp,word,i);
					cout << word << " -----> " << strchr(word,'o') << temp << "ay";
					i=strlen(word);
					vowels=true;
					break;
				}
				case 'u': {
					system("cls");
					cout << "new word:\n";
					strncpy(temp,word,i);
					cout << word << " -----> " << strchr(word,'u') << temp << "ay";
					vowels=true;
					break;
				}
			}
		}
	}
	if(vowels==false){
		system("cls");
		cout << "new word:\n";
		cout << word << " -----> " << word << "yay";
	}
	Choice:
	cout << "\n\nTry Again? yes=y, no=n\n";
	cin >> choice;
	if(choice=='y')
	{
		goto START;
	}
	else if(choice == 'n')
	{
		goto FINISH;
	}
	else
		cout << "Invalid input"; goto Choice;
	FINISH:
		system("cls");
		cout << "Thank you for using codeheads program";
	getch();
}

main (void)
{
	char pass[50], opass[]="kim", temp; int trials=3;
	START:
	cout << "PASSWORD:\n";
	while(trials!=0)
	{
	for(int i=0;;)
	{
		temp=getch();
		if(temp!='\b'&&temp!='\r')
		{
			pass[i]=temp;
			cout << "*";
			++i;
		}
		if(temp=='\b')
		{
			cout << "\b \b";
			--i;
		}
		if(temp=='\r')
		{
			pass[i]='\0';
			break;
		}
	}
	if(strcmp(pass,opass)==0)
	{
		piglatin();
	}
	else
	{
		trials--;
		system("cls");
		cout << "Wrong Password!\n" << "Trials Remaining: " << "(" << trials << ")";
		cout << "\nPress enter to continue";
		cin.get();
		system("cls");
		goto START;
	}
	}
	system("cls");
	cout << "\n\n\nTrials are over, you cannot access piglatin";
	getch();
}

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
char choice;
main (void)
{
	char m[50],f[50],temp[50];
	int same1=0,same2=0,ml,fl,tot,tot2;
	START:
	system("cls");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "\t\t\tF L A M E S";
	cout << "\n\n\t\t\t[BOY]: \n\t\t\t";
	cin >> m;
	cout << "\n\n\t\t\t[GIRL]: \n\t\t\t";
	cin >> f;
	strcpy(temp,m);
	fl=strlen(f);
	ml=strlen(m);
	for(int i=0; i<ml; i++)
	{
		for(int j=0; j<fl; j++)
		{
			if(m[i]==f[j])
			{
				m[i]='x';
			}
		}
	}
	for(int i=0; i<ml; i++)
	{
		if(m[i]=='x')
		{
			same1++;
		}
	}
	for(int i=0; i<fl; i++)
	{
		for(int j=0; j<ml; j++)
		{
			if(f[i]==temp[j])
			{
				f[i]='x';
			}
		}
	}
	for(int i=0; i<fl; i++)
	{
		if(f[i]=='x')
		{
			same2++;
		}
	}
	tot=same1+same2;
	tot2=same1+same2;
	while(tot>6)
	{
		tot-=6;
	}
	switch(tot)
	{
		case 1: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\t[F] L A M E S";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL- " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( FRIENDS )";
			cout << "\n--------------------------------------------------------------------------------\n";
			break;
		}
		case 2: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\tF [L] A M E S";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL- " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( LOVERS )";
			cout << "\n--------------------------------------------------------------------------------\n";
			break;
		}
		case 3: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\tF L [A] M E S";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL-  " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( ANGRY )";
			cout << "\n--------------------------------------------------------------------------------\n";
			break;
		}
		case 4: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\tF L A [M] E S";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL- " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( MARRIED )";
			cout << "\n--------------------------------------------------------------------------------\n";
			break;
		}
		case 5: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\tF L A M [E] S";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL- " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( ENGAGED )";
			cout << "\n--------------------------------------------------------------------------------\n";
			break;
		}
		case 6: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\tF L A M E [S]";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL- " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( SWEET HEARTS )";
			cout << "\n--------------------------------------------------------------------------------\n";
			break;
		}
		default: {
			system("cls");
			cout << "--------------------------------------------------------------------------------\n";
			cout << "\t\t\tF L A M E S";
			cout << "\n\n\t\t\t[BOY]: \n\t\t\t" << m;
			cout << "\n\n\t\t\t[GIRL]: \n\t\t\t" << f;
			cout << "\n\n\t\t\tBOY- " << same1;
			cout << "\n\n\t\t\tGIRL- " << same2;
			cout << "\n\n\t\t\tTOTAL: "<<tot2<< "\n\n\t\t\t( Not Compatible )";
			cout << "\n--------------------------------------------------------------------------------\n";
		}
	}
	CHOICE:
	cout << "\t\t\tTry Again? y-yes/n-no\n\t\t\t";
	cin>>choice;
	switch(choice)
	{
		case 'y': {
			goto START;
			break;
		}
		case 'n':{
			break;
		}
		default : {
			cout << "\n\t\t\tInvalid Input";
			system("pause");
			system("cls");
			goto CHOICE;
		}
	}
}

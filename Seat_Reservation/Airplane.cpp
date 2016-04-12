#include <stdio.h>
#include <conio.h>
#include <windows.h>
int y,fx=0,fy=0,a[6],b[5];
char seat[5][6],move,max=30,occu_seat[6][5];

void gotoxy(int x,int y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void instruction()
{
	gotoxy(16,1);
	printf("Welcome to WPIA(Wolf Pack's International Airport)");
	gotoxy(20,2);
	printf("Use W-A-S-D to move to your desired seat");
	gotoxy(30,3);
	printf("Use space to select");
}
struct names
{
	char name[20];
	bool status;
}person[6][5];
void print_airplane()
{
	if(person[fx][fy].status==false)
	seat[fx][fy]=1;
	else
	seat[fx][fy]=2;
	system("cls");
	y=10;
	gotoxy(25,17);
	if(person[fx][fy].status==false)
	{
		printf("STATUS: Free");
	}
	else
	{
		printf("STATUS: Occupied");
	}
	if(person[fx][fy].status==false)
	{
		gotoxy(25,18);
		printf("PASSENGER: X");
	}
	else
	{
		gotoxy(25,18);
		printf("PASSENGER: %s",person[fx][fy].name);
	}
	gotoxy(28,9);
	printf("--------------o--------------");
	for(int i=0; i<5; i++)
	{
		gotoxy(25,y);
		y++;
		for(int j=0; j<6; j++)
		{
			printf("[ %c ] ",seat[i][j]);
		}
		printf("\n");
	}
}
main (void)
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<5; j++)
		{
			seat[i][j]=' ';
		}
	}
	for(int i=0;;)
	{
		y=0;
		print_airplane();
		instruction();
		move=getch();
		if(person[fx][fy].status==false)
		{
			seat[fx][fy]=' ';
		}
		else{
			seat[fx][fy]='x';
		}
		if(move=='s'&&fx<4)
		{
			fx++;
		}
		if(move=='w'&&fx>0)
		{
			fx--;
		}
		if(move=='d'&&fy<5)
		{
			fy++;
		}
		if(move=='a'&&fy>0)
		{
			fy--;
		}
		if(move==32&&person[fx][fy].status==false)
		{
			gotoxy(25,20);
			printf("Name: ");
			gotoxy(31,20);
			gets(person[fx][fy].name);
			person[fx][fy].status=true;
		}
	}
	getch();
}

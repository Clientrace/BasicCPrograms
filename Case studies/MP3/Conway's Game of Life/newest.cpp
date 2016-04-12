#include <stdio.h>
#include <conio.h>
#include <windows.h>
int x[80],y[80],die=0;
char cell[80][80];
char birth()
{
	for(int i=0; i<80; i++){
		for(int j=0; j<80; j++){
			if(cell[i][j]!='x'&&i<79&&j<79){
				A:
				if(cell[i-1][j-1]=='x'||cell[i-1][j-1]=='*'){
					die++;
				}
				if(cell[i-1][j]=='x'||cell[i-1][j]=='*'){
					die++;
				}
				if(cell[i-1][j+1]=='x'||cell[i-1][j+1]=='*'){
					die++;
				}
				if(cell[i][j-1]=='x'||cell[i][j-1]=='*'){
					die++;
				}
				if(cell[i][j+1]=='x'||cell[i][j+1]=='*'){
					die++;
				}
				if(cell[i+1][j-1]=='x'||cell[i+1][j-1]=='*'){
					die++;
				}
				if(cell[i+1][j]=='x'||cell[i+1][j]=='*'){
					die++;
				}
				if(cell[i+1][j+1]=='x'||cell[i+1][j+1]=='*'){
					die++;
				}
				if(cell[i][j]=='x')
				{
					goto B;
				}
				if(die==3){
					die=0;
					cell[i][j]='o';
				}
				else{
					die=0;
				}
			}
			if(cell[i][j]=='x'){
				goto A;
				B:
				if(die>3||die<2){
					die=0;
					cell[i][j]='*';
				}
				else{
					die=0;
				}
			}
		}
	}
}
main(void)
{
	char name[20];
	A:
		system("cls");
	FILE *ftr;
	printf("Enter the file name: ");
	scanf("%s",&name);
	V:
	int gen=0,num=0;
	for(int i=0; i<80; i++){
		for(int j=0; j<80; j++){
			cell[i][j]=' ';
		}
	}
	if((ftr=fopen(name,"r"))==NULL){
		printf("File doesnt exist");
		getch();
		goto A;
	}
	else{
		for(int i=0; i<80; i++){
			fscanf(ftr,"%d %d",&x[i],&y[i]);
		}
		for(int i=0; i<79; i++){
			cell[x[i]][y[i]]='x';
			cell[0][0]=' ';
			if(y[0]==0&&x[0]==0){
				cell[0][0]='x';
			}
		}
		fclose(ftr);
	}
	system("cls");
	printf("Number of generations you want to view: ");
	scanf("%d",&gen);
	for(int i=0; i<gen; i++){
		if(i>0){
			birth();
			for(int i=0; i<80; i++){
				for(int j=0; j<80; j++){
					if(gen==0){
						cell[i][j]=' ';
					}
				}
				for(int j=0; j<80; j++){
					if(cell[i][j]=='o'){
						cell[i][j]='x';
					}
					if(cell[i][j]=='*'){
						cell[i][j]=' ';
					}
				}
			}
		}
			Sleep(300);
			system("cls");
		for(int i=0; i<20; i++){
		for(int j=0; j<80; j++){
			printf("%c",cell[i][j]);
		}
	}
	}
	getch();
	goto V;
}

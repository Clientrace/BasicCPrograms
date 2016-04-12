#include <stdio.h>
#include <queue>
#include <conio.h>
#include <windows.h>
using namespace std;
main(void)
{
	char cont;
	queue<int> hold;
int yeah;
    A:
    system("cls");
    int num[13]={1,2,3,4,5,6,7,8,9,10,11,12,13},adv[5],a,start,intv,c=44;
    puts("START:\n");
	scanf("%d",&start);
	puts("INTERVAL:\n");
	scanf("%d",&intv);
	a=(start-1);
	if(intv==0){
        system("cls");
        printf("Program Terminated.");
        goto B;
        }
    else{
	for(int i=0; i<5;i++){
		for(int k=0; k<intv; k++){
			++a;
			if(a>13)
				a=a%13;
			if(num[a-1]==0)
				k--;
		}
		if(i==4)
		c=' ';
		hold.push(a);
		yeah = hold.front;
		hold.pop;
		printf("%d%c ",yeah,c);
		num[a-1]='\0';
	}
}
    printf("\n\nPress Enter to continue.");
    getch();
    goto A;
    B:
    printf("\n\nPress Enter to close.");
    getch();
}

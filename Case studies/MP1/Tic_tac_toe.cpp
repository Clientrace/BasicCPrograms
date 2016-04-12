#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <ctype.h>
#include <windows.h>
int pick=1, times=0;
char turn[9] = { '1','2','3','4','5','6','7','8','9' };
int range(int low , int high)
{
    srand(time(NULL));
    while(true){
        int num=rand();
        if(num>=low&&num<=high){
            if(turn[num-1]!='x'&&turn[num-1]!='o'){
                return num;
            }
        }
    }
}
void board()
{
	puts("Tic toc toe:\n");
    printf("| %c | %c | %c |\n\n| %c | %c | %c |\n\n| %c | %c | %c |",turn[0],turn[1],turn[2],turn[3],turn[4],turn[5],turn[6],turn[7],turn[8]);
    printf("\n\nEnter your turn: ");
    if((turn[0]==turn[1]&&turn[1]==turn[2])||(turn[0]==turn[3]&&turn[3]==turn[6])){
        if(turn[0]=='x')
            printf("\n\nyou win!");
        else
            printf("\n\nyou loose!");
        times=6;
    }
    else if((turn[3]==turn[4]&&turn[4]==turn[5])||(turn[1]==turn[4]&&turn[4]==turn[7])){
        if(turn[4]=='x')
            printf("\n\nyou win!");
        else
            printf("\n\nyou loose!");
        times=6;
    }
    else if((turn[6]==turn[7]&&turn[7]==turn[8])||(turn[2]==turn[5]&&turn[5]==turn[8])){
        if(turn[8]=='x')
            printf("\n\nyou win!");
        else
            printf("\n\nyou loose!");
        times=6;
    }
    else if((turn[0]==turn[4]&&turn[4]==turn[8])||(turn[2]==turn[4]&&turn[4]==turn[6])){
        if(turn[4]=='x'){
            printf("\n\nyou win!");
        }
        else
            printf("\n\nyou loose!");
        times=6;
    }
    else if(times==4){
        turn[pick]='x';
        printf("tie");
        times=6;
    }
    scanf("%d",&pick);
}
main (void)
{
    for(times=0; times<5;){
        system("cls");
        board();
        if(isalpha(turn[pick-1])==false&&isdigit(pick)==false){
            turn[pick-1]='x';
            turn[(range(1,9))-1]='o';
            times++;
        }
    }
}

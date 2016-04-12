#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int b_100,b_500,b_1000,t1,t1k,t5,p1,p5,p1k,choice=0,amnt;
int t1k2=0,t12=0,t52=0,test,test2;
void withdraw(int amnt){
	if(amnt%100!=0){
		puts("Withdrawal Invalid");
	}
	else{
	if(amnt/1000>2000&&amnt/500>1000000&&amnt/100>200000){
		puts("Sorry, bills are unavailable");
	}
	else{
		if(b_1000!=0&&b_500!=0&&b_100!=0){
			if(amnt/1000<b_1000){
			test = amnt%1000;
			if(test!=0){
				t1k2 = amnt/1000;
				if(test==500){
					t52 = 1;
				}
				else if(test>500){
					test2 = test%500;
					t52 = 1;
					t12 = test2/100;
				}
				else if(test<500){
					t52 = 0;
					t12 = test/100;
				}
			}
			else{
				test = amnt%1000;
				t1k2 = amnt/1000;
				t52 = 0;
				t12 = 0;
			}
		}
		else{
			t1k2 = b_1000;
			amnt-=(t1k2*1000);
			t1k= t1k2*1000;
			if(b_500!=0){
				t52 = amnt/500;
				t12 = 0;
			}
			else{
				t52 = 0;
				t12 = amnt/100;
			}
		}
	}
		else if(b_1000==0&&b_500!=0){
			t1k2=0;
			test = amnt%500;
			if(b_500!=0){
				t52 = amnt/500;
				t12 = test/100;
			}
		}
		else if(b_100!=0){
			t1k2=0;
			t52 = 0;
			t12 = amnt/100;
		}
		else{
			t1k2=0;
			t52 = 0;
			t12 = 0;
			puts("Sorry, bills are unavailable");
		}
}
	t1k -= t1k2*1000;
	t1 -= t12*100;
	t5 -= t52*500;
	b_100 -= t12;
	b_500 -= t52;
	b_1000 -= t1k2;
		if(b_100<0&&b_500<0&&b_1000<0){
				puts("Sorry, bills are unavailable\n");
				t1k += t1k2*1000;
				t1 += t12*100;
				t5 += t52*500;
				b_100 += t12;
				b_500 += t52;
				b_1000 += t1k2;
		}
		else{
			printf("Received:%d\n",amnt);
			printf("%d-100 peso bill\n",t12);
			printf("%d-500 peso bill\n",t52);
			printf("%d-1000 peso bill\n",t1k2);
		}
	}
}
main (void){
	FILE *ptr,*ptr2;
	ptr = fopen("bills.txt","r");
	fscanf(ptr,"%d",&t1);
	fscanf(ptr,"%d",&t5);
	fscanf(ptr,"%d",&t1k);
	fscanf(ptr,"%d",&b_100);
	fscanf(ptr,"%d",&b_500);
	fscanf(ptr,"%d",&b_1000);
	fclose(ptr);
	for(int i=0;;i++){
		system("cls");
		printf("Prog. 2 Final Case Study: ATM (Machine's Perspective)\n\n");
		for(int i=0;i<80;i++)
			printf("-");
		puts("\nEnter an option:\n");
		puts("[1] Balance inquiry\n[2] Withdraw\n[3] Restock\n[4] Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: {
				system("cls");
				for(int i=0;i<80;i++)
					printf("-");
				puts("<Balance Inquiry:>\n");
				puts("\nAmount:");
				printf("\n100 peso bill:  P%d.00\n",t1);
				printf("\n500 peso bill:  P%d.00\n",t5);
				printf("\n1000 peso bill: P%d.00\n",t1k);
				printf("\nTotal:	        P%d.00\n",t1+t5+t1k);
				puts("\nStock [Bundle]:\n");
				printf("100 peso: %d pcs\n",b_100);
				printf("500 peso: %d pcs\n",b_500);
				printf("1000 peso: %d pcs\n",b_1000);
				for(int i=0;i<80;i++)
					printf("-");
				getch();
				break;
			}
			case 2: {
				for(int i=0;i<80;i++)
					printf("-");
				printf("Enter the amount: \nP");
				scanf("%d",&amnt);
				system("cls");
				for(int i=0;i<80;i++)
					printf("-");
				withdraw(amnt);
				for(int i=0;i<80;i++)
					printf("-");
				getch();
				break;
			}
			case 3: {
				b_100 = 2000;
				b_500 = 2000;
				b_1000 = 2000;
				t1 = 200000;
				t5 = 1000000;
				t1k = 2000000;
				for(int i=0;i<80;i++)
					printf("-");
				puts("Bills restored");
				for(int i=0;i<80;i++)
					printf("-");
				getch();
				break;
			}
			case 4: {
				goto exit;
				break;
			}
			default:{
				puts("Invalid Input [Program Exiting]");
				getch();
				goto exit;
			}
					
		}
		ptr2 = fopen("bills.txt","w");
		fprintf(ptr2,"%d\n",t1);
		fprintf(ptr2,"%d\n",t5);
		fprintf(ptr2,"%d\n",t1k);
		fprintf(ptr2,"%d\n",b_100);
		fprintf(ptr2,"%d\n",b_500);
		fprintf(ptr2,"%d\n",b_1000);
		fclose(ptr2);
	}
	exit:
		system("cls");
		for(int i=0;i<80;i++)
			printf("-");
		puts("\nEnd of Process\n");
		for(int i=0;i<80;i++)
			printf("-");
		getch();
}

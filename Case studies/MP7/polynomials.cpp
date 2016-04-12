#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <cstdlib>
int len1,len2,first=0;
struct term{
	int coef;
	int exp;
	term *next;
	term (int C, int E, term *T)
	: coef (C),
	exp (E),
	next (T)
	{ }
};
void arange(int *num,int *num2,int len){
	int temp,temp2;
	for(int i=0; i<len1; i++){
		for(int k=0; k<len-1; k++){
			if(num[i]>num[k]){
				temp=num[i];
				temp2=num2[i];
				num[i]=num[k];
				num2[i]=num2[k];
				num[k]=temp;
				num2[k]=temp2;
			}
		}
	}
}
main (void){
	int coef1[50],exp1[50],coef2[50],exp2[50];
	char n,ch='\b';
	term *head=NULL, *head2=NULL, *last=NULL, *last2=NULL,*head3 =NULL,*last3=NULL;
	int first=0;
	puts("First Polynomial: ");
	for(len1=0;;){
		scanf("%d",&coef1[len1]);
		scanf("%d%c",&exp1[len1],&n);
		len1++;
		if(n=='\n')
			break;
	}
	puts("Second Polynomial: ");
	for(len2=0;;){
		scanf("%d",&coef2[len2]);
		scanf("%d%c",&exp2[len2],&n);
		len2++;
		if(n=='\n')
			break;
	}
	arange(exp1,coef1,len1);
	arange(exp2,coef2,len2);
	for(int i=0; i<len1; i++)
	{
		if(i<1){
			term *temp = new term(coef1[i],exp1[i],NULL);
			head = temp;
			last = temp;
		}
		else{
			term *temp = new term(coef1[i],exp1[i],NULL);
			last -> next = temp;
			last = temp;
		}
	}
	for(int i=0; i<len2; i++){
		if(i<1){
			term *temp = new term(coef2[i],exp2[i],NULL);
			head2 = temp;
			last2 = temp;
		}
		else{
			term *temp = new term(coef2[i],exp2[i],NULL);
			last2 -> next = temp;
			last2 = temp;
		}
	}
	while(head!=NULL&&head2!=NULL){
		term *temp;
		if(head->exp>head2->exp){
			if(first == 0){
				temp = new term(head->coef,head->exp,NULL);
				head3 = temp;
				last3 = temp;
			}
			else{
				temp = new term(head->coef,head->exp,NULL);
				last3 -> next = temp;
				last3 = temp;
			}
			head = head -> next;
		}
		else if(head -> exp<head2->exp){
			if(first == 0){
				temp = new term(head2->coef,head2->exp,NULL);
				head3 = temp;
				last3 = temp;
			}
			else{
				temp = new term(head2->coef,head2->exp,NULL);
				last3 -> next = temp;
				last3 = temp;
			}
			head2 = head2 -> next;
		}
		else{
			if(first == 0){
				temp = new term(head->coef+head2->coef,head->exp,NULL);
				head3 = temp;
				last3 = temp;
			}
			else{
				temp = new term(head->coef+head2->coef,head->exp,NULL);
				last3 -> next = temp;
				last3 = temp;
			}
			head = head -> next;
			head2 = head2 -> next;
		}first = 1;
	}
	while(head2!=NULL){
		term * temp = new term(head2->coef,head2->exp,NULL);
		last3 -> next = temp;
		last3 = temp;
		head2 = head2 -> next;
	}
	while(head!=NULL){
		term * temp = new term(head->coef,head->exp,NULL);
		last3 -> next = temp;
		last3 = temp;
		head = head -> next;
	}
	while(head3!=NULL){
		if(head3->coef!=0){
			if(head3->coef!=1){
				if(abs(head3->coef)!=head3->coef){
					head3->coef=abs(head3->coef);
					ch='-';
				}
				if(head3->exp!=0&&head3->exp!=1)
					printf("%c%dx^%d",ch,head3->coef,head3->exp);
				else if(head3->exp==1)
					printf("%c%dx",ch,head3->coef);
				else if(head3->exp==0)
					printf("%c%d",ch,head3->coef);
				ch = '+';
			}
			else{
				if(abs(head3->coef)!=head3->coef){
					head3->coef=abs(head3->coef);
					ch='-';
				}
				if(head3->exp!=0&&head3->exp!=1)
					printf("%cx^%d",ch,head3->exp);
				else if(head3->exp==1)
					printf("%cx",ch,head3->coef);
				else if(head3->exp==0)
					printf("%c%d",ch,head3->coef);
				ch = '+';
			}
		}
		head3 = head3 -> next;
	}
}

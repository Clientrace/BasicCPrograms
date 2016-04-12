#include <stdio.h>
#include <conio.h>
#include <windows.h>
//global variables:
char str1[50],str2[50],str3[50];
int c,s=0,d=0;
//linked list node:
struct node{
	int number;
	node *next;
	node *prev;
};
node* head3=NULL,*last3=NULL;
//add first node:
void add_head(node *&head, node *&last, int number){
	node *temp=new node;
	temp -> number = number;
	temp -> next = NULL;
	temp -> prev = NULL;
	head = temp;
	last = temp;
}
//add the other nodes in the linked list:
void insert(node *&head, node *&last, int number){
	if(head == NULL){
		add_head(head,last,number);
	}
	else{
		node *temp = new node;
		temp -> number = number;
		temp -> next = NULL;
		temp -> prev = last;
		last -> next = temp;
		last -> prev = head;
		last = temp;	
	}
}
//add the nodes:
int add(node *head,node *head2){
	int s1=strlen(str1),s2=strlen(str2),carry,sum,temp;
	if(s1>s2){
		int space=s1-s2;
		for(int i=0; i<space; i++){
			insert(head3,last3,head->number);
			head = head -> next;
		}
		while(head!=NULL){
			carry = 0;
			int n1 = head -> number;
			int n2 = head2 -> number;
			sum = n1+n2;
			while(sum>9){
				carry=sum/10;
				sum%=10;
				last3 -> number+=carry;
			}
			insert(head3,last3,sum);
			head = head -> next;
			head2 = head2 -> next;
			sum =0;
		}
	}
	else if(s2>s1){
		int space=s2-s1;
		for(int i=0; i<space; i++){
			insert(head3,last3,head2->number);
			head2 = head2 -> next;
		}
		while(head2!=NULL){
			int n1 = head -> number;
			int n2 = head2 -> number;
			sum = n1+n2;
			insert(head3,last3,sum);
			head = head -> next;
			head2 = head2 -> next;
			while(sum>9){
				carry=sum/10;
				sum%=10;
				last3 -> number+=carry;
			}
			insert(head3,last3,sum);
			head = head -> next;
			head2 = head2 -> next;
			sum =0;
		}
	}
	else if(s1==s2){
		while(head!=NULL){
			carry = 0;
			int n1 = head -> number;
			int n2 = head2 -> number;
			sum = n1+n2;
			while(sum>9){
				carry=sum/10;
				sum%=10;
				last3 -> number+=carry;
			}
			insert(head3,last3,sum);
			head = head -> next;
			head2 = head2 -> next;
			sum =0;
		}
		}
}
//main function:
main (void){
	int d;
	node *head=NULL,*head2=NULL,*last=NULL,*last2=NULL;
	printf("Enter first Expression: ");
	gets(str1);
	printf("Enter second Expression: ");
	gets(str2);
	for(int i=0; i<strlen(str1); i++)
		insert(head,last,str1[i]-48);
	for(int i=0; i<strlen(str2); i++)
		insert(head2,last2,str2[i]-48);
	add(head,head2);
	while(head3!=NULL){
		printf("%d",head3->number);
		head3=head3->next;
	}
}

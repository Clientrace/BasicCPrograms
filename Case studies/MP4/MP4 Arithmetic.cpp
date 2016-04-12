#include <stdio.h>
#include <conio.h>
#include <stack>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
int seq(char x){
	if(x=='^')
		return 1;
	if(x=='*'||x=='/')
		return 2;
	if(x=='+'||x=='-')
		return 3;
}
main (void)
{
	char input[50];
	puts("Enter an arithmetic expression in infix form:\n");
	gets(input);
	int a,b,res=0,temp,digit;
	stack<char> oprtr;
	stack<char> oprnd;
	string output;
	for(int i=0; i<strlen(input);i++){
		if(input[i]=='('){
			output+=' ';
			oprtr.push(input[i]);
		}
		else if(input[i]==')'){
			output+=' ';
			while(oprtr.top()!='('){
				output+=oprtr.top();
				oprtr.pop(); 
			}
			oprtr.pop();
		}
		else if (input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='^'){
			while(!oprtr.empty()&&seq(oprtr.top())<=seq(input[i])){
				output+=' ';
				output += oprtr.top();
				oprtr.pop();
			}
			oprtr.push(input[i]);
		}
		else{
				printf("%c",input[i-1]);
				if(input[i-1]=='+'||input[i-1]=='-'||input[i-1]=='*'||input[i-1]=='/'||input[i-1]=='^'){
					output+=' ';
				}
				output+=input[i];
		}	
	}
	while(!oprtr.empty()){
		output+=' ';
		output+=oprtr.top();
		oprtr.pop();
	}
		int i=0;
		
	while (i < output.length())
    {
        if ( isspace(output[i]) ){
        }
        else if ( isdigit( output[i] )){
          int num = 0;
          do {
            num = num*10 + (output[i]-'0');
            i++;
            if ( i >= output.length()){
            }
          } while (isdigit(output[i]));
          oprnd.push(num);
        }
        else{
          b= oprnd.top();
          oprnd.pop();
          a= oprnd.top();
          oprnd.pop();
          switch(output[i]){
                  case '+': res=a + b;
                  oprnd.push(res);
                  break;
                  case '-': res=a - b;
                  oprnd.push(res);
                  break;
                  case '*': res=a * b;
                  oprnd.push(res);
                  break;
                  case '/': res=a / b;
                  oprnd.push(res);
                  break;
                  case '^': res=pow(a,b);
                  oprnd.push(res);
                  break;
          }
        }
        i++;
}
	printf("\n\nAnswer:\n%d", res);
	getch();
}

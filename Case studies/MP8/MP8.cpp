#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int n=0;
char name[20], nodes[20];
struct BT
{
	char Node;
	BT *left;
	BT *right;
}*BNode, *TBNode, *HNode, *Temp[30];
void Hroot(char var);
void Lchild(char var);
void Rchild(char var);
void Lchild(char var);
void inserting(char var);
void preorder(struct BT *TrNode);
void inorder(struct BT *TrNode);
void postorder(struct BT *TrNode);
int function(char Nodes[]);
int main()
{
	start:
	FILE *tPtr;
	printf ("File name:\n>");
	gets(name);
	if ((tPtr=fopen(name, "r"))!=NULL)
	{
		system("cls");
		printf("BST TRANSVERSALS:\n\n");
		printf("[Node]  [L-Subtree][R-Subtree]\n");
		while (fgets(nodes, sizeof nodes, tPtr)!=NULL)
		{
			function(nodes);
			n++;
		}
		printf ("\nRoot: %c\n", HNode->Node);
		printf ("PRE: ");	
		preorder(HNode);
		printf ("\nIN: ");
		inorder (HNode);		
		printf ("\nPOST: ");
		postorder (HNode);
		fclose(tPtr);
	}	
	else{
		system("cls");
		printf("File doesns't exist");
		getch();
		goto start;
	}
	return 0;
}
void Hroot(char var)
{
	BNode=(BT*)malloc(sizeof(BT));
	HNode=BNode;
	TBNode=BNode;
	BNode->Node=var;
}
void Lchild(char var)
{
	BNode=(BT*)malloc(sizeof(BT));
	TBNode->left=BNode;
	BNode->Node=var;
}
void Rchild(char var)
{
	BNode=(BT*)malloc(sizeof(BT));
	TBNode->right=BNode;
	BNode->Node=var;
}
void inserting(char var)
{
	int x=0;
	BNode=HNode;
	while(var!=BNode->Node)
	{
		Temp[x]=BNode->right;
		BNode=BNode->left;
		while(BNode==NULL)
		{
			BNode=Temp[x];
			x--;	
		}
		x++;
	}
	TBNode=BNode;	
}
void preorder(struct BT *TrNode)
{
	if (TrNode!=NULL)
	{
		printf ("%c ", TrNode->Node);
		preorder(TrNode->left);
		preorder(TrNode->right);
	}
}
void inorder(struct BT *TrNode)
{
	if (TrNode!=NULL)
	{
		inorder(TrNode->left);
		printf ("%c ", TrNode->Node);
		inorder(TrNode->right);
	}	
}
void postorder(struct BT *TrNode)
{
	if (TrNode!=NULL)
	{
		postorder(TrNode->left);
		postorder(TrNode->right);
		printf ("%c ", TrNode->Node);
	}
}
int function(char Nodes[])
{
	int a, i, count=0;
	i=strlen(Nodes);
	for (a=0; a<i; a++)
	{
		if (Nodes[a]!=','&&Nodes[a]!='('&&Nodes[a]!=')')
		{
			if (Nodes[a]=='n'&&Nodes[a+1]=='u')
			{
				printf ("NULL      ");
				a+=4;
			}
			if (Nodes[a+1]==','||Nodes[a+1]==')')
			{
				if (count==0&&n==0)
					Hroot(Nodes[a]);
				if (count==0&&n>0)
					inserting(Nodes[a]);
				if (count==1&&n>=0)
					Lchild(Nodes[a]);
				if (count==2&&n>=0)
					Rchild(Nodes[a]);
				BNode->left=NULL;
				BNode->right=NULL;				
				printf ("%c         ", Nodes[a]);
			}			
			count++;
		}	
	}
	printf("\n");
}

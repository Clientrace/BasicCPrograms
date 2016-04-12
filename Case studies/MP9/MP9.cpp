#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char pror[20], inor[20];
int x;
struct TR{
	char Node;
	TR *left;
	TR *right;
}*Nodes, *HNode;
void tree();
void child(int R, int J, struct TR *NNode);
void root();
void postorder(struct TR *FNode);
int main(){
	start:
	FILE *tPtr;
	char name[20];
	printf ("File name:\n>");
	gets(name);
	tPtr=fopen(name, "r");
	if(tPtr==NULL){
		printf("File Doesn't Exist");
		goto start;
	}
	printf("POSTORDER TREE TRANSVERSALS:\n ");
	while (!feof(tPtr)){
		fscanf (tPtr,"%s%s", pror, inor);
		tree();	
		postorder(HNode);
		printf("\n");
	}
	fclose(tPtr);
	return 0;	
}
void root(){
	Nodes=(TR*)malloc(sizeof(TR));
	HNode=Nodes;
	Nodes->Node=pror[0];
	Nodes->left=NULL;
	Nodes->right=NULL;
}
void child(int R, int J, struct TR *NNode){
	if (R>J){
		if(NNode->left!=NULL){
			for (int a=0; a<x; a++){
				if ((NNode->left)->Node==inor[a]){
					child(a, J, NNode->left);					
				}
			}
		}
		else{
			Nodes=(TR*)malloc(sizeof(TR));
			NNode->left=Nodes;
			Nodes->Node=inor[J];
			Nodes->left=NULL;
			Nodes->right=NULL;
		}
	}
	else{
		if(NNode->right!=NULL){
			for (int a=0; a<x; a++){
				if ((NNode->right)->Node==inor[a]){
					child(a, J, NNode->right);					
				}
			}
		}
		else{
			Nodes=(TR*)malloc(sizeof(TR));
			NNode->right=Nodes;
			Nodes->Node=inor[J];
			Nodes->left=NULL;
			Nodes->right=NULL;	
		}		
	}
}
void postorder(struct TR *FNode){
	if(FNode!=NULL){
		postorder(FNode->left);
		postorder(FNode->right);
		printf ("%c", FNode->Node);
	}	
}
void tree(){
	int i, j, r;
	x=strlen(pror);
	for (i=0; i<x; i++){
		if (pror[0]==inor[i]){
			r=i;
			root();
		}
	}
	for (i=1; i<x; i++){
		for (j=0; j<x; j++){
			if (pror[i]==inor[j]){				
				child(r, j, HNode);
			}
		}
	}	
}

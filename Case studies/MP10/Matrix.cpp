#include <stdio.h>
#include <conio.h>
#include <windows.h>

main(void)
{
	int r1,r2,c1,c2,first[20][20],second[20][20],num=0,multiply[20][20],sum=0;
	printf("Enter number of rows and columns of the first matrix:\n");
	for(int i=0; i<3; i++)
	{
		if(i==1)
		{
			printf("Rows: ");
			scanf("%d",&r1);
		}
		if(i==2)
		{
			printf("Columns: ");
			scanf("%d",&c1);
		}
	}
	printf("Enter the Elements of the first matrix:\n");
	for(int i=0; i<r1; i++)
	{
		for(int j=0; j<c1; j++)
		{
			printf("[%d]: ",++num);
			scanf("%d",&first[i][j]);
		}
	}
	num=1;
	system("cls");
	printf("Enter the number of rows and columns of the second matrix\n");
	for(int i=0; i<3; i++)
	{
	if(i==1)
		{
			printf("Rows: ");
			scanf("%d",&r2);
		}
		if(i==2)
		{
			printf("Columns: ");
			scanf("%d",&c2);
		}
	}
	num=0;
	printf("Enter the elements of the second matrix\n\n");
	for(int i=0; i<r2; i++)
	{
		for(int j=0; j<c1; j++)
		{
			printf("[%d]: ",++num);
			scanf("%d",&second[i][j]);
		}
	}
	if (c1!=r2)
	{
		printf("Multiplication cannot be done");
	}
	else{
		 for ( int i=0 ; i<r1 ; i++ )
   		 {
     		 for ( int j=0; j<c2 ; j++ )
     		 {
    			 for ( int k=0; k<r2 ; k++ )
      	    	 {
        		  sum = sum + first[i][k]*second[k][j];
				}
				multiply[i][j] = sum;
				sum = 0;
				}
		 }
	}
	system("cls");
	printf("Product:\n");
	for(int i=0; i<r1; i++)
	{
		printf("\t");
		for(int j=0; j<c2; j++)
		{
			printf("%d \t",multiply[i][j]);
		}
		printf("\n\n");
	}
	getch();
}

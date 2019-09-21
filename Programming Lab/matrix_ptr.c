/*Name : Kunal Surendra Gadgil
  Roll No. : 3164030 */
#include<stdio.h>
#include<stdlib.h>
void accept(int **a, int row, int col);
void display(int **a, int row, int col);
void add(int **a, int **b, int row, int col);
void mul(int **a, int **b, int row1, int row2, int col2);
void trans(int **a, int row, int col);
void saddle(int **a, int row, int col);
int **mallocate(int row,int col);
void main()
{
	int row1,col1,row2,col2,**a,**b;
	int n,t;
	while(1)
	{
		printf("\n1.Accept\n2.Display\n3.Addition\n4.Multiplication\n5.Transpose\n6.Saddle Point\n7.Exit\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the number of rows and columns of 1st matrix :\n");
				scanf("%d%d",&row1,&col1);
				a=mallocate(row1,col1);
				printf("Enter elements of 1st matrix :\n");
				accept(a,row1,col1);
				printf("Enter the number of rows and columns of 2nd matrix :\n");
				scanf("%d%d",&row2,&col2);
				b=mallocate(row2,col2);
				printf("Enter elements of 2nd matrix :\n");
				accept(b,row2,col2);
				break;
			case 2:
				printf("Matrix 1 : \n");
				display(a,row1,col1);
				printf("Matrix 2 : \n");
				display(b,row2,col2);
				break;
			case 3:
				if(row1==row2 && col1==col2)
					add(a,b,row1,col1);
				else
					printf("\nAddition is not possible.");
				break;
			case 4:
				if(col1==row2)
					mul(a,b,row1,row2,col2);
				else
					printf("\nMultiplication is not possible.");
				break;
			case 5:
				printf("1.Transpose of A\n2.Transpose of B\nEnter your choice : ");
				scanf("%d",&t);
				if(t==1)
					trans(a,row1,col1);
				else if(t==2)
					trans(b,row2,col2);
				else
					printf("Wrong choice.");
				break;
			case 6:
				printf("1.Saddle point of A\n2.Saddle point of B\nEnter your choice : ");
				scanf("%d",&t);
				if(t==1)
					saddle(a,row1,col1);
				else if(t==2)
					saddle(b,row2,col2);
				else
					printf("Wrong choice.");
				break;
			case 7:
				exit(0);
				break;
		}
	}
}

void accept(int **a, int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",(*(a+i)+j));
}

void display(int **a, int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{	
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
}

void add(int **a, int **b, int row, int col)
{ 
	int i,j,**c;
	c=mallocate(row,col);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
		}
	}
	printf("\nAddition is : \n");
	display(c,row,col);
}

void mul(int **a, int **b, int row1, int row2, int col2)
{
	int i,j,k,**c;
	c=mallocate(row1,col2);
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			*(*(c+i)+j)=0;
			for(k=0;k<row2;k++)
			{
				*(*(c+i)+j) += *(*(a+i)+k)**(*(b+k)+j);
			}
		}
	}
	printf("\nMultiplication is : \n");
	display(c,row1,col2);
}

void trans(int **a, int row, int col)
{
	int i,j,**c;
	c=mallocate(col,row);
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{	
			*(*(c+i)+j)=*(*(a+j)+i);
		}
	}
	printf("\nTranspose is : \n");
	display(c,col,row);
}

void saddle(int **a, int row, int col)
{
	int *rmin,*cmax,min=0,max=0,i,j;
	rmin=(int *)malloc(sizeof(int)*row);
	cmax=(int *)malloc(sizeof(int)*col);
	for(i=0;i<row;i++)
	{
		*(rmin+i)=*(*(a+i)+0);
		for(j=1;j<col;j++)
		{
			if(*(*(a+i)+j)<*(rmin+i))
				*(rmin+i)=*(*(a+i)+j);
		}
	}
	max=*(rmin+0);
	for(i=1;i<row;i++)
	{
		if(*(rmin+i)>max)
			max=*(rmin+i);
	}
	for(j=0;j<col;j++)
	{
		*(cmax+j)=*(*(a+0)+j);
		for(i=0;i<row;i++)
		{
			if(*(*(a+i)+j)>*(cmax+j))
				*(cmax+j)=*(*(a+i)+j);
		}
	}
	min=*(cmax+0);
	for(i=1;i<col;i++)
	{
		if(*(cmax+i)<min)
			min=*(cmax+i);
	}
	if(max==min)
		printf("Saddle point exists : %d\n",max);
	else
		printf("Saddle point doesn't exist.\n");
	
}

int **mallocate(int row,int col)
{
	int **a,i;
	a=(int **)malloc(sizeof(int*)*row);
	for(i=0;i<row;i++)
		a[i]=(int *)malloc(sizeof(int)*col);
	return a;
}

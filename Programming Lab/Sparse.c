#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct
{
	int row;
	int col;
	int val;
}Sparse;
void accept(int a[max][max],Sparse s[max], int m,int n);
void display(Sparse s[max]);
void add(Sparse s1[max],Sparse s2[max],Sparse s3[max]);
void sim_trans(Sparse s[max],Sparse st[max]);
void fast_trans(Sparse s[max],Sparse ft[max]);

void main()
{
	int a[max][max],b[max][max],c[max][max];
	int m1,n1,m2,n2,ch=0;
	Sparse s1[max];
	Sparse s2[max];
	Sparse s3[max];
	Sparse st[max];
	while(1)
	{
		printf("\nEnter\n1.For Addition\n2.For Simple Transpose\n3.Fast Transpose\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("\nEnter dimensions of A\n");
					scanf("%d%d",&m1,&n1);
					printf("\nEnter elements of A\n");
					accept(a,s1,m1,n1);
					printf("\nEnter dimensions of B\n");
					scanf("%d%d",&m2,&n2);
					printf("\nEnter elements of B\n");
					accept(b,s2,m2,n2);
					add(s1,s2,s3);
					printf("\nAddition is\n");
					display(s3);
					break;
			case 2:
					printf("\nEnter dimensions of A\n");
					scanf("%d%d",&m1,&n1);
					printf("\nEnter elements of A\n");
					accept(a,s1,m1,n1);
					printf("\nOriginal Matrix is\n");
					display(s1);
					printf("\nSimple transpose of A is\n");
					sim_trans(s1,st);
					break;
			case 3:
					printf("\nEnter dimensions of A\n");
					scanf("%d%d",&m1,&n1);
					printf("\nEnter elements of A\n");
					accept(a,s1,m1,n1);
					printf("Original sparse matrix:\n");
					display(s1);
					printf("Transposed sparse matrix is:\n");
					fast_trans(s1,st);
					display(st);
					break;
			case 4: exit(1);
					break;
			default: printf("\nWrong choice\n");

		}
	}
}
void accept(int a[max][max],Sparse s[max], int m,int n)
{
	int i,j,k=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
			{
				s[k].row=i;
				s[k].col=j;
				s[k].val=a[i][j];
				k++;
			}
		}
	}
	s[0].row=m;
	s[0].col=n;
	s[0].val=k-1;
}

void display(Sparse S[max])
{
 	int i;
 	for(i=0;i<S[0].val+1;i++)
 		printf("%d %d %d\n",S[i].row,S[i].col,S[i].val);
}

void add(Sparse s1[max],Sparse s2[max],Sparse s3[max])
{
        int i,j,k,t1,t2;
        if(s1[0].row!=s2[0].row && s1[0].col!=s2[0].col)
        {
        printf("Addition not possible");
        }
        else
        {
                i=j=k=1;
                t1=s1[0].val;
                t2=s2[0].val;
                s3[0].row=s1[0].row;
                s3[0].col=s1[0].col;
                while(i<=t1 && j<=t2)
                {
                if(s1[i].row<s2[j].row)
                {
                        s3[k].row=s1[i].row;
                        s3[k].col=s1[i].col;
                        s3[k].val=s1[i].val;
                        i++;
                        k++;
                }
                else if(s1[i].row>s2[j].row)
                {
                        s3[k].row=s2[j].row;
                        s3[k].col=s2[j].col;
                        s3[k].val=s2[j].val;
                        j++;
                        k++;
                }
                else if(s1[i].col<s2[j].col)
                {
                        s3[k].row=s1[i].row;
                        s3[k].col=s1[i].col;
                        s3[k].val=s1[i].val;
                        i++;
                        k++;
                }
                else if(s1[i].col>s2[j].col)
                {
                        s3[k].row=s2[j].row;
                        s3[k].col=s2[j].col;
                        s3[k].val=s2[j].val;
                        j++;
                        k++;
                }
                else if(s1[i].row==s2[j].row && s1[i].col==s2[j].col)
                {
                        s3[k].row=s1[i].row;
                        s3[k].col=s1[i].col;
                        s3[k].val=s1[i].val+s2[j].val;
                        i++;
                        j++;
                        k++;
                }
                }
                while(i<=s1[0].row)
                {
                        s3[k].row=s1[i].row;
                        s3[k].col=s1[i].col;
                        s3[k].val=s1[i].val;
                        i++;
                        k++;
                }
                while(j<=s2[0].row)
                {
                        s3[k].row=s2[j].row;
                        s3[k].col=s2[j].col;
                        s3[k].val=s2[j].val;
                        j++;
                        k++;
                }
        }
        s3[0].val=k-1;
}

void sim_trans(Sparse s[max], Sparse st[max])
{
	int i,j,k,m,n;
	k=1;
	st[0].row=s[0].col;
	st[0].col=s[0].row;
	st[0].val=s[0].val;
	for(i=0;i<s[0].col;i++)
		for(j=1;j<=s[0].val;j++)
		{
			if(i==s[j].row)
			{
				st[k].row=s[j].col;
				st[k].col=s[j].row;
				st[k].val=s[j].val;
				k++;
			}
		}
	display(st);
}

void fast_trans(Sparse s[max], Sparse st[max])
{
	int i,j,k,m,t;
	int total[max],index[max];
	t=s[0].val;
	st[0].row=s[0].col;
	st[0].col=s[0].row;
	st[0].val=s[0].val;
	for(i=0;i<s[0].col;i++)
		total[i]=0;
	for(i=0;i<=t;i++)
	{
		j=s[i].col;
		total[j]++;
	}
	index[0]=1;
	for(i=1;i<s[0].col;i++)
		index[i]=index[i-1]+total[i-1];
	for(i=1;i<=t;i++)
	{
		j=s[i].col;
		k=index[j];
		index[j]++;
		st[k].row=s[i].col;
		st[k].col=s[i].row;
		st[k].val=s[i].val;
	}
}


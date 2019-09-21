#include<stdio.h>
#include<stdlib.h>

void accept(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
}
void display(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d\n",a[i]);
}
void adiff(int a[],int b[],int size1,int size2)
{
    int i,j,flag,l[40],k=0;
    for(i=0;i<size1;i++)
    {
        flag=0;
        for(j=0;j<size2;j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            l[k]=a[i];
            k++;
        }
    }
    display(l,k);
}
void unionAB(int a[],int b[],int size1, int size2)
{
    display(a,size1);
    adiff(b,a,size2,size1);
}
void intersection(int a[],int b[],int size1, int size2)
{
    int i,j,c[size1+size2],k=0;
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size2;j++)
        {
            if(a[i]==b[j])
            {
                c[k]=a[i];
                k++;
                break;
            }
        }
    }
    display(c,k);
}
void diff(int a[],int b[], int size1, int size2)
{
    int choice;
    printf("\nEnter your  choice :\n1.A-B\n2.B-A\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nA-B is : ");
                adiff(a,b,size1,size2);
                break;
        case 2: printf("\nB-A is : ");
                adiff(b,a,size2,size1);
                break;
        default:printf("\nWrong choice\n");
    }
}
void symdiff(int a[],int b[], int size1, int size2)
{
    adiff(a,b,size1,size2);
    adiff(b,a,size2,size1);
}
int main(void)
{
    int size1,size2,ch=0;
    printf("\nEnter size of Matrix A and size of Matrix B : ");
    scanf("%d%d",&size1,&size2);
    int a[size1], b[size2];
    printf("\nEnter elements of matrix A ");
    accept(a,size1);
    printf("\nEnter elements of matrix B ");
    accept(b,size2);
    printf("\nMatrix A is : \n");
    display(a,size1);
    printf("\nMatrix B is : \n");
    display(b,size2);
    while(1)
    {
        printf("\n1.Union\n2.Intersection\n3.Difference\n4.Symmetric Difference\n5.Exit\nEnter your choice now : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nUnion is : \n");
                    unionAB(a,b,size1,size2);
                    break;
            case 2: printf("\nIntersection is : \n");
                    intersection(a,b,size1,size2);
                    break;
            case 3: diff(a,b,size1,size2);
                    break;
            case 4: printf("\nSymmetric difference is : \n");
                    symdiff(a,b,size1,size2);
                    break;
            case 5: exit(1);
                    break;
            default: printf("\nWrong choice!\n");
        }
    }
}


#include<stdio.h>
#include<stdlib.h>
#define MAX 10
 
struct stack
{
 
    int a,b;
}s[MAX];
 
int top=-1;
int a[MAX],n;
 
int isempty();
int isfull();
void accept();
void display();
void swap(int *,int *);
int partition( int ,int  );
void rec_quick( int , int );
void non_rec_quick(int ,int );
void push(int , int );
void pop(int *, int *);

void main()
{
    int ch,low=0,high;

    while(1)
    {
        printf("\n1.Recursive Quick sort");
        printf("\n2.Non_Recursive Quick sort");
        printf("\n3.Exit");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
            switch(ch)
            {
 
 
                case 1:
                        printf("\nEnter number of elements :");
                        scanf("%d",&n);
                        high = n-1;
                        accept();
                        rec_quick(low,n-1);
                        display();
                        break;
                case 2:
                        printf("\nEnter number of elements :");
                        scanf("%d",&n);
                        high=n-1;
                        accept();
                        non_rec_quick(low,high);
                        display();
                        break;
                case 3: exit(0);
            }
    }
}
 
void accept()
{
    int i;
 
    printf("\nEnter the list :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
 
 
void display()
{
    int i;
    printf("\nThe list is :");
    for(i=0;i<n;i++)
    {
        printf("\t %d",a[i]);
    }
}
 
void swap(int *a,int *b)
{
    int t=0;
    t=*a;
    *a=*b;
    *b=t;
}
 
void push(int x, int y)
{
    if(isfull() == 1 )
    {
        printf("\nStack is full.");
    }
    else
    {
        top++;
        s[top].a=x;
        s[top].b=y;
    }
}
void pop(int *x, int *y)
{
    if(isempty() == 1 )
    {
        printf("\nStack is empty.");
    }
    else
    {
        *x=s[top].a;
        *y=s[top].b;
        top--;
    }
}
 
int isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
 
int isfull()
{
    if(top == MAX)
        return 1;
    else
        return 0;
}
int partition(int low,int high)
{
    int piv,i,j;
    piv=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(a[i] <= piv && i<high)
            i++;
        while(a[j] >= piv && j>low)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
        else
            break;
    }
    swap(&a[low],&a[j]);
    return j;
}
void rec_quick(int low,int high)
{
    int j=0,i;
    if(low < high)
    {
        for(i=low;i<high+1;i++)
            	printf("%d\t",a[i]);
	printf("\n");
        j = partition(low,high);
        rec_quick(low,j-1);
        rec_quick(j+1,high);
    }
}
 
void non_rec_quick(int low ,int high)
{
    int j=0,i;
    push(low ,high);
    while(! isempty())
    {
        pop(&low , &high);
        while(low < high)
        {
            for(i=low;i<high+1;i++)
            	printf("%d\t",a[i]);
	    printf("\n");
            j = partition(low ,high);
            push(j+1,high);
            high=j-1;
        }
    }
}

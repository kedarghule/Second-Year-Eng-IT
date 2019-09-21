#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void accept(char a[50][50], int n)
{
    int i;
    printf("\nEnter strings:\n");
    for(i=0;i<n;i++)
		scanf("%s",a[i]);
}

void Bubblesort()
{
int n;
printf("\nEnter number of strings:\n");
scanf("%d",&n);
char a[50][50];
accept(a,n);
int i,j,k,pass = 1;
char temp[50];
printf("\nBubble Sort:");
for(i=0;i<n;i++)
{

	for(j=0;j<n-1-i;j++)
	{
		if(strcmp(a[j],a[j+1])>0)
		{
		strcpy(temp,a[j]);
		strcpy(a[j],a[j+1]);
		strcpy(a[j+1],temp);
		}

	}
	printf("\nPass %d: ", pass++);
	for(k=0;k<n;k++)
		printf("%s  ",a[k]);
}
printf("\n");
}

void Selectionsort()
{
int n;
printf("\nEnter number of strings:\n");
scanf("%d",&n);
char a[50][50];
accept(a,n);
int i,j,k,min,pass=1;
char temp[50];
printf("\nSelection Sort");
for(i=0;i<n-1;i++)
{
	min = i;
	for(j=i+1;j<n;j++)
	{
		if(strcmp(a[j],a[min])>0)
			min = j;

		strcpy(temp,a[i]);
		strcpy(a[i],a[min]);
		strcpy(a[min],temp);
	}
	printf("\nPass %d: ", pass++);
	for(k=0;k<n;k++)
		printf("%s  ",a[k]);

}
printf("\n");
}

void Insertionsort()
{
    int n;
    printf("\nEnter number of strings:\n");
    scanf("%d",&n);
    char a[50][50];
    accept(a,n);
    int i,j,k,pass=1;
    char temp[50];
    printf("\nInsertion Sort\n");
    for(i=1;i<n;i++)
    {
        strcpy(temp,a[i]);
        j=i-1;
        while((j>=0)&&(strcmp(a[j],temp)>0))
        {
            strcpy(a[j+1],a[j]);
            j=j-1;
        }
        strcpy(a[j+1],temp);
        printf("\nPass %d: ", pass++);
        for(k=0;k<n;k++)
            printf("%s  ",a[k]);
    }
}


void main()
{
	int ch;
    do
    {
            printf("\n1.Ascending order using Bubble sort \n2.Descending order using Selection Sort\n3.Descending order using Insertion sort\n4.Exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
		case 1:
		Bubblesort();
		break;

		case 2:
		Selectionsort();
		break;

		case 3:
        Insertionsort();
        break;

		default:
		exit(0);

		}
}while(ch<=3);
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binarysearch(char a[50][50],int n,char key[50])
{
    int beg,end,mid;
    beg=0; end=n-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(strcmp(a[mid],key)==0)
            return mid;
        else if(strcmp(a[mid],key)<0)
            beg=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
int RBSearch(char a[50][50],char key[50],int beg,int end)
{
    int mid;
    if(beg>end)
        return -1;
    mid=(beg+end)/2;
    if(strcmp(a[mid],key)==0)
        return mid;
    else if(strcmp(a[mid],key)<0)
        RBSearch(a,key,mid+1,end);
    else
        RBSearch(a,key,beg,mid-1);
}
int main(void)
{
    char a[50][50],key[50];
    int i,ch,n,flag,beg,end;
    printf("\nEnter number of strings : \n");
    scanf("%d",&n);
    printf("\nEnter strings : \n");
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    while(1)
    {
        printf("\n1.Binary search without recursion.\n2.Binary search with recursion.\n3.Exit.\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter word to be searched : ");
                    scanf("%s",key);
                    flag=binarysearch(a,n,key);
                    if(flag==-1)
                        printf("\nWord not present\n");
                    else
                        printf("\nWord present at position %d",flag+1);
                    break;
            case 2: beg=0;end=n-1;
                    printf("\nEnter word to be searched : ");
                    scanf("%s",key);
                    flag=RBSearch(a,key,beg,end);
                    if(flag==-1)
                        printf("\nWord not present\n");
                    else
                        printf("\nWord present at position %d",flag+1);
                    break;
                    break;
            case 3: exit(1);
                    break;
            default: printf("\nWrong choice.\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
void accept(char str[20])
{
    scanf("%s",str);
}
int length(char str[20])
{
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}
void palindrome(char str1[20])
{
    int i,j=0;
    int len=length(str1);
    char str2[20];
    for(i=len-1;i>=0;i--)
    {
        str2[j]=str1[i];
        j++;
    }
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(str1[i]!=str2[i])
            flag=1;
    }
    if(flag==0)
        printf("\nIt is a palindrome string\n");
    else
        printf("\nIt is not a palindrome string\n");
}
int compare(char str1[20],char str2[20])
{
    int i,l,d;
    l=length(str1);
    for(i=0;i<l;i++)
    {
        d=str1[i]-str2[i];
        if(d==0)
            continue;
        else
            break;
    }
    return d;
}
void copy(char str1[20],char str2[20])
{
    int i,j=0;
    //char temp[20];
    str1[20]='\0';
    for(i=0;str2[i]!='\0';i++)
      {
          str1[i]=str2[i];j++;
      }
    /**for(j=i;str1[j]!='\0';j++)
        temp[j]=str1[j];**/
    for(i=0;i<j;i++)
        printf("%c",str1[i]);
    printf("\n");
}
void reverse(char str[])
{
    int l=length(str);
    int i;
    for(i=l-1;i>=0;i--)
        printf("%c",str[i]);
}
void substring(char str1[],char str2[])
{
    int l1=length(str1);
    int l2=length(str2);
    int i,j,k=0,flag=0;
    for(i=0;i<l1;i++)
    {
        if(str2[0]==str1[i])
        {
            j=i;
            for(k=0;k<l2;k++)
            {
                if(str2[k]==str1[j])
                {
                    j++;flag=1;
                }
                else
                    continue;
            }
            if(k==l2 && flag==1)
            {
                printf("\nIt is a substring\n");
                break;
            }
        }
    }
    if(flag==0)
                printf("\nIt is not a substring\n");
}
int main(void)
{
    int ch,len,com;
    char str1[20],str2[20];
    printf("\nEnter a string\n");
    accept(str1);
    while(1)
    {
        printf("\n1.Length\n2.Palindrome\n3.String comparison\n4.Copy\n5.Reverse\n6.Substring\n7.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: len=length(str1);
                    printf("\nLength of the string is = %d\n",len);
                    break;
            case 2: palindrome(str1);
                    break;
            case 3: printf("\nEnter string 2 : ");
                    accept(str2);
                    com=compare(str1,str2);
                    if(com>0)
                        printf("\nString %s is greater.\n",str1);
                    else if(com<0)
                        printf("\nString %s is greater.\n",str2);
                    else
                        printf("\nStrings are same.\n");
                    break;
            case 4: printf("\nEnter string 2 : ");
                    accept(str2);
                    copy(str1,str2);
                    break;
            case 5: printf("\nReversed string is = ");
                    reverse(str1);
                    break;
            case 6: printf("\nEnter string 2 : ");
                    accept(str2);
                    substring(str1,str2);
                    break;
            case 7: exit(1);
                    break;

        }
    }
}

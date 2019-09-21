#include<stdio.h>
#include<stdlib.h>
void accept(char str[20]);
int slen(char *x);
void rev(char *x);
int scomp(char str1[20], char str2[20]);
void copy(char *x, char *y);
void substr(char str1[20], char str2[20]);
void main()
{
	char str1[20],str2[20];
	int len=0,ch=0,com;
	while(1)
	{
		printf("\n\n1.Length\n2.Palindrome\n3.String Compare\n4.Copy\n5.Reverse\n6.Substring\n7.Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter a string : ");
				accept(str1);
				len=slen(str1);
				printf("Length is : %d",len);
				break;
			case 2:
			{
				printf("Enter a string : ");
				accept(str1);
				copy(str2,str1);
				rev(str2);
				com=scomp(str1,str2);
				if(com==0)
				{
					printf("String is Palindrome.");
				}
				else
				{
					printf("String is not a Palindrome");
				}
				break;
			}
			case 3:
			{
				printf("Enter first string : ");
				accept(str1);
				printf("Enter second string : ");
				accept(str2);
				com=scomp(str1,str2);
				if(com>0)
				{
					printf("String '%s' is greater.",str1);
				}
				else if(com<0)
				{
					printf("String '%s' is greater.",str2);
				}
				else
				{
					printf("Strings are same.");
				}
				break;
			}
			case 4:
			{
				printf("Enter first string : ");
				accept(str1);
				printf("Enter second string : ");
				accept(str2);
				copy(str1,str2);
				printf("Now the first string is : %s",str1);
				break;
			}
			case 5:
			{
				printf("Enter a string : ");
				accept(str1);
				rev(str1);
				printf("Reversed string is : %s",str1);
				break;
			}
			case 6:
			{
				printf("Enter first string : ");
				accept(str1);
				printf("Enter second string : ");
				accept(str2);
				substr(str1,str2);
				break;
			}
			default :
				exit(0);
		}
	}
}
void accept(char str[20])
{
	scanf("%s",str);
}

int slen(char *x)
{
	int i=0;
	while(*x!='\0')
	{
		i++;
		x++;
	}
	return i;
}

void rev(char *x)
{
	int i=0,j;
	char temp;
	j=slen(x)-1;
	while(i<j)
	{
		temp=*(x+i);
		*(x+i)=*(x+j);
		*(x+j)=temp;
		j--;
		i++;
	}
}

void copy(char *x, char *y)
{
	while(*y!='\0')
	{
		*x=*y;
		x++;
		y++;
	}
	*x='\0';
}

int scomp(char *x, char *y)
{
	int i,l,d;
	l=slen(x);
	for(i=0;i<l;i++)
	{
		d=*(x+i)-*(y+i);
		if(d==0)
			continue;
		else
			break;
	}
	return d;
}
void substr(char *x, char *y)
{
	int i,j,k;
	j=0;
	k=0;
	while(*(x+k)!='\0' && *(y+j)!='\0')
	{
		i=k;
		j=0;
		while(*(x+k)!='\0' && *(y+j)!='\0')
		{
			if(*(x+i)!=*(y+j))
			{
				break;
			}
			i++;
			j++;
		}
		k=k+1;
	}
	if(*(y+j)=='\0')
		printf("It is a Substring.");
	else
		printf("It is not a Substring.");
}


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node *prev , *next;
}NODE;
//typedef struct node NODE;
// FUNCTION DECLARATIONS

NODE *getnode(char);
NODE *create();

NODE *search(NODE *first,char);
void display(NODE *temp);
int count(NODE *first);

char accept();
NODE *addnode(NODE *);
NODE * addbegin(NODE *first,char);
void addend(NODE *first,char);
void addbyvalue(NODE *first,char);

NODE *delnode(NODE *);
NODE * delbegin(NODE *first);
void delend(NODE *first);
NODE *delbyvalue(NODE *first);

//void disp_forward(NODE *first);
void disp_backwrd(NODE *first);

int main()
{
	NODE *first = NULL;
	int total=0 , opt;
	char ch[2];
	
//	char *str;
	NODE *S = NULL;
//	NODE *p,*q;
for(;;)
{


	printf("\n 1. Create the list");
	printf("\n 2. Search the node");
	printf("\n 3. Count the list");
	printf("\n 4. Insert the node");
	printf("\n 5. Delete the node");
	printf("\n 6. Display Forward");
	printf("\n 7. Display Backward");
	printf("\n 8. Exit\n");
	scanf("%d", &opt);
	switch(opt)
	{
		case 1:  		// CREATE
			first = create();
			break;
		case 2:			// SEARCH
			if( first != NULL )
			{
				printf("\n Enter the charaxter :");
				scanf("%s", ch);
								
				S = search(first,ch[0]);

				if( S != NULL )
				{
					printf("\nCHARACTER FOUND \n");
					printf("\n----------------------------------");
					printf("\n%c",S->data);
				}
				else
					printf("\n CHARACTER NOT FOUND.");
			}//end of (first != NULL)
			else
				printf("\n EMPTY LIST");

			break;
		case 3:  	// COUNT
			if( first != NULL )
			{
				total = count(first);
				printf("\n Total number of characters in DLL are : %d", total);
			}
			else
				printf("\n LIST IS EMPTY.");

			break;

		case 4:
			if (first != NULL )
				first = addnode(first);
			else
				printf("\n LIST NOT CREATED.");
			break;


		case 5:
			if (first != NULL )
				first = delnode(first);
			else
				printf("\n LIST IS EMPTY.");
			break;

		case 6:
			if( first != NULL )
			{
				display(first);

			}
			else
				printf("\n LIST IS EMPTY.");
			break;
		case 7:
			if( first != NULL )
			{
				disp_backwrd(first);

			}
			else
				printf("\n LIST IS EMPTY.");
			break;

		case 8:
			exit(0);

	}//end of switch
}//end of infinite for
}// end of main

/*------------------- FUNCTION DEFINITON'S STARTS HERE ------------------- */
NODE * getnode(char ch)
{
	NODE *temp = NULL;
	temp = (NODE *) malloc(sizeof(NODE));
	temp->data = ch;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

NODE * create()
{
	NODE *first = NULL, *last = NULL, *temp  = NULL;
	int i=0;
	char *str = NULL;
	str = (char *)malloc(sizeof(char) * 15);
	printf("Enter a string:");
	scanf("%s",str);

	while(str[i]!='\0')
	{

		temp = getnode(str[i]);
		if( first == NULL )
			first = temp;
		else
		{
			last -> next = temp;
			temp -> prev = last;
		}

		last = temp;
		i++;
	}//end of for

	return first;
}//end of create

void display(NODE *ptr)
{
	printf("\nTHE LIST IS : ");
	while(ptr!=NULL)
	{
		if(ptr->next!=NULL)
			printf("%c -> ",ptr->data);
		else
			printf("%c ",ptr->data);
		ptr = ptr->next;
	}//end of while
}//end of display

void disp_backwrd(NODE *ptr)
{
	printf("\nTHE LIST IS : ");
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	while(ptr!=NULL)
	{
		if(ptr->prev != NULL)
			printf("%c -> ",ptr->data);
		else
			printf("%c ",ptr->data);
		ptr = ptr->prev;
	}//end of while
}//end of display

NODE *search(NODE *first, char ch)
{
	NODE *temp = NULL;
	temp = first;

	while(temp != NULL)
	{
		if( temp->data == ch )
			return (temp);
		temp = temp->next;
	}

	return NULL;
}

int count(NODE *first)
{
	NODE *temp = first;
	int cnt = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		cnt++;
	}
	return cnt;
}


NODE *addnode(NODE *first)
{
	int opt;
	char ch;
	for(;;)
	{
		printf("\n THE LIST IS : \n");
		display(first);
		printf("\n");

		printf("\n 1. Add at the beginning");
		printf("\n 2. Add at the end");
		printf("\n 3. Add after value");
		printf("\n 4. return to main");
		printf("\nEnter your choice :");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				ch = accept();
				first = addbegin(first,ch);
				break;
			case 2:
				ch = accept();
				addend(first,ch);
				break;
			case 3:
				ch = accept();
				addbyvalue(first,ch);
				break;
			case 4:
				return first;
		}//end of switch
	}//end of infinite for
}// END OF INSERT MENU

char accept()
{
	char ch[2];
	printf("Enter the character to be inserted:");
	scanf("%s",ch);
	return (ch[0]);
}


NODE * addbegin(NODE *first, char ch)
{
	NODE *temp = NULL;
	temp = getnode(ch);
	temp->next = first;
	first->prev = temp;
	first = temp;
	return(first);
}// END OF ADD BEGIN

void addend(NODE *first, char ch)
{
	NODE *temp = NULL, *ptr = NULL;
	ptr = first;
	temp = getnode(ch);
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = temp;
	temp->prev = ptr;
}// END OF ADD-END

void addbyvalue(NODE *first, char ch)
{
	NODE *temp = NULL, *ptr = NULL;
	char val[2];
	printf("\n Enter the data of node after which to be inserted:");
	scanf("%s", val);
	ptr = search(first, val[0]);

	if( ptr != NULL )//IF DATA EXISTS
	{
		temp = getnode(ch);
		temp->next = ptr->next;
		temp->prev = ptr;
		ptr->next = temp;
	}
	else
		printf("\n DATA NOT FOUND.");
}// END OF ADD-VALUE


NODE *delnode(NODE *first)
{
	int ch;
	for(;;)
	{
		printf("\n List is : \n");
		display(first);
		printf("\n");
		printf("Which u want to delete ? \n");
		printf("1.At Front \n2.At End \n3.In Middle");
		printf("\n4.return to main");
		printf("\nEnter your choice :");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	
				first = delbegin(first);
				break;
			
			case 2:
				delend(first);
				break;

			case 3:
				first = delbyvalue(first);
				break;
			case 4:
				return first;
		}//end of switch
	}//end of infinite for
}// END OF DELETE MENU

NODE * delbegin(NODE *first)
{
	NODE *temp = NULL;
	temp = first;
	first = first->next;
	first->prev = NULL;
	printf("\n Data %c deleted", temp->data);
	free(temp);
	return first;
}

void delend(NODE *first)
{
	NODE *temp = NULL, *ptr = NULL;
	temp = first;
	while(temp->next != NULL)
	{
		ptr = temp;
		temp = temp ->next;
	}

	ptr->next = NULL;
	printf("\n Data %c deleted", temp->data);
	free(temp);
}

NODE *delbyvalue(NODE *first)
{
	// currr is node to be deleted and prev is predecessor of ptr

	NODE *curr = NULL, *prev = NULL;
	char val[2];

	curr = first;
	
	printf("\n Enter the node value:");
	scanf("%s", val);

	while( curr != NULL )
	{
		// traverse till requried node to delete is found
		if( curr->data == val[0] )
		{
			break;
		}//end of if

		prev = curr;
		curr = curr->next;
	}//end of while

	if( curr != NULL )   // NODE IS PRESENT
	{
		if(curr == first)
		{
			first = first->next;
			first->prev = NULL;
		}
		else
		// IF NODE IS ANY INTERMEDIATE
		{
			prev->next = curr->next;
			curr->next->prev = prev;
		}
		printf("\n Data %c deleted", curr->data);
		free(curr);
	}
	else
		printf("\n DATA NOT FOUND.");
	return first;
}//end of delete by value

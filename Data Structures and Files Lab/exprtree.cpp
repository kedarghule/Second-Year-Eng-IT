#include<iostream>
using namespace std;

typedef struct node
{
	char data[10];
	struct node *left,*right;
}node;

typedef struct stack
{
	node *data;
	int flag;
}stack;

class expressiontree
{
	char str[20];
	public:
		expressiontree()
		{
			str[0]='\0';
		}	
		node *create();
		node *displayinorder(node *root);
		node *displaypreorder(node *root);
		node *displaypostorder(node *root);
		void inorder_nonrec(node* root);
		void preorder_nonrec(node* root);
		void postorder_nonrec(node* root);
};

class stack1
{
	public:
		stack data[30];
		int top;
		stack1()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		void push(stack t)
		{
			data[++top]=t;
		}
		stack pop()
		{
			return data[top--];
		}
};
node* expressiontree::create()
{
	node* root;
	int top=-1;
	int i=0;
	node** stack=new node*[50];
	cout<<"Enter the expression : ";
	cin>>str;
	do
	{
		node *temp;
		temp=new node;
		temp->data[0]=str[i];
		temp->left=NULL;
		temp->right=NULL;
		if(isalnum(str[i]))
			stack[++top]=temp;
		else
		{
			temp->right=stack[top--];
			temp->left=stack[top--];
			stack[++top]=temp;
		}
		i++;
	
	}while(str[i]!='\0');
	root=stack[top];
	return root;
}

node* expressiontree::displayinorder(node *root)
{
	node* temp=root;
	if(temp!=NULL)
	{
		displayinorder(temp->left);
		cout<<temp->data;
		displayinorder(temp->right);
	}
	else
		return temp;
}
node* expressiontree::displaypreorder(node *root)
{
	node* temp=root;
	if(temp!=NULL)
	{
		cout<<temp->data;
		displaypreorder(temp->left);
		displaypreorder(temp->right);
	}
	else
		return temp;
}
node* expressiontree::displaypostorder(node *root)
{
	node* temp=root;
	if(temp!=NULL)
	{
		displaypostorder(temp->left);
		displaypostorder(temp->right);
		cout<<temp->data;
	}
	else
		return temp;
}
void expressiontree::inorder_nonrec(node* root)
{
	node* temp=root;
	node** stack=new node*[50];
	int top=-1;
	do
	{
		while(temp!=NULL)
		{
			stack[++top]=temp;
			temp=temp->left;
		}
		temp=stack[top--];
		cout<<temp->data;
		temp=temp->right;
	}while(temp!=NULL || top!=-1);
}
void expressiontree::preorder_nonrec(node* root)
{
	node* temp=root;
	node** stack=new node*[50];
	int top=-1;
	do
	{
		while(temp!=NULL)
		{
			cout<<temp->data;
			stack[++top]=temp;
			temp=temp->left;
		}
		temp=stack[top--];
		temp=temp->right;
	}while(temp!=NULL || top!=-1);
}
void expressiontree::postorder_nonrec(node* root)
{
	stack s;
	stack1 st;
	node* temp=root,*temp1;
	while(temp!=NULL)
	{
		s.data=temp;
		s.flag=0;
		st.push(s);
		temp=temp->left;
	}
	while(!st.empty())
	{
		s=st.pop();
		if(s.flag==0)
		{
			s.flag=1;
			st.push(s);
			temp=s.data;
			temp=temp->right;
			while(temp!=NULL)
			{
				s.data=temp;
				s.flag=0;
				st.push(s);
				temp=temp->right;
			}
		}
		else
		{
			temp1=s.data;
			cout<<temp1->data;
		}
	}
}
int main()
{
	int ch;
	node* root;
	expressiontree t;
	while(1)
	{
		cout<<"1.Create\n2.Infix\n3.Prefix\n4.Postfix\n5.Infix Non Recursive\n6.Prefix Non Recursive\n7.Postfix Non Recursive\n8.Exit\nEnter option : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				root=t.create();
				break;
			case 2:	
				cout<<"Infix : ";
				t.displayinorder(root);
				cout<<"\n";
				break;
			case 3:	
				cout<<"Prefix : ";
				t.displaypreorder(root);
				cout<<"\n";
				break;
			case 4:	
				cout<<"Postfix : ";
				t.displaypostorder(root);
				cout<<"\n";
				break;
			case 5:
				cout<<"Infix Non Recursive: ";
				t.inorder_nonrec(root);
				cout<<"\n";
				break;
			case 6:
				cout<<"Prefix Non Recursive: ";
				t.preorder_nonrec(root);
				cout<<"\n";
				break;
			case 7:
				cout<<"Postfix Non Recursive: ";
				t.postorder_nonrec(root);
				cout<<"\n";
				break;
			case 8: 
				return 0;
		}
	}
}













#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;
typedef struct stack
{
	node *data;
	struct stack *next=NULL;
}stack;
class bst
{
	public:
		stack *top;
		node *root;
		bst()
		{
			root=NULL;
		}
		void insert();
		void create_tree(int x);
		void inorder(node *);
		void displaycall();
		void push(node *x);
		node *pop();
		void nrinorder(node *);
		void nrdisplaycall();
		void mirror();
		void deleten();
		node *search(node *root,int x);
		void display_level();
		
};

void bst::create_tree(int x)
{
	node *temp,*temp1,*r;
	r=new node();
	r->data=x;
	if(root==NULL)
	{
		root=r;
		return;
	}
	temp=root;
	while(temp!=NULL)
	{
		temp1=temp;
		if(x>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(x>temp1->data)
		temp1->right=r;
	else
		temp1->left=r;
}
void bst::insert()
{
	int n,x,i;
	cout<<"\tEnter no. of nodes : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\tEnter value : ";
		cin>>x;
		create_tree(x);
	}
}
void bst::inorder(node *x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		cout<<x->data<<" ";
		inorder(x->right);
	}
}
void bst::displaycall()
{
	cout<<"\n\tTree is : ";
	inorder(root);
}
void bst::push(node *x)
{
	stack *p;
	p=new stack;
	if(top==NULL)
	{
		p->data=x;
		p->next=NULL;
		top=p;
	}
	else
	{
		p->data=x;
		p->next=top;
		top=p;
	}
}
node * bst::pop()
{
	node *x;
	stack *temp;
	temp=top;
	top=top->next;
	x=temp->data;
	delete temp;
	return x;
}
void bst::nrinorder(node *nr)
{
	top=NULL;
	node *p;
	node *m;
	p=nr;
	while(top!=NULL || p!=NULL)
	{
		if(p!=NULL)
		{
			push(p);
			p=p->left;
		}
		else
		{
			m=pop();
			cout<<m->data<<" ";
			p=m->right;
		}
	}
}
void bst::nrdisplaycall()
{
	cout<<"\n\tTree is : ";
	nrinorder(root);
}
void bst::mirror()
{
	node *temp=root,*temp1;
	node **Q=new node*[20];
	int R=-1,F=-1;
	Q[++R]=temp;
	do
	{
		temp=Q[++F];
		temp1=temp->left;
		temp->left=temp->right;
		temp->right=temp1;
		if(temp->left!=NULL)
			Q[++R]=temp->left;
		if(temp->right!=NULL)
			Q[++R]=temp->right;
	}while(R!=F);
	cout<<"\tMirror image is : ";
	inorder(root);
}
void bst::deleten()
{
	node *temp=root,*temp1=NULL,*temp2=NULL,*temp3=NULL;
	int x;
	cout<<"\tEnter node to be deleted : ";
	cin>>x;
	while(temp!=NULL)
	{
		if(x==temp->data)
			break;
		else if(x>temp->data)
		{
			temp1=temp;
			temp=temp->right;
		}
		else if(x<temp->data)
		{
			temp1=temp;
			temp=temp->left;
		}
	}
	if(temp==NULL)
		cout<<"\tData is not present.";
	else
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			if(temp1->data > temp->data)
				temp1->left=NULL;
			else if(temp1->data < temp->data)
				temp1->right=NULL;
			cout<<"\tData "<<x<<" is deleted.";
			delete temp;
		}
		else if(temp->left!=NULL && temp->right==NULL)
		{
			if(temp1->right->data == temp->data)
				temp1->right=temp->left;
			else
				temp1->left=temp->left;
			cout<<"\tData "<<x<<" is deleted.";
			delete temp;
		}
		else if(temp->right!=NULL && temp->left==NULL)
		{
			if(temp1->right->data == temp->data)
				temp1->right=temp->right;
			else
				temp1->left=temp->right;
			cout<<"\tData "<<x<<" is deleted.";
			delete temp;
		}
		else
		{
			temp2=temp->right;
			if(temp2->left==NULL)
			{
				temp2->left=temp->left;
				if(temp1->left->data == temp->data)
					temp1->left=temp2;
				else
					temp1->right=temp2;
				delete temp;
			}
			else
			{
				while(temp2->left!=NULL)
				{
					temp3=temp2;
					temp2=temp2->left;
				}	
				temp->data=temp2->data;
				temp3->left=NULL;
				delete temp2;
			}
			cout<<"\tData "<<x<<" is deleted.";
		}
	}
	
}
node *bst::search(node *root,int x)
{
	node *temp=root;
	while(temp!=NULL)
	{
		if(x==temp->data)
			break;
		else if(x>temp->data)
			temp=temp->right;
		else if(x<temp->data)
			temp=temp->left;
	}
	return temp;
}
void bst::display_level()
{
	node *temp=root,*temp1;
	node **q1=new node*[20];
	node **q2=new node*[20];
	int r1=-1,f1=-1,r2=-1,f2=-1;
	q1[++r1]=temp;
	int i=0;
	do
	{
		i++;
		while(r1!=f1)
		{
			temp1=q1[++f1];
			cout<<"\tLevel "<<i<<" : ";
			if(temp1!=NULL)
				cout<<temp1->data<<endl;
			if(temp1->left!=NULL)
				q2[++r2]=temp1->left;
			if(temp1->right!=NULL)
				q2[++r2]=temp1->right;
		}
		i++;
		while(r2!=f2)
		{
			temp1=q2[++f2];
			cout<<"\tLevel "<<i<<" : ";
			if(temp!=NULL)
				cout<<temp1->data<<endl;
			if(temp1->left!=NULL)
				q1[++r1]=temp1->left;
			if(temp1->right!=NULL)
				q1[++r1]=temp1->right;
		}
	}while(r1!=f1 || r2!=f2);
}
int main()
{
	bst b;
	int ch;
	while(1)
	{
		cout<<"\n1.Insert\n2.Display\n3.Non Recursive Display\n4.Display levelwise\n5.Search\n6.Mirror Image\n7.Delete\n8.Exit\nEnter option : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b.insert();
				break;
			case 2:
				b.displaycall();
				break;
				
			case 3:
				b.nrdisplaycall();
				break;
			case 4:
				b.display_level();
				break;
			case 5:
				int x;
				node *temp;
				cout<<"\tEnter node to be searched : ";
				cin>>x;
				temp=b.search(b.root,x);
				if(temp==NULL)
					cout<<"\tData not present.";
				else
					cout<<"\tData "<<x<<" found.";
				break;
			case 6:
				b.mirror();
				break;
			case 7:
				b.deleten();
				break;
			case 8:
				return 0;
			default :
				cout<<"Invalid choice.";
					
		}
	}
	return 0;
}

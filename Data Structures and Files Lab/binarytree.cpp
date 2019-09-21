#include<iostream>
using namespace std;

template <class T>
class BT
{
	typedef struct node
	{
		T data;
		struct node *left,*right;	
	}node;
	
	typedef struct stack
	{
		node *data;
		struct stack *next=NULL;
	}stack;
	node *root,*newroot;
	stack *top;
	int depthl,depthr;
	public:
		BT()
		{
			root=NULL;
			top=NULL;
			depthl=depthr=0;
			newroot=NULL;
		}
		void create(T data)
		{
			if(root==NULL)
			{
				root=new node();
				root->left=NULL;
				root->right=NULL;
				root->data=data;	
			}
		}
		bool isempty()
		{
			if(root==NULL)
				return true;
			return false;
		}
		node *search(node *root,T key)
		{
			if(root!=NULL)
			{
				if(root->data==key)
					return root;
				else
				{
					node *tempA=search(root->left,key);
					node *tempB=search(root->right,key);
					
					if(tempA!=NULL)
						return tempA;
					else
						return tempB;
				}
			}
			else
				return NULL;
		}
		void insert(T data,T key)
		{
			char ch;
			if(root!=NULL)
			{
				node *temp=search(root,key);
				if(temp!=NULL)
				{
					node *n=new node();
					n->data=data;
					n->left=NULL;
					n->right=NULL;				
					cout<<"Enter location to be inserted (l or r) : ";
					cin>>ch;
					if(temp->left==NULL && ch=='l')
						temp->left=n;
					else if(temp->right==NULL && ch=='r')
						temp->right=n;
					else
						cout<<"\nLocation Full.";
				}
				else
					cout<<"\nKey doesnt exist.";
			}
		}
		
		void inorder(node *root)
		{
			if(root!=NULL)
			{
				inorder(root->left);
				cout<<root->data;
				inorder(root->right);
			}
		}
		void preorder(node *root)
		{
			if(root!=NULL)
			{
				cout<<root->data;
				preorder(root->left);
				preorder(root->right);
			}
		}
		void postorder(node *root)
		{
			if(root!=NULL)
			{
				postorder(root->left);
				postorder(root->right);
				cout<<root->data;
			}
		}
		
		void display(node *nr)
		{
			int ch;
			while(1)
			{
				cout<<"\n1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\nEnter option : ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"\tInorder : ";
						inorder(nr);
						break;
					case 2:
						cout<<"\tPreorder : ";
						preorder(nr);
						break;
					case 3:
						cout<<"\tPostorder : ";
						postorder(nr);
						break;
					case 4:
						return;
					default:
						cout<<"Invalid.";
				}
			}
		}
		
		void displaycall()
		{
			display(root);
		}
		void depthleft(node *root)
		{
			if(root->left!=NULL)
			{
				depthl++;
				depth(root->left);
			}
		}
		void depthright(node *root)
		{
			if(root->right!=NULL)
			{
				depthr++;
				depth(root->right);
			}
		}
		int depth(node *root)
		{
			depthleft(root);
			depthright(root);
			if(depthl>depthr)
				return depthl;
			else if(depthl<depthr)
				return depthr;
			else
				return depthl;
		}
		void depthcall()
		{
			int i=depth(root);
			depthl=depthr=0;
			cout<<"Depth is : "<<i<<"\n";
		}
		void leafnode(node *root)
		{
			if(root!=NULL)
			{
				if(root->left==NULL && root->right==NULL)
					cout<<root->data;
				else
				{	
					leafnode(root->left);
					leafnode(root->right);
				}
			}
		
		}
		void leafcall()
		{
			cout<<"Leafnodes are : ";
			leafnode(root);
			cout<<"\n";
		}
		node *copytree(node *root,node *newroot)
		{
			if(root==NULL)
				return NULL;
			else
			{
				node *tempa=new node;
				node *tempb=new node;
				newroot=new node;
				newroot->data=root->data;
				newroot->left=copytree(root->left,tempa);
				newroot->right=copytree(root->right,tempb);
			}	
			return newroot;
		}
		void callcopy()
		{
			node *nr;
			nr=copytree(root,newroot);
			cout<<"Tree copied successfully.";
			display(nr);
		}
		void push(node *x)
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
		node *pop()
		{
			node *x;
			stack *temp;
			temp=top;
			top=top->next;
			x=temp->data;
			delete temp;
			return x;
		}	
		node *peek()
		{
			if(top==NULL)
				return NULL;
			return top->data;
		}
		void nrinorder(node *nr)
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
					cout<<m->data;
					p=m->right;
				}	
			}	
		}
		void nrpreorder(node *nr)
		{
			node *m;
			top=NULL;
			if(nr==NULL)
				return;
			push(nr);
			while(top!=NULL)
			{
				m=pop();
				cout<<m->data;
				if(m->right!=NULL)
					push(m->right);
				if(m->left!=NULL)
					push(m->left);
			}
		}
		void nrpostorder(node *nr)
		{
			if(nr==NULL)
				return;
			do
			{
				while(nr)
				{
					if(nr->right)
						push(nr->right);
					push(nr);
					nr=nr->left;
				}
				nr=pop();
				if(nr->right && peek()==nr->right)
				{
					pop();
					push(nr);
					nr=nr->right;
				}
				else
				{
					cout<<nr->data;
					nr=NULL;
				}
				
			}while(top!=NULL);	
		}
		void nrdisplaycall()
		{	
			nrdisplay(root);
		}
		void nrdisplay(node *nr)
		{
			int ch;
			while(1)
			{
				cout<<"\n1.Inorder\n2.Preorder\n3.Postorder\n4.Exit\nEnter option : ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						cout<<"\tInorder : ";
						nrinorder(nr);
						break;
					case 2:
						cout<<"\tPreorder : ";
						nrpreorder(nr);
						break;
					case 3:
						cout<<"\tPostorder : ";
						nrpostorder(nr);
						break;
					case 4:
						return;
					default:
						cout<<"Invalid.";
				}
			}
		}
};

int main()
{
	int ch;
	int a,key;
	BT<int>b;
	while(1)
	{
		cout<<"1.Create\n2.Insert\n3.Display\n4.Depth\n5.Leafnodes\n6.Copy tree\n7.Non Recursive Display\n8.Exit\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter element of tree : ";
				cin>>a;
				b.create(a);
				cout<<"Tree is created successfully.\n";
				break;
			case 2:
				if(!b.isempty())
				{
					cout<<"\nEnter the element to be inserted in tree : ";
					cin>>a;
					cout<<"\nInsert key where to insert : ";
					cin>>key;
					b.insert(a,key);
					cout<<"\nNew element inserted successfully.\n";
				}
				else
					cout<<"\nFirst create tree.\n";
				break;
			case 3:
				b.displaycall();
				break;
			case 4:
				b.depthcall();
				break;
			case 5:
				b.leafcall();
				break;
			case 6:
				b.callcopy();
				break;
			case 7:
				b.nrdisplaycall();
				break;
			case 8:
				return 0;
			default:
				cout<<"\nInvalid choice.";
		}
	}
	return 0;
}

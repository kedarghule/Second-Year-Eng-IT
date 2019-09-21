#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
template<class t>
class stack
{
	struct node
	{
		t data;
		struct node *next;
	};
	node *top;
	public :
		void push(t x);
		t pop();
		bool stack_empty();
		void display();
		int precedence(char ch);
		string intopost(string in_str);
		string intopre(string in_str);
		string reverse(string in_str);
		t getvalue(string post_str);
		t preval(string pre_str);
		t stack_top();
		t evaluate(char ch,int op1,int op2);
		stack()
		{
			top=NULL;
		}
		~stack()
		{
			while(top!=NULL)
			{
				node *temp;
				temp=top;
				top=top->next;
				delete temp;
			}
		}
};

template<class t>t stack<t>::stack_top()
{
	t a;
	a=top->data;
	return a;
}

template<class t>int stack<t>::precedence(char ch)
{
	if(ch=='(')
		return 0;
	else if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/' || ch=='%')
		return 2;
	else
		return 3;
}

template<class t>void stack<t>::push(t x)
{
	node *p;
	p=new node;
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

template<class t>t stack<t>::pop()
{
	t x;
	node *temp;
	temp=top;
	top=top->next;
	x=temp->data;
	delete temp;
	return x;
}

template<class t>bool stack<t>::stack_empty()
{
	if(top==NULL)
		return true;
	return false;
}

template<class t>void stack<t>::display()
{
	node *temp;
	temp=top;
	cout<<"Stack is : \n";
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}

template<class t>string stack<t>::intopost(string in_str)
{
	string post_str("");
	int i;
	stack<int>s1;
	char ch,op;
	for(i=0;i<in_str.length();i++)
	{
		ch=in_str.at(i);
		if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
			post_str.append(1,ch);
		else
		{
			if(ch=='(')
				s1.push(ch);
			else if(ch==')')
			{
				while(op=s1.pop()!='(')
					post_str.append(1,op);
			}
			else if(s1.stack_empty()!=true && (precedence(ch)<=precedence(s1.stack_top())))
			{
				op=s1.pop();
				post_str.append(1,op);
			}
			if(ch!='(' && ch!=')')
				s1.push(ch);
			
		}
	}
	while(s1.stack_empty()!=true)
	{
		op=s1.pop();
		post_str.append(1,op);
	}
	return post_str;
}

template<class t>string stack<t>::intopre(string in_str)
{
	string post_str(""),rev_str,pre_str;
	int i;
	stack<int> s1;
	rev_str=reverse(in_str);
	post_str=s1.intopost(rev_str);
	pre_str=reverse(post_str);
	return pre_str;
	
}

template<class t>string stack<t>::reverse(string in_str)
{
	int i;
	stack<int> s1;
	char ch;
	string rev_str;
	for(i=0;i<in_str.length();i++)
		s1.push(in_str.at(i));
	while(!s1.stack_empty())
	{
		ch=s1.pop();
		if(ch=='(')
			rev_str.append(1,')');
		else if(ch==')')
			rev_str.append(1,'(');
		else
			rev_str.append(1,ch);
	}
	return rev_str;
}

template<class t>t stack<t>::evaluate(char ch,int op1,int op2)
{	int r=0;
	if(ch=='+')
		return(op1 + op2);
	else if(ch=='-')
		return(op1 - op2);
	else if(ch=='*')
		return(op1 * op2);
	else if(ch=='/')
		return(op1 / op2);
	else if(ch=='%')
		return(op1 % op2);
}

template<class t>t stack<t>::getvalue(string post_str)
{
	int op1,op2,i;
	char ch;
	stack<char> s1;
	t res;
	for(i=0;i<post_str.length();i++)
	{
		ch=post_str.at(i);
		if(isalnum(ch))
		{
			if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
			{
				cout<<"Enter value of character "<<ch<<" : ";
				cin>>ch;
				ch=ch-48;
				s1.push(ch);
			}
			else if(ch>=0 || ch<=9)
				s1.push(ch-48);
		}
		else
		{
			op2=s1.pop();
			op1=s1.pop();
			res=s1.evaluate(ch,op1,op2);
			s1.push(res);
		}
	}
	return res;
}

template<class t>t stack<t>::preval(string pre_str)
{
	t res;
	stack<char>s1;
	string post_str;
	post_str=reverse(pre_str);
	res=s1.getvalue(post_str);
	return res;
}

int main()
{
	stack<int> x;
	/*int n,a;
	cout<<"1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice : ";
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Enter element : ";
			cin>>a;
			x.push(a);
			break;
		case 2:
			
	}
	*/
	int n,res;
	string a,b;
	
	while(1)
	{
		cout<<"1.Infix to Postfix\n2.Infix to Prefix\n3.Evaluate Postfix\n4.Evaluate Prefix\n5.Exit\nEnter choice : ";
		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Enter expression : ";
				cin>>a;
				b=x.intopost(a);
				cout<<"\nPostfix : "<<b<<"\n";
				break;
			case 2:
				cout<<"Enter expression : ";
				cin>>a;
				b=x.intopre(a);
				cout<<"\nPrefix : "<<b<<"\n";
				break;
			case 3:
				res=x.getvalue(b);
				cout<<"\nResult : "<<res<<"\n";
				break;
			case 4:
				res=x.preval(b);
				cout<<"\nResult : "<<res<<"\n";
				break;
			case 5:
				return 0;
		}
	}	
	
	return 0;

}

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node
{
	int srno;
	char name[20];
	int age;
	char disease[30];
	int severity;
	struct node *next;	
}node;

class queue
{
	public :
		node *F,*R;
		queue()
		{
			F=NULL;
			R=NULL;
		}
		void enqueue(node);
		void dequeue();
		void display();
		int empty()
		{
			if(F==NULL)
				return 1;
			else
				return 0;
		}
};
void queue::enqueue(node x)
{
	if(F==NULL)
		F=R=new node(x);
	else
	{
		R->next=new node(x);
		R=R->next;
	}	
	R->next=NULL;	
}
void queue::dequeue()
{
	node *temp;
	if(F==NULL)
		cout<<"Queue is empty.";
	else
	{
		temp=F;
		F=F->next;
		free(temp);
		cout<<"Patient is no longer in queue.";
	}

}

void queue::display()
{
	node *temp=F;
	if(temp==NULL)
		return;
		
	while(temp!=NULL)
	{
		cout<<"Sr. No : "<<temp->srno;
		cout<<"\nName : "<<temp->name<<"\n";
		temp=temp->next;
	}
}

class pq
{
	public:
		queue q[3];
		void arrival();
		void service();
		void display();
};

void pq::arrival()
{
	node temp;
	cout<<"Enter sr.no, name, age, disease : ";
	cin>>temp.srno>>temp.name>>temp.age>>temp.disease;
	
	if(strcmp(temp.disease,"HeartAttack")==0 || strcmp(temp.disease,"Paralysis")==0)
		temp.severity=0;
	else if(strcmp(temp.disease,"Dengue")==0 || strcmp(temp.disease,"Malaria")==0)
		temp.severity=1;
	else if(strcmp(temp.disease,"Cough")==0 || strcmp(temp.disease,"Fever")==0)
		temp.severity=2;
	else
		cout<<"Invalid disease.";
		
	switch(temp.severity)
	{
		case 0:
			q[0].enqueue(temp);
			break;
		case 1:
			q[1].enqueue(temp);
			break;
		case 2:
			q[2].enqueue(temp);
			break;
	}
	
}

void pq::service()
{
	node *temp;
	int i=0;
	while(i<3 && q[i].empty())
		i++;
	if(i==3)
		cout<<"\nAll queues empty.";
	else
	{
		temp=q[i].F;
		cout<<"\nSr. No : "<<temp->srno;
		cout<<"\nName : "<<temp->name;
		q[i].dequeue();
	}
}

void pq::display()
{
	cout<<"\nSerious patients : \n";
	q[0].display();
	cout<<"\nMedium severity patients : \n";
	q[1].display();
	cout<<"\nGeneral patients : ";
	q[2].display();
}

int main()
{
	pq q;
	int i;
	while(1)
	{
		cout<<"\n1.New patient\n2.Service patient\n3.Display\n4.Exit\nEnter choice : ";
		cin>>i;
		switch(i)
		{
			case 1:
				q.arrival();
				break;
			case 2:
				q.service();
				break;
			case 3:
				q.display();
				break;
			case 4:
				return 0;
		}
	}
	return 0;
}

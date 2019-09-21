#include<iostream>
using namespace std;
#define MAX 20
typedef struct node
{
	struct node *next;
	int vertex,comments,month,friends;
}node;

class graph
{
	int visited[MAX];
	node *g[20];
	node v[20];
	int n;
	public :
		graph()
		{
			n=0;
		}
		void insert(int vi,int vj);
		void readgraph();
		void birthmonth();
		void maxmin_comments();
		void maxmin_friends();
		void dfs(int start);
		void dfs1(int start);
		void bfs(int v);
};

class queue
{
	int data[30];
	int rear,front;
	public:
		queue()
		{
			rear=front=-1;
		}
		int empty()
		{
			if(rear==-1)
				return 1;
			return 0;
		}
		void insert(int x)
		{
			if(empty())
				rear=front=0;
			else
				rear=rear+1;
			data[rear]=x;
		}
		int deleteq()
		{
			int x=data[front];
			if(rear==front)
				rear=front=-1;
			else
				front=front+1;
			return x;
		}
};

void graph::bfs(int v)
{
	queue q;
	node *p;
	int i,w;
	for(i=0;i<n;i++)
		visited[i]=0;
	q.insert(v);
	cout<<"\n"<<v;
	visited[v]=1;
	while(!q.empty())
	{	
		v=q.deleteq();
		for(p=g[v];p!=NULL;p=p->next)
		{
			w=p->vertex;
			if(visited[w]==0)
			{
				q.insert(w);
				visited[w]=1;
				cout<<"\n"<<w;
			}
		}
		
	}
}

void graph::dfs(int start)
{
	int i;
	cout<<"\n"<<start;
	for(i=0;i<n;i++)
		visited[i]=0;
	dfs1(start);
}

void graph::dfs1(int i)
{
	node *p;
	p=g[i];
	visited[i]=1;
	while(p!=NULL)
	{
		i=p->vertex;
		if(!visited[i])
		{
			cout<<"\n"<<i;
			dfs1(i);
		}
		p=p->next;
	}
}

void graph::maxmin_comments()
{
	int i,j=0,k=0,maxno=0,minno=999,whomax,whomin;
	for(i=0;i<n;i++)
	{
		if(v[i].comments > maxno)
		{
			maxno=v[i].comments;
			whomax=i;
		}
		if(v[i].comments < minno)
		{
			minno=v[i].comments;
			whomin=i;
		}
	}
	cout<<"\nFriends with most comments : \n";
	for(i=0;i<n;i++)
	{
		if(v[i].comments == maxno)
			cout<<"Friend "<<i<<endl;
	}
	cout<<"\nFriends with least comments : \n";
	for(i=0;i<n;i++)
	{
		if(v[i].comments == minno)
			cout<<"Friend "<<i<<endl;
	}
}

void graph::maxmin_friends()
{
	int i,j=0,k=0,maxno=0,minno=999,whomax,whomin;
	for(i=0;i<n;i++)
	{
		if(v[i].friends > maxno)
		{
			maxno=v[i].friends;
			whomax=i;
		}
		if(v[i].friends < minno)
		{
			minno=v[i].friends;
			whomin=i;
		}
	}
	cout<<"\nFriends with most friends : \n";
	for(i=0;i<n;i++)
	{
		if(v[i].friends == maxno)
			cout<<"Friend "<<i<<endl;
	}
	cout<<"\nFriends with least friends : \n";
	for(i=0;i<n;i++)
	{
		if(v[i].friends == minno)
			cout<<"Friend "<<i<<endl;
	}
}

void graph::birthmonth()
{
	int temp,i;
	cout<<"Enter month to find birthdays : ";
	cin>>temp;
	cout<<"Friends with birthday in this month : \n";
	for(i=0;i<n;i++)
	{
		if(v[i].month == temp)
			cout<<"Friend "<<i<<endl;
	}
}

void graph::insert(int vi,int vj)
{
	node *p,*q;
	q=new node;
	q->vertex=vj;
	q->next=NULL;
	if(g[vi]==NULL)
		g[vi]=q;
	else
	{
		p=g[vi];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	}
};

void graph::readgraph()
{
	int i,vi,vj,no_edges;
	cout<<"Enter no. of vertices : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		g[i]=NULL;
		v[i].friends=0;
		cout<<"Friend no. : "<<i<<endl;
		cout<<"Enter Month of birth : ";
		cin>>v[i].month;
		cout<<"Enter no. of comments : ";
		cin>>v[i].comments;
	}
	cout<<"Enter total no. of edges : ";
	cin>>no_edges;
	for(i=0;i<no_edges;i++)
	{
		cout<<"Enter vertices to be connected : ";
		cin>>vi>>vj;
		insert(vi,vj);
		insert(vj,vi);
		v[vi].friends++;
		v[vj].friends++;
	}

}

int main()
{
	graph x;
	int n;
	while(1)
	{
		cout<<"\n1.Read Graph\n2.Birthday in a month\n3.Max and Min Comments\n4.Max and Min Friends\n5.DFS\n6.BFS\n7.Exit\nEnter choice : ";
		cin>>n;
		switch(n)
		{
			case 1:
				x.readgraph();
				break;
			case 2:
				x.birthmonth();
				break;
			case 3:
				x.maxmin_comments();
				break;
			case 4:
				x.maxmin_friends();
				break;
			case 5:
				cout<<"DFS traversal is : ";
				x.dfs(0);
				cout<<endl;
				break;
			case 6:
				cout<<"BFS traversal is : ";
				x.bfs(0);
				cout<<endl;
				break;
			case 7:
				return 0;
		}
		
	}
	return 0;
}

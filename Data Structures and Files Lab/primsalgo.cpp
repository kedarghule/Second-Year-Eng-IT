/* A business house has several offices in different countries.They want to lease phone lines to connect them with each other and the phone company charges a different rent to connect different pairs of signals. Business house wants to connect all its offices with minimum total cost. Solve the problem suggesting appropriate data structure.*/ 
#include<iostream>
using namespace std;
#define INFINITY 999
class graph
{
	int nodes,edges,start,end,weight,source_vertex,mindist;
	int wt[20][20];
	int visited[20];
	public:
		 graph(int n,int e);
		 void creategraph();
		 void display();
		void prims();
		 
};
graph::graph(int n,int e)
{
	nodes=n;edges=e;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				wt[i][j]=0;
			else
				wt[i][j]=INFINITY;
		}
	}
}
void graph::creategraph()
{
	for(int i=0;i<edges;i++)
	{
		cout<<"Enter start and end of the edge : ";
		cin>>start>>end;
		if(start==end)
		{
			cout<<"Error.Can't enter self loop.";
			i--;
			continue;
		}
		cout<<"Enter weight : ";
		cin>>weight;
		wt[start][end]=weight;
		wt[end][start]=weight;
	}
}
void graph::display()
{
	int i,j;
	cout<<"\nAdjacency matrix : "<<endl;
	for(i=0;i<nodes;i++)
		cout<<"\t"<<i;
	for(i=0;i<nodes;i++)
	{
		cout<<"\n";
		cout<<i;
		for(j=0;j<nodes;j++)
			cout<<"\t"<<wt[i][j];
	}
}
void graph::prims()
{
	int n=nodes;
        int i,j,m,l,temp,sum=0,k,min,pass;
        for(i=0;i<n;i++)
		visited[i]=0;
	visited[0]=1;
	for(pass=0;pass<n-1;pass++)
	{
		min=99;
		for(i=0;i<n;i++)
		{
			temp=99;
			if(visited[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(wt[i][j]<temp && visited[j]==0  && wt[i][j]!=0)
					{
						temp=wt[i][j];
						k=j;
					}
				}
				if(min>temp)
				{
					min=temp;
					l=i;
					m=k;
				}
			}
		}
		sum=sum+min;
		visited[m]=1;
		cout<<"\n"<<l<<" - "<<m;
	}
	cout<<"\nCost of MST = "<<sum<<"\n";
}
int main()
{
	int n,e;
	cout<<"\nEnter number of nodes : ";
	cin>>n;
	cout<<"Enter number of edges : ";
	cin>>e;
	graph G(n,e);
	G.creategraph();
	G.display();
	G.prims();
	return 0;
}




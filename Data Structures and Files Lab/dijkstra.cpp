/*Represent a given graph using adjacency matrix or adjacency list and find the shortest path using Djikstra's Algorithm(single source of destination)*/

#include<iostream>
#include<stdlib.h>
using namespace std;

#define INFINITY 999

class graph
{
	int nodes,edges,src_vrtx;
	int wt[20][20];
	bool v[20];
	int pre[20],dist[20];
	public:
		graph(int n,int e);
		void creategraph();
		void display();
		void init();
		int getclosestnode();
		void shortestdist();
		void output();
		void printpath(int node);
};

graph::graph(int n,int e)
{
	int i,j;
	nodes=n;
	edges=e;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
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
	int i;
	int start,end,weight;
	for(i=0;i<edges;i++)
	{
		cout<<"Enter start and end : ";
		cin>>start>>end;
		cout<<"Enter weight : ";
		cin>>weight;
		wt[start][end]=weight;
	}
	while(1)
	{
		cout<<"\nEnter source vertex : ";
		cin>>src_vrtx;
		if(src_vrtx < nodes)
			break;
		else
			cout<<"\nInvalid input.";	
	}	
}

void graph::display()
{
	int i,j;
	cout<<"Adjacency matrix : \n";
	for(i=0;i<nodes;i++)
	{
		cout<<"\t"<<i;
	}
	for(i=0;i<nodes;i++)
	{
		cout<<"\n";
		cout<<i;
		for(j=0;j<nodes;j++)
			cout<<"\t"<<wt[i][j];
	}
}

void graph::init()
{
	int i;
	for(i=0;i<nodes;i++)
	{
		v[i]=false;
		pre[i]=-1;
		dist[i]=INFINITY;
	}
	dist[src_vrtx]=0;
}

int graph::getclosestnode()
{
	int i;
	int mindist=INFINITY;
	int cn;
	for(i=0;i<nodes;i++)
	{
		if(!v[i] && mindist > dist[i])
		{	
			mindist=dist[i];
			cn=i;
		}
	}
	return cn;	
}

void graph::shortestdist()
{
	int i,j,cn;
	init();
	for(i=0;i<nodes;i++)
	{
		cn=getclosestnode();
		v[cn]=true;
		for(j=0;j<nodes;j++)
		{
			if(!v[j] && wt[cn][j] > 0)
			{
				if(dist[j] > dist[cn]+wt[cn][j])
				{
					dist[j]=dist[cn]+wt[cn][j];
					pre[j]=cn;
				}
			}
		}
	}
}

void graph::output()
{
	int i;
	cout<<"\n";
	for(i=0;i<nodes;i++)
	{
		if(i==src_vrtx)
			cout<<src_vrtx<<"-"<<src_vrtx;
		else
			printpath(i);
		cout<<" -> "<<dist[i];
		cout<<"\n";
	}
}

void graph::printpath(int node)
{
	if(node==src_vrtx)
		cout<<node<<"-";
	else if(pre[node]==-1)
		cout<<"No path from "<<src_vrtx<<" to "<<node;
	else
	{
		printpath(pre[node]);
		cout<<node<<"-";
	}
}	

int main()
{
	int n,e;
	cout<<"Enter no. of nodes and edges : ";
	cin>>n>>e;
	graph g(n,e);
	g.creategraph();
	g.display();
	g.shortestdist();
	g.output();
	return 0;
}
















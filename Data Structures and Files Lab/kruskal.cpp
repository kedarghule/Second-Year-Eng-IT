/*Represent any real world graph using adjacency list or adjacency matrix. Find minimum spanning tree using Kruskal's algorithm.*/

#include<iostream>
using namespace std;

class kruskal
{
	struct node
	{
		int a,b,weight;	
	};
	struct node store[100];
	struct node path[100];
	int parent[100];
	int y,nv,ne;
	public :
		kruskal();
		void create();
		void display();
		void sort();
		void kruskalalgo();
		void union1(int i,int j);
		int find(int x);
};

kruskal::kruskal()
{
	for(y=0;y<100;y++)
		parent[y]=y;
}

void kruskal::create()
{
	int i;
	cout<<"Enter no. of vertices and edges : ";
	cin>>nv>>ne;
	for(i=0;i<ne;i++)
	{	
		cout<<"Enter end vertices and weight between them : ";
		cin>>store[i].a>>store[i].b>>store[i].weight;
	}
}

void kruskal::display()
{
	int i,cost=0;
	for(i=0;i<nv-1;i++)
	{	
		cout<<path[i].a<<"-"<<path[i].b<<" => "<<path[i].weight<<"\n";
		cost+=path[i].weight;
	}
	cout<<"\nCost of MST = "<<cost<<"\n";	
}

void kruskal::sort()
{
	struct node temp;
	int i,j;
	for(i=1;i<ne;i++)
		for(j=0;j<ne-i;j++)
			if(store[j+1].weight<=store[j].weight)
			{
				temp=store[j+1];
				store[j+1]=store[j];
				store[j]=temp;
			}
}

void kruskal::kruskalalgo()
{
	sort();
	int pn=0,i=0,p1,p2;
	while(pn<nv-1)
	{
		p1=find(store[i].a);
		p2=find(store[i].b);
		if(p1!=p2)
		{
			path[pn++]=store[i];
			union1(p1,p2);
		}
		i++;
	}
}

void kruskal::union1(int i,int j)
{
	parent[j]=i;
}

int kruskal::find(int x)
{
	if(parent[x]!=x)
		parent[x]=find(parent[x]);
	return parent[x];
}

int main()
{
	kruskal k;
	k.create();
	k.kruskalalgo();
	k.display();
	return 0;
}






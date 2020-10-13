//adjacency matrix representation
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int node;
	cin>>node;
	vector<vector<int> >adj_mat(node,vector<int>(node));//2D matrix of size node*node*sizeof(int)
	int edge;
	cin>>edge;
	for(int i=0;i<edge;i++)
	{
			int u,v;
		//u,v belongs to {1,2,...,node}
		cin>>u>>v;//represents u and v are connected by edge (if the graph is undirected then v and u are also connected by an edge)
		//assuming it is undirected
		
		adj_mat[u][v]=1;
		//if it is undirected then v and v are also connected ,threfore 
		adj_mat[v][u]=1;
		//if it is weighted graph than instead of 1 there would be weight of graph.
	}
}

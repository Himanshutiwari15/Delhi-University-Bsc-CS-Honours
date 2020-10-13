//Graph representation
//Using adjacency list 
//Most efficient with less memory complexity 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int node;
	cin>>node;
	vector<int>adj[node+1];//represents node number of empty vectors
	//size of adj[i] represents number of nodes conneced with i nodes
	int edge;
	cin>>edge;
	for(int i=0;i<edge;i++)
	{
		int u,v;
		//u,v belongs to {1,2,...,node}
		cin>>u>>v;//represents u and v are connected by edge (if the graph is undirected then v and u are also connected by an edge)
		//assuming it is undirected
		
		adj[u].push_back(v);
		//if it is undirected then v and v are also connected ,threfore 
		adj[v].push_back(v);
	}
	
}

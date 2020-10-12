#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int connected_component=0;
void DFS(int beg,int max_capacity,vector<int>adj[],vector<int>&vis_dfs)
{
	//visited beg node if existed
	if(beg>max_capacity)
	{
		cout<<"Invalid";
		return ;
	}
	//visited beg node
	vis_dfs[beg]=1;
	cout<<beg<<endl;
	for(auto x:adj[beg])
	{
		if(!vis_dfs[x])//not visited
		{
			DFS(x,max_capacity,adj,vis_dfs);
		}
	}
}

void BFS(int beg,int max_capacity,vector<int>adj[],vector<int>&vis_bfs)
{
	//marking beg as visited
	vis_bfs[beg]=1;
//maintaining a queue for all reachables
queue<int>reach;
cout<<beg<<endl;
reach.push(beg);
while(!reach.empty())
{
	beg=reach.front();
	reach.pop();
	for(auto x:adj[beg])
	{
		if(!vis_bfs[x])
		{
			reach.push(x);
			vis_bfs[x]=1;
		}
	}
}
}
int main()
{
	int node;
	cin>>node;
vector<int>adj[1+node];
int edge;
cin>>edge;	
vector<int>vis_dfs(node+1),vis_bfs(node+1);//0 represents node not visisted
//building begin
for(int i=0;i<edge;i++)
{
	int u,v;
	cin>>u>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
	//assuming graph is undirected
}
//building end
int source;
cin>>source;
DFS(source,node+1,adj,vis_dfs);
//time complexity of above DFS is O(node+edge) reachable from source node
//space complexity is O(node)

//BFS
BFS(source,node+1,adj,vis_bfs);
//BFS

//Practical applications
//for count of connected component
vector<int>vis(node+1);
for(int i=1;i<=node;i++)
{
	if(!vis[i])
	{
		connected_component++;
		DFS(i,node+1,adj,vis);
	}
}
cout<<connected_component;
}

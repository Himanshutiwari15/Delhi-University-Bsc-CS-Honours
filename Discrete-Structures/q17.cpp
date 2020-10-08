//program to find out the in-degree and out- degree of a given directed graph
#include<iostream>
using namespace std;
int main()
{
   int n;
   cout<<"n\tEnter the no. of vertex in the directed graph:";
   cin>>n;
   int a[n][n], in=0, out=0, b, c;
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
      {
         cout<<"\n\tEnter the no. of edges between vertex "<<i+1<<" and "<<j+1<< " : ";
         cin>>a[i][j];
      }
   }
   cout<<"The adjacency matrix of directed graph is displayed below"<<"\n";
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
          cout<<a[i][j]<<"  ";
       cout<<"\n";
   }
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
      {
         cout<<"Enter the number of edges from vertex "<<i+1<<" to vertex "<<j+1<<"  ";
         cin>>b;
         out+=b;
         cout<<"Enter the number of edges from vertex "<<j+1<<" to vertex "<<i+1<<"  ";
         cin>>c;
         in+=c;
      }
      cout<<"The indegree of vertex "<<i+1<<" is "<<in<<"\n";
      cout<<"The outdegree of vertex "<<i+1<<" is "<<out<<"\n";
      in=0;
      out=0;
   }
   return 0;
}   

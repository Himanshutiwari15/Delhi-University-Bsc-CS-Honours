//Program to accept a graph and check if it is a complete graph or not.
#include<iostream>
using namespace std;
int main()
{
   int i,j,t=0,n;
   cout<<"Enter the number of vertices: ";
   cin>>n;
   int a[n][n];
   for(i=0;i<n;i++)
   { 
      for(j=0;j<n;j++)
      {
         cout<<"Enter the number of edges from vertex "<<i+1<<" to vertex "<<j+1<<"  ";
         cin>>a[i][j];
      }
   }
   cout<<"The adjacency matrix of the graph is"<<'\n';
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
         cout<<a[i][j]<<"  ";
      cout<<'\n';
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
          if(i==j)
          {
             if(a[i][j]!=0)
             {
                t=1;
                break;
             }
          }
          else
          {
             if(a[i][j]!=1)
             {
                t=1;
                break;
             }
          }  
       }
       if(t==1)
          break;
   }
   if(t==0)
      cout<<"The graph is complete graph"<<'\n';
   else
   {
      cout<<"The graph is not a complete graph"<<'\n';
      t=0;
   }
   return 0;
} 

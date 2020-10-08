//program to verify whether the graph is euler path or euler circuit or neither
#include<iostream>
using namespace std; 
 int main()
{
 int adjm[10][10];
 int n;
 cout<<"\n\tEnter the no. of vertices:";
 cin>>n;
 int sum=0;
 int n1=0,n2=0;//n1 for even degrees and n2 for odd degrees
  for(int i=0;i<n;i++)
 {
   for(int j=0;j<n;j++)
  {
   cout<<"\n\tEnter the no. of edges that vertex "<<i+1<<" is having with vertex "<<j+1<<":";
   cin>>adjm[i][j];
  }
 }
  for(int i=0;i<n;i++)
 {
  sum=0;
   for(int j=0;j<n;j++)
  {
   sum=sum+adjm[i][j];
  }
  if(sum%2==0)
   n1++;
  else if(sum%2!=0)
   n2++;
 }
  if(n1=n)
   cout<<"\n\tThis is a euler circuit";
  else if(n2=2)
   cout<<"\n\tThis is a euler path";
  else
   cout<<"\n\tThis graph is neither euler circuit nor euler path";
  return 0;    
 }
     

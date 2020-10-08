//This program is to find number of leaf nodes in a full m-array tree with i internal vertices
#include<iostream>
using namespace std;
int main()
{
   int m,i;
   cout<<"Enter the value of m in the tree";
   cin>>m;
   cout<<"Enter the number of internal vertices";
   cin>>i;
   cout<<"The number of leaf nodes are  "<<(m-1)*i+1<<'\n';
   return 0;    
}


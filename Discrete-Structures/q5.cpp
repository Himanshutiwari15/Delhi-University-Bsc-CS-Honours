//Program for recursive function for generating fibonacci series
#include <iostream>
using namespace std;
int fibonacci(int n,int a,int b,int c)
{
   c=a+b;
   a=b;
   b=c;
   cout<<c<<",";
   while(n>0)
   { 
      n--;
      return(fibonacci(n,a,b,c));
   }
   return 0;
}
int main() 
{
   int n;
   cout<<"\n\tEnter the no. of terms in fibonacci series:";
   cin>>n;
   cout<<0<<","<<1<<",";
   fibonacci(n,0,1,0);
   return 0;
}

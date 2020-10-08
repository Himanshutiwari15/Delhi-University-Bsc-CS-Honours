//program to find the value of f(x) for some x
#include<iostream>
using namespace std;
int main()
{//polynomial: anx^n+.....+a0
   int deg,x;
   cout<<"\n\tEnter the degree of polynomial:";
   cin>>deg;
   int coef[deg+1];
   for(int i=deg; i>=0; i--)
   {
      cout<<"\n\tEnter the coeficients for a"<<i<<":";
      cin>>coef[i];
   }
   cout<<"\n\tEnter the value of x for which you want to find f(x) :";
   cin>>x;
   int powsum[deg+1],sum=0;
   int temp=deg;
   for(int i=0; i<deg+1; i++)
   {
      powsum[i]=1;   //powsum[0] is equivalent to x^n
      for(int y=0;y<temp;y++)
         powsum[i]*=x;
      temp--;
   }
   for(int i=0,y=deg; i<deg+1, y>=0; i++, y--)
   {
         sum+=(coef[y]*powsum[i]);
   }
   cout<<"\n\tValue of f("<<x<<") :"<<sum;
   return 0;
}                  

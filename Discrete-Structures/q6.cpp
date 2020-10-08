//Program to make a recurcive function on tower of hanoi
#include<iostream>
using namespace std;
void tower(int a,char from,char sec,char to)
{
   if(a==1)
   {
      cout<<"\t\tMove disc 1 from "<<from<<" to "<<to<<"\n";
      return;
   }
   else
   {
      tower(a-1,from,to,sec);
      cout<<"\t\tMove disc "<<a<<" from "<<from<<" to "<<to<<"\n";
      tower(a-1,sec,from,to);
   }
}
int main()
{
   int n;
   cout<<"\n\t*****Tower of Hanoi*****";
   cout<<"\n\tEnter number of discs : ";
   cin>>n;
   cout<<"\n\n";
   tower(n,'A','B','C');
   return 0;
}

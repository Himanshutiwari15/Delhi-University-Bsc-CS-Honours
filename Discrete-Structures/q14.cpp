/*This program is to graphically represent the values of a function for a 
recurrence relation*/
#include<iostream>
using namespace std;
int main()
{   int function(int);
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int result = function(n);
    
    cout<<"The result is "<<result<<'\n';
    system("pause");
    return 0;
}
   int function(int n)
   {   if(n == 0)
          return 1;
       else
          return (function(n - 1) + n);
   }
          

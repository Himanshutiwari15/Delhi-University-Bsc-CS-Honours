//This program is to implement binary search using recursion
#include<iostream>
using namespace std;

int main()
{
   int search(int [], int, int, int);
   int n, low, upper, s, i;
   cout<<"Enter the number of elements: ";
   cin>>n;
   int a[n];
   for(i=0; i<n; i++)
   {
      cout<<"Enter the element: ";
      cin>>a[i];
   }
   cout<<"Enter the value to be searched: ";
   cin>>s;
   low = 0;
   upper = n-1;
   int result = search(a, low, upper, s);
   if(result == s)
     cout<<"The number is found"<<'\n';
   else
     cout<<"The number is not found"<<'\n';
   system("pause");
   return 0;
}



int search(int a[], int low, int upper, int s)
{
   int mid;
   mid = (low + upper)/2;
   if(low == upper)
      return a[low];
     else if(s < a[mid])
   {
      upper = mid-1;
      return search(a, low, upper, s);
   }
                
     else if(s > a[mid])
   { 
      low = mid+1;
       return search(a, low, upper, s);
   } 
     else if(s == a[mid])
      return a[mid];
}       

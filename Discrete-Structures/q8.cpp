#include<iostream>  
using namespace std;  
int main ()  
{  
   int temp;   
   int a[10],n;
   cout<<"\n\tEnter the elements in array:";
   cin>>n;
   for(int i = 0; i<n; i++)
   {
      cout<<"\n\tEnter the element "<<i+1<<":";
      cin>>a[i];
   }      
   for(int i = 0; i<n; i++)  
   {  
      for(int j = i+1; j<n; j++)  
      {  
         if(a[j] < a[i])  
         {  
            temp = a[i];  
            a[i] = a[j];  
            a[j] = temp;   
         }   
      }   
   }   
   cout <<"Printing Sorted Element List ...\n";  
   for(int i = 0; i<n; i++)  
   {  
      cout <<a[i]<<"\n";  
   }  
   return 0;  
}  

//Program for insertion sort
#include<iostream>
using namespace std;
void display(int *a, int n) 
{
   for(int i=0; i<n; i++)
      cout<<a[i]<<" ";
   cout<<endl;
}
void insertionSort(int *a, int n)
{
   int temp, j;
   for(int i=1; i<n; i++) 
   {
      temp=a[i];//take value
      j=i;
      while(j>0 && a[j-1]>temp) 
      {
         a[j]=a[j-1];
         j--;
      }
      a[j]=temp;   //insert in right place
   }
}
int main() 
{
   int n;
   cout<<"Enter the number of elements: ";
   cin>>n;
   int a[n];    //create an array with given number of elements
   cout<<"Enter elements:"<<endl;
   for(int i = 0; i<n; i++) 
   {
      cin>>a[i];
   }
   cout<<"Array before Sorting: ";
   display(a, n);
   insertionSort(a, n);
   cout << "Array after Sorting: ";
   display(a, n);
}

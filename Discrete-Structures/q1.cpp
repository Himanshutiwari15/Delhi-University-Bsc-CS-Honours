//This program is to perform some set operations on a given set which is an array of integers.
#include<iostream>
#include <string>
#include<ctype.h>
#include<math.h>
using namespace std;

 int ismember(int,int [],int);
 void cardinality(int [],int); 
 
 
int main()
{   int i, j, b, n;
    double size;
    
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    
    int A[n];
    
    
    
    for(i = 0; i < n; i++)
       {
       cout<<"Enter any number ";
        cin>>A[i];
       }
     
            
do{   
      
      
      cout<<"     Main Menu      "<<'\n';
      cout<<"1-Check membership of A"<<'\n';
      cout<<"2-Determine cardinality of A"<<'\n';
      cout<<"3-Powerset"<<'\n';
      cout<<"4-Exit"<<'\n';
      cout<<"Enter your choice"<<'\n';
      cin>>b;
      cout<<"++++++";
      switch(b)
      {       
               
                case 1 :            
                
                
                {
                     cout<<"++++++";
                     int s;
                int e;
                cout<<"Enter the element to be searched: ";
                cin>>e;
                
                s = ismember(e,A,n); 
                
                
                if(s == 1)
                   cout<<e<<" is the element of A ";
                else 
                   cout<<e<< " is not the element of A ";
                   cout<<'\n';
                break;
                }
          case 2 :
                 cardinality(A, n);
                 break;
          case 3 :
                {
                 size = pow(2,n);
                 cout<<size;
                 
                for(int l = 0; l < size; l++)
                
                {   for(int q = 0; q < n; q++)
                
                    {   
                        if(l & (1 << q))
                    
                           cout<<A[q];
                    }
                   cout<<'\n';
                }
                    break;
                }
           case 4 :
                exit(0);
      default :
                  cout<<"Wrong Choice"<<'\n';
                               
      }   
         
 }while(1);
 
 
 
      system("pause");
      return 0;                  
}



int ismember(int a, int A[], int n) 
{   for(int i = 0; i < n; i++)
    {   if(a == A[i])  
        return 1;
        break;
    }
}

void cardinality(int A[],int n)
{   int z = 0;
    for(int i = 0;i < n; i++)
    {   if(isdigit(A[i]))
        z++;
    }
    cout<<"The cardinality is"<<z<<'\n';
}

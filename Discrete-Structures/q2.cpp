//This program is to accept two sets from the user and perform some set operations
#include<iostream>
using namespace std;
int main()

{   int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int A[n], B[n], i, j, z, t=0, k, c[2*n], d[2*n], l, m=0, e[n], f[n], g[n], h[n], p=0, u[10]= {1,2,3,4,5,6,7,8,9,10};
    cout<<"Enter the elements of set A :"<<'\n';
    
    for(i=0;i<n;i++)
       cin>>A[i];
	   cout<<'\n';
       
    cout<<"Enter the elements of set B :";
    
    for(i = 0; i<n; i++)
       cin >> B[i];
       
    do
    {   cout<<"Main Menu ";
    cout<<"1-To check whether a set is subset of other"<<'\n';
    cout<<"2-Union and Intersection of two sets"<<'\n';
    cout<<"3-Complement of a Set"<<'\n';
    cout<<"4-Set Difference and Symmetric Difference"<<'\n';
    cout<<"5-Cartesian Product of a set"<<'\n';
    cout<<"6-Exit"<<'\n';
    cin>>z;
    
    switch(z)
    {   
        case 1 :
               k = 0;
               for(i = 0; i < n; i++)
               {
                  for(j = 0; j < n; j++)
                  {
                     if(B[k] == A[j])
                     {   t = 1;
                         k++;
                         break;
                     }
                  }
                  if(t == 0)
                     cout<<"B is not a subset of A";
                  else
                     t = 0;
               }
               k = 0;
               t = 0;
               for(i = 0; i < n; i++)
               {
                  for(j = 0; j < n; j++)
                  {
                     if(A[k] == B[j])
                     {   t = 1;
                         k++;
                         break;
                     }
                  }
                  if(t == 0)
                     cout<<"A is not a subset of B";
                  else
                     t = 0;
               }
               break;
        case 2 :
               l = 0;
               
               for(i = 0; i < n; i++)
               
                  c[i] = A[i];
               
               for(i = 0, j = n; i < n; i++, j++)
                  
                  c[j] = B[i];
               
               for(i = 0; i < n; i++)
               {   
                   for(j = 0; j < n; j++)
                   {   
                       if(A[i] == B[j])
                       {   d[l] = A[i];
                           l++;
                           break;
                       }
                   }
               }
               cout<<"The Union of A and B is "<<"{ ";
               
               for(i = 0; i < 2 * n; i++)
               
                  cout<<c[i]<<", ";
                  
               cout<<" }"<<'\n';
               cout<<"The Intersection of A and B is "<<"{ ";
                      
               for(i = 0; i < 2 * n; i++)
               
                  cout<<d[i]<<", ";
                  
               cout<<" }"<<'\n';
               break;
        case 3 :
               m = 0;
               
               for(i = 0; i < n; i++)
               {   
                   for(j = 0; j<n; j++)
                   {
                       if(A[i] == u[j])
                       {   t = 1;
                           break;
                       }
                   }
                   if(t == 0)
                   {  e[m] = A[i];
                      m++;
                   }
                   else
                      t = 0;
               }
               m = 0;
               t = 0;
               for(i = 0; i < n; i++)
               {   
                   for(j = 0; j < n; j++)
                   {
                       if(B[i] == u[j])
                       {   t = 1;
                           break;
                       }
                   }
                   if(t == 0)
                   {  f[m] = A[i];
                      m++;
                   }
                   else
                      t = 0;
               }
               cout<<"The Complement of set A is"<<'\n';
               cout<<"{ ";
               
               for(i = 0; i < n; i++)
                  cout<<e[i]<<", ";
               
               cout<<" }"<<'\n';
                cout<<"The Complement of set B is"<<'\n';
               cout<<"{ ";
               
               for(i = 0; i < n; i++)
                  cout<<f[i]<<", ";
               
               cout<<" }"<<'\n';
               break;
        case 4 :
               p = 0;               
               for(i = 0; i < n; i++)
               {   
                   for(j = 0; j < n; j++)
                   {
                       if(A[i] == B[j])
                       {   t = 1;
                           break;
                       }
                   }
                   if(t == 0)
                   {  g[p] = A[i];
                      p++;
                   }
                   else
                      t = 0;
               }
               t = 0;
               p = 0;
               for(i = 0; i < n; i++)
               {   
                   for(j = 0; j < n; j++)
                   {
                       if(B[i] == A[j])
                       {   t = 1;
                           break;
                       }
                   }
                   if(t == 0)
                   {  h[p] = B[i];
                      p++;
                   }
                   else
                      t = 0;
               }
               cout<<"A-B= { ";
               
               for(i = 0; i < n; i++)
                  cout<<g[i]<<", ";
                  
               cout<<" }"<<'\n';
                cout<<"B-A= { ";
               
               for(i = 0; i < n; i++)
                  cout<<h[i]<<", ";
               cout<<" }"<<'\n';
               break;
        case 5 :
               cout<<"A x B ={ ";
               
               for(i = 0; i < n; i++)
               {   
                   for(j = 0; j < n; j++)
                   {   
                       cout<<"( "<<A[i]<<","<<B[j]<<" ) , ";
                   }
               }
               cout<<" }"<<'\n';
               break;
        case 6 :
               exit(0);
        default :
                cout<<"Wrong Choice "<<'\n';
        }
    }while(1);
    cout<<'\n';
    system("pause");
    return 0;
}
    

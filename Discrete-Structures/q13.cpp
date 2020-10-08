//This program is to print the truth table of some logical operations
#include<iostream>
using namespace std;
int main()
{
    int x, y;
    char ch;
    cout<<"Enter the values of x and y: ";
    cin>>x>>y;
    do
    {cout<<"\t\t\tMain Menu"<<'\n';
     cout<<"a-Conjunction"<<'\n';
     cout<<"b-Disjunction"<<'\n';
     cout<<"c-Exclusive OR"<<'\n'; 
     cout<<"d-Conditional"<<'\n';
     cout<<"e-Bi-Conditional"<<'\n';
     cout<<"f-Exclusive Nor"<<'\n';
     cout<<"g-Negation"<<'\n';
     cout<<"h=NAND"<<'\n';
     cout<<"i-NOR"<<'\n';
     cout<<"j-Exit"<<'\n';
     cout<<"Enter your choice"<<'\n';
     cin>>ch;
     
     switch(ch)
     {
         case 'a' :
                  int r;
                  if(x == 1 && y == 1)
                     r = 1;
                  else
                     r = 0;
                  cout<<"Conjunction : "<<r<<'\n';
                  break;
         case 'b' :
                  int s;
                  if(x == 0 && y == 0)
                     s = 0;
                  else
                     s = 1;
                  cout<<"Disjunction : "<<s<<'\n';
                  break;
         case 'c' :
                  int t;
                  if(x == y)
                    t = 0;
                  else
                     t = 1;
                  cout<<"Exclusive OR : "<<t<<'\n';
                  break;
         case 'd' :
                  int u;
                  if(x == 1 && y == 0)
                     u = 0;
                  else
                     u = 1;
                  cout<<"Conditional : "<<u<<'\n';
                  break;
         case 'e' :
                  int v;
                  if(x == y)
                     v = 1;
                  else
                     v = 0;
                  cout<<"Bi-Conditional : "<<v<<'\n';
                  break;
         case 'f' :
                  int w;
                  if(x == y)
                     w = 1;
                  else
                     w = 0;
                  cout<<"Exclusive NOR : "<<w<<'\n';
                  break;
         case 'g' :
                  int z;
                  if(x == 0)
                     z = 1;
                  else
                     z = 0;
                  cout<<"Negation : "<<z<<'\n';
                  break;
         case 'h' :
                  int k;
                  if(x == 1 && y == 1)
                     k = 0;
                  else 
                     k = 1;
                  cout<<"NAND : "<<k<<'\n';
                  break;
         case 'i' :
                  int l;
                  if(x == 0 && y == 0)
                     l = 1;
                  else
                     l = 0;
                  cout<<"NOR : "<<l<<'\n';
                  break;
         case 'j' :         
                  exit(0);
         default :
                 cout<<"Wrong Choice"<<'\n';
         }
     }while(1);
system("pause");
return 0;
}                     

/*This program is to print the number of paths of length n from source and 
desination entered by the user in a given graph*/
#include<iostream>
using namespace std;
int main()
{
 int i, n, x, y, f, z;
 cout<<"Enter the number of vertices: ";
 cin>>n;
 void multiply(int c[][3], int d[][3], int t, int h);
 int a[3][3], b[3][3];
 cout<<"Enter the source vertex";
 cin>>x;
 cout<<"Enter the destination vertex";
 cin>>y;
 cout<<"Enter the length of path";
 cin>>z;
 for(i = 0; i < n; i++)
    {
	 for(f = 0; f < n; f++)
     {
	   cout<<"Enter the number of edges from vertex "<<i + 1<<" to vertex "<<f + 1<<" ";
       cin>>a[i][f];
       b[i][f] = a[i][f];
     }
    }
 for(i = 2; i <= z; i++)
  multiply(a, b, i, n);
 cout<<"The number of paths of length "<<n<<" from vertex "<<x<<" to vertex "<<y<<" is "<<b[x][y]<<'\n';
 system("pause");
 return 0;
}





                  
  void multiply(int c[][3],int d[][3],int t,int h)
  {int j,k,l,s=0;
   if(t==2)
     {for(j=0;j<h;j++)
         {for(k=0;k<h;k++)
              {for(l=0;l<h;l++)
                  s+=c[j][l]*c[l][k];
              d[j][k]=s;
              s=0;
              }
         }
     }
     else
       {int e[h][h];
        for(j=0;j<h;j++)
         {for(k=0;k<h;k++)
              {for(l=0;l<h;l++)
                  s+=d[j][l]*c[l][k];
              e[j][k]=s;
              s=0;
              }
         }
      for(j=0;j<h;j++)
         {for(k=0;k<h;k++)
              d[j][k]=e[j][k];
         }
      }
 }
 

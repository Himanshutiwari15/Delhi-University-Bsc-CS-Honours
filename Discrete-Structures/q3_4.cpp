//Create a class RELATION, use Matrix notation to represent a relation. Include functions to
//check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program
//to use this class and also Equivalent, partial order or none
#include<stdio.h>
#include<iostream>
int main()
{
    int a[10][10], m, i, j, k, r=1, ir=1, s=1, ans=1, tr=1;
    cout<<"\nEnter the order of the square matrix :";
    cin>>m;
    cout<<"\nEnter the relation in matrix format(0/1):\n";
    
    for(i = 0; i < m; i++)
    
        for(j = 0; j < m; j++)
         cin>>a[i][j];
        //To check reflexive
    for(i = 0; i < m; i++)
    {
        if(a[i][i] != 1)
        
           r = 0;
        if(a[i][i] != 0)
        
           ir = 0;
    }
    //To check symmetric
    
    for(i = 0; i < m; i++)
    
        for(j = 0; j<m; j++)
        {
            if(a[i][j] == 1 && a[j][i] != 1)
               s = 0;
            if(a[i][j] == 1 && a[j][i] == 1 && i != j)
               ans = 0;
        }
        //To check transitive
        for(i = 0; i < m; i++)
        
           for(j = 0; j < m; j++)
           
              for(k = 0; k < m; k++)
              
                 if(a[i][j] == 1 && a[j][k] == 1 && a[i][k] != 1)
                    tr = 0;
           if(r == 1)
              cout<<"\n\nRelationis reflexive";
           else if(ir == 1)
              cout<<"\n\nRelation is irreflexive";
           else
              cout<<"\n\nRelation is neither reflexive nor irreflexive";
           if(s == 1)
             cout<<"\n\nRelation is symmetric";
           if(ans == 1)
             cout<<"\n\nRelation is antisymmetric";
           if(s != 1 && ans != 1)
              cout<<"\n\nRelation is not symmetric";
           if(tr == 1)
              cout<<"\n\nRelation is transitive";
           else
              cout<<"\n\nRelation is not transitive";
           if(r == 1 && s == 1 && tr == 1)
              cout<<"\n\nRelation is equivalance";
           else
              cout<<"\n\nRelation is not a equivalance relation";
           if(r == 1 && ans == 1 && tr == 1)
              cout<<"\n\nRelation is partial ordering relation";
           else
              cout<<"\n\nRelation is not a partial ordering relation";
           cout<<"\n\n";
           system("pause");
           return 0;
 }

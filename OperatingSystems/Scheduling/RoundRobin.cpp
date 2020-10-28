#include <iostream>
using namespace std;
 
int main(){
    int i,j,k=0,p=0,q,temp,s=0,idle=0,done=0;
    float sum=0;
    //taking input
    cout<<"Please enter the number of process : ";
    cin>>p;                                                       

    int a[p][4];
    int b[p][5];
 
    cout<<"Please enter the Time Quantum : ";
    cin>>q;
 
    cout<<"\n\nProcess\tArrival\tBurst\n-------\t-------\t-----\n";
    for(i=0;i<p;i++){
        for(j=0;j<3;j++){
            cin>>a[i][j];
        }
        a[i][3]=a[i][2];//storing total time of each process to another cell 
    }
    cout<<"\n\nTime-Line is as follows (Verticle View)....\n\n";
 
    i=a[0][1];
 
    while(done!=p){
        if(k==p)
            k=0;
 
        if(a[k][1]<=i){
            if(a[k][2]!=0){
                if(a[k][2]>=q){
                    printf("%5d-----------\n        |p-%-4d|\n",i,a[k][0]);
                    a[k][2]-=q;
                    i+=q;
                }else{
                    printf("%5d-----------\n        |p-%-4d|\n",i,a[k][0]);
                    i+=a[k][2];
                    a[k][2]=0;
                 }
 
                 if(a[k][2]==0){
                     b[s][0]=a[k][0];
                     b[s][1]=a[k][1];
                     b[s][2]=i;
                     b[s][3]=a[k][3];
                     b[s][4]=((i-a[k][1])-a[k][3]);        
                     sum+=((i-a[k][1])-a[k][3]);
                     s++;
                     done++;
                 }
                 idle=0;
            }
            k++;             
        }else{
             if(idle==0){
                 idle=1;
                 k=0;
              }else if(idle==1){
                   printf("%5d-----------\n        |Idle  |\n",i); 
                   idle=2;
                   i++;     
              }else
                   i++;           
        }
    }
 
    printf("%5d-----------\n",i); 
 
    cout<<endl<<endl;
 
 
    cout<<"Table of processes with completion record as they were completed\n\n";
    cout<<"\n\nProcess\tArrival\tFinish\tTotal\tWait\n------------------------------------\n";
 
    for(i=0;i<s;i++)
        cout<<b[i][0]<<"\t"<<b[i][1]<<"\t"<<b[i][2]-1<<"\t"<<b[i][3]<<"\t"<<b[i][4]<<"\n";
 
    cout<<"\n\nAvg. Wait time = "<<sum/p<<endl<<endl;      
    return 0;
}

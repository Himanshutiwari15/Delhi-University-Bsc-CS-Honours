/* This programme is actually a game made by Himanshu Tiwari.
this code is matching the concept of the game which all of us must have played in there pc's 
before all this new types of graphical games came.
this is a game named  "lucky bombs" if you think your luck is great then do come and play my game 
once for only one time ..
lets see how strong is your luck actually is ..
so guys enjoy the code its only for reading and please no modification should be done to this code.
*/
#include<iostream>
using namespace std;

//defining functions
//this is to initialise the both arrays 
void initialise(int arr[][4],char ar[][4])
{
for(int i=0;i<4;++i)
for(int j=0;j<4;++j)
{
arr[i][j]=1;
ar[i][j]=' ';
}

arr[0][0]=0;
arr[0][3]=0;
arr[2][0]=0;
arr[1][2]=0;
arr[3][3]=0;
//ar[0][0]='@';
//ar[0][3]='@';
//ar[2][0]='@';
//ar[1][2]='@';
//ar[3][3]='@';
}

//to display the basic grid
void grid_display (char ar[][4])
{
for(int i=0;i<4;++i)
{
cout<<"*___*___*___*___*"<<endl;
for(int j=0;j<4;++j)
{
cout<<"|  "<<ar[i][j];
}
cout<<"|   "<<endl;
}
}

//to initialise row and column according to choice entered
void row_column_initialise (int &r,int &c,int ch)
{
switch(ch)
{
case 1:r=0;
	c=0;
	break;
case 2:r=0;
	c=1;
	break;
case 3:r=0;
	c=2;
	break;
case 4:r=0;
	c=3;
	break;
case 5:r=1;
	c=0;
	break;
case 6:r=1;
	c=1;
	break;
case 7:r=1;
	c=2;
	break;
case 8:r=1;
	c=3;
	break;
case 9:r=2;
	c=0;
	break;
case 10:r=2;
	c=1;
	break;
case 11:r=2;
	c=2;
	break;
case 12:r=2;
	c=3;
	break;
case 13:r=3;
	c=0;
	break;
case 14:r=3;
	c=1;
	break;
case 15:r=3;
	c=2;
	break;
case 16:r=3;
	c=3;
	break;
default:cout<<"you entered a wrong choice"<<endl;
}
}

//this grid is only when user losts the match
void lost_grid()
{
cout<<"*___*___*___*___*"<<endl;
cout<<"| @ |   |   | @ |"<<endl;
cout<<"*___*___*___*___*"<<endl;
cout<<"|   |   | @ |   |"<<endl;
cout<<"*___*___*___*___*"<<endl;
cout<<"| @ |   |   |   |"<<endl;
cout<<"*___*___*___*___*"<<endl;
cout<<"|   |   |   | @ |"<<endl;
cout<<"*___*___*___*___*"<<endl;
}


//this is important and heavy function of all programme
void check (int r,int c,int arr[][4],int &fla,char ar[][4])
{
if(arr[r][c]==0)
{
lost_grid();
cout<<"you lost "<<endl<<"GAME OVER ";
cout<<" your score is: ";
int score =0;
for(int i=0;i<4;++i)
{
for(int j=0;j<4;++j)
{
if(arr[i][j]==2)
score+=1;
}
}
fla =1;
cout<<score<<endl;
}
else
{
for(int i=0;i<4;++i)
{
for(int j=0;j<4;++j)
{
if((r==i)&&(r==j)&&(arr[r][c]!=0))
{
ar[r][c]='#';
arr[r][c]=2;
if(arr[r+1][c]!=0)
{
arr[r+1][c]=2;
ar[r+1][c]='#';
}
if(arr[r-1][c]!=0)
{
arr[r-1][c]=2;
ar[r-1][c]='#';
}
}
}
}
}
}


//for the check of condition that any other turn is available or not
void win_or_not(int arr[][4],int &f)
{
int coun=0;
for(int i=0;i<4;++i)
{
for(int j=0;j<4;++j)
{
if(arr[i][j]==2)
coun+=1;
}
}
if(coun==11)
{
f=1;
cout<<"!!!!congo!!!!"<<endl;
cout<<"you won the match you won the luck"<<endl;
cout<<"lucky guy you have the score of 11"<<endl;
cout<<"enjoy your lucky day"<<endl;
}
}


//main
int main()
{
char time_pass[4][4];
int flag=0,flag2=0;
int bomb_grid[4][4];
initialise(bomb_grid,time_pass);
int choice=0;
cout<<"hello welcome to my game "<<endl;
cout<<"hope you enjoy"<<endl<<"this is a game where you can check your luck and have fun playing this interesting game "<<endl<<"LUCKY BOMBS"<<endl;
cout<<"rules:"<<endl<<"1:you have to choose any no. from 1 to 16 ."<<endl<<"2:@ defines  bomb and # define safe ."<<endl<<"3:happy playing"<<endl;
grid_display(time_pass);
while((flag!=1)&&(flag2!=1))
{
cout<<"please enter the choice"<<endl;
cin>>choice;
int row=0,column=0;
row_column_initialise(row,column,choice);
check (row,column,bomb_grid,flag,time_pass);
if(flag!=1)
{
grid_display(time_pass);
}
win_or_not(bomb_grid,flag2);
}
cout<<"thanks for playing"<<endl;
return 0;
}

#include<iostream>
#include<string>

//#define tic_tac_toe_grid 9

using namespace std;

void input(char tttarray[],int position,char choice)
{
    tttarray[position]=choice;
}

void startgame(char tttarray[])
{
    for(int i=0;i<9;++i)
        tttarray[i]='';
}

void displaygamegrid(char tttarray[])
{
    cout<<"*___*___*___*"<<endl;
    for(int i=0;i<9;++i)
    {
        cout<<"|"<<tttarray[i]<<" ";
        if((i+1)%3==0&&i!=0)
        {
            cout<<"|"<<endl;
            cout<<"*___*___*___*"<<endl;
        }
    }
}

bool isfull(char tttarray[])
{
    for(int i=0;i<9;++i)
    {
        if(tttarray[i]==' ')
        {
            return false;
        }
    }
    return true;
    
}

bool isempty(char input)
{
    if(input==' ')
        return true;
    return false;
}

bool winatrow(char tttarray[])
{
    for(int i=0;i<9;i+=3)
    {
        char left =tttarray[i];
        char mid=tttarray[i+1];
        char right=tttarray[i+2];
        if(!isempty(left)&&!isempty(right))
        {
            if(left==mid&&left==right)
            {
                return true;
            }
        }
    }
    return false;
}

bool winatcolumn(char tttarray[])
{
    for(int i=0;i<3;++i)
    {
        char left=tttarray[i];
        char mid=tttarray[i+3];
        char right=tttarray[i+6];
        if(!isempty(left)&&!isempty(mid)&&!isempty(right))
        {
            if(left==mid&&left==right)
            {
                return true;
            }
        }
    }
    return false;
}

bool winatdiagonal(char tttarray[])
{
    char mid=tttarray[4];
    if(!isempty(mid)&&!isempty(tttarray[0])&&!isempty(tttarray[8]))
    {
        if(mid==tttarray[0]&&mid==tttarray[8])
        {
            return true;
        }
    }
    else if(!isempty(mid)&&!isempty(tttarray[2])&&!isempty(tttarray[6]))
    {
        if(mid==tttarray[2]&&mid==tttarray[6])
        {
            return true;
        }
    }
    return false;    
}

bool win(char tttarray[])
{
    if(winatrow(tttarray))
        return true;
    else if(winatcolumn(tttarray))
        return true;
    else if(winatdiagonal(tttarray))
        return true;
    return false;
}

int main()
{
    char tttarray[9];
    startgame(tttarray);
    int currentchance=0;
    cout<<"TIC TAC TOE"<<endl<<endl;
    displaygamegrid(tttarray);    
    cout<<endl;
    while(!isfull(tttarray))
    {
        int positionchoice;
        currentchance +=1;
/*change*/        bool player2= (currentchance%2==0)?true:false;
        player2?cout<<"player 2 chance.."<<endl<<"insert to position>":cout<<"player 1 chance.."<<endl<<"insert to position>";
        cin>>positionchoice;
        while (!isempty(tttarray[positionchoice]))
        {
            cout<<"psition occupied.please select another option>";
            cin>>positionchoice;
        }
        if(player2)
            tttarray[positionchoice]='o';
        else
            tttarray[positionchoice]='x';
//print
        displaygamegrid(tttarray);
        cout<<endl;
//check winner
        if(win(tttarray))
        {
            if(player2)
                cout<<"player 2 won the tic tac toe.";
            else
                cout<<"player 1 won the tic tac toe.";
            break;
        }
    }
    if(!win(tttarray))
        cout<<"draw";                
}

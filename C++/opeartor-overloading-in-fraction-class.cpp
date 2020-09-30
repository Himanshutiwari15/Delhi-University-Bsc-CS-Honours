/*this is programme that takes a fraction and performs various 
operations in it.
it actuallu overloads various operators and do make use of them using 
menu driven programme .
the whole programme is encoded with various comments that will help the 
reader to understand the code.
a strict instruction is been given by the programmer 
that user is not allowed to do 
any changes to the code ..
HAPPY CODING*/


#include<iostream>
using namespace std;

//class starts here

class fraction
{
    private:                                      //private data members
    int numenator;
    int denominator;
    public:                                       

        //constructor overloading prototype

    fraction();
    fraction(int num);
    fraction(int num,int denom);

        //member functions

    void store(int num,int denom);
    void print();
    void reduce();

    //friend functions
    
    friend void operator <<(ostream &out,fraction &fr);
    friend void operator >>(istream &in,fraction &fr);
    
    
    
    fraction operator +(int num)            // add (x/y +2) with constant (+) overloaded
    {
        fraction temp;
        temp.numenator=numenator + (num*denominator);
        temp.denominator=denominator;        
        temp.reduce();
        return temp;
    }

    friend fraction operator +(int num,fraction &fr);            // add (2+x/y)with constant (+) overloade    

    fraction operator +(fraction &fr)            //add (+) overloaded
    {
        fraction temp;
        temp.numenator=(numenator*fr.denominator)+(denominator*fr.numenator);
        temp.denominator=(denominator*fr.denominator);
        temp.reduce();
        return temp;
    }
    fraction operator -(fraction &fr)             //subtract (-) overloaded
    {
        fraction temp;
        temp.numenator=(numenator*fr.denominator)-(denominator*fr.numenator);
        temp.denominator=(denominator*fr.denominator);
        temp.reduce();
        return temp;
    }
    fraction operator *(fraction &fr)               //product (*) overloaded
    {
        fraction temp;
        temp.numenator=(numenator*fr.numenator);
        temp.denominator=(denominator*fr.denominator);
        temp.reduce();
        return temp;
    }
    fraction operator /(fraction &fr)                //divide (/) overloaded
    {
        fraction temp;
        temp.numenator=(numenator*fr.denominator);
        temp.denominator=(denominator*fr.numenator);
        temp.reduce();
        return temp;
    }
    bool operator <(fraction fr)                //less than (<) overloaded
    {
        if(numenator*fr.denominator<denominator*fr.numenator)
            return true;
        else
            return false;
    }
    bool operator >(fraction fr)                    //greater than (>) oveloaded
    {
        if(numenator*fr.denominator>denominator*fr.numenator)
            return true;
        else
            return false;
    }
    bool operator ==(fraction fr)                    //equals to (==) overloaded
    {
        reduce();
        fr.reduce();
        if(numenator==fr.numenator)
        {
            if(denominator==fr.denominator)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool operator !=(fraction fr)                      //not equals to (!=) overloaded
    {
        reduce();
        fr.reduce();
        if(numenator!=fr.numenator)
        {
                return true;
        }
        else
        {
            if(denominator==fr.denominator)
            {    
            return false;
            }
            else
                return false;
        }
    }
    fraction operator ++()                        //prefix increament (++) overloaded
    {
        reduce();
        numenator+=denominator;
        return *this;
    }
    fraction operator ++(int)                        //postfix increament (++) overloaded
    {
        reduce();
        fraction temp;
        temp.numenator=numenator;
        temp.denominator=denominator;
        numenator+=denominator;
        return temp;
    }
    fraction operator --()                       //prefix decreament(--) overloaded
    {
        reduce();
        numenator-=denominator;
        return *this;
    }
    fraction operator --(int)                        //postfix decreament (--) overloaded
    {
        reduce();
        fraction temp;
        temp.numenator=numenator;
        temp.denominator=denominator;
        numenator-=denominator;
        return temp;
    }
    
};

    fraction operator +(int num,fraction &fr)              // add with constant (+) overloaded
    {
        fraction temp;
        temp.numenator=fr.numenator + (num*fr.denominator);
        temp.denominator=fr.denominator;        
        temp.reduce();
        return temp;
    }    

void operator <<(ostream &out,fraction &fr)              //insertion (<<) overloaded
{
    out<<fr.numenator<<"/"<<fr.denominator<<"\n";
}

void operator >>(istream &in,fraction &fr)                     //excertion (>>) overloaded
{
    in>>fr.numenator>>fr.denominator;
    fr.print();
}

fraction::fraction()                              //default constructor
{
    numenator=0;
    denominator=1;
}

fraction::fraction(int num)
{
    numenator=num;
    denominator=1;
}

fraction::fraction(int num,int denom)
{
    numenator=num;
    denominator=denom;
}

void fraction::print()                           //to print 
{
    cout<<numenator<<"/"<<denominator<<endl;
}
void fraction::reduce()                            //to reduce like 2/4 is equal to 1/2 so this task will be done in this function
{
    bool flag= false;
    if(numenator*denominator<0)
    {
        if(denominator<0)
        {
            denominator*=-1;
            numenator*=-1;
        }
        numenator*=-1;
        flag=true;
    }
    else
    {
        if(numenator<0)
        {
            denominator*=-1;
            numenator*=-1;
        }
    }
    int i=2;
    while(i<=numenator&&i<=denominator)
    {
        if(numenator%i==0)
        {
            if(denominator%i==0)
            {
                numenator/=i;
                denominator/=i;
            }
            else
                ++i;
        }
        else
            ++i;
    }
    if(flag==true)
        numenator*=-1;
    
}

//main starts here

int main()
{
    cout<<"enter the number in following pattern: "<<endl;
    cout<<"numenator1 denominator1 numenator2 denominator2"<<endl;
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

    fraction fr1(a,b),fr2(c,d),fr3(e,f);

    cout<<"fraction 1: ";
    fr1.print();
    cout<<"\nfraction 2: ";
    fr2.print();
    cout<<"\nfraction 3: ";
    fr3.print();
    cout<<endl;
    int n=0,k=0;
    int m=1;
    do
    {
    cout<<"-_-_-_-_-_-_-_-_MENU_-_-_-_-_-_-_-_-_-_-\n";                           //menu    
    cout<<"1:ADD 2 fractions\n ";
    cout<<"2:ADD 3 fractions\n ";
    cout<<"3:SUBTRACTION\n ";
    cout<<"4:MULTIPLICATION\n ";
    cout<<"5:DIVISION\n ";
    cout<<"6:LESS THAN\n ";
    cout<<"7:GREATER THAN\n ";
    cout<<"8:EQUALS TO\n ";
    cout<<"9:NOT EQUALS TO\n ";
    cout<<"10:POSTFIX INCREAMENT:\n ";
    cout<<"11:POSTFIX DECREAMENT:\n ";
    cout<<"12:PREFIX INCREAMENT:\n ";
    cout<<"13:PREFIX DECREAMENT:\n ";
    cout<<"14:print the fraction:\n";
    cout<<"15:get fraction from user:\n";
    cout<<"16:add with a constant number(x/y +constant )form:\n";
    cout<<"17:add with the constant number (constant + x/y)form:\n";
    cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    cout<<"please enter the choice:\n ";
    cin>>n;
    switch (n)                                                    //switch statements to check the choice
    {
    case 1:cout<<"fraction 1+ fraction 2:";
        (fr1+fr2).print();
        cout<<"fraction 2+fraction 3:";
        (fr2+fr3).print();
        cout<<"fraction 1+fraction 3:";
        (fr1+fr3).print();
        break;
    case 2:cout<<"fraction 1+fraction 2+fraction 3:";
        (fr1+fr2+fr3).print();
        break;
    case 3:cout<<"fraction 1-fraction 2:";
        (fr1-fr2).print();
        break;
    case 4:cout<<"fraction 1*fraction 2:";
        (fr1*fr2).print();
        break;
    case 5:cout<<"fraction 1/fraction 2:";
        (fr1/fr2).print();
        break;
    case 6:cout<<" is fraction 1<fraction 2:";
        cout<<(fr1<fr2);
        break;
    case 7:cout<<" is fraction 1>fraction 2:";
        cout<<(fr1>fr2);
        break;
    case 8:cout<<"is fraction 1==fraction 2:";
        cout<<(fr1==fr2);
        break;
    case 9:cout<<"is fraction 1!=fraction 2:";
        cout<<(fr1!=fr2);
        break;
    case 10:cout<<"fraction 1++:";
        (fr1++).print();
        break;
    case 11:cout<<"fraction 1--:";
        (fr1--).print();
        break;
    case 12:cout<<"++fraction 1:";
        (++fr1).print();
        break;
    case 13:cout<<"--fraction 1:";
        (--fr1).print();
        break;
    case 14:cout<<fr1;
        cout<<fr2;
        cout<<fr3;
        break;
    case 15:cin>>fr1;
        cin>>fr2;
        cin>>fr3;
        break;
    case 16: cout<<"enter the number to be added";
        cin>>k;
        (fr1+k).print();
        break;
    case 17:cout<<"enter the number to added";
        cin>>k;
        (k+fr2).print();
        break;
    default:cout<<"you entered a wrong input ";
    }
    cout<<"\ndo you want to work more 0/1 (0 is for false and 1 is for true):";
    cin>>m;
    }while(m);
    return 0;
}

//main ends here

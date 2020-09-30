//some header files used in this programme
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class BANK                       //class BANK begins here     
{       
                                 //private data members

    int account_no;              //for storing account number
    char name[50],type;          //for storing name and type of account
    int deposit;                 //money you want to deposit
                                 
                                 //member functions
    public:
        void create_account(); //function to get data from user
        void display();         //function to show data on screen
        void modify();          //function to add new data
        void deposite(int);      //function to accept amount and add to balance amount
        void withdraw(int);     //function to accept amount and subtract from balance amount
    	void report() const;	//function to show data in tabular form 
        int retaccount_no();	//function to return account number
        int retdeposit();   	//function to return balance amount
        char rettype();      	//function to return type of account

};                              //class ends here

    void BANK::create_account()
        {
	    cout<<"\nwelcome \n";
	    cout<<"\nenter the details to create an account\n";
	    cout<<"\nEnter The account No. :";
	    cin>>account_no;
	    cout<<"\n\nEnter The Name of The account Holder : ";
	    cin.ignore();
	    cin.getline(name,50);
	    cout<<"\nEnter Type of The account (C/S) : ";
	    cin>>type;
	    type=toupper(type);
	    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
        cin>>deposit;
	    cout<<"\n\n\nAccount Created..";
        }
    void BANK::display()
        {  cout<<"\t\t\t*Account Detail*\t\t\t\t\t\t\t\t\t";
           cout<<"\n Name of the account holder:"<<name;    
           cout<<"\n Account type:"<<type;
           cout<<"\n Account number :"<<account_no;
           cout<<"\n Amount in the bank account:"<<deposit;
        }  
        
    void BANK::modify()
        {
	        cout<<"\nAccount No. : "<<account_no;
	        cout<<"\nModify Account Holder Name : ";
    	    cin.ignore();
	        cin.getline(name,50);
        	cout<<"\nModify Type of Account : ";
        	cin>>type;
        	type=toupper(type);
	        cout<<"\nModify Balance amount : ";
	        cin>>deposit;
            }

    void BANK::deposite(int x)
        { 
            deposit+=x;
        }

    void BANK::withdraw(int x)
        { 
            deposit-=x;
        }
    	
    void BANK::report() const
        {   
	        cout<<account_no<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
        }

    int BANK::retaccount_no()
        { 
            return account_no;
        }

    int BANK::retdeposit()
        { 
            return deposit;;
        }

    char BANK::rettype()
        { 
            return type;
        }

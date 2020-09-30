//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>
#include "Class_Bank_Account.h"    //this haeder file is used to use a class made before with various inbuilt member functions
#include "Important_Function.h"    //this header file uses the various functions which makes the use of programme more efficient

using namespace std;

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
    {
	    char ch;
	    int num;
	    intro();                  //introduction funtion for the user
	    do
	    {
		    
		    cout<<"\n\n\n\tMAIN MENU";       //menu
	    	cout<<"\n\n\t01. NEW ACCOUNT";
		    cout<<"\n\n\t02. DEPOSIT AMOUNT";
    		cout<<"\n\n\t03. WITHDRAW AMOUNT";
	    	cout<<"\n\n\t04. BALANCE ENQUIRY";
		    cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
    		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
	    	cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		    cout<<"\n\n\t08. EXIT";
    		cout<<"\n\n\tSelect Your Option (1-8) ";
	    	cin>>ch;
		
    		switch(ch)           
	    	{
		        case '1':
        			write_account();
		        	break;
        		case '2':
		        	cout<<"\n\n\tEnter The account No. : "; cin>>num;
        			deposit_withdraw(num, 1);
		        	break;
        		case '3':
		        	cout<<"\n\n\tEnter The account No. : "; cin>>num;
        			deposit_withdraw(num, 2);
		        	break;
        		case '4': 
		        	cout<<"\n\n\tEnter The account No. : "; cin>>num;
        			display_sp(num);
		        	break;
        		case '5':
		        	display_all();
			        break;
        		case '6':
		        	cout<<"\n\n\tEnter The account No. : "; cin>>num;
			        delete_account(num);
        			break;
		         case '7':
        			cout<<"\n\n\tEnter The account No. : "; cin>>num;
		        	modify_account(num);
        			break;
		         case '8':
        			cout<<"\n\n\tThanks for using bank managemnt system";
		        	break;
        		 default :cout<<"\a";       //that's for a bell ring,may it work!!!
		        }
    		cin.ignore();                  // this is used to clear the char buffer :::for /n or anything else
    		cin.get();
	        }while(ch!='8');                // do while loop ends here
        	return 0;
        }
// main ends here
//programme terminated

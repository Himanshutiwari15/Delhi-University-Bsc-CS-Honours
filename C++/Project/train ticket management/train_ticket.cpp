
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//FIXING SEAT AVAILABILITY FOR ALL TRAINS.............................
int ac1=0,ac2=10,ac3=10,second_sitting=30,sleeper=250;
//-------------------------------------------------------------------
int i=0;

struct eticket
{
	char name[100];
	char address[100];
	long long int ph;
    char gender[10];
    int age;
    char id[20];
    char pass[20];
	char from[25],To[10];
	int month,day,year,c,s,food,tins;
	char berth[10];
	float total;
}st[100];
 int book(struct eticket st[],int t);
  	    
//FOR SIGNUP-------------------------------------------------------------
void signup()
{
	system("cls");
	if(i<10)
	{
       printf("\n\n*****SIGNUP PORTAL*****\n");
       printf("Enter signup credential:\n(id must be numeric and password must be alphanumeric)\n\n LOGIN ID: ");
       scanf("%s",st[i].id);
       printf(" PASSWORD: ");
       scanf("%s",st[i].pass);
	   int m;
	
       int captcha;
       m=rand()*100;
       printf("\n -------\n");
       printf("|  %d   |\n",m);
       printf(" -------\n");
       printf("\nENTER CAPTCHA: ");
       scanf("%d",&captcha);

       if(captcha==m)
       {
     	printf("\n \t\tSIGNUP SUCESSFULLY\n");
       }
       else
       {
  	    printf("\nINVALID CAPTCHA :( !!PLEASE TRY AGAIN :)");
       }
    }i++;
}
//FOR LOGIN---------------------------------------------------------------

void login()
{
    int Z=0;
	system("cls");
    char identity[20];
    int t,b;
    char p[20];
    system("cls");
    printf("\n****WELCOME TO LOGIN PORTAL*****   \n");
    printf("\nENTER USER ID: ");
    scanf("%s",identity);
    for(t=0;t<i;t++)
	{
  	    if(strcmp(identity,st[t].id)==0)
		{
  		Z=1;
  		printf(" PASSWORD: ");
  		scanf("%s",p);
  		if(strcmp(p,st[t].pass)==0)
		{
  		system("cls");
  		printf("\n\t\tLOGIN SUCESSFULLY :))\n");
  		printf("\n Press 1 to book train else 0: ");
  		scanf("%d",&b);
  		if(b==1)
		{
  			printf("\n");
  			system("cls");
  			book(st,t);
  		}
  		else
	    {
  			system("cls");
  			printf("\n\t hope we meet again :)");
		}
     	}
  		else
  		printf("\n\t\twrong password :(---GALAT HAI PASSWORD--:(\n");
	    }
    }
    if(Z==0)
	  printf("\nINVALID USER ID  :( !! PLEASE TRY AGAIN");
}
//for booking--------------------------------------------------------------------------

int book(struct eticket st[],int t)
{
	int ax=0;
	printf("******TOWARDS BOOKING GATEWAy**********");
	printf("\n----------------------------------------------------------------------\n");
	printf("\n WHERE FROM:");
	scanf("%s",st[t].from);
	printf("\n WHERE TO:");
	scanf("%s",st[t].To);
	printf("\nENTER DATE OF JOURNEY:");
	scanf("%d %d %d",&st[t].day,&st[t].month,&st[t].year);
	printf("\n\n TRAINS RUNNING ON %d:%d:%d ARE AS FOLLOWS:",st[t].day,st[t].month,st[t].year);
	printf("\n ----------------------------------------------------------------------------\n");
	printf("   |SNO.|TRAIN NO | TRAIN NAME        |DEPRT.TIME|ARRIVAL_TIME |TOTAL_DISTANCE|");
	printf("\n |----| --------|-------------------|----------|-------------|--------------|\n");
	printf("\n |1.  | 12309   | RJPB RAJDHANI     | 07:35    | 19:00       |   1001KM     |\n");
	printf("\n |2.  | 12566   | SAMPARK KRANTI    | 05:30    | 19:00       |   998KM      |\n");
	printf("\n |3.  | 14055   | BRAHMPUTRA MAIL   | 04:30    | 20:30       |   1004KM     |\n");
	printf("\n |4.  | 12505   | POORVA EXPRESS    | 02:30    | 07:00       |   1014KM     |\n");
    printf("\n |5.  | 12487   | NORTH EAST EXPRESS| 08:30    | 22:00       |   1087KM     |\n");
    printf("\n ----------------------------------------------------------------------------\n");

	printf("\nSELECT TRAINS FROM ABOVE LIST: ");
	scanf("%d",&st[t].c);
//	system("cls");
    printf("\n\t\t TOTAL SEATS\n");
	printf("\n\t1.AC TIER1\t%d\n\t2.AC TIER2\t%d\n\t3.AC TIER3\t%d\n\t4.SECOND SITTING %d\n\t5.SLEEPER\t%d\n\t6.GENERAL: ",ac1,ac2,ac3,second_sitting,sleeper);
	printf("\n\n\tSELECT COACH: ");
	scanf("%d",&st[t].s);
	printf("\nENTER BERTH PREFERENCE(UPPER/LOWER/MIDDLE): ");
	scanf("%s",st[t].berth);
	printf("\n PRESS 1 for FOOD SERVICE DURING JOURNEY AND 0 FOR NO : ");
	scanf("%d",&st[t].food);
	printf("\n press 1 to take travel safety insurance (just Rs 5) and 0 for no.: ");
	scanf("%d",&st[t].tins);
	if(st[t].c==1||st[t].c==2||st[t].c==3||st[t].c==4||st[t].c==5 &&  st[t].s==1||st[t].s==2||st[t].s==3||st[t].s==4||st[t].s==5||st[t].s==6)
	{
		switch(st[t].c)
		{
			case 1:
			{
				printf("\n |1.  | 12309  | RJPB RAJDHANI | 07:35 | 19:00 | 1001KM |\n\n");
				switch(st[t].s)
				{

					case 1:
					if(ac1>0)
					{
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}
					else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}
					else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
					printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);

					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
					
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
				    
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
					break;
				}
				break;
			}

			case 2:
			{	printf("\n |2.  | 12566| SAMPARK KRANTI| 05:30 | 19:00 | 998KM      |\n");

				switch(st[t].s)
				{

					case 1:if(ac1>0)
					{
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
					
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
					
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						{
						break;
					}
				}

			break;
		}

			case 3:
			{printf("\n |3.  | 14055   | BRAHMPUTRA MAIL   | 04:30    | 20:30       |   1004KM     |\n");

				switch(st[t].s)
				{
					case 1:if(ac1>0)
					{
					
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
						
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
						
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						break;
				}
			break;
		}

			case 4:
			{
					printf("\n |4.  | 12505   | POORVA EXPRESS    | 02:30    | 07:00       |   1014KM     |\n");

				switch(st[t].s)
				{
					case 1:if(ac1>0)
					{
					
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{

						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:
					if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
					
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
				    
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						break;
				}
				break;
			}
			case 5:
			{printf("\n |5.  | 12487   | NORTH EAST EXPRESS| 08:30    | 22:00       |   1087KM     |\n");

				switch(st[t].s)
				{
					case 1:if(ac1>0)
					{
						
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else

						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					break;
				    case 6:
					
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						break;
				}
				break;
			}
		default:
		 break;
		}
	}else
        {
    	printf("INVAID OPTION");
     	}
     	//system("cls");
	  	 printf("\n***ENTER PASSENGER DETAILS*\n");
		 printf("\nPASSENGER NAME: ");
		 scanf("%s",st[t].name);
		 printf("PHONE NUMBER: ");
		 scanf("%lld",&st[t].ph);
		 printf("ADDRESS: ");
		 scanf("%s",st[t].address);
		 printf("GENDER: ");
		 scanf("%s",st[t].gender);
		 printf("ENTER AGE: ");
		 scanf("%d",&st[t].age);



	  float gst=120;
	  float tfare=0;
	  float fochrg=500;
	  float inschg=5;
	  if(st[t].c==1)
	  {
	  	  if (st[t].s==1)
	  	  { tfare=2250;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2220;
		  }else if(st[t].s==3)
		  {
		  	tfare=2000;
		  }else if (st[t].s==4)
		  {tfare=750;
	      }else if (st[t].s==5)
	      {tfare=560;
		  }else if (st[t].s==6)
		  {tfare=250;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==2)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==3)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==4)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==5)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else
	  {
		st[t].total=tfare+gst+fochrg+inschg;
	  }
int choice;
system("cls");
	printf("\n PRESS 1 TO CONTINUE---- \n  OR 0 TO CANCEL CURRNET BOOKING: ");
	scanf("%d",&choice);
	if(choice==1)
	{
   	//system("cls");
	printf("\n**** E-TICKET******\n");
	printf("\n___________\n");
	printf("\n| PASSENGER NAME   :%s      ",st[t].name);
	printf("\n___________\n");
	printf("\n| PHONE NUMBER     :%lld   ",st[t].ph);
	printf("\n___________\n");
	printf("\n| ADDRESS          :%s     ",st[t].address);
	printf("\n___________\n");
	printf("\n| GENDER           :%s     ",st[t].gender);
	printf("\n___________\n");
	printf("\n| AGE              :%d      ",st[t].age);
	printf("\n___________\n");

//fare details-------------------------------------------------------------------------
	printf("\n\n***FARE DETAILS:***\n");
	printf("\n___________\n");
	printf("\n| TICKET FARE: Rs. %f       ",tfare);
	printf("\n|___________\n");
	printf("\n| GST CHARGES: Rs. %f       ",gst);
	printf("\n|___________\n");
	if(st[t].food==1)
	{
	printf("\n| FOOD CHARGES:Rs.500         ");
	printf("\n|___________\n");
	st[t].total=tfare+gst+500;
    }
    else
    {
	printf("\n FOOD CHARGES= Rs. 0          ");
	printf("\n|___________\n");
    st[t].total=tfare+gst;
	}
	if(st[t].tins==1)
	{
	printf("\n| TRAVEL INSURANCE CHARGES=RS.5");
	printf("\n|__________\n");
	
		st[t].total+=5;
	}else
	{
	printf("\n TRAVEL INSURANCE CHARGES=RS.0");
	printf("\n____________\n");
		st[t].total+=0;
	}

	printf("\n| \nTOTAL FARE:Rs.%f        ",st[t].total);
	printf("\n|__________\n");
	
//train details--------------------------------------------------------------------------
	printf("\n\n****TRAIN DETAILS*****\n");

	switch(st[t].c)
		{
			case 1:
	           {
			    printf("TRAIN IS:");
				printf("| 12309  | RJPB RAJDHANI | 07:35 | 19:00 | 1001KM |\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");}
				printf("\nBERTH: %s",st[t].berth);
                break;
			  }
            case 2:
			 {

                printf("TRAIN IS:");
				printf("| 12566   | SAMPARK KRANTI    | 05:30    | 19:00       |   998KM      \n\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");
				}
				printf("\nBERTH: %s",st[t].berth);
                break;
				}
            case 3:
			 {

                printf("TRAIN IS:");
				printf("|| 14055   | BRAHMPUTRA MAIL   | 04:30    | 20:30       |   1004KM     |\n\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");}
			    printf("\nBERTH: %s",st[t].berth);
                break;
	            }
	        case 4:
			    {

                printf("TRAIN IS:");
				printf("\n\n |4.  | 12505   | POORVA EXPRESS    | 02:30    | 07:00       |   1014KM     |\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");
				}
				printf("\nBERTH: %s",st[t].berth);
                break;
				}
            case 5:
				{
				printf("TRAIN IS:");
				printf("| 12487   | NORTH EAST EXPRESS| 08:30    | 22:00       |   1087KM     |\n\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");}
				printf("\nBERTH: %s",st[t].berth);
				printf("\n-----------------------------");
                break;
				}
            default:
			break;
        }

	printf("\n\n**:) HAPPY JOURNEY :)***\n");
	printf("\n-----------------------------");

}
else{
	system("cls");
	printf("\n****WELCOME AGAIN:)*****");
   }
}



int main()
{
	int n;
	for(i>0; ;i++)
	{
		printf("\n");
		printf("1. signup\n");
		printf("2. login\n");
		printf("3. log out\n");
		printf("enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				signup();
				break;
			}
		case 2:
		{
			login();
			break;
		}
		case 3:
		{
			return 0;
			break;
		}
		}
	}
}/*PROGRAM TO RAILWAY PORTAL
AUTHOR:JAY PRAKASH
STATUS:RUNNING*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//FIXING SEAT AVAILABILITY FOR ALL TRAINS.............................
int ac1=0,ac2=10,ac3=10,second_sitting=30,sleeper=250;
//-------------------------------------------------------------------
int i=0;

struct eticket
{
	char name[100];
	char address[100];
	long long int ph;
    char gender[10];
    int age;
    char id[20];
    char pass[20];
	char from[25],To[10];
	int month,day,year,c,s,food,tins;
	char berth[10];
	float total;
}st[100];
 int book(struct eticket st[],int t);
  	    
//FOR SIGNUP-------------------------------------------------------------
void signup()
{
	system("cls");
	if(i<10)
	{
       printf("\n\n*****SIGNUP PORTAL*****\n");
       printf("Enter signup credential:\n(id must be numeric and password must be alphanumeric)\n\n LOGIN ID: ");
       scanf("%s",st[i].id);
       printf(" PASSWORD: ");
       scanf("%s",st[i].pass);
	   int m;
	
       int captcha;
       m=rand()*100;
       printf("\n -------\n");
       printf("|  %d   |\n",m);
       printf(" -------\n");
       printf("\nENTER CAPTCHA: ");
       scanf("%d",&captcha);

       if(captcha==m)
       {
     	printf("\n \t\tSIGNUP SUCESSFULLY\n");
       }
       else
       {
  	    printf("\nINVALID CAPTCHA :( !!PLEASE TRY AGAIN :)");
       }
    }i++;
}
//FOR LOGIN---------------------------------------------------------------

void login()
{
    int Z=0;
	system("cls");
    char identity[20];
    int t,b;
    char p[20];
    system("cls");
    printf("\n****WELCOME TO LOGIN PORTAL*****   \n");
    printf("\nENTER USER ID: ");
    scanf("%s",identity);
    for(t=0;t<i;t++)
	{
  	    if(strcmp(identity,st[t].id)==0)
		{
  		Z=1;
  		printf(" PASSWORD: ");
  		scanf("%s",p);
  		if(strcmp(p,st[t].pass)==0)
		{
  		system("cls");
  		printf("\n\t\tLOGIN SUCESSFULLY :))\n");
  		printf("\n Press 1 to book train else 0: ");
  		scanf("%d",&b);
  		if(b==1)
		{
  			printf("\n");
  			system("cls");
  			book(st,t);
  		}
  		else
	    {
  			system("cls");
  			printf("\n\t hope we meet again :)");
		}
     	}
  		else
  		printf("\n\t\twrong password :(---GALAT HAI PASSWORD--:(\n");
	    }
    }
    if(Z==0)
	  printf("\nINVALID USER ID  :( !! PLEASE TRY AGAIN");
}
//for booking--------------------------------------------------------------------------

int book(struct eticket st[],int t)
{
	int ax=0;
	printf("******TOWARDS BOOKING GATEWAy**********");
	printf("\n----------------------------------------------------------------------\n");
	printf("\n WHERE FROM:");
	scanf("%s",st[t].from);
	printf("\n WHERE TO:");
	scanf("%s",st[t].To);
	printf("\nENTER DATE OF JOURNEY:");
	scanf("%d %d %d",&st[t].day,&st[t].month,&st[t].year);
	printf("\n\n TRAINS RUNNING ON %d:%d:%d ARE AS FOLLOWS:",st[t].day,st[t].month,st[t].year);
	printf("\n ----------------------------------------------------------------------------\n");
	printf("   |SNO.|TRAIN NO | TRAIN NAME        |DEPRT.TIME|ARRIVAL_TIME |TOTAL_DISTANCE|");
	printf("\n |----| --------|-------------------|----------|-------------|--------------|\n");
	printf("\n |1.  | 12309   | RJPB RAJDHANI     | 07:35    | 19:00       |   1001KM     |\n");
	printf("\n |2.  | 12566   | SAMPARK KRANTI    | 05:30    | 19:00       |   998KM      |\n");
	printf("\n |3.  | 14055   | BRAHMPUTRA MAIL   | 04:30    | 20:30       |   1004KM     |\n");
	printf("\n |4.  | 12505   | POORVA EXPRESS    | 02:30    | 07:00       |   1014KM     |\n");
    printf("\n |5.  | 12487   | NORTH EAST EXPRESS| 08:30    | 22:00       |   1087KM     |\n");
    printf("\n ----------------------------------------------------------------------------\n");

	printf("\nSELECT TRAINS FROM ABOVE LIST: ");
	scanf("%d",&st[t].c);
//	system("cls");
    printf("\n\t\t TOTAL SEATS\n");
	printf("\n\t1.AC TIER1\t%d\n\t2.AC TIER2\t%d\n\t3.AC TIER3\t%d\n\t4.SECOND SITTING %d\n\t5.SLEEPER\t%d\n\t6.GENERAL: ",ac1,ac2,ac3,second_sitting,sleeper);
	printf("\n\n\tSELECT COACH: ");
	scanf("%d",&st[t].s);
	printf("\nENTER BERTH PREFERENCE(UPPER/LOWER/MIDDLE): ");
	scanf("%s",st[t].berth);
	printf("\n PRESS 1 for FOOD SERVICE DURING JOURNEY AND 0 FOR NO : ");
	scanf("%d",&st[t].food);
	printf("\n press 1 to take travel safety insurance (just Rs 5) and 0 for no.: ");
	scanf("%d",&st[t].tins);
	if(st[t].c==1||st[t].c==2||st[t].c==3||st[t].c==4||st[t].c==5 &&  st[t].s==1||st[t].s==2||st[t].s==3||st[t].s==4||st[t].s==5||st[t].s==6)
	{
		switch(st[t].c)
		{
			case 1:
			{
				printf("\n |1.  | 12309  | RJPB RAJDHANI | 07:35 | 19:00 | 1001KM |\n\n");
				switch(st[t].s)
				{

					case 1:
					if(ac1>0)
					{
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}
					else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}
					else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
					printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);

					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
					
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
				    
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
					break;
				}
				break;
			}

			case 2:
			{	printf("\n |2.  | 12566| SAMPARK KRANTI| 05:30 | 19:00 | 998KM      |\n");

				switch(st[t].s)
				{

					case 1:if(ac1>0)
					{
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
					
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
					
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						{
						break;
					}
				}

			break;
		}

			case 3:
			{printf("\n |3.  | 14055   | BRAHMPUTRA MAIL   | 04:30    | 20:30       |   1004KM     |\n");

				switch(st[t].s)
				{
					case 1:if(ac1>0)
					{
					
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
						
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
						
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						break;
				}
			break;
		}

			case 4:
			{
					printf("\n |4.  | 12505   | POORVA EXPRESS    | 02:30    | 07:00       |   1014KM     |\n");

				switch(st[t].s)
				{
					case 1:if(ac1>0)
					{
					
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
					
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{

						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:
					if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
					
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else
					{
						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 6:
				    
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						break;
				}
				break;
			}
			case 5:
			{printf("\n |5.  | 12487   | NORTH EAST EXPRESS| 08:30    | 22:00       |   1087KM     |\n");

				switch(st[t].s)
				{
					case 1:if(ac1>0)
					{
						
						ac1--;
						printf("YOUR SEAT NO. IS (AC TIER 1)=%d",ac1);
					}else
					{
						printf("\nAC TRIER 1 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 2:if(ac2>0)
					{
						ac2--;
						printf("YOUR SEAT NO. IS (AC TIER 2)=%d",ac2);
					}else
					{
						printf("\nAC TRIER 2 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 3:if(ac3>0)
					{
					
						ac3--;
						printf("YOUR SEAT NO. IS (AC TIER 3)=%d",ac3);
					}else
					{
						printf("\nAC TRIER 3 = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
					case 4:if(second_sitting>0)
					{
					
						second_sitting--;
						printf("YOUR SEAT NO. IS (2nd sitting)=%d",second_sitting);
					}else
					{
						printf("\nsecond_sitting= O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					}break;
				    case 5:if(sleeper>0)
					{
						sleeper--;
						printf("YOUR SEAT NO. IS (sleeper)=%d",sleeper);
					}else

						printf("\nSleeper = O SEATS AVAILABLE(TICKET CONFIRMATION IS IN WAITING LIST)");
					break;
				    case 6:
					
					printf("\nGENERAL =INFINITE SEATS :)");
					break;
					default:
						break;
				}
				break;
			}
		default:
		 break;
		}
	}else
        {
    	printf("INVAID OPTION");
     	}
     	//system("cls");
	  	 printf("\n***ENTER PASSENGER DETAILS*\n");
		 printf("\nPASSENGER NAME: ");
		 scanf("%s",st[t].name);
		 printf("PHONE NUMBER: ");
		 scanf("%lld",&st[t].ph);
		 printf("ADDRESS: ");
		 scanf("%s",st[t].address);
		 printf("GENDER: ");
		 scanf("%s",st[t].gender);
		 printf("ENTER AGE: ");
		 scanf("%d",&st[t].age);



	  float gst=120;
	  float tfare=0;
	  float fochrg=500;
	  float inschg=5;
	  if(st[t].c==1)
	  {
	  	  if (st[t].s==1)
	  	  { tfare=2250;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2220;
		  }else if(st[t].s==3)
		  {
		  	tfare=2000;
		  }else if (st[t].s==4)
		  {tfare=750;
	      }else if (st[t].s==5)
	      {tfare=560;
		  }else if (st[t].s==6)
		  {tfare=250;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==2)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==3)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==4)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else if (st[t].c==5)
	  	  {
	  	  if (st[t].s==1)
	  	  { tfare=2350;

	  	  }else if (st[t].s==2)
	  	  {
	  		tfare=2020;
		  }else if(st[t].s==3)
		  {
		  	tfare=1900;
		  }else if (st[t].s==4)
		  {tfare=780;
	      }else if (st[t].s==5)
	      {tfare=600;
		  }else if (st[t].s==6)
		  {tfare=150;
		  }
		st[t].total=tfare+gst;
	  }
	  else
	  {
		st[t].total=tfare+gst+fochrg+inschg;
	  }
int choice;
system("cls");
	printf("\n PRESS 1 TO CONTINUE---- \n  OR 0 TO CANCEL CURRNET BOOKING: ");
	scanf("%d",&choice);
	if(choice==1)
	{
   	//system("cls");
	printf("\n**** E-TICKET******\n");
	printf("\n___________\n");
	printf("\n| PASSENGER NAME   :%s      ",st[t].name);
	printf("\n___________\n");
	printf("\n| PHONE NUMBER     :%lld   ",st[t].ph);
	printf("\n___________\n");
	printf("\n| ADDRESS          :%s     ",st[t].address);
	printf("\n___________\n");
	printf("\n| GENDER           :%s     ",st[t].gender);
	printf("\n___________\n");
	printf("\n| AGE              :%d      ",st[t].age);
	printf("\n___________\n");

//fare details-------------------------------------------------------------------------
	printf("\n\n***FARE DETAILS:***\n");
	printf("\n___________\n");
	printf("\n| TICKET FARE: Rs. %f       ",tfare);
	printf("\n|___________\n");
	printf("\n| GST CHARGES: Rs. %f       ",gst);
	printf("\n|___________\n");
	if(st[t].food==1)
	{
	printf("\n| FOOD CHARGES:Rs.500         ");
	printf("\n|___________\n");
	st[t].total=tfare+gst+500;
    }
    else
    {
	printf("\n FOOD CHARGES= Rs. 0          ");
	printf("\n|___________\n");
    st[t].total=tfare+gst;
	}
	if(st[t].tins==1)
	{
	printf("\n| TRAVEL INSURANCE CHARGES=RS.5");
	printf("\n|__________\n");
	
		st[t].total+=5;
	}else
	{
	printf("\n TRAVEL INSURANCE CHARGES=RS.0");
	printf("\n____________\n");
		st[t].total+=0;
	}

	printf("\n| \nTOTAL FARE:Rs.%f        ",st[t].total);
	printf("\n|__________\n");
	
//train details--------------------------------------------------------------------------
	printf("\n\n****TRAIN DETAILS*****\n");

	switch(st[t].c)
		{
			case 1:
	           {
			    printf("TRAIN IS:");
				printf("| 12309  | RJPB RAJDHANI | 07:35 | 19:00 | 1001KM |\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");}
				printf("\nBERTH: %s",st[t].berth);
                break;
			  }
            case 2:
			 {

                printf("TRAIN IS:");
				printf("| 12566   | SAMPARK KRANTI    | 05:30    | 19:00       |   998KM      \n\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");
				}
				printf("\nBERTH: %s",st[t].berth);
                break;
				}
            case 3:
			 {

                printf("TRAIN IS:");
				printf("|| 14055   | BRAHMPUTRA MAIL   | 04:30    | 20:30       |   1004KM     |\n\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");}
			    printf("\nBERTH: %s",st[t].berth);
                break;
	            }
	        case 4:
			    {

                printf("TRAIN IS:");
				printf("\n\n |4.  | 12505   | POORVA EXPRESS    | 02:30    | 07:00       |   1014KM     |\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");
				}
				printf("\nBERTH: %s",st[t].berth);
                break;
				}
            case 5:
				{
				printf("TRAIN IS:");
				printf("| 12487   | NORTH EAST EXPRESS| 08:30    | 22:00       |   1087KM     |\n\n");
				printf("\nCOACH:");
				if(st[t].s==1)
				{printf("AC TIER 1");
				  if(ac1==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac1);
				  }
				}
				else if (st[t].s==2)
				{printf("AC TIER 2");
				  if(ac2==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac2);
				  }
				}
				else if(st[t].s==3)
				{printf("AC TIER 3");
				  if(ac3==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",ac3);
				  }
				}
				else if(st[t].s==4)
				{printf("SECOND SITTING");
				  if(second_sitting==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",second_sitting);
				  }
				}
				else if(st[t].s==5)
				{printf("SLEEPER");
				   if(sleeper==0)
				  {printf("\nTICKET IS IN WAILTING LIST");
				  }else
				  {printf(" CONFERMED :SEAT NO.:%d",sleeper);
				  }
				}
				else
				{
				printf("GENERAL\n** INFINITE SEATS :)**");}
				printf("\nBERTH: %s",st[t].berth);
				printf("\n-----------------------------");
                break;
				}
            default:
			break;
        }

	printf("\n\n**:) HAPPY JOURNEY :)***\n");
	printf("\n-----------------------------");

}
else{
	system("cls");
	printf("\n****WELCOME AGAIN:)*****");
   }
}



int main()
{
	int n;
	for(i>0; ;i++)
	{
		printf("\n");
		printf("1. signup\n");
		printf("2. login\n");
		printf("3. log out\n");
		printf("enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				signup();
				break;
			}
		case 2:
		{
			login();
			break;
		}
		case 3:
		{
			return 0;
			break;
		}
		}
	}
}
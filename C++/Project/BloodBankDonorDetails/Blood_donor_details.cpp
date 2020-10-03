#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
int Ndonor = -1;
class donor
{
private:
    char DName[30], Address[100], Sex, BGroup[3];
    int DNumber, Age;

public:
    void GetData()
    {
        cout << "\n\t\t Enter the Donor Number : ";
        cin >> DNumber;
        cout << "\n\t\t Enter the Donor Name   : ";
        cin >> DName;
        cout << "\n\t\t Enter Donor Address    : ";
        cin >> Address;
        cout << "\n\t\t Enter Age              : ";
        cin >> Age;
        cout << "\n\t\t Enter Sex(m,f)         : ";
        cin >> Sex;
        cout << "\n\n\t\t Enter Blood Group    : ";
        cin >> BGroup;
    }

    void Choice1() // function will tells the person with o+ blood group
    {
        if ((strcmp("o+", BGroup)))
        {
            cout << "\n"
                 << setw(6) << DNumber << setw(20) << DName << setw(30) << Address; //setw() is used to set the width of the o/p
        }                                                                           // if it is not used then then o/p will be concatinate or compressed
    }                                                                               // Ex: without setw() --- 4039harryvspk
    void Choice2()                                                                  //fuction to know the age group b/w 16 to 25         // EX : with using setw() --- 4039   harry    vspk
    {
        if (Age > 16 && Age < 25)
        {
            cout << "\n"
                 << setw(6) << DNumber << setw(20) << DName << setw(30) << Address;
        }
    }

    void Choice3() //function will tells if she is a female then check the blood group and age condition
    {
        if ((Sex == 'f' || Sex == 'F') && (strcmp("a", BGroup)) && (Age > 19 && Age < 24))
        {
            cout << "\n"
                 << setw(6) << DNumber << setw(20) << DName << setw(30) << Address;
        }
    }
};
int main()
{
    donor d[100];       // class <object>
    int Option, i, opt; // opt -- new blood entry and Search(i.e, below switch case)   and   option -- Menu switch case (i.e., for searching)
    char choice, ch;    // choice -- used for to enter Y/N for another Donor    ch -- used for to enter Y/N for Menu
    void Design();      // function for title design
    do
    {
        Design();
        cout << "\n\t\t 1.New Blood Donors Entry \n";
        cout << "\n\t\t 2.Searching\n";
        cout << "\n\t\t Enter Your Choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            do
            {
                Design();
                Ndonor++;
                d[Ndonor].GetData();
                cout << "\n\t\t To Enter Another Donor Press Y... ";
                cout << "Otherwise Press 'N' go back to menu... :";
                cin >> choice;
            } while (choice == 'y' || choice == 'Y');
            break;
        case 2:
            if (Ndonor == -1)
            {
                cout << "\n\t\t No Donors\n";
                break;
            }
            Design();
            cout << "\n\t 1.Blood Donors Having the Blood group O+\n";
            cout << "\n\t 2.Blood Donors in the age between 16 to 25 \n";
            cout << "\n\t 3.Female Donors having Blood Group A in the age between 19 and 24 \n";
            cout << "\n\t Enter Your Choice :";
            cin >> Option;
            Design();
            cout << "\n"
                 << setw(6) << "Donor Number" << setw(20) << "Donor name" << setw(30) << "Donor Address\n";
            switch (Option)
            {
            case 1:
                for (i = 0; i <= Ndonor; i++)
                {
                    d[i].Choice1();
                }
                break;
            case 2:
                for (i = 0; i <= Ndonor; i++)
                {
                    d[i].Choice2();
                }
                break;
            case 3:
                for (i = 0; i <= Ndonor; i++)
                {
                    d[i].Choice3();
                }
                break;
            default:
                cout << "\n\t\t Error!! Enter the Correct Number";
            }
            break;
        default:
            cout << "\n\t\t Error! Enter Choice Correctly..";
        }
        cout << "\n\n\t\t To Continue With Main Menu Press Y...  ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
void Design()
{
    cout << "\n\t\t\t Blood Donor Details \n";
    cout << "\n\t\t\t ******************* \n";
}


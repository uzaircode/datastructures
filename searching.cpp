#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct SEARCHbook
{
    string SEARCHname, SEARCHemail;
    int SEARCHnoTele, SEARCHtarget;
};
int main()
{
    struct SEARCHbook SB;
    int found;

    cout<<"Please enter your name: ";
    getline(cin,SB.SEARCHname);
    cout<<"Please enter your Email: ";
    getline(cin,SB.SEARCHemail);
    cout<<"Please enter your Phone number: ";
    cin>>SB.SEARCHnoTele;


    cout<<endl<<"*#*#*#*#*#*#*#*#*#*#*#*#*#*";
    cout<<endl<<"CHOOSE YOUR BOOK GENRE";
    cout<<endl<<"*#*#*#*#*#*#*#*#*#*#*#*#*#*"<<endl;
    cout<<endl<<"[1] Romance";
    cout<<endl<<"[2] Horror";
    cout<<endl<<"[3] Historical";
    cout<<endl<<"[4] Fantasy";
    cout<<endl<<"[5] Magical Realism";
    cout<<endl<<"[6] Science Fiction";
    cout<<endl<<"[7] Mystery"<<endl;

    cout<<"Enter genre that you want [1-7]: "<<endl;
    cin>>SB.SEARCHtarget;

    found = 0;

    while(SB.SEARCHtarget<7 && found==0)
    {
        if(SB.SEARCHtarget == 1)
        {
            found = 1;
            cout<<"Genre found! ROMANCE";
        }
        else if(SB.SEARCHtarget == 2)
        {
            found = 1;
            cout<<"Genre found! HORROR";
        }
        else if(SB.SEARCHtarget == 3)
        {
            found = 1;
            cout<<"Genre found! HISTORICAL";
        }
        else if(SB.SEARCHtarget == 4)
        {
            found = 1;
            cout<<"Genre found! FANTASY";
        }
        else if(SB.SEARCHtarget == 5)
        {
            found = 1;
            cout<<"Genre found! MAGICAL REALISM";
        }
        else if(SB.SEARCHtarget == 6)
        {
            found = 1;
            cout<<"Genre found! SCIENCE FICTION";
        }
        else if(SB.SEARCHtarget == 7)
        {
            found = 1;
            cout<<"Genre found! MYSTERY";
        }

        cout<<endl<<"User Name: "<<SB.SEARCHname;
        cout<<endl<<"User Email: "<<SB.SEARCHemail;
        cout<<endl<<"User Phone Number: "<<SB.SEARCHnoTele;
        cout<<endl<<"Genre That User Choose: "<<SB.SEARCHtarget;
    }

    cout<<"Genre not found! Sorry:(";


    return 0;
}
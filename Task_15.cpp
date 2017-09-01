#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void Intext()
{
    fstream F;
    F.open("STORY.TXT",ios::out);
    char S[80],CH;
    cout<<"Enter text..."<<endl;
    do
    {
        gets(S);
        F<<S<<endl;
        cout<<"More(Y/N)?";
        cin>>CH;
        CH=toupper(CH);
    }
    while(CH!='N');
    F.close();
}
void Outtext()
{
    fstream F;
    F.open("Story.txt", ios::in);
    char S[80];
    while(F.getline(S,80))
    {
        cout<<S<<endl;
    }
}
void main()
{
    clrscr();
    char Opt;
    do
    {
        cout<<"E:EnterText D:Display Text Q:Quit"<<endl;
        cin>>Opt;
        Opt=toupper(Opt);
        switch(Opt)
        {
                A_Sample_Practical_HandBook_For_XII_Sc_(2017-18)_[Complete_&_get_it_signed_before_30-09-2017] page 44
            case 'E': Intext();
                break;
            case 'D': Outtext();
                break;
        }
    } while (Opt!='Q');
    getch();
}

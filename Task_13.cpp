#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
class BOOK
{
    int Bno;
    char Author[20];
    char Bname[20];
    float Price;
public:
    void Enter()
    {
        cout<<"\nBook Number: ";
        cin>>Bno;
        cout<<"Name of Book: ";
        gets(Bname);
        cout<<"Name of Author: ";
        gets(Author);
        cout<<"Price: ";
        cin>>Price;
    }
    void Display()
    {
        cout<<setw(5)<<Bno
        <<setw(20)<<Bname
        <<setw(20)<<Author
        <<setw(10)<<Price<<endl;
    }
    int RBno(){ return Bno; }
    char* RBname(){ return Bname; }
};

void Disp(BOOK Lib[], int b)
{
    cout<<setw(5)<<"Bno"
    <<setw(20)<<"Bname"
    <<setw(20)<<"Author"
    <<setw(10)<<"Price (Rs.)"<<endl;
    for(int i=0;i<b;i++)
    {
        Lib[i].Display();
        cout<<endl;
    }
}
void Create(BOOK Lib[], int &b)
{
    do
    {
        cout<<"No. of books <=10: "; cin>>b;
    }while((b>10)||(b<1));
    cout<<"Kindly Enter Details...";
    for(int i=0;i<b;i++)
    {
        Lib[i].Enter();
    }
}
void SearchNo(BOOK Lib[], int b, int data)
{
    int found=0;
    for(int i=0;i<b;i++)
    {
        if(data==Lib[i].RBno())
        {
            Lib[i].Display();
            found++;
        }
    }
    if(!found)
        cout<<"Data not found!"<<endl;
}
void SearchName(BOOK Lib[], int b, char name[])
{
    int found=0;
    for(int i=0;i<b;i++)
    {
        if(strcmpi(name,Lib[i].RBname())==0)
        {
            Lib[i].Display();
            found++;
        }
    }
    if(!found)
        cout<<"Data not found!"<<endl;
}
void main()
{
    clrscr();
    BOOK Lib[10];
    char name[20];
    int b, data;
    Create(Lib,b);
    cout<<"\n ### Displaying Library ### \n";
    Disp(Lib, b);
    cout<<"Book No. to be searched : "; cin>>data;
    SearchNo(Lib, b, data);
    cout<<"Book Name to be searched : "; gets(name);
    SearchName(Lib, b, name);
    getch();
}

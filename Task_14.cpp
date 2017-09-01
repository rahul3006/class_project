#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct DATE
{
    int Day;
    int Month;
    int Year;
};

class STUDENT
{
private:
    int Admno;
    char Sname[20];
    DATE DOB;
    
    
public:
    void Input();
    void Disp()
    {
        cout<<setw(7)<<Admno
        <<setw(20)<<Sname
        <<setw(15)<<DOB.Day<<" / "<<DOB.Month<<" / "<<DOB.Year<<endl;
    }
    DATE RDOB(){ return DOB; }
};

void STUDENT::Input()
{
    cout<<"Admno: "; cin>>Admno;
    cout<<"Name: "; gets(Sname);
    cout<<"DOB:- YYYY: ";cin>>(DOB.Year);
    cout<<"MM: "; cin>>DOB.Month;
    cout<<"DD: "; cin>>DOB.Day;
}

void Input(STUDENT Class[], int &n)
{
    do
    {
        cout<<"Enter No. of Students: ";cin>>n;
    }while(n>100);
    for(int i=0;i<n;i++)
    {
        Class[i].Input();
    }
}

void Show(STUDENT Class[], int &n)
{
    cout<<setw(7)<<"Admno"
    <<setw(20)<<"Name"
    <<setw(15)<<"DOB"<<endl;
    for(int i=0;i<n;i++)
    {
        Class[i].Disp();
    }
}

void find(STUDENT Class[], int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
        if(Class[i].RDOB().Year==1990)
            if(Class[i].RDOB().Day==Class[i].RDOB().Month)
                if((Class[i].RDOB().Day==1)||(Class[i].RDOB().Day==2)||(Class[i].RDOB().Day==3))
                { Class[i].Disp();
                    cout<<endl;
                    flag++;
                }
    if(!flag)
        cout<<"No matching data found...";
}

void main()
{
    clrscr();
    STUDENT Class[100]; int n;
    Input(Class,n);
    cout<<endl<<"The Students are:"<<endl;
    Show(Class,n);
    cout<<endl<<endl;
    cout<<"Those Students whos DOB is 1/1/1990, or 2/2/1990 or 3/3/1990:"<<endl;
    find(Class,n);
    getch();
}

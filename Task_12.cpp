#include<iostream> 
#include<stdio.h> 
#include<iomanip.h>
#include<string.h>

using namespace std;

struct DATE {
    int Day, Month, Year;
};

struct STUDENT {
    int Admno;
    char Sname[20];
    DATE DOB;
};


void Input(STUDENT S[], int &n) {
    do {
        cout<<"Enter No. of Students: ";cin>>n;
    }
    while(n>100);
    for(int i=0;i<n;i++) {
        cout<<"\nEnter Details of Student "<<i+1<<" :\n";
        cout<<"Admno: ";
        cin>>S[i].Admno;
        cout<<"Name: ";
        gets(S[i].Sname);
        cout<<"DOB:-\nYear: ";
        cin>>(S[i].DOB.Year);
        cout<<"Month: ";
        cin>>S[i].DOB.Month;
        cout<<"Date: ";
        cin>>S[i].DOB.Day;
    }
}


void Disp(STUDENT S[], int &n) {
    cout<<setw(6)<<"AdmNo."<<setw(20)<<"Name"<<setw(9)<<"DOB\n";
    for(int i=0;i<n;i++)
        cout<<setw(6)<<S[i].Admno<<setw(20)<<S[i].Sname<<setw(3)<<S[i].DOB.Day<<'/'<<setw(2)<<S[i].DOB.Month<<'/'<<setw( 4)<<S[i].DOB.Year<<endl;
}


void Search(STUDENT S[], int n){

    char N[20];
    cout<<"Enter Name of Student to search: ";
    gets(N);
    for(int i=0;i<n;i++)
    if(!(strcmpi(N,S[i].Sname)))
        cout<<"Admno: "<<S[i].Admno<<" ; DOB: "<<S[i].DOB.Day<<'/'<<S[i].DOB.Month<<'/'<<S[i].DOB.Year;
    }


    void find(STUDENT S[], int n) {
        int flag=0;
        for(int i=0;i<n;i++)
            if(S[i].DOB.Year==1990)
                if(S[i].DOB.Day==S[i].DOB.Month) if((S[i].DOB.Day==1)||(S[i].DOB.Day==2)||(S[i].DOB.Day==3)) {
                    flag++;
                    cout<<"Admn No:"<<S[i].Admno<<"\nName:"<<S[i].Sname<<"\nD.O.B:"<<S[i].DOB.Day<<'/'<<setw(2)<<S[i].DOB.Month<<'/'<<setw(4)<< S[i].DOB.Year<<endl;
                }
        
        if(!flag)
            cout<<"No matching entries found!";
    }


    void main() {
        clrscr();
        STUDENT S[100]; int n;
        Input(S,n);
        cout<<"Students are:\n";
        Disp(S,n);
        cout<<endl<<endl;
        Search(S,n);
        cout<<"\nStudents whose DOB is 1/1/1990, or 2/2/1990 or 3/3/1990:\n"; find(S,n);
        getch();
    }

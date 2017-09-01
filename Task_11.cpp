#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<string.h>
struct FLIGHT
{
    int Flno;
    char DepTime[20], ArrTime[20];
    float Fare;
};

void Input(FLIGHT F[], int &n)
{
    do
    {
        cout<<"Enter No. of Flights: "; cin>>n;
    }while(n>100);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Details of Flight "<<i+1<<" : ";
        cout<<"Number: "; cin>>F[i].Flno;
        cout<<"Departure Time: "; gets(F[i].DepTime);
        cout<<"Arrival Time: "; gets(F[i].ArrTime);
        cout<<"Fare: "; cin>>F[i].Fare;
    }
}
void Disp(FLIGHT F[], int n)
{
    cout<<"Number"<<setw(20)<<"DepartureTime"<<setw(21)<<"ArrivalTime"<<setw(12)<<"Fare\n";
    for(int i=0;i<n;i++)
    {
        cout<<setw(6)<<F[i].Flno<<setw(20)<<F[i].DepTime<<setw(21)<<F[i].ArrTime<<setw(12)<<F[i].Fare;
        cout<<endl;
    }
}
void Lowest(FLIGHT F[], int n)
{
    for(int i=0, small=0;i<n;i++)
        if(F[small].Fare>F[i].Fare)
            small=i;
    cout<<"No.: "<<F[small].Flno<<"\nDept Time: "<<F[small].DepTime<<"\nArrivalTime: "<<F[small].ArrTime<<"\nFare:
    "<<F[small].Fare;
}
void main()
{
    clrscr();
    FLIGHT F[100]; int n;
    Input (F,n);
    cout<<"\nFlight Board:\n\n";
    Disp(F,n);
    cout<<"\nFlight with the lowest fare: \n\n";
    Lowest(F,n);
    getch();
}

#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>
#include<string.h>

using namespace std;

struct ACCOUNT{
    int Acno;
    char Name[20];
    float Balance;
};


void Input(ACCOUNT A[], int &n){
    do{
        cout<<"Enter No. of Accounts: ";
        cin>>n;
    }
    while(n>100);
    for(int i=0;i<n;i++){
        cout<<"Enter Details of Account "<<i+1<<" :\n";
        cout<<"Number: ";
        cin>>A[i].Acno;
        cout<<"Name: ";
        cin.ignore();
        cin.getline(A[i].Name, sizeof(A[i]).Name);
        cout<<"Balance: ";
        cin>>A[i].Balance;
    }
}


void Display(ACCOUNT A){
    cout<<'\t'<<A.Acno<<'\t'<<A.Name<<'\t'<<A.Balance;
    cout<<endl;
}

void Display(ACCOUNT A[], int n){
cout<<"Number"<<'\t'<<"Name"<<'\t'<<"Balance"<<endl;
    for(int i=0;i<n;i++){
        Display(A[i]);
    }
}

void Displakh(ACCOUNT A[], int n){
    int flag=0;
    for(int i=0;i<n;i++){
        if(A[i].Balance>100000){
            Display(A[i]);
            flag++;
        }
    }
    if(!flag)
        cout<<"  No records matching this criteria!";
}

int main(){
    system("clear");
    ACCOUNT A[100];
    int n = 0;
    Input(A,n);
    cout<<"\nDisplaying the Accounts:\n\n";
    Display(A,n);
    cin.ignore();
    cin.get();
    system("clear");
    cout<<"\nDisplaying those accounts whose Balance > 100000:\n\n";
    Displakh(A,n);
    
}

#include<iostream>
#include<conio.h>
#include<stdio.h> 
#include<iomanip.h> 
#include<string.h>

using namespace std;


struct CANDIDATE

{
    int Cno, Score; char Cname[20];
};



void Input(CANDIDATE C[], int &n) {
    do
    {
        cout<<"Enter no. of Candidates<=100: ";
        cin>>n;
    }
    while(n>100);
    
    for(int i=0;i<n;i++) {
        cout<<"\nEnter Details of Candidate "<<i+1<<" : "<<endl;
        cout<<"Number: ";
        cin>>C[i].Cno;
        cout<<"Name: ";
        gets(C[i].Cname);
        cout<<"Score: ";
        cin>>C[i].Score;
    }
}

void Disp(CANDIDATE C[], int n) {
    cout<<"Number"<<"Name"<<"Score"<<endl;
    for(int i=0;i<n;i++) {
        cout<<C[i].Cno<<C[i].Cname<<C[i].Score;
        cout<<endl;
    }
}


void Sort(CANDIDATE C[], int n) {
    CANDIDATE temp;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(C[j].Score>C[j+1].Score) {
                temp=C[j]; C[j]=C[j+1]; C[j+1]=temp;
            }
        }
    }
}



int main() {
    system("cls");
    CANDIDATE C[100];
    int n;
    Input(C,n);
    cout<<"\nDisplaying Candidates:"<<endl;
    Disp(C,n);
    Sort(C,n);
    cout<<"\nDisplaying Candidates Sorted on Scores:"<<endl;
    Disp(C,n);
    
}


#include<iostream>
#include<conio.h> 
#include<stdio.h> 
#include<string.h>
using namespace std;

typedef char String[50];
void Create(String[], int&);
void Disp(String[], int);
void BSort(String[], int);
int LSearch(String[], int, String);
int main(){
    system("cls");
    String COU[20],data;
    int N;
    cout<<"Sorted in descending order: "<<endl;
    Disp(COU,N);
    cout<<"Enter data to be searched:";
    gets(data);
    
    int found=LSearch(COU,N,data);
        if(found!=-1)
        cout<<endl<<"Country Registered";
    
          else
            cout<<endl<<"Country not registered";
    getch();
}



void Create(String N[],int& l) {
    cout<<"Enter number of countries: ";
    cin>>l;
    cout<<"Enter names of countries:"<<endl;
        for(int I=0;I<l;I++)
        
            gets(N[I]);
}


void Disp(String N[], int x) {
    cout<<endl<<"COUNTRY NAMES:"<<endl;
        for(int I=0;I<x;I++)
        
            puts(N[I]);
}



void BSort(String N[], int x) {
     for(int I=0;I<x;I++) {
        for(int J=0;J<(x-I-1);J++)
            if(strcmpi(N[J],N[J+1])<0){
            
            String T;
                strcpy(T,N[J]);
                strcpy(N[J],N[J+1]);
                strcpy(N[J+1],T);
        }
     }
}

int LSearch(String A[],int N,String data) {
    int I=0,found=-1;
      while(I<N && found==-1) {
        if(strcmpi(data,A[I])==0) found=I;
         I++;
      }
    return found;
}

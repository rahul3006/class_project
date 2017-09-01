#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void Create( int[], int&);
void Display( int[], int);
void Ssort(int[], int);
bool Bsearch(int[], int, int);
int main(){
    clrscr();
    int N, A[20], Data;
    Create(A,N);
    cout<<"The original array is "<<endl;
    Display(A,N);
    cout<<"The sorted array is "<<endl;
    Ssort(A,N);
    Display(A,N);
    cout<<"Enter the element to be searched: "<<endl;
    cin>>Data;
    int x=Bsearch(A,N,Data);
    if (x!=-1)
        cout<<Data<<" present at location "<<x<<endl;
    else
        cout<<"Not present"<<endl;
    getch();
}
void Create( int A[], int &N){
    int I;
    do{ cout<<"Enter the number of elements<=20: ";
        cin>>N;
    }
    while(N>20);
    cout<<"Enter the elements: ";
    for(I=0; I<N; I++)cin>>A[I];
}
void Display( int A[], int N){
    int I;for(I=0;I<N;I++)cout<<A[I]<<endl;
}
void Ssort(int A[], int N){
    int I,J,Temp,Small;
    for(I=0;I<N-1;I++){
        Small=I;
        for(J=I+1;J<N;J++)
            if(A[J]<A[Small])
Small=J;
        if(Small!=I){
            Temp=A[I];
            A[I]=A[Small];
            A[Small]=Temp;
        }
    }
}
int Bsearch(int A[], int n, int data){
    int Mid,ub=n-1,lb=0,found=-1;
    while((ub>=lb)&&(found==-1)){
        Mid=(lb+ub)/2;
        if(A[Mid]==data)found=Mid;
        else if(A[Mid]<data)
            lb=Mid+1;
else
    ub=Mid-1;

}
    return found;
}


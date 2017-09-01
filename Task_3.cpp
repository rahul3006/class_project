#include<iostream>
using namespace std;

void Create( int A[], int &N) {
    int I;
    do{
        cout<<"Enter the number of elements<=20: ";
        cin>>N;
    }
    while(N>20);
    cout<<"Enter the elements: ";
    for(I=0; I<N; I++)
        cin>>A[I];
}


void Display( int A[], int N){
    int I;
    for(I=0;I<N;I++)
        cout<<A[I]<<endl;
}


void Isort(int A[],int N){
    int I,J,Temp;
    for(I=1;I<N;I++){
        Temp=A[I];
        J=I-1;
        while((Temp<A[J])&&(J>=0)){
            A[J+1]=A[J];
            J--;
        }
        A[J+1]=Temp;
    }
    
}


int Lsearch(int A[], int N, int Data){
    for(int i = 0; i < N; i++){
        if(A[i] == Data)
            return i;
    }
    
    return -1;
}


int main()
{
    system("clear");
    int N, A[20], Data;
    Create(A,N);
    cout<<"The original array is "<<endl;
    Display(A,N);
    cout<<"The sorted array is "<<endl;
    Isort(A,N);
    Display(A,N);
    cout<<"Enter the element to be searched: "<<endl; cin>>Data;
    int x=Lsearch(A,N,Data);
    if (x!=1)
        cout<<Data<<" present at location "<<x<<endl;
    else
            cout<<"Not present"<<endl;

}

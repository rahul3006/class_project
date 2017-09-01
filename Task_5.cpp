#include<iostream>
#include<conio.h>

using namespace std;

void create_matrix(int A[][100], int k, int l) {
    cout<<"\nEnter elements: "<<endl;
    for(int i=0; i<k; i++){
        for(int j=0; j<l; j++)
        cin>>A[i][j];     
    }
}


void disp_matrix(int A[][100], int k, int l ) {
    for(int i=0; i<k; i++) {
        for(int j=0; j<l; j++)
        cout<<A[i][j]<<endl;
    }
}


void sum_matrix(int A[][100], int B[][100], int C[][100], int k, int l){
	for(int i=0; i<k; i++)
        for(int j=0; j<l; j++)
			
            C[i][j]=A[i][j]+B[i][j];
}


void diff_matrix(int A[][100], int B[][100], int C[][100], int k, int l) {
    for(int i=0; i<k; i++)
        for(int j=0; j<l; j++)
			
			C[i][j]=A[i][j]-B[i][j];
}


 int main(){
    
    system("cls");
    
    int X[100][100], Y[100][100], k, l, S[100][100], D[100][100];
    cout<<"Enter no of rows<=100:";
    cin>>k;
	 
    cout<<"Enter no of columns<=100:";
    cin>>l;
    
    cout<<"First matrix: ";
    create_matrix(X,k,l);
    
    cout<<"Second matrix: ";
    create_matrix(Y,k,l);
  
    cout<<"\nFirst matrix: "<<endl;
    disp_matrix(X,k,l);
    
    cout<<"\nSecond matrix: "<<endl;
    disp_matrix(Y,k,l);
    
    sum_matrix(X,Y,S,k,l);
    cout<<"\nSum of both matrices: "<<endl;
    disp_matrix(S,k,l);
    
    diff_matrix(X,Y,D,k,l);
    cout<<"\nDifference of both matrices: "<<endl;
    disp_matrix(D,k,l);
    
}

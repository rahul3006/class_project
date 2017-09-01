#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstdlib>

using namespace std;


double sqrRoot(double m){
    double eps=1.0e-7, l1, l2, h;
    if(m>1){
        l1=1;
        l2=m;
    }
    else if(m>0){
        l1=m;
        l2=1;
    }
    else{
        cout<<"Square root of -tive number does not exist!";
        cin.get();
        exit(0);
    }
    
    
    for(h=(l1+l2)/2;
        eps<fabs(h*h-m);
        h=(l1+l2)/2){
        h*h>m ? l2=h : l1=h;
    }
    return h;
}



int* createArray(int size){
    static int arr[1000];
    
    // Get current time
    unsigned int sval = (unsigned)time(0);
    // seed random number generator
    srand(sval);
    for(int i = 0; i < size; i++){
        arr[i] = rand();
    }
    for(int i=0; i<size; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    
    return arr;
}



void revEachWord(char *s){
    void revWord(char *, char *);//Fn prototype to reverse a word
    char *word_begin = s;
    char *word_end = s;
    while(*word_end) //As ling as word_end is not NULL (i.e. '\0') { word_end++;
        if(*word_end == '\0'){
            revWord(word_begin, word_end-1);
        }
        else if(*word_end == ' '){
            revWord(word_begin, word_end-1);
            word_begin = word_end+1;
        }
} // End of while loop






/* End of revEachWord()*/
/*Fn to reverse a sub-string from pointer begin to pointer end */



void revWord(char *begin, char *end){
    
    while(begin < end){
        char temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
/* End of revWord()*/


int main(){
    system("clear");
    double sqrRoot(double);
    void createArray(int *, int, int);
    void revEachWord(char *);
    char ch;
    int choice;
    
    do{
        cout<<"\nMAIN MENU\n";
        cout<<"1. Find Square Root\n";
        cout<<"2. Create an Array of m Distinct Random Numbers\n";
        cout<<"3. Reverse Each Word of a String\n";
        cout<<"4. Exit\n";
        cout<<"Enter, Your Choice(1-4): ";
        cin>>choice;
        
        
        switch(choice){
            case 1 : double num;
                cout<<"Enter Number: ";
                cin>>num;
                cout<<"Square root: "<<sqrRoot(num)<<endl;
                ch=cin.get();
                break;
 
            
            
            case 2 : int ub,lb, ar[100];
                cout<<"Enter Lower Limit of Random Number range: ";
                cin>>lb;
                cout<<"Enter Upper Limit of Random Number range: ";
                cin>>ub;
                createArray(ar, lb, ub);
                ch=cin.get();
                break;
                
                
                
            case 3 : char *str1;
                cout<<"Enter, a string: ";
                gets(str1);
                revEachWord(str1);
                ch=cin.get();
        }
    }
    
    while(choice<4);
}




#include<iostream.h>
#include<conio.h>
#include<stdio.h>
typedef char String[50];


void Count(String N)
{
    int V=0,C=0,D=0;
    for(int I=0; N[I]!='\0';I++)
    {
        if((N[I]>='A'&& N[I]<='Z') || (N[I]>='a'&& N[I]<='z'))
            switch(N[I])
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                V++;
                break;
            default:
                C++;
        }
        else if(N[I]>='0' && N[I]<='9')
            D++;
    }
    cout<<"No. of vowels= "<<V<<endl;
    cout<<"No. of consonents= "<<C<<endl;
    cout<<"No. of digits= "<<D<<endl;
}



void Rev(String N)
{
    String R;
    for(int L=0; N[L]!='\0'; L++);
    L--;
    for(int C=0; L>=0; C++,L--)
        R[C]=N[L];
    R[C]='\0';
    cout<<"Reversed string is "<<R;
}

void main()
{
    clrscr();
    String A;
    cout<<"Enter String: ";
    gets(A);
    Count(A);
    Rev(A);
    getch();
}

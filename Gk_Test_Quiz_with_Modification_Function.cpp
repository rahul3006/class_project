//
//  Gk_Test_Quiz_with_Modification_Function.cpp
//  
//
//  Created by Rahul Thukral on 03/10/17.
//
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>

class QUIZ{
private:
    int qno;
    char qdesc[50];
    char choice1[10];
    char choice2[10];
    char choice3[10];
    char choice4[10];
    char correctans;
    
public:
    
    void getdata(){
        cout<<endl;
        cout<<"question no:";cin>>qno;
        cout<<"question :";gets(qdesc);
        cout<<"choice 1:";gets(choice1);
        cout<<"choice 2:";gets(choice2);
        cout<<"choice 3:";gets(choice3);
        cout<<"choice 4:";gets(choice4);
        cout<<"correct ans :";cin>>correctans;
        cout<<endl;
    }
    
    
    void putdata(){
        
        cout<<qdesc<<endl<<endl;
        cout<<"a)"<<choice1<<setw(25)<<"b)"<<choice2<<endl;
        cout<<"c)"<<choice3<<setw(25)<<"d)"<<choice4;
    }
    
    
    int rQno(){
        
        return qno;
    }
    
    
    char rCorrectans(){
        
        return correctans;
    }
    
};


void inputq(){
    
    QUIZ q;
    int ch=0,ch1;
    fstream f;
    f.open("Quiz.txt",ios::binary|ios::out|ios::in);
    f.seekg(0);
    
    cout<<"enter the no of question you want to enter : ";
    cin>>ch1;
    
    while(ch<ch1){
        
        q.getdata();
        f.write((char*)&q,sizeof(q));
        ++ch;
    }
    
    f.close();
    
}


void randomq(int *ar){   //to generate and store random numbers in array
    
    int m,i=0,searchRes;
    char ch;
    randomize();
    QUIZ q;
    
    fstream f;
    f.open("Quiz.txt",ios::binary|ios::in);
    
    while(i<10){
        f.clear();
        f.seekg(0,ios::beg);
        searchRes=0;
        m=random(50)+1;
        while(!f.eof()){
            
            f.read((char*)&q,sizeof(q));
            if(m==q.rQno()){
                
                for(int j=0; j<=i; j++){
                    if(m==ar[j]) searchRes=1;
                }
                
                if(searchRes==0) ar[i++]=m;
            }
            
        }
    }
    
    f.close();
    
}//end of randomq function

QUIZ q;
int d;

ifstream f;
f.open("Quiz.txt",ios::binary);
ofstream f2;
f2.open("Temp.txt",ios::out|ios::binary);

cout<<"enter ques no you want to delete : ";
cin>>d;

while(f.read((char*)&q,sizeof(q))){
    if(q.rQno()!=d)
        f2.write((char*)&q,sizeof(q));
        }

cout<<"qno " <<d<<" deleted successfully.";
f2.close();
f.close();
remove("Quiz.txt");
rename("Temp.txt","Quiz.txt");

}


void modifyrecord(){    //to modify a record in binary file
    fstream f;
    QUIZ q;
    int found=0,m;
    f.open("Quiz.txt",ios::binary|ios::in);
    cout<<"enter ques no you want to modify : ";
    cin>>m;
    cout<<endl<<"qno "<<m<<" is : ...."<<endl;
    
    f.clear();
    f.seekg(0,ios::beg);
    
    while(f.read((char*)&q,sizeof(q)) && found==0){
        
        if(q.rQno()==m){
            q.putdata();
            cout<<endl<<"\nEnter The New Details of question.";
            q.getdata();
            int pos=-1*sizeof(q);
            
            f.seekp(pos,ios::cur);
            f.write((char*)&q,sizeof(q));
            
            found=1;
            
            cout<<"qno " <<m<<" modified successfully.";
        }
    }
    
    if(found) cout<<"Question not found";
    
    f.close();
    
}//end of modify function


void DisplayAll(){       //to display all the records of binary file
    
    
    QUIZ q;
    
    fstream f;
    f.open("Quiz.txt",ios::binary|ios::in);
    
    cout<<endl;
    
    while(f.read((char *)&q,sizeof(q))){
        q.putdata();
        cout<<endl;
    }
    
    f.close();
    getch();
    
}//end of displayall function


void quiz (){     //to display the quiz
    
    
    int *ar,wrong=0,skip=0,score=0,correct=0,count=1,Qno=0 ;
    char ans,cont;
    
    fstream f;
    f.open("Quiz.txt",ios::binary|ios::in|ios::out);
    
    QUIZ q;
    
    cout<<setw(50)<<" GK TESTING QUIZ";
    cout<<"\nINSTRUCTIONS:";
    cout<<"\n1.The quiz contains 10 multiple choice questions";
    cout<<"\n2.Enter answer in form of 'a','b','c','d' only.";
    cout<<"\n3. Any other response will be treated as incorrect.";
    cout<<"\n4.On every correct ans you will get 4 points";
    cout<<" and 0 for every incorret answer.";
    cout<<"\n5. You can type 's' to skip the question.";
    cout<<endl<<"\nLets Play."<<endl;
    getch();
    
    randomq(ar);
    
    for(int i=0;i<10;i++){
        f.clear();
        f.seekg(0,ios::beg);
        
        while(!f.eof()){
            
            f.read((char*)&q,sizeof(q));
            if(ar[i]==q.rQno()){
                ++Qno;
                
                cout<<endl<<Qno<<")";
                q.putdata();
                
                cout<<endl<<endl<<"enter answer : ";
                cin>>ans;
                
                if(ans!='s'){
                    if(q.rCorrectans()==ans){
                        score+=10;
                        ++correct ;
                        cout<<" $$ correct ans! $$ "<<endl;
                    }
                    
                    else{
                        cout<<" XX wrong ans! XX "<<endl;
                        ++wrong;
                    }
                }
                
                
                else if (ans=='s'){
                    ++skip;
                    cout<<"question is skipped."<<endl;
                    --count;
                }
                
            }
        }
        
        
        
        if(i<9){
            cout<<"want to continue(y/n)";
            cin>>cont;
            cont=tolower(cont);
            
            if(cont=='n') break;
            else ++count;
        }
    }
    
    
    cout<<endl<<"your result:"<<endl;
    cout<<"score:" <<score<<endl;
    cout<<"questions attempted:"<<count<<endl;
    cout<<"skipped:"<<skip<<endl;
    cout<<"correct:"<<correct<<endl;
    cout<<"wrong:"<<wrong;
    
    f.close();
    
}//end of play function


void main(){
    
    system("cls");
    char choice;
    int option;
    do{
        
        system("cls");
        cout<<endl<<endl<<"E : Edit \nP : play\nD : displayall\nQ : quit";
        cout<<endl<<"enter your choice: ";
        cin>>choice;
        
        choice=toupper(choice);
        
        if(choice=='E'){
            
            cout<<endl<<endl<<"Editing :"<<endl;
            cout<<"1: Delete.";
            cout<<endl<<"2: Modify";
            cout<<endl<<"3: Input"<<endl;
            cout<<"enter your choice :";
            cin>>option;
            cout<<endl;
            
            
            if(option==1) deleterecord();
            else if(option==2) modifyrecord();
            else if(option==3) inputq();
        }
        
        else if(choice=='P')
        {
            quiz();
            getch();
        }
        
        else if(choice=='D')
        {
            DisplayAll();
        }
        
    } while(choice!='Q');
    
}



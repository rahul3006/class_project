//
//  Diff_eq_Eulers_Method.cpp
//  
//
//  Created by Rahul Thukral on 20/11/17.
//

#include <stdio.h>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float f(float(x),float(y)){
    return (-y);
}

int main(){
    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i,m;
    float h;
    cout<<"Given Equation is dy/dx = -y "<<endl;
    cout<<"Enter the number of Iterations "<<endl;
    cin>>n;
    cout<<"Enter The Value of Step Size (h)"<<endl;
    cin>>h;
    double y[n],x[n];
    cout<<"Enter the value of x0 "<<endl;
    cin>>x[0];
    cout<<"Enter The Value of y0 "<<endl;
    cin>>y[0];
    for(i=1;i<=n;i++){
        x[i]=x[i-1]+h;
    }
    
    for(i=1;i<=n;i++){
        
        y[i]=y[i-1]+(h*f(x[i-1],y[i-1]));
    }
    
    for(m=0;m<=56;m++) cout<<"-";
    
    cout<<"\niteration No"<<setw(10)<<"x"<<setw(15)<<"y"<<endl;
    for(m=0;m<=56;m++) cout<<"-";
    cout<<"\n";
    for(i=1;i<=n;i++){
        
        cout<<setw(5)<<i<<setw(20)<<x[i]<<setw(15)<<y[i]<<endl;
    }
    for(m=0;m<=56;m++) cout<<"-";
    cout<<"\n";
    return 0;
}


//output//
Last login: Mon Nov 20 00:38:16 on ttys000
Rahuls-MacBook-Air:~ rahul$ cd desktop
Rahuls-MacBook-Air:desktop rahul$ ls
Alpha-OS            Eulers Method Diff Eq.cpp    Quiz_rahul.cpp            Shop.dat            gkquiz.pdf            quiz.pdf
Apple_Inc            Eulers Method Diff Eq.hpp    Quiz_rahul.hpp            Untitled 2.pages        machine prob.cpp.save        quiz_app2.cpp
C++                QUIZ copy.cpp            Rahul Research Paper.pages    a.out                myprogram.cpp.save        rrp.pdf
CalculusVolume1-OP.pdf        QUIZ.cpp            Rahul Tax.docx            aarushi.pages            questions.numbers        shubham.pages
Diff_eq_Eulers_Method.cpp    QUIZ.hpp            Rahul's Coding            cpp-codes-master-5

Rahul's Github id            Convex_Optimisation.pdf            Sigmoid_Function.Cpp(Details)

Rahuls-MacBook-Air:desktop rahul$ g++ Diff_eq_Eulers_Method.cpp
Rahuls-MacBook-Air:desktop rahul$ ./a.out
Given Equation is dy/dx = -y
Enter the number of Iterations
5
Enter The Value of Step Size (h)
100
Enter the value of x0
12
Enter The Value of y0
12
---------------------------------------------------------
iteration No         x              y
---------------------------------------------------------
1            112.0000     -1188.0000
2            212.0000    117612.0000
3            312.0000  -11643588.0000
4            412.0000 1152715196.0000
5            512.0000 -114118800964.0000
---------------------------------------------------------
Rahuls-MacBook-Air:desktop rahul$











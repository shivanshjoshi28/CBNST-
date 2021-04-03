//g++ -c -Wall -fPIC .\Bisection_method.cpp 
// (command to convert .o file from Bisection_method.cpp that can be further used to convert to .so file )



// g++ -shared -o .\Bisection_method.so .\Bisection_method.o
// (command to convert .o file to .so file)


// gcc -L -Wall main.c -o main .\Bisection_method.so .\pbPlots.c .\supportLib.c -lm
// (command to convert main.c to main.exe using .o and .so file )


#include <iostream>
#include<cmath>
#include<regex>
#include<sstream>
#include<cstring>
using namespace std;
extern "C" int thirdcoef=0,secondcoef=0,firstcoef=0,num=0,coeftrig=0;
extern "C" string trig="";
extern "C" double f1(double a)
{
    double rada=3.14159*a/180;
    if(trig=="cos")
    {
        return ((thirdcoef*rada*rada*rada)+(secondcoef*rada*rada)+(firstcoef*rada)+num+(coeftrig*cos(rada)));
    }
    else if(trig=="")
    {
        return ((thirdcoef*a*a*a)+(secondcoef*a*a)+(firstcoef*a)+num);
    }
    else
        return ((thirdcoef*rada*rada*rada)+(secondcoef*rada*rada)+(firstcoef*rada)+num+(coeftrig*sin(rada)));
}
extern "C" void startBisection()
{
    printf("*** Bisection Method ***\n");
    printf("Enter the equation(3x^3+x^2-2x-6 =0) Not Transcendtal you want to find roots : \n");
    thirdcoef=0;
    secondcoef=0;
    firstcoef=0;
    num=0;
    coeftrig=5;
    trig="";
    double a,b;

    string s;
    cin>>s;
    vector<int>v;
    int pluspos=0;
    int minuspos=0;
    while(s.find('+',pluspos+1)<s.length()|| s.find('-',minuspos+1)<s.length())
    {
        // cout<<"pluspos="<<pluspos<<endl;         //debugging purpose
        pluspos=s.find('+',pluspos+1);
        minuspos=s.find('-',minuspos+1);
        if(pluspos<s.length())
        {
            // cout<<"+ is present at location : "<<pluspos<<endl;     //debugging purpose
            // s[pluspos]='.';
            v.push_back(pluspos);
        }
        if(minuspos<s.length())
        {
            // cout<<"- is present at location : "<<minuspos<<endl;     //debugging purpose
            // s[minuspos]='.';
            v.push_back(minuspos);
        }
        if(minuspos>s.length()) minuspos=s.length()-1;
        if(pluspos>s.length()) pluspos=s.length()-1;
    v.push_back(s.find('='));
    int start=0;
    for(int i=0;i<v.size();i++)
    {
        string str="";
        for(int j=start;j<v[i];j++)
        {
            str+=s[j];
        }
        // cout<<str<<endl;         //debugging purpose
        start=v[i];
        if(str.find("x^3")<str.length())
        {
            string num="";
            for(int i=0;i<str.find("x^3");i++)
            {
                num+=str[i];
            }
            if(num=="+" || num=="")
                thirdcoef=1;
            else if(num=="-")
                thirdcoef=-1;

            else
            {
                stringstream ss(num);
                ss>>thirdcoef;
            }
        }
        else if(str.find("x^2")<str.length())
        {
            string num1="";
            for(int i=0;i<str.find("x^2");i++)
            {
                num1+=str[i];
            }
            if(num1=="+" || num1=="")
                secondcoef=1;
            else if(num1=="-")
                secondcoef=-1;

            else
            {
                stringstream ss(num1);
                ss>>secondcoef;
            }
        }

        else if(str.find("x")<str.length())
        {
            string num1="";
            for(int i=0;i<str.find("x");i++)
            {
                num1+=str[i];
            }
            if(num1=="+" || num1=="")
                firstcoef=1;
            else if(num1=="-")
                firstcoef=-1;
            else
            {
                stringstream ss(num1);
                ss>>firstcoef;
            }
        }
        else
        {
            stringstream ss(str);
            ss>>num;
        }
    }
    }


    cout<<"According to You The coefficients are : \n";
    cout<< "secondcoef = "<<secondcoef<<endl;
    cout<< "thirdcoef = "<<thirdcoef<<endl;
    cout<< "firstcoef = "<<firstcoef<<endl;
    cout<< "num = "<<num<<endl;




    while(1)
    {
        cout<<"Enter the approximate range :: ";
        cin>>a>>b;
        if(f1(a)*f1(b)>0)
        {
            cout<<"Please Try again "<<endl;
        }
        else if(f1(a)==0)
        {
            cout<<"Root is "<<a<<endl;
            exit(0);
            break;
        }
        else if(f1(b)==0)
        {
            cout<<"Root is "<<b<<endl;
            exit(0);
            break;
        }
        else
        {
            break;
        }

    }

        int iter;
        double tol;
        cout<<"Enter the iteration and tolerance :";
        cin>>iter>>tol;
        for(int i=0;i<iter ;i++)
        {
            double c=double((a+b)/2.0);    // bisection formula 

            double temp=c;
             cout<<"At "<<i+1<< " temp= "<<temp<<endl;
            if(f1(c)==0)
            {
                cout<<"Root is : "<<c<<endl;
                exit(0);
                break;
                exit(0);
            }
            if(f1(a)*f1(c)<0)
            {
                b=c;
            }
            else 
            {
                a=c;
            }
            c=double((a+b)/2.0);


            if(fabs(temp-c)<tol)
            {
                cout<<"temp= "<<temp<<" c= "<<c<<"iter = "<<i+1<<"difference"<<fabs(temp-c)<<endl;
                cout<<"Got final answer as "<<c<<endl;
                exit(0);
                break;
            }
            else
            {
                cout<<"In iteration no. "<<i+1<<" we have a= "<<a<<" and b= "<<b<<" and got c as "<<c<<endl;
            }
            
        }
        cout<<"Sorry your equation can't be solved ... Please increase the no. of iteration !! It might help You !!";
}




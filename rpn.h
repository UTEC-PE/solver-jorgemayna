#include <iostream>
#include "stack.h"
#include "queue.h"
#include <string>
using namespace std;


int p(string s)
{
    if(s=="(")
    {
        return 1;
    }
    if(s=="+" || s=="-")
    {
        return 2;
    }
    if(s=="*" || s=="/")
    {
        return 3;
    }
    if(s=="^")
    {
        return 4;
    }
}
void compare(string a,Queue<string>& s_rpn,Stack<string>& oper)
{
    while(!oper.empty())
    {
        if(a==")")
        {
            while(oper.peek()!="(")
            {
                s_rpn.push_back(oper.peek());
                oper.pop();
            }
            oper.pop();
            break;
        }
        else if(a=="(")
        {
            oper.push(a);
            break;
        }
        else if(a=="^" && oper.peek()=="^")
        {
            oper.push(a);
            break;
        }else if(p(oper.peek())>=p(a))
        {
            s_rpn.push_back(oper.peek());
            oper.pop();
        }else
        {
            oper.push(a);
            break;
        }
    }
    if(oper.empty())
    {
        oper.push(a);
    }

}

void toRPN(string s,Queue<string>& s_rpn,Stack<string>& oper)
{
    system("cls");
    cout<<"==========================================================="<<endl;
    cout<<"\t\tPractica Operaciones"<<endl;
    cout<<"==========================================================="<<endl;
    cout<<endl;
    cout <<"* Operacion en formato infijo:      ";
    cout <<s<<endl;
    string ca,res;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<=122 && s[i]>=97)
        {
            ca=s[i];
            cout<<ca<<" = ";
            cin>>res;

            while(s.find(ca)!=s.npos)
            {
                int ff=s.find(ca);
                s.replace(ff,1,res);
            }
        }
    }
    cout <<"                                    "<<s<<endl<<endl;
    cout<<"==========================================================="<<endl;

    string f="";
    int i=0;
    bool num,operan;
    while(i<s.length())
    {
        num=false; f=""; operan=false;
        while((48<=s[i] && s[i]<=57) || s[i]==46)
        {
            f=f+s[i];
            i++;
            num=true;
        }
        if(num)
        {
            s_rpn.push_back(f);
        }

        char a=s[i];

        while(s[i]=='+' || s[i]=='-')
        {
            operan=true;
            if(s[i+1]==a)
            {
                a='+';
            }else if(s[i+1]=='+' || s[i+1]=='-')
            {
                a='-';
            }else
            {
                break;
            }
            i++;
        }
        if(operan)
        {
            f=a;
            compare(f,s_rpn,oper);
        }
        f=s[i];
        switch(s[i])
        {
        case '*':
            compare(f,s_rpn,oper);
        break;
        case '/':
            compare(f,s_rpn,oper);
        break;
        case '(':
            compare(f,s_rpn,oper);
        break;
        case ')':
            compare(f,s_rpn,oper);
        break;
        case '^':
            compare(f,s_rpn,oper);
        break;


        }
        i++;

    }
    while(!oper.empty())
    {
        s_rpn.push_back(oper.peek());
        oper.pop();
    }

}

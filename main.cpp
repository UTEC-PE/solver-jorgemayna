#include <iostream>
#include "stack.h"
#include "queue.h"
#include <string>
#include "rpn.h"
using namespace std;
double operar(string s,double a,double b)
{
    if(s=="+")
    {
        return a+b;
    }
    if(s=="-")
    {
        return a-b;
    }
    if(s=="*")
    {
        return a*b;
    }
    if(s=="/")
    {
        return a/b;
    }
    if(s=="^")
    {
        double sol=1;
        for(int i=0;i<b;i++)
        {
            sol=sol*a;
        }
        return sol;
    }
}
void solve(Queue<string>& s_rpn,Stack<double>& numbers)
{
    string sol;
    double operand_1,operand_2;
    int si=s_rpn.size();
    for(int i=0;i<si;i++)
    {
        sol=s_rpn.front();
        if(sol=="+" || sol=="-" || sol=="*" || sol=="/" || sol=="^")
        {
            operand_2=numbers.peek();
            numbers.pop();
            operand_1=numbers.peek();
            numbers.pop();
            numbers.push(operar(sol,operand_1,operand_2));
        }else
        {
            numbers.push(double(stoi(sol)));
        }
        s_rpn.pop_front();
    }
}

void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;
      cout<<endl;
      cout<<"Elija una operacion:"<<endl;
      cout<<"7/4*((a+b)*a)+3"<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      char* str="7/4*((a+b)^4*a)+3";
      Stack<double> stack;
      Queue<string> queue;



}

int main(int argc, char const *argv[]) {
    //menu();
    string a="7/4*((a+b)^4*a)+3";
    string ca,res;
    cout <<a<<endl;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]<=122 && a[i]>=97)
        {
            ca=a[i];
            cout<<ca<<" = ";
            cin>>res;

            while(a.find(ca)!=a.npos)
            {
                int ff=a.find(ca);

                //a.erase(ff);
                a.replace(ff,1,res);
                //a.insert(ff,res);
            }

        }
    }
    cout<<endl;
    cout <<a<<endl;

    Queue<string> s_rpn;
    Stack<string> oper;

    toRPN(a,s_rpn,oper);
    oper.clear();
    s_rpn.print();

    Stack<double> numbers;
    solve(s_rpn,numbers);
    numbers.print();



    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}


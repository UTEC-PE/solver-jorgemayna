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
    // Qué sucede si no entras a ninguno de tus ifs, no retornas nada?
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
            numbers.push(stod(sol));
        }
        s_rpn.pop_front();
    }
}

int menu() {
    // No me está funcionando con la mayoría de ecuaciones
    // Prueba con este caso (17*3/2-a)^b    a=5, b=1  Respuesta => 20.5
      system("cls");
      int op;
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;
      cout<<endl;
      cout<<"Elija una opcion:"<<endl;
      cout<<"1) 7/4*((a+b)*a)+3"<<endl; // Las funciones las estás repitiendo, podrías usar el string de abajo para imprimirlas
      cout<<"2) 7/4*((a+-+--b)*a)+3"<<endl; // No me funciona en muchos casos
      cout<<"3) 2+(3)"<<endl;
      cout<<"4) 7/4*((a+b)^4*a)+3"<<endl;
      cout<<"5) Ingrese su propia operacion"<<endl;
      cin>>op;
      return op;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      //char* str="7/4*((a+b)^4*a)+3";
      Stack<double> stack;
      Queue<string> queue;



}

int main(int argc, char const *argv[]) {

    string a;
    switch(menu())
      {
        case 1: a="7/4*((a+b)*a)+3";
        break;
        case 2: a="7/4*((a+-+--b)*a)+3";
        break;
        case 3: a="2+(3)";
        break;
        case 4: a="7/4*((a+b)^4*a)+3";
        break;
        case 5:
            cout <<endl;
            cout<<"Ingrese la operacion:  "<<endl;
            cin>>a;
        break;
      }
    Queue<string> s_rpn;
    Stack<string> oper;

    toRPN(a,s_rpn,oper);
    oper.clear();
    cout<<"Operacion en formato posfijo(RPN):   ";
    s_rpn.print();

    Stack<double> numbers;
    solve(s_rpn,numbers);
    cout <<endl<<endl<<"            Solucion:  ";
    numbers.print();



    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}


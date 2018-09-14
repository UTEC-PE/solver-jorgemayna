#include <iostream>
#include "stack.h"
#include "queue.h"
#include <string>
using namespace std;

void toRPN(string s,Queue<string>& s_rpn,Stack<string>& oper)
{


}

void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

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

    Queue<string> s_rpn;
    Stack<string> oper;

    toRPN(a,s_rpn,oper);

    s_rpn.print();

    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}


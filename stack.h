#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"



using namespace std;

template <typename T>
class Stack {
    private:
        Node<T>* head;
        Node<T>* tail;

        int nodes;

    public:
        Stack();

        void push(T value);

        void pop();

        T peek();

        bool empty();
        int size();
        void print();

        void clear();


        ~Stack();
};

template<class T> Stack<T>::Stack()
{
    head=nullptr;
    nodes=0;

}
template<typename T> int Stack<T>::size()
{
    return nodes;
}

template<typename T> bool Stack<T>::empty()
{
    bool a=true;
    if(head==nullptr)
    {
        return a;
    }else{
        return !a;
    }
}

template<typename T> void Stack<T>::push(T value)
{
    Node<T>* temp = new Node<T>;
    temp->data=value;

    if (head==nullptr)
    {

        head=temp;
        head->next=nullptr;

    }
    else
    {
        temp->next=head;
        head=temp;
    }
    nodes++;
    temp=nullptr;




}
template<typename T> void Stack<T>::pop()
{
    if(nodes==1)
    {
        delete head;
        head=nullptr;


    }else{
        Node<T>* temp=head->next;
        delete head;
        head=temp;
        temp=nullptr;
    }
    nodes--;
}
template<typename T> T Stack<T>::peek()
{

    return head->data;

}


template<typename T> void Stack<T>::clear()
{
    if(!empty())
    {
        while(head!=nullptr)
        {
            pop();
        }
        nodes=0;



    }



}



template<typename T> void Stack<T>::print()
{
    Node<T>* temp;
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

template<class T> Stack<T>::~Stack()
{
    clear();

}
#endif

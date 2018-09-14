#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"



using namespace std;

template <typename T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;

        int nodes;

    public:
        Queue();

        T front();
        T back();
        void push_back(T value);
        void pop_front();
        bool empty();
        int size();
        void print();
        void clear();


        ~Queue();
};

template<class T> Queue<T>::Queue()
{
    head=nullptr;
    tail=nullptr;
    nodes=0;

}
template<typename T> T Queue<T>::front()
{

    return(head->data);

}

template<typename T> T Queue<T>::back()
{

    return(tail->data);

}
template<typename T> int Queue<T>::size()
{
    return nodes;
}

template<typename T> bool Queue<T>::empty()
{
    bool a=true;
    if(head==nullptr)
    {
        return a;
    }else{
        return !a;
    }
}
template<typename T> void Queue<T>::pop_front()
{
    if(head!=tail)
    {
        Node<T>* temp=head->next;
        delete head;
        head=temp;
        temp=NULL;
    }else{

        delete head;
        delete tail;
        head=nullptr;
        tail=nullptr;
    }
}

template<typename T> void Queue<T>::push_back(T value)
{

    Node<T>* temp = new Node<T>;
    temp->data=value;
    temp->next=nullptr;
    if (tail==nullptr)
    {
        tail=temp;
        head=tail;
    }else{

        tail->next=temp;
        tail=temp;
    }
    nodes++;
    temp=nullptr;
}


template<typename T> void Queue<T>::clear()
{
    if(!empty())
    {
        while(head!=nullptr)
        {
            pop_front();
        }
        nodes=0;



    }



}



template<typename T> void Queue<T>::print()
{
    Node<T>* temp;
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

template<class T> Queue<T>::~Queue()
{
    clear();

}
#endif

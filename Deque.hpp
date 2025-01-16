#ifndef LINKED_DEQUE
#define LINKED_DEQUE
#include "DLinkedList.hpp"
#include "RuntimeExcept.hpp"
#include "EmptyExcept.hpp"
#include <iostream>

template <typename E> class LinkedDeque{
    public:
        LinkedDeque():D(), nElm(0){}
        int size() const {return nElm;}
        bool empty() const {return nElm==0;}
        const E &front() const noexcept(false);
        const E &back() const noexcept(false);
        void insertFront(const E &e);
        void insertBack(const E &e);
        void removeFront() noexcept(false);     
        void removeBack() noexcept(false);
        void print();
    private:
        int nElm;
        DLinkedList<E> D;
};

template <typename E> const E &LinkedDeque<E>::front() const noexcept(false){
    if(empty()){
        throw EmptyExcept("Front of empty deque");
    }
    return D.front();
}
template <typename E> const E &LinkedDeque<E>::back() const noexcept(false){
    if(empty()){
        throw EmptyExcept("Back of empty deque");
    }
    return D.back();
}

template <typename E> void LinkedDeque<E>::insertFront(const E &e){
    D.addFront(e);
    nElm++;
}
template <typename E> void LinkedDeque<E>::insertBack(const E &e){
    D.addBack(e);
    nElm++;
}
template <typename E> void LinkedDeque<E>::removeFront() noexcept(false){
    if(empty()){
        throw EmptyExcept("removeFront of empty deque");
    }
    D.removeFront();
    nElm--;
}
template <typename E> void LinkedDeque<E>::removeBack() noexcept(false){
    if(empty()){
        throw EmptyExcept("removeBack of empty deque");
    }
    D.removeBack();
    nElm--;
}

template <typename E> void LinkedDeque<E>::print(){
    LinkedDeque<E> p;
    while(!empty()){
        std::cout<<front()<<" ";
        p.insertFront(front());
        removeFront();
    }
    while(!p.empty()){
        insertFront(p.front());
        p.removeFront();
    }
    std::cout<<std::endl;
}

#endif
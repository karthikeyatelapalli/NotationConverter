#ifndef DLINKEDLIST
#define DLINKEDLIST

#include "DNode.hpp"

template <typename E> class DLinkedList{
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const E &front() const;
        const E &back() const;
        void addFront(const E &e);
        void addBack(const E &e);
        void removeFront();
        void removeBack();
        int getSize() { return nElm; }
    private:
        int nElm = 0;
        DNode<E> *header;
        DNode<E> *trailer;
    protected:
        void add(DNode<E> *v, const E &e);
        void remove(DNode<E> *v);
};

template <typename E> DLinkedList<E>::DLinkedList(){
    header=new DNode<E>;
    trailer=new DNode<E>;
    header->next=trailer;
    trailer->prev=header;
}
template <typename E> bool DLinkedList<E>::empty() const{
    return header->next==trailer;
}
template <typename E> const E &DLinkedList<E>::front() const{
    return header->next->elm;
}
template <typename E> const E &DLinkedList<E>::back() const{
    return trailer->prev->elm;
}
template <typename E> DLinkedList<E>::~DLinkedList(){
    while(!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}
template <typename E> void DLinkedList<E>::add(DNode<E> *v, const E &e){
    DNode<E> *u = new DNode<E>;
    u->elm=e;
    u->next=v;
    u->prev=v->prev;
    u->prev->next=u;
    v->prev=u;
    nElm++;
}
template <typename E> void DLinkedList<E>::remove(DNode<E> *v){
    DNode<E> *u = v->prev;
    DNode<E> *w = v->next;
    u->next=w;
    w->prev=u;
    delete v;
    nElm--;
}

template <typename E> void DLinkedList<E>::addFront(const E &e){
    add(header->next, e);
}
template <typename E> void DLinkedList<E>::addBack(const E &e){
    add(trailer, e);
}
template <typename E> void DLinkedList<E>::removeFront(){
    remove(header->next);
}
template <typename E> void DLinkedList<E>::removeBack(){
    remove(trailer->prev);
}

#endif
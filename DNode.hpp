#ifndef DNODE
#define DNODE

template <typename E> class DNode {
    public:
        DNode(){}
    private:
        E elm;
        DNode<E> *prev;
        DNode<E> *next;
    template <typename T> friend class DLinkedList;
};
#endif
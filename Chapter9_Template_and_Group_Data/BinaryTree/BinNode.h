//
// Created by gedsH on 2020/8/20.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINNODE_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINNODE_H

#define stature(p) ((p) ? (p)->height : -1)

template <class T>
class BinNode{
public:
    BinNode<T> *parent, *lChild, *rChild;
    T data;
    int height;

    BinNode();
    BinNode(T e, BinNode<T> *p = nullptr, BinNode<T> *lc = nullptr, BinNode<T> *rc = nullptr);
    int size(); // 以当前节点为根的后代总数(包括当前节点)
    BinNode<T>* insertAsLC(const T& e);
    BinNode<T>* insertAsRC(const T& e);
};

template <class T>
BinNode<T>::BinNode() {
    height = 0;
    parent = nullptr;
    lChild = nullptr;
    rChild = nullptr;
}

template <class T>
BinNode<T>::BinNode(T e, BinNode<T> *p, BinNode<T> *lc, BinNode<T> *rc) {
    data = e;
    parent = p;
    lChild = lc;
    rChild = rc;
}

template <class T>
BinNode<T>* BinNode<T>::insertAsLC(const T &e) {
    return lChild = new BinNode<T>(e, this);
}

template <class T>
BinNode<T>* BinNode<T>::insertAsRC(const T &e) {
    return rChild = new BinNode<T>(e, this);
}

template <class T>
int BinNode<T>::size() {
    int s = 1;
    if(lChild) s += lChild->size();
    if(rChild) s += rChild->size();
    return s;
}



#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINNODE_H

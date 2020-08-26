//
// Created by gedsH on 2020/8/20.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINNODE_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINNODE_H

#define stature(p) ((p) ? (p)->height : -1) // 若为空树, 则高度为-1

template <class T>
class BinNode{
public:
    BinNode<T> *parent, *lChild, *rChild; // 父节点; 左孩子; 右孩子;
    T data;
    int height; // 节点在树中的高度, 该成员变量在BinTree中随着树的生长而更新. 单个节点的高度定义为0, 空节点的高度为-1.

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
    height = 0;
    data = e;
    parent = p;
    lChild = lc;
    rChild = rc;
}

template <class T>
BinNode<T>* BinNode<T>::insertAsLC(const T &e) {
    return lChild = new BinNode<T>(e, this); // 完成三件事：指定父节点, 创建新节点, 指定左孩子
}

template <class T>
BinNode<T>* BinNode<T>::insertAsRC(const T &e) {
    return rChild = new BinNode<T>(e, this); // 完成三件事：指定父节点, 创建新节点, 指定右孩子
}

/** @brief 返回节点的degree, 即其所有子节点个数(包括该节点自身)
 * */
template <class T>
int BinNode<T>::size() {
    int s = 1;
    if(lChild) s += lChild->size();
    if(rChild) s += rChild->size();
    return s;
}



#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINNODE_H

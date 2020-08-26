//
// Created by gedsH on 2020/8/21.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINTREE_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINTREE_H

#include "BinNode.h"
#include <math.h>

template <class T>
class BinTree{
protected:
    int size_;
    BinNode<T>* root_;
    virtual int updateHeight(BinNode<T>* p); // 定义为虚方法, 允许其派生类进行重写
    void updateHeightAbove(BinNode<T>* p);

public:
    BinTree():size_(0), root_(nullptr){}
    int size();
    bool empty();
    BinNode<T>* root();
    BinNode<T>* insertAsRC(BinNode<T>* p, const T& e);
    BinNode<T>* insertAsLC(BinNode<T>* p, const T& e);
    BinNode<T>* insertAsRoot(const T& e);
};

template <class T>
int BinTree<T>::updateHeight(BinNode<T> *p) {
    // 单个节点高度定义为 1
    return p->height = 1 + std::fmax(stature(p->lChild), stature(p->rChild)); // 节点高度 = 子节点高度最大者 + 1
}

template <class T>
void BinTree<T>::updateHeightAbove(BinNode<T> *p) {
    int old_height, new_height;
    while (p){ // 如果节点为空, 则停止更新高度
        old_height = p->height;
        new_height = updateHeight(p);
        if(old_height == new_height)
            break; // 如果高度不变化, 则停止更新高度
        else
            p = p->parent;
    }
}

template <class T>
int BinTree<T>::size() {
    return size_;
}

template <class T>
bool BinTree<T>::empty(){
    return size_ <= 0 ;
}

template <class T>
BinNode<T>* BinTree<T>::root(){
    return root_;
}

template <class T>
BinNode<T>* BinTree<T>::insertAsLC(BinNode<T>* p, const T& e){
    size_++;
    p->insertAsLC(e);
    updateHeightAbove(p);
    return p->lChild;
}

template <class T>
BinNode<T>* BinTree<T>::insertAsRC(BinNode<T>* p, const T& e){
    size_++;
    p->insertAsRC(e);
    updateHeightAbove(p);
    return p->rChild;
}

template <class T>
BinNode<T>* BinTree<T>::insertAsRoot(const T &e) {
    size_ = 1;
    return root_ = new BinNode<T>(e);
}
#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINTREE_H

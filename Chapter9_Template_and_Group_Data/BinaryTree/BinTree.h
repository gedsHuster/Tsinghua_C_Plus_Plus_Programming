//
// Created by gedsH on 2020/8/21.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINTREE_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINTREE_H

#include "BinNode.h"
#include <math.h>
#include "Stack/StackV2.h"
#include "Queue/queue.h"

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

    template<class VST> void PreTraverse_Recursion(BinNode<T>* x, VST& visit);
    template<class VST> void PreTraverse_IterateV1(BinNode<T>* x, VST& visit);
    template<class VST> void visitAlongLeftBranch(BinNode<T>* x, VST& visit, StackV2<BinNode<T>*>& S);
    template<class VST> void PreTraverse_IterateV2(BinNode<T>* x, VST& visit);

    template<class VST> void InTraverse_Recursion(BinNode<T>* x, VST& visit);
    void goAlongLeftBranch(BinNode<T>* x, StackV2<BinNode<T>*>& S);
    template<class VST> void InTraverse_Iterate(BinNode<T>* x, VST& visit);

    template<class VST> void PostTraverse_Recursion(BinNode<T>* x, VST& visit);
    void goAlongLeftBranchForPostTraverse(BinNode<T>* x, StackV2<BinNode<T>*>& S);
    template<class VST> void PostTraverse_Iterate(BinNode<T>* x, VST& visit);

    template<class VST> void LevelTraverse(BinNode<T>* x, VST& visit);
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

/** @brief 递归遍历整个树(先序遍历)
 * */
template<class T> template<class VST>
void BinTree<T>::PreTraverse_Recursion(BinNode<T> *x, VST& visit) {
    if(!x) return;  // 终止条件
    visit(x->data); // 先序遍历, 根节点
    PreTraverse_Recursion(x->lChild, visit); // 左子树
    PreTraverse_Recursion(x->rChild, visit); // 右子树
}

/** @brief 先序遍历-迭代版本1.0
 * */
template<class T> template<class VST>
void BinTree<T>::PreTraverse_IterateV1(BinNode<T> *x, VST &visit) {
    StackV2<BinNode<T>*> S; // 创建一个存储节点指针的栈
    if(x) S.push(x);
    while(!S.empty()){
        x = S.pop();
        visit(x->data);     // 访问节点数据
        // 由于是先序遍历(V L R), 且栈是先进后出的, 因此右孩子先入栈, 后访问
        if(x->rChild) S.push(x->rChild); // 如果有右孩子, 则将其入栈
        if(x->lChild) S.push(x->lChild); // 如果有左孩子, 则将其入栈
    }
}

template<class T> template<class VST>
void BinTree<T>::visitAlongLeftBranch(BinNode<T>* x, VST &visit, StackV2<BinNode<T>*>& S) {
    while (x){ // 沿着左链依次访问节点
        visit(x->data);
        S.push(x->rChild); // 将右孩子入栈, 即使为空也入栈, 因为后续空节点进入该函数只是“走过场”
        x = x->lChild;     // 沿着左孩子向下移动, 直到左孩子为空
    }
}


template<class T> template<class VST>
void BinTree<T>::PreTraverse_IterateV2(BinNode<T> *x, VST &visit) {
    StackV2<BinNode<T>*> S; // 创建栈, 用于记录右孩子
    while(true){
        visitAlongLeftBranch(x, visit, S);
        if(S.empty()) break; // 循环终止条件
        x = S.pop();         // 弹出栈中的一个右孩子, 在沿着左链依次访问
    }
}

template<class T> template<class VST>
void BinTree<T>::InTraverse_Recursion(BinNode<T> *x, VST &visit) {
    if(!x) return;
    if(x->lChild) InTraverse_Recursion(x->lChild, visit);
    visit(x->data);
    if(x->rChild) InTraverse_Recursion(x->rChild, visit);
}

/** @brief 沿着左侧边逐步深入, 且左孩子均入栈, 以方便后续自低向上逐次访问左孩子
 * */
template<class T>
void BinTree<T>::goAlongLeftBranch(BinNode<T> *x, StackV2<BinNode<T> *> &S) {
    while (x){
        S.push(x);
        x = x->lChild;
    }
}

/** @brief 中序遍历(L V R)-迭代版本, 时间复杂度O(n)
 *         从中序遍历的规则和过程可以看出这样的规律, 即左侧边最深处节点最先被访问, 其次是该节点的右子树
 *         因此可将左侧边节点自顶向下压入栈中, 然后访问顶部节点, 最后将节点切换成右子树, 以转交控制权, 并以相同方式遍历
 * */
template<class T> template<class VST>
void BinTree<T>::InTraverse_Iterate(BinNode<T> *x, VST &visit) {
    StackV2<BinNode<T>*> S;
    while (true){
        goAlongLeftBranch(x, S);
        if(S.empty()) break;
        x = S.pop();
        visit(x->data);
        x = x->rChild;
    }
}

/** @brief 后序遍历(L R V)--递归形式
 * */
template<class T> template<class VST>
void BinTree<T>::PostTraverse_Recursion(BinNode<T> *x, VST &visit) {
    if(!x) return;
    if(x->lChild) PostTraverse_Recursion(x->lChild, visit);
    if(x->rChild) PostTraverse_Recursion(x->rChild, visit);
    visit(x->data);
}

template<class T>
void BinTree<T>::goAlongLeftBranchForPostTraverse(BinNode<T> *x, StackV2<BinNode<T> *> &S) {
    while (x){ // 如果右节点为非空
        S.push(x);
        if(!x->lChild && x->rChild)
            x = x->rChild; // 若只有右孩子, 也要将右孩子入栈, 因为右孩子被访问的优先级高于其父节点
        else
            x = x->lChild;
    }
}

template<class T> template<class VST>
void BinTree<T>::PostTraverse_Iterate(BinNode<T> *x, VST &visit) {
    StackV2<BinNode<T>*> S;
    while(true){
        goAlongLeftBranchForPostTraverse(x, S);
        if(S.empty()) break;
        x = S.pop();
        visit(x->data);
        if(x->parent == nullptr)
            break;       // x的父节点为空, 则x为根节点
        else if(x->parent->rChild == x)
            x = nullptr; //  如果x本身作为其父节点的右孩子, 那么下一步要访问的是其父节点, 因此可令x为空, 待会goAlong只走个过场, 然后直接pop栈中早已入栈的父节点
        else
            x = x->parent->rChild;// 若x为其父节点的左孩子, 则控制权转交给父节点的右孩子
    }
}

/** @brief 层次遍历 - 按照自上而下, 自左而右的顺序遍历
 *         由于层次遍历中, 父节点一定先于子节点被访问, 左孩子一定先于右孩子被访问,
 *         所以不存在"逆序"情况, 故可利用队列结构存储节点.
 *
 * */
template<class T> template<class VST>
void BinTree<T>::LevelTraverse(BinNode<T> *x, VST &visit) {
    Queue<BinNode<T>*> Q; // 创建队列
    Q.enqueue(x);         // 将树根节点插入队列尾部
    while(!Q.empty()){    // 若队列为空, 则结束遍历
        x = Q.dequeue();  // 取出队首元素
        visit(x->data);   // 访问队首元素
        if(x->lChild) Q.enqueue(x->lChild); // 若存在左孩子, 则将左孩子插入队尾
        if(x->rChild) Q.enqueue(x->rChild); // 若存在右孩子, 则将右孩子插入队尾
    }
}

#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_BINTREE_H

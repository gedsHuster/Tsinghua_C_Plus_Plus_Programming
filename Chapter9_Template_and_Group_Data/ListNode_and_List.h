//
// Created by gedsH on 2020/8/14.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_LISTNODE_AND_LIST_NODETEST_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_LISTNODE_AND_LIST_NODETEST_H

#include <iostream>

/** @brief 定义节点类, 以便后续构造链表
 * */
template <class T>
class ListNode{
public:
    ListNode<T>* pred;  // 前驱节点
    ListNode<T>* succ;  // 后继节点
    T data;             // 节点的数据域
    ListNode() ;
    ListNode(const T& e, ListNode<T>* pred_ = NULL, ListNode<T>* succ_ = NULL);

    ListNode<T>* insertElemAsPredNode(const T& e);
    ListNode<T>* insertElemAsSuccNode(const T& e);
};

/** @brief 节点类的构造函数
 * */
template <class T>
ListNode<T>::ListNode() {}

/** @brief 节点类的构造函数
 *  @param e 节点中数据
 *  @param pred_ 前驱节点
 *  @param succ_ 后继节点
 * */
template <class T>
ListNode<T>::ListNode(const T& e, ListNode<T> *pred_, ListNode<T> *succ_) {
    data = e;
    pred = pred_;
    succ = succ_;
}

/** @brief 在当前节点之前插入数据元素, 并构造新的节点
 *  @param e 待插入的数据元素
 * */
template <class T>
ListNode<T>* ListNode<T>::insertElemAsPredNode(const T &e) {
    ListNode<T>* node_ptr = new ListNode<T>(e, pred, this);
    pred->succ = node_ptr;
    pred = node_ptr;
    return node_ptr;
}

/** @brief 在当前节点之后插入数据元素, 并构造新的节点
 *  @param e 待插入的数据元素
 * */
template <class T>
ListNode<T>* ListNode<T>::insertElemAsSuccNode(const T &e) {
    ListNode<T>* node_ptr = new ListNode<T>(e, this, succ);
    succ->pred = node_ptr;
    succ = node_ptr;
    return node_ptr;
}

/** @brief 链表类
 * */
template <class T>
class List{
private:
    int size_;              // 链表元素数量
    ListNode<T>* header;    // 链表头哨兵节点
    ListNode<T>* trailer;   // 链表尾哨兵节点
protected:
    void init();                             // 用于构造
    int clear();                             // 用于析构
    void copyNodes(ListNode<T>* p, int num); // 用于复制构造
public:
    List();
    ~List();
    List(const List<T> &L);
    List(const List<T> &L, int pos, int num);
    List(ListNode<T>* p, int num);

    int size() const;
    bool empty() const;
    bool valid(ListNode<T>* p) const;
    ListNode<T>* first() const;
    ListNode<T>* last() const;
    ListNode<T>* operator[](int pos) const;


    ListNode<T>* insertElemAsFirstNode(const T& e);
    ListNode<T>* insertElemAsLastNode(const T& e);
    ListNode<T>* insertElemAfterNode(ListNode<T>* p, const T& e);
    ListNode<T>* insertElemBeforeNode(ListNode<T>* p, const T& e);

    T remove(ListNode<T>* p);

    void traverse(void (*visit) (T&));
};

/** @brief 初始化List类的成员变量, 用于构造新的链表
 * */
template <class T>
void List<T>::init() {
    size_ = 0;
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer; header->pred = nullptr;
    trailer->pred = header; trailer->succ = nullptr;
}

/** @brief 删除链表中的所有节点, 用于析构整个链表
 * */
template <class T>
int List<T>::clear() {
    int old_size = size_;
    while(0 < size_)
        remove(header->succ);
    return old_size;
}

/** @brief 复制给定节点后的num个节点到链表的尾部, 用于复制构造新的链表
 *  @param p 待复制的第一个节点
 *  @param num 需要复制的节点数目
 * */
template <class T>
void List<T>::copyNodes(ListNode<T> *p, int num) {
    init();
    while(num--){
        insertElemAsLastNode(p->data);
        p = p->succ;
    }
}

template <class T>
List<T>::List() {
    init();
}

template <class T>
List<T>::~List(){
    clear();
    delete header;
    delete trailer;
}

template <class T>
List<T>::List(const List<T>& L) {
    copyNodes(L.first(), L.size_);
}

template <class T>
List<T>::List(const List<T>& L, int pos, int num) {
    copyNodes(L[pos], num);
}

template <class T>
List<T>::List(ListNode<T>* p, int num) {
    copyNodes(p, num);
}

template <class T>
int List<T>::size() const {
    return size_;
}

template <class T>
bool List<T>::empty() const {
    return size_ <= 0;
}

template <class T>
bool List<T>::valid(ListNode<T> *p) const {
    return p && (header != p) && (trailer != p);
}

template <class T>
ListNode<T>* List<T>::first() const{
    return header->succ;
}

template <class T>
ListNode<T>* List<T>::last() const {
    return trailer->pred;
}

template <class T>
ListNode<T>* List<T>::operator[](int pos) const {
    ListNode<T> *p;
    if(pos >= 0){
        p = first();
        while (0 < pos--)
            p = p->succ;
    }else if(pos < 0){
        p = last();
        while (-1 > pos++)
            p = p->pred;
    }
    return p;
}

template <class T>
ListNode<T>* List<T>::insertElemAsFirstNode(const T &e) {
    size_++;
    return header->insertElemAsSuccNode(e);
}

template <class T>
ListNode<T>* List<T>::insertElemAsLastNode(const T &e) {
    size_++;
    /** 注意！ 一定是trailer前插, 不是header前插! 否则段错误, 因为header->pred无定义, 故那段内存被保护 **/
    return trailer->insertElemAsPredNode(e);
}

template <class T>
ListNode<T>* List<T>::insertElemAfterNode(ListNode<T> *p, const T &e) {
    size_++;
    return p->insertElemAsSuccNode(e);
}

template <class T>
ListNode<T>* List<T>::insertElemBeforeNode(ListNode<T> *p, const T &e) {
    size_++;
    return p->insertElemAsPredNode(e);
}

template <class T>
T List<T>::remove(ListNode<T> *p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    size_--;
    return e;
}

template <class T>
void List<T>::traverse(void (*visit)(T &)) {
    for(ListNode<T>* p = header->succ; p != trailer; p = p->succ)
        (*visit)(p->data);
}

#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_LISTNODE_AND_LIST_NODETEST_H

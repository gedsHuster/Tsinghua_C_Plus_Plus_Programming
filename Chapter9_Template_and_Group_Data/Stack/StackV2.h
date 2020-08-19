//
// Created by gedsH on 2020/8/19.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACKV2_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACKV2_H

#include "List/ListNode_and_List.h"

template <class T>
class StackV2: public List<T>{
public:
    StackV2();
    void push(const T& item);
    T pop();
    bool empty();
    T top();

};

template <class T>
StackV2<T>::StackV2() {
}

template <class T>
void StackV2<T>::push(const T &item) {
    List<T>::insertElemAsLastNode(item);
}

template <class T>
T StackV2<T>::pop(){
    return List<T>::remove(List<T>::last());
}

template <class T>
bool StackV2<T>::empty(){
    return List<T>::empty();
}

template <class T>
T StackV2<T>::top() {
    return List<T>::last()->data;
}

#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACKV2_H

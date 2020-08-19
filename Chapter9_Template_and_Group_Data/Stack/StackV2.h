//
// Created by gedsH on 2020/8/19.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACKV2_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACKV2_H

#include "List/ListNode_and_List.h"

template <class T>
class StackV2: public List<T>{
public:
    StackV2(){}
    void push(const T& item){List<T>::insertElemAsLastNode(item);}
    T pop(){return List<T>::remove(List<T>::last());}
    T top(){return List<T>::last()->data;}

};

#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACKV2_H

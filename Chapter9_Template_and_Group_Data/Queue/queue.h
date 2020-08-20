//
// Created by gedsH on 2020/8/20.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_QUEUE_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_QUEUE_H

#include <Stack/StackV2.h>

template <class T>
class Queue: public List<T>{
public:
    Queue(){}
    void enqueue(const T& e){List<T>::insertElemAsLastNode(e);} // 插入
    T dequeue(){return List<T>::remove(List<T>::first());}      // 删除
    T rear(){return List<T>::last()->data;}                     // 尾部元素
    T front(){return List<T>::first()->data;}                   // 首部元素
};

#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_QUEUE_H

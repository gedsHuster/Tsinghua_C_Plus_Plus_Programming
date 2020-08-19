//
// Created by gedsH on 2020/8/16.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACK_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACK_H

#include <assert.h>
#include <iostream>

template <class T, int SIZE=50>
class Stack{
private:
    int top;
    T list[SIZE];
public:
    Stack();
    void push(T item);     // 压入栈
    T pop();               // 弹出栈
    void clear();          // 清空栈
    const T& peek() const; // 返回栈顶数据
    bool isEmpty() const;  // 判断栈是否为空
    bool isFull() const;   // 判断栈是否为满
};

template <class T, int SIZE>
Stack<T,SIZE>::Stack(){
    top = -1;
}

template <class T, int SIZE>
void Stack<T,SIZE>::push(T item){
    assert(!isFull());
    list[++top] = item;
}

template <class T, int SIZE>
T Stack<T,SIZE>::pop(){
    assert(!isEmpty());
    return list[top--];
}

template <class T, int SIZE>
void Stack<T,SIZE>::clear(){
    top = -1;
}

template <class T, int SIZE>
const T& Stack<T,SIZE>::peek() const {
    return list[top];
}

template <class T, int SIZE>
bool Stack<T,SIZE>::isEmpty() const {
    return top == -1;
}

template <class T, int SIZE>
bool Stack<T,SIZE>::isFull() const {
    return top == SIZE-1;
}
#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_STACK_H

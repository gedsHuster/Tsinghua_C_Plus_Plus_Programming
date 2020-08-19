//
// Created by gedsH on 2020/8/16.
//

#include "Stack.h"
int main()
{
    Stack<int,4> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    int item = 4;
    stack1.push(item);

    std::cout << "isFull: " << stack1.isFull() << std::endl;

    while (!stack1.isEmpty()){
        std::cout << stack1.peek() << " ";
        std::cout << stack1.pop() << std::endl;
    }
    std::cout << "isEmpty: " << stack1.isEmpty() << std::endl;

    return 0;
}
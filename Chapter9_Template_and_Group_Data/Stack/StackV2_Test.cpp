//
// Created by gedsH on 2020/8/19.
//

#include "StackV2.h"
template <class T>
void print(T& item){
    std::cout << item << ",";
}

int main()
{
    StackV2<int> stackV2;
    std::cout << stackV2.empty() << std::endl;

    stackV2.push(5);
    stackV2.traverse(print);
    std::cout << "\n";

    stackV2.push(3);
    stackV2.traverse(print);
    std::cout << "\n";

    std::cout << stackV2.pop() << std::endl;
    stackV2.traverse(print);
    std::cout << "\n";

    stackV2.push(7);
    stackV2.traverse(print);
    std::cout << "\n";

    stackV2.push(3);
    stackV2.traverse(print);
    std::cout << "\n";

    std::cout << stackV2.top() << std::endl;
    stackV2.traverse(print);
    std::cout << "\n";

    std::cout << stackV2.empty() << std::endl;
    stackV2.traverse(print);
    std::cout << "\n";

    stackV2.push(11);
    stackV2.traverse(print);
    std::cout << "\n";

    std::cout << stackV2.size() << std::endl;
    stackV2.traverse(print);
    std::cout << "\n";

    return 0;
}
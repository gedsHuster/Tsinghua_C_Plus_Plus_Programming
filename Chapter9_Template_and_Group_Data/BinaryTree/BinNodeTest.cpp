//
// Created by gedsH on 2020/8/20.
//

#include "BinNode.h"
#include <iostream>
int main()
{
    BinNode<int> binNode1, binNode2, binNode3;
    binNode1.data = 1;
    binNode2.data = 2;
    binNode3.data = 3;

    binNode2.parent = &binNode1;
    binNode1.lChild = &binNode2;

    binNode3.parent = &binNode1;
    binNode1.rChild = &binNode3;

    std::cout << "size: " << binNode1.size() << std::endl;
    std::cout << "data: " << binNode1.data << std::endl;
    std::cout << "lChild data: " << binNode1.lChild->data << std::endl;
    std::cout << "rChild data: " << binNode1.rChild->data << std::endl;

    return 0;
}
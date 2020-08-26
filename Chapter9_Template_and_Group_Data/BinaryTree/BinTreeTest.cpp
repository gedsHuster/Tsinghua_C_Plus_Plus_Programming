//
// Created by gedsH on 2020/8/21.
//

#include "BinTree.h"
#include <iostream>

int main()
{
    BinTree<int> tree;
    std::cout << tree.empty() << std::endl;
    std::cout << tree.size() << std::endl;
//    tree.insertAsRoot(0);
//    std::cout << tree.empty() << std::endl;
//    std::cout << "tree size: " << tree.size() << std::endl;

    BinNode<int> node(-1);
    std::cout << "node size: " << node.size() << std::endl;
    tree.insertAsLC(&node, 1);
    tree.insertAsRC(&node, 2);
    std::cout << tree.empty() << std::endl;
    std::cout << "tree size: " << tree.size() << std::endl;
    std::cout << "node height: " << node.height << std::endl;
    std::cout << "node size: " << node.size() << std::endl;
    std::cout << "node lChild: " << node.lChild->data << std::endl;
    std::cout << "node rChild: " << node.rChild->data << std::endl;
    std::cout << "node : " << node.lChild->parent->data << std::endl;
    std::cout << "node : " << node.rChild->parent->data << std::endl;

    return 0;
}

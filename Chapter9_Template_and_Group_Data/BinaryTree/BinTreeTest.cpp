//
// Created by gedsH on 2020/8/21.
//

#include "BinTree.h"
#include <iostream>

template<class T>
void print(const T &e){
    std::cout << e << ", ";
}

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

    //   -1
    //  1   2

    std::cout << "Pre-traverse recursion version..." << std::endl;
    tree.PreTraverse_Recursion(&node, print<int>);
    std::cout << std::endl;

    std::cout << "Pre-traverse iterate version 1..." << std::endl;
    tree.PreTraverse_IterateV1(&node, print<int>);
    std::cout << std::endl;

    std::cout << "Pre-traverse iterate version 2..." << std::endl;
    tree.PreTraverse_IterateV2(&node, print<int>);
    std::cout << std::endl;

    std::cout << "In-traverse recursion version..." << std::endl;
    tree.InTraverse_Recursion(&node, print<int>);
    std::cout << std::endl;

    std::cout << "In-traverse iterate version..." << std::endl;
    tree.InTraverse_Iterate(&node, print<int>);
    std::cout << std::endl;

    std::cout << "Post-traverse recursion version..." << std::endl;
    tree.PostTraverse_Recursion(&node, print<int>);
    std::cout << std::endl;

    std::cout << "Post-traverse iterate version..." << std::endl;
    tree.PostTraverse_Iterate(&node, print<int>);
    std::cout << std::endl;

    std::cout << "Level-traverse ..." << std::endl;
    tree.LevelTraverse(&node, print<int>);
    std::cout << std::endl;

    return 0;
}

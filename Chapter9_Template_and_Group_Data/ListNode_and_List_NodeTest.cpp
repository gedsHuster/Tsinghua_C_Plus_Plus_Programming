//
// Created by gedsH on 2020/8/14.
//
/**@brief  测试节点
 * @author geds
 * @date 2020-08-14
 * */
#include "ListNode_and_List.h"
int main()
{
    ListNode<int> node1(1, nullptr, nullptr);
    ListNode<int> node3(3, nullptr, nullptr);
    ListNode<int> node2(2, &node1, &node3);

    std::cout << node1.data << " " << node2.data << " "  << node3.data <<  std::endl;
    std::cout << node2.pred->data << " " << node2.data<< " " << node2.succ->data << std::endl;

    ListNode<int> *node_succ;
    node_succ = node2.insertElemAsSuccNode(4);
    std::cout << node_succ->data << std::endl;
    std::cout << node_succ->pred->data << std::endl;
    std::cout << node_succ->succ->data << std::endl << std::endl;

    ListNode<int> *node_pred;
    node_pred = node2.insertElemAsPredNode(5);
    std::cout << node_pred->data << std::endl;
    std::cout << node_pred->pred->data << std::endl;
    std::cout << node_pred->succ->data << std::endl << std::endl;
    return 0;
}
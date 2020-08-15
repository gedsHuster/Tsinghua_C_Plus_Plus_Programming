//
// Created by gedsH on 2020/8/14.
//

#include "ListNode_and_List.h"

template <class T>
void printNode(T& n){
    std::cout << n << " ";
}

int main()
{
    /** 初始化 **/
    std::cout << "初始化链表...\n\n";
    List<int> list1;

    /** 插入 **/
    std::cout << "向链表中插入元素, 首部插入, 尾部插入...\n";
    list1.insertElemAsLastNode(1);
    list1.insertElemAsLastNode(2);
    list1.insertElemAsLastNode(3);
    list1.insertElemAsFirstNode(0);
    list1.insertElemAsFirstNode(-5);
    list1.insertElemAsFirstNode(-1);
    list1.insertElemAsFirstNode(-2);
    list1.insertElemAsFirstNode(-3);
    int pos = 0;
    for(ListNode<int>* p= list1.first(); pos < list1.size(); pos++){
        std::cout << p->data << " ";
        p = p->succ;
    }
    std::cout << "\n\n";

    /** 索引 **/
    std::cout << "正向循环索引打印链表中的所有元素...\n";
    for(int i = 0; i < list1.size(); i++){
        std::cout << list1[i]->data << " ";
    }
    std::cout << "\n逆向循环索引打印链表中的所有元素...\n";
    for(int i = -1; i > -list1.size() - 1; i--){
        std::cout << list1[i]->data << " ";
    }
    std::cout << "\n\n";

    /** 遍历 **/
    std::cout << "遍历打印链表中的所有元素...\n";
    list1.traverse(printNode);
    std::cout << "\n\n";

    /** 链表尺寸, 状态, 首/尾元素, 正/逆序检索 **/
    std::cout << "输出链表尺寸, 状态, 首/尾元素, 正/逆序检索...\n";
    std::cout << "size:    \t " << list1.size()             << std::endl;
    std::cout << "empty:   \t " << list1.empty()            << std::endl;
    std::cout << "first:   \t " << list1.first()            << std::endl;
    std::cout << "List[0]: \t " << list1[0]                 << std::endl;
    std::cout << "last:    \t " << list1.last()             << std::endl;
    std::cout << "List[-1]:\t " << list1[-1]                << std::endl;
    std::cout << "valid:   \t " << list1.valid(list1[0]) << std::endl;
    std::cout << "\n";
    bool a = true;
    a;
    /** 删除元素 **/
    std::cout << "删除节点List[3]...\n";
    list1.remove(list1[3]);
    list1.traverse(printNode); std::cout << "\n\n";

    /** 插入 **/
    std::cout << "插入元素, 在List[3]前插和后插元素4...\n";
    list1.insertElemAfterNode(list1[3], 4);
    list1.insertElemBeforeNode(list1[3], -4);
    list1.traverse(printNode); std::cout << "\n\n";

    /** 复制构造函数 **/
    std::cout << "复制整个链表至新链表...\n";
    List<int> new_list1(list1);
    new_list1.traverse(printNode); std::cout << "\n";

    std::cout << "复制旧链表List[4](包括)后的5个元素至新链表...\n";
    List<int> new_list2(list1, 4, 5);
    new_list2.traverse(printNode); std::cout << "\n";

    std::cout << "复制旧链表List[4](包括)后的5个元素至新链表...\n";
    List<int> new_list3(list1[4], 5);
    new_list3.traverse(printNode); std::cout << "\n\n";

    return 0;
}
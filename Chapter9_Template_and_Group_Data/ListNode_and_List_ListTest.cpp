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
    /** ��ʼ�� **/
    std::cout << "��ʼ������...\n\n";
    List<int> list1;

    /** ���� **/
    std::cout << "�������в���Ԫ��, �ײ�����, β������...\n";
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

    /** ���� **/
    std::cout << "����ѭ��������ӡ�����е�����Ԫ��...\n";
    for(int i = 0; i < list1.size(); i++){
        std::cout << list1[i]->data << " ";
    }
    std::cout << "\n����ѭ��������ӡ�����е�����Ԫ��...\n";
    for(int i = -1; i > -list1.size() - 1; i--){
        std::cout << list1[i]->data << " ";
    }
    std::cout << "\n\n";

    /** ���� **/
    std::cout << "������ӡ�����е�����Ԫ��...\n";
    list1.traverse(printNode);
    std::cout << "\n\n";

    /** ����ߴ�, ״̬, ��/βԪ��, ��/������� **/
    std::cout << "�������ߴ�, ״̬, ��/βԪ��, ��/�������...\n";
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
    /** ɾ��Ԫ�� **/
    std::cout << "ɾ���ڵ�List[3]...\n";
    list1.remove(list1[3]);
    list1.traverse(printNode); std::cout << "\n\n";

    /** ���� **/
    std::cout << "����Ԫ��, ��List[3]ǰ��ͺ��Ԫ��4...\n";
    list1.insertElemAfterNode(list1[3], 4);
    list1.insertElemBeforeNode(list1[3], -4);
    list1.traverse(printNode); std::cout << "\n\n";

    /** ���ƹ��캯�� **/
    std::cout << "��������������������...\n";
    List<int> new_list1(list1);
    new_list1.traverse(printNode); std::cout << "\n";

    std::cout << "���ƾ�����List[4](����)���5��Ԫ����������...\n";
    List<int> new_list2(list1, 4, 5);
    new_list2.traverse(printNode); std::cout << "\n";

    std::cout << "���ƾ�����List[4](����)���5��Ԫ����������...\n";
    List<int> new_list3(list1[4], 5);
    new_list3.traverse(printNode); std::cout << "\n\n";

    return 0;
}
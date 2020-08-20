/** brief  基于链表实现一个队列
 *  author geds
 *  date   2020-08-20
 * */

#include "queue.h"
template <class T>
void print(T e){
    std::cout << e << ",";
}

int main()
{
    Queue<int> q;
    std::cout << q.empty() << std::endl;

    q.enqueue(5);
    q.traverse(print);
    std::cout << "\n";

    q.enqueue(3);
    q.traverse(print);
    std::cout << "\n";

    q.dequeue();
    q.traverse(print);
    std::cout << "\n";

    q.enqueue(7);
    q.enqueue(2);
    q.traverse(print);
    std::cout << "\n";

    std::cout << q.front() << std::endl;

    std::cout << q.empty() << std::endl;

    q.enqueue(11);
    q.traverse(print);
    std::cout << "\n";

    std::cout << q.size() << std::endl;

    q.enqueue(6);
    q.enqueue(7);
    q.traverse(print);
    std::cout << "\n";

    q.dequeue();
    q.dequeue();

    std::cout << q.front() << std::endl;
    std::cout << q.size() << std::endl;
    return 0;
}

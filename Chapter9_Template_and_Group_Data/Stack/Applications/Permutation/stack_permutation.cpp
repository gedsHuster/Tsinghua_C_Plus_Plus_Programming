/** brief  : 栈结构应用案例--判断给定序列是否为合法的栈混洗
 *  author : geds
 *  date   : 2020-08-20
 * */

#include <Stack/StackV2.h>
#include <vector>

/** @brief 判断给定序列是否为合法的栈混洗
 *  @param strInit 初始状态
 *  @param strTarget 目标状态
 *  @return true:合法, false:非法
 * */
bool isLegalStackPermutation(std::string strTarget, std::string strInit){
    StackV2<char> A, B, S, temp;
    for(int i=0; i<strInit.size(); i++)
        temp.push(strInit[i]);
    while(!temp.empty())
        A.push(temp.pop());

    int count = 0;
    bool A_empty = false, S_empty = true;
    while (!A.empty() || !S.empty()){
        // A不空,则向S中压入A的顶部元素
        if(!A.empty()) S.push(A.pop());

        // S不空
        if(!S.empty() || count==0 ){// 注意初始时S为空

            while (S.top() == strTarget[count]){ // 如果S中的元素满足要求,则一直弹出并压入B中
                B.push(S.pop());
                count++;
                if(S.empty()) break; // 每次pop之前, 判断S是否为空
            }

            // S不空
            if(!S.empty()){
                // S顶部元素又不满足要求, 且A空了
                if(S.top() != strTarget[count] && A.empty()){
                    std::cout << strTarget << " is not a valid permutation!" << std::endl;
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    std::vector<std::string> vec;
    vec.push_back("1243");
    vec.push_back("1342");
    vec.push_back("2143");
    vec.push_back("2341");
    vec.push_back("3142");
    vec.push_back("4321");
    for(int i=0; i<vec.size(); i++)
        std::cout << isLegalStackPermutation(vec[i], "1234") << std::endl;

    return 0;
}
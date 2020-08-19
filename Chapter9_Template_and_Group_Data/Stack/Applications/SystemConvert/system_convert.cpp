//
// Created by gedsH on 2020/8/19.
//

#include "Stack/StackV2.h"
#include <vector>
#include <math.h>

/** @brief 将10进制数转换为指定进制
 *  @param S 用于存储转换结果
 *  @param n 给定的10进制数值
 *  @param base 要转换的进制数
 * */
void convert(StackV2<char>& S, __int64 n, int base){
    char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(n > 0){
        S.push(digit[n % base]);
        n /= base;
    }
}

/** @brief 将某一进制数转换为10进制
 *  @param str 以字符串形式输入的某一进制的数值
 *  @param base 被转换的进制
 * */
int invert(std::string str, int base){
    StackV2<int> S;
    int temp=0, result=0;
    for(int i=0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            switch (str[i]) {
                case '0': temp = 0; break;
                case '1': temp = 1; break;
                case '2': temp = 2; break;
                case '3': temp = 3; break;
                case '4': temp = 4; break;
                case '5': temp = 5; break;
                case '6': temp = 6; break;
                case '7': temp = 7; break;
                case '8': temp = 8; break;
                case '9': temp = 9; break;
            }
        }else if(str[i] >= 'A' && str[i] <= 'F'){
            switch (str[i]) {
                case 'A': temp = 10; break;
                case 'B': temp = 11; break;
                case 'C': temp = 12; break;
                case 'D': temp = 13; break;
                case 'E': temp = 14; break;
                case 'F': temp = 15; break;
            }
        }
        S.push(temp);
    }
    int count = 0;
    while (!S.empty()){
        result += S.pop() * std::pow(base, count);
        count++;
    }
    return result;
}

int main()
{
    // 将16进制AF转换为10进制
    int num_dec = invert("AF", 16);
    StackV2<char> S;
    // 将10进制转换为2进制
    convert(S, num_dec, 2);
    while(!S.empty())
        std::cout << S.pop();
    std::cout << std::endl;

    return 0;
}
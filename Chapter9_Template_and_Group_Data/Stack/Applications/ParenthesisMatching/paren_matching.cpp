//
// Created by gedsH on 2020/8/19.
//

#include "Stack/StackV2.h"
#include <math.h>

/** @brief 字符串预处理, 剔除非括号的字符, 只保留括号字符
 *  @param str_in 原始字符串
 *  @return 预处理后的字符串
 * */
std::string strPreprocessing(std::string str_in){
    std::string str_out;
    for(int i=0; i<str_in.size(); i++){
        switch (str_in[i]) {
            case '(': str_out.push_back(str_in[i]); break;
            case ')': str_out.push_back(str_in[i]); break;
            case '[': str_out.push_back(str_in[i]); break;
            case ']': str_out.push_back(str_in[i]); break;
            case '{': str_out.push_back(str_in[i]); break;
            case '}': str_out.push_back(str_in[i]); break;
        }
    }
    return str_out;
}

/** @brief 括号匹配性检查
 *  @param str 预处理后的字符串
 *  @return 是否匹配
 * */
bool checkParenMatch(std::string str){
    StackV2<char> S;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            S.push(str[i]);
        else{
            if(!S.empty()){
                if(std::abs(int(str[i]) - int(S.top())) <= 2)
                    S.pop();
            } else
                return false;
        }
    }
    return S.empty();
}

int main()
{
    std::string str = "{((1+2)* [5/2.0])}";
    std::string str2 = strPreprocessing(str) ;
    std::cout << str2 << ": ";
    std::cout << checkParenMatch(str2) << std::endl;
    return 0;
}

// ASCII Code
// '(', ')', '[', ']',  '{',  '}'
//  40,  41,  91,  93,  123,  125
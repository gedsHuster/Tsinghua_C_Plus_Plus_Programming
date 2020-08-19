//
// Created by gedsH on 2020/8/16.
//

#ifndef TSINGHUA_C_PLUS_PLUS_PROGRAMMING_CALCULATORTEST_H
#define TSINGHUA_C_PLUS_PLUS_PROGRAMMING_CALCULATORTEST_H

#include "Stack.h"
#include <vector>
#include <sstream>

class Calculator{
private:
    std::vector<std::string> splitStr(const std::string& str);
    std::vector<std::string> infix2suffix(const std::vector<std::string>& vec_in);
    double computeFromSuffix(std::vector<std::string>& vec_suffix);
public:
    Calculator();
    void run();
};

Calculator::Calculator() = default;

/** @brief 计算器运行函数, 输入“q”结束程序
 * */
void Calculator::run() {
    std::string str;
    std::vector<std::string> vec, vec_suffix;
    double result;
    while(std::getline(std::cin, str) && str != "q"){
        vec = splitStr(str);                                /** 预处理: 分离字符串 **/
        vec_suffix = infix2suffix(vec);                     /** 中缀表达式转后缀表达式 **/
        result = computeFromSuffix(vec_suffix);          /** 从后缀表达式计算结果 **/
        std::cout << "result: " << result << std::endl;
    }
}

/** @brief 预处理字符串, 分割字符串, 使每一部分有意义,如: 54, -12, 3.2, +, -, *, /, (, )等
 *  @param str 原始字符串
 *  @return 预处理后的字符串数组, 数组中的每一个元素都是一个有意义的字符串, 如数字, 四则运算符, 括号
 * */
std::vector<std::string> Calculator::splitStr(const std::string& str) {
    std::vector<std::string> outVec;
    std::string temp_str;           // 字符串缓存
    std::stringstream temp_ss;      // 用于字符转字符串
    for(int i = 0; i<str.size(); i++){
        if(str[i] == ' '){
            /**空格字符**/
            // 保存缓存中的数字
            if(temp_str.size() > 0){
                outVec.push_back(temp_str);
                temp_str.clear();
            }
        } else{
            /**数字字符**/
            if(str[i] >= '0' && str[i] <= '9'){
                // 缓存数字中的一个字符
                temp_str.push_back(str[i]);
                // 最后一个数字,直接保存
                if(i == str.size()-1){
                    outVec.push_back(temp_str);
                    temp_str.clear();
                }
            }else{
                /**各种符号字符**/
                // 若为小数点字符
                if(str[i] == '.'){
                    temp_str.push_back(str[i]);
                    continue;
                }
                // 若为负号字符
                if(temp_str.size() == 0 && str[i] == '-'){
                    temp_str.push_back(str[i]);
                    continue;
                }
                // 若缓存不为空, 保存缓存中存在数字
                if(temp_str.size() > 0){
                    outVec.push_back(temp_str);
                    temp_str.clear();
                }
                // 保存四则运算负号
                temp_ss << str[i];
                outVec.push_back(temp_ss.str());
                temp_ss.str(""); // 清空
            }
        }
    }
    return outVec;
}

/** @brief   将四则运算的中缀表达式转换成后缀表达式
 *  @details 利用一个栈存储四则运算符号, 何时压入栈, 何时弹出栈要视情况而定
 *           从左至右遍历中缀表达式的每个数字和符号, 如果是数字, 则直接保存起来.
 *           如果是符号, 若栈为空, 则直接压入栈; 若栈非空, 判断其与栈顶符号的优先级,
 *           若是右括号或优先级低于栈顶符号, 则栈顶符号依次出栈并保存起来. ('*','\'优先于'+','-')
 *  @param  vec_in 预处理好的字符串数组, 以中缀表达式的方式存储
 *  @return 后缀表达式的字符串数组
 * */
std::vector<std::string> Calculator::infix2suffix(const std::vector<std::string>& vec_in){
    // Operator ASCII Code: 43+ 45- 42* 47/
    std::vector<std::string> vec_out;
    Stack<std::string> stack;
    int temp;
    for(int i=0; i<vec_in.size(); i++){
        if(vec_in[i] == "+"){
            if(stack.isEmpty() || stack.peek() == "("){// 左括号
                stack.push(vec_in[i]);
            }else{
                while(!stack.isEmpty())
                    vec_out.push_back(stack.pop());
                stack.push(vec_in[i]);
            }
            continue;
        }else if(vec_in[i] == "-"){
            if(stack.isEmpty() || stack.peek() == "("){// 左括号
                stack.push(vec_in[i]);
            }else{
                while(!stack.isEmpty())
                    vec_out.push_back(stack.pop());
                stack.push(vec_in[i]);
            }
            continue;
        }else if(vec_in[i] == "*"){
            stack.push(vec_in[i]);
            continue;
        }else if(vec_in[i] == "/"){
            stack.push(vec_in[i]);
            continue;
        }else if(vec_in[i] == "("){
            stack.push(vec_in[i]);
            continue;
        }else if(vec_in[i] == ")"){
            while (stack.peek() != "(")
                vec_out.push_back(stack.pop());
            stack.pop(); // 弹出左括号"("
            continue;
        }else{
            // 若是数字, 直接保存
            vec_out.push_back(vec_in[i]);
        }
    }
    // 最后将栈中的符号全部输出
    while(!stack.isEmpty())
        vec_out.push_back(stack.pop());

    return vec_out;
}

/** @brief 从后缀表达式字符串数组计算四则运算结果
 *  @details 利用一个栈存储数字, 何时压入栈保存,或弹出栈进行四则运算, 视情况而定
 *           从左到右遍历后缀表达式的每一个数字和符号, 如果遇到是数字就进栈.
 *           如果遇到四则运算符, 就弹出位于栈顶的两个数字, 进行四则运算(注意运算顺序).
 *           运算结果再入栈, 一直到获得最终结果.
 *  @param vec_suffix 后缀表达式的字符串数组
 *  @return 四则运算计算结果
 * */
double Calculator::computeFromSuffix(std::vector<std::string>& vec_suffix){
//    double result;
    double temp1, temp2;
    Stack<double> stack;
    std::istringstream iss;
    for(int i=0; i<vec_suffix.size(); i++){
        if(vec_suffix[i] == "+"){
            temp1 = stack.pop();
            temp2 = stack.pop();
            stack.push(temp2 + temp1);
//            std::cout << "push '+' result: " << temp2 << " + " << temp1 <<" = "<< temp2+temp1 << "\n";
            continue;
        } else if(vec_suffix[i] == "-"){
            temp1 = stack.pop();
            temp2 = stack.pop();
            stack.push(temp2 - temp1);
//            std::cout << "push '-' result: "  << temp2 << " - " << temp1 <<" = "<< temp2-temp1 << "\n";
            continue;
        }else if(vec_suffix[i] == "*"){
            temp1 = stack.pop();
            temp2 = stack.pop();
            stack.push(temp2 * temp1);
//            std::cout << "push '*' result: "  << temp2 << " * " << temp1 <<" = "<< temp2*temp1 << "\n";
            continue;
        }else if(vec_suffix[i] == "/"){
            temp1 = stack.pop();
            temp2 = stack.pop();
            if(temp1 == 0){
                std::cerr << "denominator is equal to zero!" << std::endl;
                exit(1);
            } else
                stack.push(temp2 / temp1);
//            std::cout << "push '/' result: "  << temp2 << " / " << temp1 <<" = "<< temp2/temp1 << "\n";
            continue;
        } else{
            // 字符串转double
//            std::cout << "vec_suffix[" << i << "]: " << vec_suffix[i] << ", ";
            iss.str(vec_suffix[i]);
            iss >> temp1;
            stack.push(temp1);
            iss.clear();
            iss.str(""); // 清空
//            std::cout << "push num: " << temp1 << "\n";
        }
    }
    return stack.pop(); // 输出栈低的最终计算结果
}


#endif //TSINGHUA_C_PLUS_PLUS_PROGRAMMING_CALCULATORTEST_H

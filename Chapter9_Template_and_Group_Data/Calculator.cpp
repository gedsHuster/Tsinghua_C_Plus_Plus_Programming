/**@brief  实现了一个计算器类,可以计算实数的四则运算,支持输入中缀表达式
 *         计算器类的实现具体可分为三步:
 *         1. 原始字符串的分割处理
 *         2. 中缀表达式转换成后缀表达式  (用到栈结构)
 *         3. 从后缀表达式中计算出结果   (用到栈结构)
 * @author geds
 * @date 2020-08-18
 * */

#include "Calculator.h"

int main()
{
    Calculator cal;
    cal.run();
    return 0;
}
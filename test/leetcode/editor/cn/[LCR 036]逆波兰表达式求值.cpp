//根据 逆波兰表示法，求该后缀表达式的计算结果。 
//
// 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。 
//
// 
//
// 说明： 
//
// 
// 整数除法只保留整数部分。 
// 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：tokens = ["2","1","+","3","*"]
//输出：9
//解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
// 
//
// 示例 2： 
//
// 
//输入：tokens = ["4","13","5","/","+"]
//输出：6
//解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
// 
//
// 示例 3： 
//
// 
//输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//输出：22
//解释：
//该算式转化为常见的中缀算术表达式为：
//  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22 
//
// 
//
// 提示： 
//
// 
// 1 <= tokens.length <= 10⁴ 
// tokens[i] 要么是一个算符（"+"、"-"、"*" 或 "/"），要么是一个在范围 [-200, 200] 内的整数 
// 
//
// 
//
// 逆波兰表达式： 
//
// 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。 
//
// 
// 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。 
// 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。 
// 
//
// 逆波兰表达式主要有以下两个优点： 
//
// 
// 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。 
// 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。 
// 
//
// 
//
// 
// 注意：本题与主站 150 题相同： https://leetcode-cn.com/problems/evaluate-reverse-polish-
//notation/ 
//
// Related Topics 栈 数组 数学 👍 62 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int string_to_int(string s) {
        int sum = 0;
        int negative = false;
        for (char c: s) {
            if (c == '-')
                negative = true;
            else
                sum = sum * 10 + c - '0';

        }
        return negative ? -1 * sum : sum;
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i += 1) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int res;
                if (tokens[i] == "+") {
                    res = num1 + num2;
                } else if (tokens[i] == "-") {
                    res = num2 - num1;
                } else if (tokens[i] == "*") {
                    res = num1 * num2;
                } else if (tokens[i] == "/") {
                    res = num2 / num1;
                }
                s.push(res);
            } else {
                s.push(string_to_int(tokens[i]));
            }
        }

        return s.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

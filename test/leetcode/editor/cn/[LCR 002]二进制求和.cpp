//给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1： 
//
// 
//输入: a = "11", b = "10"
//输出: "101" 
//
// 示例 2： 
//
// 
//输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
//
// 
//
// 
// 注意：本题与主站 67 题相同：https://leetcode-cn.com/problems/add-binary/ 
//
// Related Topics 位运算 数学 字符串 模拟 👍 88 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {
        stack<char> st;
        int i = a.size() - 1;
        int j = b.size() - 1;


        int sum = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            st.push(sum % 2 + '0');
            sum /= 2;
        }

        if (sum) {
            st.push('1');
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

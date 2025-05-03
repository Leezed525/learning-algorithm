//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
// 
// 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 10⁴ 
// s[i] 为 '(' 或 ')' 
// 
//
// Related Topics 栈 字符串 动态规划 👍 2695 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int i = 0;
        int ans = 0;
        int last = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                if(st.empty()) {
                    i++;
                    last = i;
                    continue;
                }
                st.pop();
                if(st.empty()) {
                    ans = max(ans, i + 1 - last);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
            i++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

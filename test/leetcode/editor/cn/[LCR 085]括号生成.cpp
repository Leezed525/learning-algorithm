//正整数 n 代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
//
// 
//
// 
// 注意：本题与主站 22 题相同： https://leetcode-cn.com/problems/generate-parentheses/ 
//
// Related Topics 字符串 动态规划 回溯 👍 93 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> ans;

    vector<char> s;

    string vectorToString() {
        string tmp = "";
        for (char i: s) {
            tmp += i;
        }
        return tmp;
    }

    void dfs(int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(vectorToString());
            return;
        }
        if (left < right && right > 0) {
            s.push_back(')');
            dfs(left, right - 1);
            s.pop_back();
        }
        if (left > 0) {
            s.push_back('(');
            dfs(left - 1, right);
            s.pop_back();
        }
        return;
    }


    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

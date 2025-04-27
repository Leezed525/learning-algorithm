//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
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
// Related Topics 字符串 动态规划 回溯 👍 3828 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> ans;
    vector<char> path;

    void chartostring(){
        string s = "";
        for (char c: path) {
            s += c;
        }
        ans.push_back(s);
    }

    void dfs(int left, int right){
        if(left == 0 && right == 0){
            chartostring();
            return;
        }
        if (left > 0) {
            path.push_back('(');
            dfs(left - 1, right);
            path.pop_back();
        }
        if (right > left && right > 0) {
            path.push_back(')');
            dfs(left, right - 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return ans;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

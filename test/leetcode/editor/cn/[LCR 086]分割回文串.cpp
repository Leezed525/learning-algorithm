//给定一个字符串 s ，请将 s 分割成一些子串，使每个子串都是 回文串 ，返回 s 所有可能的分割方案。 
//
// 
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "google"
//输出：[["g","o","o","g","l","e"],["g","oo","g","l","e"],["goog","l","e"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出：[["a"]] 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// 
//
// 
// 注意：本题与主站 131 题相同： https://leetcode-cn.com/problems/palindrome-partitioning/ 
//
// Related Topics 深度优先搜索 广度优先搜索 图 哈希表 👍 79 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<string>> ans;
    vector<string> path;
    int len;
    vector<vector<int>> dp;
    string str;

    void dfs(int start) {
        if (start == len) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < len; i += 1) {
            if (dp[start][i]) {
                path.push_back(str.substr(start, i - start + 1));
                dfs(i + 1);
                path.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        len = s.size();
        str = s;
        for (int i = 0; i < len; i += 1) {
            dp.push_back(vector<int>(len, 0));
        }
        //先生成dp矩阵来判断区间【i-j】之间是否是回文子串
        for (int i = len - 1; i >= 0; i -= 1) {
            for (int j = i; j < len; j += 1) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        dfs(0);
        //打印dp矩阵
//        for (int i = 0; i < len; i += 1) {
//            for (int j = 0; j < len; j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }

        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

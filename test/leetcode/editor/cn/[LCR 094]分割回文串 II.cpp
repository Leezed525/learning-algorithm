//给定一个字符串 s，请将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回符合要求的 最少分割次数 。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：s = "ab"
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2000 
// s 仅由小写英文字母组成 
// 
//
// 
//
// 
// 注意：本题与主站 132 题相同： https://leetcode-cn.com/problems/palindrome-partitioning-
//ii/ 
//
// Related Topics 字符串 动态规划 👍 82 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCut(string s) {
        int dp[2010][2010] = {0};
        int n = s.size();
        for (int i = n - 1; i >= 0; i -= 1) {
            for (int j = i; j < n; j += 1) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        //输出dp矩阵
//        for (int i = 0; i < n; i += 1) {
//            for (int j = 0; j < n; j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        int ans = 0;
        int f[2010] = {0};
        for (int i = 0; i < n; i += 1) {
            f[i] = INT_MAX;
        }
        for (int i = 0; i < n; i += 1) {
            if (dp[0][i])
                f[i] = 0;
            else{
                for (int j = 0; j < i; j += 1) {
                    if(dp[j + 1][i]) {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }


        return f[n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

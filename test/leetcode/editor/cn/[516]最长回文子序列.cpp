//给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。 
//
// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bbbab"
//输出：4
//解释：一个可能的最长回文子序列为 "bbbb" 。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出：2
//解释：一个可能的最长回文子序列为 "bb" 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 1307 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1005][1005] = {0};

        for (int i = 1; i <= s.size(); i += 1) {
            dp[i][i] = 1;
        }

        for (int i = s.size(); i > 0; i -= 1) {
            for (int j = i + 1; j <= s.size(); j += 1) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        //输出dp数组

//        for (int i = 1; i <= s.size(); i += 1) {
//            for (int j = 1; j <= s.size(); j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//        cout << endl;

        return dp[1][s.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

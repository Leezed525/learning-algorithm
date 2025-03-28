//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 6826 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1005][1005] = {0};
        int res = 0;
//        for (int i = 1; i <= s.size(); i += 1) {
//            dp[i][i] = 1;
////            res += 1;
//        }
        int start = -1;
        int end = -1;
        int max_len = 0;

        for (int i = s.size(); i > 0; i -= 1) {
            for (int j = i; j <= s.size(); j += 1) {
                if (s[i - 1] == s[j - 1] ) {
                    if (j - i <= 1 || dp[i + 1][j - 1] == 1) {
                        int len = j - i + 1;
                        if (len > max_len) {
                            max_len = len;
                            start = i - 1;
                            end = j - 1;
                        }
                        dp[i][j] = 1;
                        res += 1;
                    }
                }
            }
        }

        return s.substr(start, max_len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

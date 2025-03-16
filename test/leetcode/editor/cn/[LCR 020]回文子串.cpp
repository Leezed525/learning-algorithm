//给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由小写英文字母组成 
// 
//
// 
//
// 
// 注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/palindromic-substrings/ 
//
// Related Topics 字符串 动态规划 👍 108 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        int dp[1005][1005] = {0};
        int res = 0;
        for (int i = s.size(); i > 0; i -= 1) {
            for (int j = i; j <= s.size(); j += 1) {
                if (s[i - 1] == s[j - 1]) {
                    if(j - i <= 1 || dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

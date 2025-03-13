//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。 
//
// 回文字符串 是正着读和倒过来读一样的字符串。 
//
// 子字符串 是字符串中的由连续字符组成的一个序列。 
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
// Related Topics 双指针 字符串 动态规划 👍 1413 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    int countSubstrings(string s) {
        int dp[1005][1005] = {0};
        int res = 0;
//        for (int i = 1; i <= s.size(); i += 1) {
//            dp[i][i] = 1;
////            res += 1;
//        }

        for (int i = s.size(); i > 0; i -= 1) {
            for (int j = i; j <= s.size(); j += 1) {
                if (s[i - 1] == s[j - 1] ) {
                    if (j - i <= 1 || dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                        res += 1;
                    }
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

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

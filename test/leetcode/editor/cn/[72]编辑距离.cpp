//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 3616 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[505][505] = {0};
        for (int i = 1; i <= word1.size(); i += 1) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.size(); i += 1) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); i += 1) {
            for (int j = 1; j <= word2.size(); j += 1) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        //输出dp
//        for (int i = 0; i <= word1.size(); i += 1) {
//            for (int j = 0; j <= word2.size(); j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//        cout << endl;

        return dp[word1.size()][word2.size()];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 10⁹ + 7 取模。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//rabbbit
//rabbbit
//rabbbit 
//
// 示例 2： 
//
// 
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 1000 
// s 和 t 由英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 1326 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {

        int dp[1005][1005] = {0};

        int mod = 1e9 + 7;

        for (int i = 0; i <= s.size(); i += 1) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= t.size(); i += 1) {
            for (int j = i; j <= s.size(); j += 1) {
                dp[i][j] = dp[i][j - 1] % mod;
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i][j] + dp[i - 1][j - 1] % mod;
                }
            }
        }

        //输出dp数组
//        for (int i = 1; i <= t.size(); i += 1) {
//            for (int j = 1; j <= s.size(); j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;

        return dp[t.size()][s.size()];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

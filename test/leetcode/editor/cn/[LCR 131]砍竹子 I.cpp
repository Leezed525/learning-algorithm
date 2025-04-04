//现需要将一根长为正整数 bamboo_len 的竹子砍为若干段，每段长度均为正整数。请返回每段竹子长度的最大乘积是多少。 
//
// 
//
// 示例 1： 
//
// 
//输入: bamboo_len = 12
//输出: 81
// 
//
//提示：
//
// 
// 2 <= bamboo_len <= 58 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
//
// Related Topics 数学 动态规划 👍 631 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        int dp[60] = {0, 1, 1, 2, 4, 6, 9};
        for (int i = 7; i <= bamboo_len; i++) {
            dp[i] = max(2 * dp[i - 2], 3 * dp[i - 3]);
        }

        return dp[bamboo_len];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

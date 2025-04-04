//现需要将一根长为正整数 bamboo_len 的竹子砍为若干段，每段长度均为 正整数。请返回每段竹子长度的 最大乘积 是多少。 
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
// 
//
// 示例 1： 
//
// 
//输入：bamboo_len = 12
//输出：81
// 
//
// 
//
// 提示： 
//
// 
// 2 <= bamboo_len <= 1000 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
//
// 
//
// Related Topics 数学 动态规划 👍 270 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        long dp[1010] = {0, 1, 1, 2, 4, 6, 9};
        long mod = 1000000007;
        for (int i = 7; i <= bamboo_len; i++) {
            dp[i] = 3 * dp[i - 3] % mod;
        }

        return (int) dp[bamboo_len];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

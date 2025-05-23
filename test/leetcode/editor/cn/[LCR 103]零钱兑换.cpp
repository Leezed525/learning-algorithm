//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：coins = [1], amount = 1
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：coins = [1], amount = 2
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 2³¹ - 1 
// 0 <= amount <= 10⁴ 
// 
//
// 
//
// 
// 注意：本题与主站 322 题相同： https://leetcode-cn.com/problems/coin-change/ 
//
// Related Topics 广度优先搜索 数组 动态规划 👍 110 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long dp[10010] = {0};
        for (int i = 1; i <= amount; i += 1) {
            dp[i] = INT_MAX;
        }
        for (int i: coins) {
            for (int j = i; j <= amount; j += 1) {
                dp[j] = min(dp[j], dp[j - i] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

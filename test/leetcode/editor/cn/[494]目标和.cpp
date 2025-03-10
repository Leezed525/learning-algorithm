//给你一个非负整数数组 nums 和一个整数 target 。 
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ： 
//
// 
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。 
// 
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], target = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 20 
// 0 <= nums[i] <= 1000 
// 0 <= sum(nums[i]) <= 1000 
// -1000 <= target <= 1000 
// 
//
// Related Topics 数组 动态规划 回溯 👍 2093 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {

        int dp[2005] = {0};
        dp[1000 + nums[0]] += 1;
        dp[1000 - nums[0]] += 1;
        for (int i = 1; i < nums.size(); i += 1) {
            int temp[2005] = {0};
            for (int j = 0; j < 2005; j += 1) {
                if (dp[j] != 0) {
                    temp[j + nums[i]] += dp[j];
                    temp[j - nums[i]] += dp[j];
                }
            }
            for (int j = 0; j < 2005; j += 1) {
                dp[j] = temp[j];
            }
        }
        return target > 1000 ? 0 : dp[target + 1000];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

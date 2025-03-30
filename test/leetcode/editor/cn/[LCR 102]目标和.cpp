//给定一个正整数数组 nums 和一个整数 target 。 
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
// 
//
// 
// 注意：本题与主站 494 题相同： https://leetcode-cn.com/problems/target-sum/ 
//
// Related Topics 数组 动态规划 回溯 👍 81 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[2010] = {0};
        dp[1000] = 1;
        for (int i: nums) {
            int tmp[2010] = {0};
            for (int j = 0; j <= 2000; j += 1) {
                if (dp[j] != 0) {
                    int right = j + i;
                    int left = j - i;
                    if(right >= 0 && right <= 2000) tmp[right] += dp[j];
                    if(left >= 0 && left <= 2000) tmp[left] += dp[j];
                }
            }
            for (int j = 0; j <= 2000; j += 1) {
                dp[j] = tmp[j];
            }
        }
        return dp[target + 1000];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//一个专业的小偷，计划偷窃一个环形街道上沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同
//时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。 
//
// 给定一个代表每个房屋存放金额的非负整数数组 nums ，请计算 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,3,2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,1]
//输出：4
//解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 1000 
// 
//
// 
//
// 
// 注意：本题与主站 213 题相同： https://leetcode-cn.com/problems/house-robber-ii/ 
//
// Related Topics 数组 动态规划 👍 67 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() <= 2) {
            if (nums.size() == 1) {
                return nums[0];
            } else {
                return max(nums[0], nums[1]);
            }
        }
        int dp[110][2];
        int ans = 0;
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        int n = nums.size();
        for (int i = 1; i < n - 1; i += 1) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        ans = max(dp[n - 2][0], dp[n - 2][1]);
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        for (int i = 2; i < n; i += 1) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        ans = max(ans, max(dp[n - 1][0], dp[n - 1][1]));

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

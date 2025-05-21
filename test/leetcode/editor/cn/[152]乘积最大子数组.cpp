//给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 
//
// 测试用例的答案是一个 32-位 整数。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
// 
//
// 示例 2: 
//
// 
//输入: nums = [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -10 <= nums[i] <= 10 
// nums 的任何子数组的乘积都 保证 是一个 32-位 整数 
// 
//
// Related Topics 数组 动态规划 👍 2441 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <long> maxF(nums.begin(),nums.end()), minF(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max((long)nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min((long)nums[i], maxF[i - 1] * nums[i]));
            if(minF[i]<INT_MIN) {
                minF[i]=nums[i];
            }
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

//leetcode submit region end(Prohibit modification and deletion)

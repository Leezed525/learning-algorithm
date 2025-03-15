//给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。 
//
// 
//
// 示例 1： 
//
// 
//输入: nums = [0,1]
//输出: 2
//解释: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。 
//
// 示例 2： 
//
// 
//输入: nums = [0,1,0]
//输出: 2
//解释: [0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// nums[i] 不是 0 就是 1 
// 
//
// 
//
// 
// 注意：本题与主站 525 题相同： https://leetcode-cn.com/problems/contiguous-array/ 
//
// Related Topics 数组 哈希表 前缀和 👍 158 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        //解法一： 把0变成-1，然后求和为0的最长子数组
//        unordered_map<int, int> mp;
//        int pre_sum = 0;
//        int res = 0;
//        for (int i = 0; i < nums.size(); i += 1) {
//            if (nums[i] == 0) nums[i] = -1;
//            pre_sum += nums[i];
//            if (pre_sum == 0) res = i + 1;
//            if (mp.count(pre_sum)) {
//                res = max(res, i - mp[pre_sum]);
//            } else {
//                mp[pre_sum] = i;
//            }
//        }
//        return res;
        //解法二： 前缀和+哈希表
        unordered_map<int, int> mp;
        int sum_0 = 0;
        int sum_1 = 0;
        int res = 0;
        for(int i = 0;i < nums.size();i += 1) {
            if(nums[i] == 0) sum_0 += 1;
            else sum_1 += 1;
            int diff = sum_0 - sum_1;
            if(diff == 0) res = i + 1;
            if(mp.count(diff)){
                res = max(res, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

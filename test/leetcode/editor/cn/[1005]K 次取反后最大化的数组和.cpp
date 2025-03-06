//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组： 
//
// 
// 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。 
// 
//
// 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。 
//
// 以这种方式修改数组后，返回数组 可能的最大和 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,2,3], k = 1
//输出：5
//解释：选择下标 1 ，nums 变为 [4,-2,3] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,-1,0,2], k = 3
//输出：6
//解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [2,-3,-1,5,-4], k = 2
//输出：13
//解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁴ 
// -100 <= nums[i] <= 100 
// 1 <= k <= 10⁴ 
// 
//
// Related Topics 贪心 数组 排序 👍 478 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        //获取负数的个数
        int negativeCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                negativeCount += 1;
            }
        }
        if(k > negativeCount) {
            //如果负数的个数小于k，那么将所有的负数都变为正数
            for (int i = 0; i < negativeCount; i++) {
                nums[i] = -nums[i];
            }
            k -= negativeCount;
            if(k % 2 == 1) {
                //如果k是奇数，那么将最小的数变为负数
                sort(nums.begin(), nums.end());
                nums[0] = -nums[0];
            }
        } else {
            //如果负数的个数大于等于k，那么将前k个数变为负数
            for (int i = 0; i < k; i++) {
                nums[i] = -nums[i];
            }
        }

        //求和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

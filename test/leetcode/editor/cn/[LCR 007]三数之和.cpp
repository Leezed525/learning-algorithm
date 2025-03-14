//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 
//不重复 的三元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// 
//
// 
// 注意：本题与主站 15 题相同：https://leetcode-cn.com/problems/3sum/ 
//
// Related Topics 数组 双指针 排序 👍 161 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == -nums[i]) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    r--;
                } else if (sum < -nums[i]) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

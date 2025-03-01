//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != 
//k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [0,0,0]
//输出：[[0,0,0]]
//解释：唯一可能的三元组和为 0 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 双指针 排序 👍 7312 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i += 1) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < 0) {
                    l += 1;
                } else if (sum > 0) {
                    r -= 1;
                } else {
                    //去重，可以把逻辑放在push 之后
                    if (l > i + 1 && nums[l] == nums[l - 1]) {
                        l += 1;
                        continue;
                    }
                    if (r < nums.size() - 1 && nums[r] == nums[r + 1]) {
                        r -= 1;
                        continue;
                    }
                    res.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    r -= 1;
                }
            }
        }

        return res;


//        vector<vector<int>> res;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i += 1) {
//            if (nums[i] > 0) {
//                break;
//            }
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            unordered_set<int> s;
//            for (int j = i + 1; j < nums.size(); j += 1) {
//                // 去除三数以上相同 ，且 i + k + k = 0的重复情况
//                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j] == nums[j - 2]) {
//                    continue;
//                }
//                if (s.find(-nums[i] - nums[j]) != s.end()) {
//                    vector<int> v = {nums[i], nums[j], -nums[i] - nums[j]};
//                    res.push_back(v);
//                    s.erase(-nums[i] - nums[j]);
//                }
//                s.insert(nums[j]);
//            }
//        }
//        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

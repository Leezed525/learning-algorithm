//给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= 
//t ，同时又满足 abs(i - j) <= k 。 
//
// 如果存在则返回 true，不存在返回 false。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3,1], k = 3, t = 0
//输出：true 
//
// 示例 2： 
//
// 
//输入：nums = [1,0,1,1], k = 1, t = 2
//输出：true 
//
// 示例 3： 
//
// 
//输入：nums = [1,5,9,1,5,9], k = 2, t = 3
//输出：false 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 2 * 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 0 <= k <= 10⁴ 
// 0 <= t <= 2³¹ - 1 
// 
//
// 
//
// 
// 注意：本题与主站 220 题相同： https://leetcode-cn.com/problems/contains-duplicate-iii/ 
//
// Related Topics 数组 桶排序 有序集合 排序 滑动窗口 👍 98 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<long, int> mp;
    map<long, int>::iterator low, up;

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.size() < 2) {
            return false;
        }
        mp[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i += 1) {
            low = mp.lower_bound((long)nums[i] - t);
//            if(low == mp.end()) cout << nums[i] << endl << low->first << " " << low->second << endl;
            while (low != mp.end() && abs(nums[i] - low->first) <= t) {
                if (i - low->second <= k) return true;
                low++;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

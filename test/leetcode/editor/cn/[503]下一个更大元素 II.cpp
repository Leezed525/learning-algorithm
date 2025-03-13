//给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素
// 。 
//
// 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 
//。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数； 
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 
//
// 示例 2: 
//
// 
//输入: nums = [1,2,3,4,3]
//输出: [2,3,4,-1,4]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
//
// Related Topics 栈 数组 单调栈 👍 1037 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> s;

        vector<int> nums2(nums.size() * 2);
        for (int i = 0; i < 2 * nums.size(); i += 1) {
            nums2[i] = nums[i % nums.size()];
        }

        vector<int> res(nums.size(), -1);

        for (int i = 0; i < nums2.size(); i += 1) {
            if (s.empty() || nums2[i] <= nums2[s.top()]) {
                s.push(i);
            } else {
                while (!s.empty() && nums2[i] > nums2[s.top()]) {
                    res[s.top() % nums.size()] = nums2[i];
                    s.pop();
                }
                s.push(i);
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

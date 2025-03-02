//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回 滑动窗口中的最大值 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 3031 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    deque<int> d;

    void pop(int val) {
        if (!d.empty() && d.front() == val) {
            d.pop_front();
        }
    }

    void push(int val) {
        if (d.empty() || d.back() >= val) {
            d.push_back(val);
        } else {
            while (!d.empty() && d.back() < val)
                d.pop_back();
            d.push_back(val);
        }
    }

    int front() {
        return d.front();
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        for (int i = 0; i < k - 1; i++) {
            push(nums[i]);
        }
        vector<int> res;
        for (int i = k - 1; i < nums.size(); i++) {
            push(nums[i]);
            res.push_back(front());
            pop(nums[i - k + 1]);
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

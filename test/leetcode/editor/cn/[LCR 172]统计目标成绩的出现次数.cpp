//某班级考试成绩按非严格递增顺序记录于整数数组 scores，请返回目标成绩 target 的出现次数。 
//
// 
//
// 示例 1： 
//
// 
//输入: scores = [2, 2, 3, 4, 4, 4, 5, 6, 6, 8], target = 4
//输出: 3 
//
// 示例 2： 
//
// 
//输入: scores = [1, 2, 3, 5, 7, 9], target = 6
//输出: 0 
//
// 
//
// 提示： 
//
// 
// 0 <= scores.length <= 10⁵ 
// -10⁹ <= scores[i] <= 10⁹ 
// scores 是一个非递减数组 
// -10⁹ <= target <= 10⁹ 
// 
//
// 
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/ 
//
// 
//
// Related Topics 数组 二分查找 👍 462 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        auto left = lower_bound(scores.begin(), scores.end(), target);
        auto right = upper_bound(scores.begin(), scores.end(), target);
        int ans = right - left;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

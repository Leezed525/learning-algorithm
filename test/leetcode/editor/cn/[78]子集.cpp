//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
//
// Related Topics 位运算 数组 回溯 👍 2446 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums, int start, int n) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, n);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(nums, 0, 0);
        for (int i = 0; i < nums.size(); i += 1) {
            dfs(nums, 0, i + 1);
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

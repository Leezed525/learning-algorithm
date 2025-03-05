//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 数组 回溯 排序 👍 1685 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> res;

    vector<int> path;
    vector<bool> vis;

    void dfs(vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i += 1) {
            if (vis[i] || us.find(nums[i]) != us.end()) continue;
            vis[i] = true;
            path.push_back(nums[i]);
            us.insert(nums[i]);
            dfs(nums);
            path.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vis = vector<bool>(nums.size(), false);
        dfs(nums);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

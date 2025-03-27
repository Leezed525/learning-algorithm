//给定一个可包含重复数字的整数集合 nums ，按任意顺序 返回它所有不重复的全排列。 
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
// 
//
// 
// 注意：本题与主站 47 题相同： https://leetcode-cn.com/problems/permutations-ii/ 
//
// Related Topics 数组 回溯 👍 69 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;
    vector<int> vis;


    void dfs(vector<int> &nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i += 1) {
            if (!s.count(nums[i]) && vis[i] == 0) {
                vis[i] = 1;
                s.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vis = vector<int>(nums.size(), 0);
        dfs(nums);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

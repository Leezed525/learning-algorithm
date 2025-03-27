//给定一个不含重复数字的整数数组 nums ，返回其 所有可能的全排列 。可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
//
// 
//
// 
// 注意：本题与主站 46 题相同：https://leetcode-cn.com/problems/permutations/ 
//
// Related Topics 数组 回溯 👍 85 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> vis;
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int> &nums){
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i += 1) {
            if (vis[i] == 0) {
                path.push_back(nums[i]);
                vis[i] = 1;
                dfs(nums);
                vis[i] = 0;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vis = vector<int>(nums.size(), 0);
        dfs(nums);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

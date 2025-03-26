//给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
//。 
//
// candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：candidates = [10,1,2,7,6,1,5], target = 8
//输出：
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2： 
//
// 
//输入：candidates = [2,5,2,1,2], target = 5
//输出：
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// 
//
// 
// 注意：本题与主站 40 题相同： https://leetcode-cn.com/problems/combination-sum-ii/ 
//
// Related Topics 数组 回溯 👍 61 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ans;
    int target;
    vector<int> path;

    void dfs(vector<int> &nums, int pos, int sum) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = pos; i < nums.size(); i += 1) {
            if (sum + nums[i] > target) return;
            if (i != pos && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, sum + nums[i]);
            path.pop_back();
        }
        return;
    }


    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

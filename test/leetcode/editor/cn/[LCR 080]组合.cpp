//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 
//
// 示例 1： 
//
// 
//输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入: n = 1, k = 1
//输出: [[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// 
//
// 
// 注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/ 
//
// Related Topics 数组 回溯 👍 65 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ans;
    int n, k;

    void dfs(vector<int> &cur, int pos, int count) {
        if (count == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = pos; i <= n; i += 1) {
            cur.push_back(i);
            dfs(cur, i + 1, count + 1);
            cur.pop_back();
        }
        return;

    }

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> cur;
        dfs(cur, 1, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

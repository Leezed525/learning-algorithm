//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
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
//输入：n = 1, k = 1
//输出：[[1]] 
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
// Related Topics 回溯 👍 1732 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> vis;

    void dfs(int n, int k, int start){
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; i += 1) {
            if (vis[i] == 1) continue;
            vis[i] = 1;
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vis = vector<int>(n + 1, 0);
        dfs(n, k, 1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

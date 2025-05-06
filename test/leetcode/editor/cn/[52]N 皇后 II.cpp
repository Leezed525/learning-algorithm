//n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 
//
// 
//
// 
// 
// 示例 1： 
// 
// 
//输入：n = 4
//输出：2
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
// 
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
//
// Related Topics 回溯 👍 569 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    struct node {
        int x, y;
    };
//    vector<vector<string>> ans;
    vector<node> path;
    int ans = 0;

    bool check(int x, int y) {
        // 检查是否有皇后在同一列
        for (auto &i: path) {
            if (i.y == y) return false;
        }
        // 检查是否有皇后在同一斜线
        for (auto &i: path) {
            if (abs(i.x - x) == abs(i.y - y)) return false;
        }
        // 检查是否有皇后在同一行
        for (auto &i: path) {
            if (i.x == x) return false;
        }
        return true;
    }

    void dfs(int x, int n) {
        if(x == n){
            ans += 1;
            return;
        }
        for (int i = 0; i < n; i += 1) {
            if (check(x, i)) {
                path.push_back({x, i});
                dfs(x + 1, n);
                path.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        dfs(0, n);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

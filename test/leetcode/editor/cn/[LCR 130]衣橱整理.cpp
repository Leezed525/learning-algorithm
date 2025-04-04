//家居整理师将待整理衣橱划分为 m x n 的二维矩阵 grid，其中 grid[i][j] 代表一个需要整理的格子。整理师自 grid[0][0] 开始 逐
//行逐列 地整理每个格子。 
//
// 整理规则为：在整理过程中，可以选择 向右移动一格 或 向下移动一格，但不能移动到衣柜之外。同时，不需要整理 digit(i) + digit(j) > 
//cnt 的格子，其中 digit(x) 表示数字 x 的各数位之和。 
//
// 请返回整理师 总共需要整理多少个格子。 
//
// 
//
// 示例 1： 
//
// 
//输入：m = 4, n = 7, cnt = 5
//输出：18
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n, m <= 100 
// 0 <= cnt <= 20 
// 
//
// 
//
// Related Topics 深度优先搜索 广度优先搜索 动态规划 👍 686 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int digit(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    int wardrobeFinishing(int m, int n, int cnt) {
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            ans += 1;
            int x= p.first, y = p.second;
            for (int i = 0; i < 2; i += 1) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= m || ny >= n) continue;
                if (vis[nx][ny]) continue;
                if (digit(nx) + digit(ny) > cnt) continue;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
//        cout << ans;
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

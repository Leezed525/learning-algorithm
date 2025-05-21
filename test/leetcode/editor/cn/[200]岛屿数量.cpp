//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 2765 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        int count = 0;

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count += 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        int x = p.first;
                        int y = p.second;
                        for (int k = 0; k < 4; k += 1) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(grid[nx][ny] == '1' && !vis[nx][ny]) {
                                q.push({nx, ny});
                                vis[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }

        return count;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//给定一个由 0 和 1 组成的非空二维数组 grid ，用来表示海洋岛屿地图。 
//
// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 
//0（代表水）包围着。 
//
// 找到给定的二维数组中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1
//,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0
//,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//输出: 6
//解释: 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。 
//
// 示例 2： 
//
// 
//输入: grid = [[0,0,0,0,0,0,0,0]]
//输出: 0 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 50 
// grid[i][j] is either 0 or 1 
// 
//
// 
//
// 注意：本题与主站 695 题相同： https://leetcode-cn.com/problems/max-area-of-island/ 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 101 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    int fa[55][55];

    void init() {
        for (int i = 0; i <= 50; i += 1) {
            for (int j = 0; j <= 50; j += 1) {
                fa[i][j] = i * 50 + j;
            }
        }
    }

    int get(int x, int y) {
        if (fa[x][y] != x * 50 + y)
            return fa[x][y] = get(fa[x][y] / 50, fa[x][y] % 50);
        else
            return fa[x][y];
    }

    void merge(int x1, int y1, int x2, int y2) {
        int val = get(x1, y1);
        fa[val / 50][val % 50] = get(x2, y2);
    }

    bool check(int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m) return true;
        else return false;
    }


    int maxAreaOfIsland(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        //1. 并查集做法 19ms  27MB
//        init();
//        for (int i = 0; i < n; i += 1) {
//            for (int j = 0; j < m; j += 1) {
//                if (grid[i][j]) {
//                    for (int k = 0; k < 4; k += 1) {
//                        int nx = i + dx[k];
//                        int ny = j + dy[k];
//                        if (check(nx, ny) && grid[nx][ny] == 1) {
//                            merge(i, j, nx, ny);
//                        }
//                    }
//                }
//            }
//        }
//
//        unordered_map<int, int> mp;
//        int ans = 0;
//        for (int i = 0; i < n; i += 1) {
//            for (int j = 0; j < m; j += 1) {
//                if (grid[i][j] == 1) {
//                    int root = get(i, j);
//                    mp[root] += 1;
//                    ans = max(ans, mp[root]);
//                }
//            }
//        }
//        return ans;



//        bfs做法  18ms  31.3MB
        int ans = 0;
        vector<vector<int>> vis = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    queue<pair<int, int>> q;
                    int tmp = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        tmp += 1;

                        for (int k = 0; k < 4; k += 1) {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];
                            if (check(nx, ny) && grid[nx][ny] == 1 && vis[nx][ny] == 0) {
                                q.push({nx, ny});
                                vis[nx][ny] = 1;
                            }
                        }
                    }
                    ans = max(ans, tmp);
                }
            }
        }

        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

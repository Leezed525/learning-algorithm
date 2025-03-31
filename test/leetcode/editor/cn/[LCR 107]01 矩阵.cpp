//给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。 
//
// 两个相邻元素间的距离为 1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
//输出：[[0,0,0],[0,1,0],[0,0,0]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
//输出：[[0,0,0],[0,1,0],[1,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n <= 10⁴ 
// 1 <= m * n <= 10⁴ 
// mat[i][j] is either 0 or 1. 
// mat 中至少有一个 0 
// 
//
// 
//
// 
// 注意：本题与主站 542 题相同：https://leetcode-cn.com/problems/01-matrix/ 
//
// Related Topics 广度优先搜索 数组 动态规划 矩阵 👍 66 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis = vector<vector<int>>(n, vector<int>(m, 0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k += 1) {
                int nx = cur.first + dx[k];
                int ny = cur.second + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                    ans[nx][ny] = ans[cur.first][cur.second] + 1;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

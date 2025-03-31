//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。 
//
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
//输出：4 
//解释：最长递增路径为 [1, 2, 6, 9]。 
//
// 示例 2： 
//
// 
//
// 
//输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
//输出：4 
//解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 
//
// 示例 3： 
//
// 
//输入：matrix = [[1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 2³¹ - 1 
// 
//
// 
//
// 
// 注意：本题与主站 329 题相同： https://leetcode-cn.com/problems/longest-increasing-path-
//in-a-matrix/ 
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 记忆化搜索 数组 动态规划 矩阵 👍 54 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int dp[210][210] = {0};
    int vis[210][210] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n,m;
    vector<vector<int>> matrix;

    void dfs(int x, int y){
        int len = 0;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >=0 && ny < m && matrix[nx][ny] > matrix[x][y] ){
                if(vis[nx][ny] == 0){
                    dfs(nx, ny);
                }
                len = max(len, dp[nx][ny]);
            }
        }
        len += 1;
        dp[x][y] = len;
    }


    int longestIncreasingPath(vector<vector<int>> &matrix) {
        this->matrix = matrix;

        n = matrix.size();
        m = matrix[0].size();

        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if(vis[i][j] == 0){
                    dfs(i, j);
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

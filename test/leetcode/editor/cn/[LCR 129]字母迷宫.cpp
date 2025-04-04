//字母迷宫游戏初始界面记作 m x n 二维字符串数组 grid，请判断玩家是否能在 grid 中找到目标单词 target。 注意：寻找单词时 必须 按照字
//母顺序，通过水平或垂直方向相邻的单元格内的字母构成，同时，同一个单元格内的字母 不允许被重复使用 。 
//
// 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target = 
//"SEE"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target = 
//"ABCB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n = grid[i].length 
// 1 <= m, n <= 6 
// 1 <= target.length <= 15 
// grid 和 target 仅由大小写英文字母组成 
// 
//
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
//
// 
//
// 
//
// Related Topics 数组 字符串 回溯 矩阵 👍 846 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    string target;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int m, n;

    vector<vector<int>> vis;

    bool check(int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(vis[x][y]) return false;
        return true;
    }


    bool dfs(vector<vector<char> > &grid, int x, int y, int pos) {
        if (pos == target.size()) return true;
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(nx, ny) && grid[nx][ny] == target[pos]) {
                vis[nx][ny] = 1;
                if (dfs(grid, nx, ny, pos + 1)) return true;
                vis[nx][ny] = 0;
            }
        }
        return false;
    }

    bool wordPuzzle(vector<vector<char>> &grid, string target) {
        this->target = target;
        n = grid.size();
        m = grid[0].size();

        vis = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j] == target[0]) {
                    vis[i][j] = 1;
                    if (dfs(grid, i, j, 1)) return true;
                    vis[i][j] = 0;
                }
            }
        }

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

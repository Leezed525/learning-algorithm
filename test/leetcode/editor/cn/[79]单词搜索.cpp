//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"SEE"
//输出：true
// 
//
// 示例 3： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
//
// Related Topics 深度优先搜索 数组 字符串 回溯 矩阵 👍 1999 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool visited[6][6] = {false};
    int n,m;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool check(int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(visited[x][y]) return false;
        return true;
    }

    bool dfs(vector<vector<char>> &board, string &word, int index, int x, int y) {
        if(index == word.size()) return true;
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(nx, ny) && board[nx][ny] == word[index]) {
                visited[nx][ny] = true;
                if(dfs(board, word, index + 1, nx, ny)) return true;
                visited[nx][ny] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(dfs(board, word, 1, i, j)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

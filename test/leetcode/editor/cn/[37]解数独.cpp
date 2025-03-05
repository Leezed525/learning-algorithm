//编写一个程序，通过填充空格来解决数独问题。 
//
// 数独的解法需 遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 
//
// 
// 
// 
// 示例 1： 
// 
// 
//输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".
//",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".
//","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6
//"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[
//".",".",".",".","8",".",".","7","9"]]
//输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8
//"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],[
//"4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9",
//"6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4",
//"5","2","8","6","1","7","9"]]
//解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
// 
// 
// 
// 
//
//
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字或者 '.' 
// 题目数据 保证 输入数独仅有一个解 
// 
//
// Related Topics 数组 哈希表 回溯 矩阵 👍 1901 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool find_flag = false;

    bool check(vector<vector<char>> &board, int x, int y, int n) {
        for (int i = 0; i < 9; i += 1) {
            // 检查行
            if (board[x][i] == n + '0' && i != y) return false;
            //检查列
            if (board[i][y] == n + '0' && i != x) return false;
        }
        // 检查九宫格
        int x0 = x / 3 * 3, y0 = y / 3 * 3;
        for (int i = x0; i < x0 + 3; i += 1) {
            for (int j = y0; j < y0 + 3; j += 1) {
                if (board[i][j] == n + '0' && i != x && j != y) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<char>> &board){
        int x = -1, y = -1;
        for (int i = 0; i < 9; i += 1) {
            for (int j = 0; j < 9; j += 1) {
                if (board[i][j] == '.') {
                    x = i;
                    y = j;
                    for (int num = 1; num <= 9; num += 1) {
                        if (check(board, x, y, num)) {
                            board[x][y] = num + '0';
                            if(dfs(board)) return true;
                            board[x][y] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board) {
        dfs(board);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

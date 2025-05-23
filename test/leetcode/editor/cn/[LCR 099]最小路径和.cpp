//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：一个机器人每次只能向下或者向右移动一步。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[1,2,3],[4,5,6]]
//输出：12
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 100 
// 
//
// 
//
// 
// 注意：本题与主站 64 题相同： https://leetcode-cn.com/problems/minimum-path-sum/ 
//
// Related Topics 数组 动态规划 矩阵 👍 76 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int dp[210][210] = {0};
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i <= m; i += 1) {
            for (int j = 1; j <= n; j += 1) {
                if (i == 1) dp[i][j] = dp[i][j - 1] + grid[i - 1][j - 1];
                else if (j == 1) dp[i][j] = dp[i - 1][j] + grid[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

//        for (int i = 1; i <= m; i += 1) {
//            for (int j = 1; j <= n; j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }

        return dp[m][n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

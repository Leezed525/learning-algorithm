//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：4
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] 为 '0' 或 '1' 
// 
//
// Related Topics 数组 动态规划 矩阵 👍 1798 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[310][310] = {0};
        int ans = 0;
        for (int i = 0; i < m; i += 1) {
            dp[0][i] = matrix[0][i] - '0';
            ans = max(ans, dp[0][i]);
        }
        for (int i = 1; i < n; i += 1) {
            dp[i][0] = matrix[i][0] - '0';
            ans = max(ans, dp[i][0]);
            for (int j = 1; j < m; j += 1) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

//现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为： 
//
// 
// 只能从架子的左上角开始拿珠宝 
// 每次可以移动到右侧或下侧的相邻位置 
// 到达珠宝架子的右下角时，停止拿取 
// 
//
// 注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。 
//
// 
//
// 示例 1： 
//
// 
//输入：frame = [[1,3,1],[1,5,1],[4,2,1]]
//输出：12
//解释：路径 1→3→5→2→1 可以拿到最高价值的珠宝 
//
// 
//
// 提示： 
//
// 
// 0 < frame.length <= 200 
// 0 < frame[0].length <= 200 
// 
//
// 
//
// Related Topics 数组 动态规划 矩阵 👍 554 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jewelleryValue(vector<vector<int>> &frame) {
        int dp[210][210] = {0};
        int n = frame.size();
        int m = frame[0].size();
        for (int i = 0; i < m; i += 1) {
            dp[0][i] = frame[0][i] + (i == 0 ? 0 : dp[0][i - 1]);
        }
        for (int i = 1; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                dp[i][j] = frame[i][j] + max(dp[i - 1][j], (j > 0 ? dp[i][j - 1] : 0));
            }
        }
        //输出dp
//        for (int i = 0; i < n; i += 1) {
//            for (int j = 0; j < m; j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
        return dp[n - 1][m - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//你选择掷出 num 个色子，请返回所有点数总和的概率。 
//
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 num 个骰子所能掷出的点数集合中第 i 小的那个的概率。 
//
// 
//
// 示例 1： 
//
// 
//输入：num = 3
//输出：[0.00463,0.01389,0.02778,0.04630,0.06944,0.09722,0.11574,0.12500,0.12500,0.
//11574,0.09722,0.06944,0.04630,0.02778,0.01389,0.00463]
// 
//
// 示例 2： 
//
// 
//输入：num = 5
//输出:[0.00013,0.00064,0.00193,0.00450,0.00900,0.01620,0.02636,0.03922,0.05401,0.
//06944,0.08372,0.09452,0.10031,0.10031,0.09452,0.08372,0.06944,0.05401,0.03922,0.
//02636,0.01620,0.00900,0.00450,0.00193,0.00064,0.00013]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num <= 11 
// 
//
// 
//
// Related Topics 数学 动态规划 概率与统计 👍 596 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> statisticsProbability(int num) {
        int dp[15][100] = {0};
        for (int i = 1; i <= 6; i += 1) {
            dp[1][i] = 1;
        }
        int total = num > 1 ? 0 : 6;

        for (int i = 2; i <= num; i += 1) {
            for (int j = 1; j <= (i - 1) * 5 + 6; j += 1) {
                for (int k = 0; k < 6; k += 1) {
                    if (j - k > 0) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
                if(i == num) {
                    total += dp[i][j];
                }
            }
        }
        //输出dp
//
//         for (int i = 1; i <= num; i += 1) {
//            for (int j = 1; j <= (i - 1) * 5 + 6; j += 1) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//         }




//        int total = pow(6, num);
        vector<double> res;
        for (int i = 1; i <= (num - 1) * 5 + 6; i += 1) {
            res.push_back(dp[num][i] / (double)total);
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

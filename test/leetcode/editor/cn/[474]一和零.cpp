//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。 
//
// 
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。 
// 
//
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//输出：4
//解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
//其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 
//n 的值 3 。
// 
//
// 示例 2： 
//
// 
//输入：strs = ["10", "0", "1"], m = 1, n = 1
//输出：2
//解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 600 
// 1 <= strs[i].length <= 100 
// strs[i] 仅由 '0' 和 '1' 组成 
// 1 <= m, n <= 100 
// 
//
// Related Topics 数组 字符串 动态规划 👍 1221 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    struct node {
        int zero;
        int one;
        string str;
    };

    node getZeroOne(string s) {
        int zero = 0, one = 0;
        for (int i = 0; i < s.length(); i += 1) {
            if (s[i] == '0') {
                zero += 1;
            } else {
                one += 1;
            }
        }
        return {zero, one, s};
    }

    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<node> nodes;
        for (int i = 0; i < strs.size(); i += 1) {
            nodes.push_back(getZeroOne(strs[i]));
        }
        int dp[105][105] = {0};
        for (int i = 0; i < nodes.size(); i += 1) {
            for (int j = m; j >= nodes[i].zero; j -= 1) {
                for (int k = n; k >= nodes[i].one; k -= 1) {
                    dp[j][k] = max(dp[j][k], dp[j - nodes[i].zero][k - nodes[i].one] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

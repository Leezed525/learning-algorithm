//今天的有氧运动训练内容是在一个长条形的平台上跳跃。平台有 num 个小格子，每次可以选择跳 一个格子 或者 两个格子。请返回在训练过程中，学员们共有多少种不
//同的跳跃方式。 
//
// 结果可能过大，因此结果需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：n = 5
//输出：8
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 100 
// 
//
// 注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/ 
//
// Related Topics 记忆化搜索 数学 动态规划 👍 423 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trainWays(int num) {
        int ppre = 1,pre = 1,cur = 1;
        for (int i = 2; i <= num; ++i) {
            cur = (ppre + pre) % 1000000007;
            ppre = pre;
            pre = cur;
        }

        return num == 0 ? 1 : cur;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

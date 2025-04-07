//现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下： 
//
// 
// 密文由非负整数组成 
// 数字 0-25 分别对应字母 a-z 
// 
//
// 请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：ciphertext = 216612
//输出：6
//解释：216612 解密后有 6 种不同的形式，分别是 "cbggbc"，"vggbc"，"vggm"，"cbggm"，"cqgbc" 和 "cqgm" 
//
// 
//
// 提示： 
//
// 
// 0 <= ciphertext < 2³¹ 
// 
//
// 
//
// Related Topics 字符串 动态规划 👍 621 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int crackNumber(int ciphertext) {
        string s = "0" + to_string(ciphertext);
        int dp[20] = {0};

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < s.size(); i++) {
            dp[i] = dp[i - 1];
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(num <= 25 && num >= 10) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size() - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

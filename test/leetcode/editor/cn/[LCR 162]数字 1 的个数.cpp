//给定一个整数 num，计算所有小于等于 num 的非负整数中数字 1 出现的个数。 
//
// 
//
// 示例 1： 
//
// 
//输入：num = 0
//输出：0
// 
//
// 示例 2： 
//
// 
//输入：num = 13
//输出：6 
//
// 
//
// 提示： 
//
// 
// 0 <= num < 10⁹ 
// 
//
// 注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/ 
//
// 
//
// Related Topics 递归 数学 动态规划 👍 472 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int digitOneInNumber(int num) {
        int ans = 0;
        long digit = 1;
        int high = num / 10, cur = num % 10, low = 0;
        while (high != 0 || cur != 0) {
            if (cur == 0) ans += high * digit;
            else if(cur == 1) ans += high * digit + low + 1;
            else ans += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high = high / 10;
            digit *= 10;
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

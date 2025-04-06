//某班级学号记录系统发生错乱，原整数学号序列 [1,2,3,4,...] 分隔符丢失后变为 1234... 的字符序列。请实现一个函数返回该字符序列中的第 
//k 位数字。 
//
// 
//
// 示例 1： 
//
// 
//输入：k = 5
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：k = 12
//输出：1
//解释：第 12 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 1 ，它是 11 的一部分。 
//
// 
//
// 提示： 
//
// 
// 0 <= k < 2³¹ 
//
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
//
// 
//
// Related Topics 数学 二分查找 👍 370 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthNumber(int k) {
        if(k < 10) return k;
        int digit = 0;
        long long count = 0;
        long long cur = 0;
        while (true) {
            digit += 1;
            cur = count + digit * 9 * pow(10, digit - 1);
            if (cur >= k) {
                break;
            }
            count = cur;
        }
        int num = (k - count - 1) / digit;
        int index = (k - count - 1) % digit;
        int start = pow(10, digit - 1);
        int res = start + num;
        index = digit - index - 1;
        while (index--) {
            res /= 10;
        }
        return res % 10;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

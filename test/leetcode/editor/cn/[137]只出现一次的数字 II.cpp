//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。 
//
// 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,2,3,2]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,0,1,0,1,99]
//输出：99
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 
// 
//
// Related Topics 位运算 数组 👍 1109 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count[32] = {0};
    int ans = 0;
    int singleNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                count[j] += nums[i] & 1;
                count[j] %= 3;
                nums[i] >>= 1;
            }
        }
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= count[31 - i];
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 5583 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int> &height) {



        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);

        // 从右往左 找到每个柱子右边最高的柱子
        int maxr = 0;
        for (int i = height.size() - 1; i >= 0; i -= 1) {
            maxr = max(maxr, height[i]);
            right[i] = maxr;
        }

        int maxl = 0;
        for(int i = 0; i < height.size(); i += 1) {
            maxl = max(maxl, height[i]);
            left[i] = maxl;
        }

        int res = 0;


        //输出每个柱子的左右最高柱子
//        for (int i = 0; i < height.size(); i += 1) {
//            cout << left[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < height.size(); i += 1) {
//            cout << right[i] << " ";
//        }
        for (int i = 0; i < height.size(); i += 1) {
            res += min(left[i], right[i]) - height[i];
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

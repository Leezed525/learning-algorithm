//给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=10⁵ 
// 0 <= heights[i] <= 10⁴ 
// 
//
// 
//
// 
// 注意：本题与主站 84 题相同： https://leetcode-cn.com/problems/largest-rectangle-in-
//histogram/ 
//
// Related Topics 栈 数组 单调栈 👍 124 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> ls, rs;
        vector<int> lres(heights.size(), 0), rres(heights.size(), 0);
        //计算右边有多少个比i节点高的矩阵
        for (int i = 0; i < heights.size(); i += 1) {
            if (rs.empty()) {
                rs.push(i);
                continue;
            }
            while (!rs.empty() && heights[i] < heights[rs.top()]) {
                rres[rs.top()] = i - rs.top() - 1;
                rs.pop();
            }
            rs.push(i);
        }
        while (!rs.empty()) {
            rres[rs.top()] = heights.size() - rs.top() - 1;
            rs.pop();
        }
        //计算左边
        for (int i = heights.size() - 1; i >= 0; i -= 1) {
            if (ls.empty()) {
                ls.push(i);
                continue;
            }
            while (!ls.empty() && heights[i] < heights[ls.top()]) {
                lres[ls.top()] = ls.top() - i - 1;
                ls.pop();
            }
            ls.push(i);
        }

        while (!ls.empty()) {
            lres[ls.top()] = ls.top();
            ls.pop();
        }
        //输出左右矩阵
//        for (int i = 0; i < lres.size(); i += 1) cout << lres[i] << " ";
//        cout << endl;
//        for (int i = 0; i < rres.size(); i += 1) cout << rres[i] << " ";
//        cout << endl;

        int res = 0;

        for (int i = 0; i < rres.size(); i += 1) {
            res = max(res, (rres[i] + lres[i] + 1) * heights[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

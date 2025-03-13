//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
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
// Related Topics 栈 数组 单调栈 👍 2885 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {

        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);

        stack<int> sl, sr;
        for (int i = 0; i < heights.size(); i += 1) {
            if (sr.empty() || heights[i] >= heights[sr.top()]) {
                sr.push(i);
            } else {
                while (!sr.empty() && heights[i] < heights[sr.top()]) {
                    right[sr.top()] = i - sr.top() - 1;
//                    int len = i - sr.top() - 1;
//                    cout << "right[" << sr.top()  << "] = " << len << endl;
                    sr.pop();
                }
                sr.push(i);
            }
        }
        int len = heights.size();
        while (!sr.empty()) {
            right[sr.top()] = len - sr.top() - 1;
            sr.pop();
        }

        for (int i = heights.size() - 1; i >= 0; i -= 1) {
            if (sl.empty() || heights[i] >= heights[sl.top()]) {
                sl.push(i);
            } else {
                while (!sl.empty() && heights[i] < heights[sl.top()]) {
                    left[sl.top()] = sl.top() - i - 1;
                    sl.pop();
                }
                sl.push(i);
            }
        }

        while (!sl.empty()) {
            left[sl.top()] = sl.top();
            sl.pop();
        }

        //输出left和right
//        for (int i = 0; i < heights.size(); i += 1) {
//            cout << left[i] << " ";
//        }
//        cout << endl;
//
//        for (int i = 0; i < heights.size(); i += 1) {
//            cout << right[i] << " ";
//        }

        int res = 0;

        for(int i = 0;i < heights.size(); i += 1) {
            res = max(res, (left[i] + right[i] + 1) * heights[i]);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

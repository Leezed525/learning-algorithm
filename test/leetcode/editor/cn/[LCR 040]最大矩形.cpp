//给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。 
//
// 注意：此题 matrix 输入格式为一维 01 字符串数组。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：matrix = ["10100","10111","11111","10010"]
//输出：6
//解释：最大矩形如上图所示。
// 
//
// 示例 2： 
//
// 
//输入：matrix = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：matrix = ["0"]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：matrix = ["1"]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：matrix = ["00"]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// rows == matrix.length 
// cols == matrix[0].length 
// 0 <= row, cols <= 200 
// matrix[i][j] 为 '0' 或 '1' 
// 
//
// 
//
// 注意：本题与主站 85 题相同（输入参数格式不同）： https://leetcode-cn.com/problems/maximal-
//rectangle/ 
//
// Related Topics 栈 数组 动态规划 矩阵 单调栈 👍 99 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = 0; i < n; i += 1) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                right[s.top()] = i;
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            right[s.top()] = n;
            s.pop();
        }
        int res = 0;
        for (int i = 0; i < n; i += 1) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }

    int maximalRectangle(vector<string> &matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> height(matrix[0].size(), 0);
        int ans = 0;
        for (int i = 0; i < matrix.size(); i += 1) {
            for (int j = 0; j < matrix[i].size(); j += 1)
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

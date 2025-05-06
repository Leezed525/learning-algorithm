//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1922 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int x = matrix.size();
        int y = matrix[0].size();
        int all_round = (min(x, y) + 1) / 2;
        for (int round = 0; round < all_round; round += 1) {
            //向右
            for (int j = round; j < y - round; j++) ans.push_back(matrix[round][j]);
            //向下
            for (int i = round + 1; i < x - round; i++) ans.push_back(matrix[i][y - round - 1]);
            //向左
            for (int j = y - round - 2; j >= round && x - round - 1 != round; j--)
                ans.push_back(matrix[x - round - 1][j]);
            //向上
            for (int i = x - round - 2; i > round && y - round - 1 != round; i--) ans.push_back(matrix[i][round]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

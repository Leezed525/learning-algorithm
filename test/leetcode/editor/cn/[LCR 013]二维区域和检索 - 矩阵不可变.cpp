//给定一个二维矩阵 matrix，以下类型的多个请求： 
//
// 
// 计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。 
// 
//
// 实现 NumMatrix 类： 
//
// 
// NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化 
// int sumRegion(int row1, int col1, int row2, int col2) 返回左上角 (row1, col1) 、右下角
// (row2, col2) 的子矩阵的元素总和。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: 
//["NumMatrix","sumRegion","sumRegion","sumRegion"]
//[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,
//1,2,2],[1,2,2,4]]
//输出: 
//[null, 8, 11, 12]
//
//解释:
//NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,
//0,1,7],[1,0,3,0,5]]]);
//numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
//numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
//numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200
// 
// -10⁵ <= matrix[i][j] <= 10⁵ 
// 0 <= row1 <= row2 < m 
// 0 <= col1 <= col2 < n 
// 
// 最多调用 10⁴ 次 sumRegion 方法 
// 
//
// 
//
// 
// 注意：本题与主站 304 题相同： https://leetcode-cn.com/problems/range-sum-query-2d-
//immutable/ 
//
// Related Topics 设计 数组 矩阵 前缀和 👍 97 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
public:

    vector<vector<int>> pre_sum;
//    vector<vector<int>> m;

    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i += 1) {
            pre_sum.push_back({});
            int pre = 0;
            for (int j = 0; j < matrix[i].size(); j += 1) {
                pre += matrix[i][j];
                pre_sum[i].push_back(pre + (i == 0 ? 0 : pre_sum[i - 1][j]));
            }
        }

        //调试，打印前缀和矩阵
//        for (int i = 0; i < pre_sum.size(); i += 1) {
//            for (int j = 0; j < pre_sum[i].size(); j += 1) {
//                cout << pre_sum[i][j] << " ";
//            }
//            cout << endl;
//        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum += pre_sum[row2][col2];
        if (row1 > 0) sum -= pre_sum[row1 - 1][col2];
        if (col1 > 0) sum -= pre_sum[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) sum += pre_sum[row1 - 1][col1 - 1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)

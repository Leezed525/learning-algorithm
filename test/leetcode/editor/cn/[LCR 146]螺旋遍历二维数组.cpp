//给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。 
//
// 螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：array = [[1,2,3],[8,9,4],[7,6,5]]
//输出：[1,2,3,4,5,6,7,8,9]
// 
//
// 示例 2： 
//
// 
//输入：array  = [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
//输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= array.length <= 100 
// 0 <= array[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
//
// 
//
// Related Topics 数组 矩阵 模拟 👍 609 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>> &array) {
        vector<int> ans;
        if (array.size() == 0 || array[0].size() == 0) return ans;
        int x = array.size();
        int y = array[0].size();
        int all_round = (min(x, y) + 1) / 2;
        for (int round = 0; round < all_round; round += 1) {
            //向右
            for (int j = round; j < y - round; j++) ans.push_back(array[round][j]);
            //向下
            for (int i = round + 1; i < x - round; i++) ans.push_back(array[i][y - round - 1]);
            //向左
            for (int j = y - round - 2; j >= round && x - round - 1 != round; j--)
                ans.push_back(array[x - round - 1][j]);
            //向上
            for (int i = x - round - 2; i > round && y - round - 1 != round; i--) ans.push_back(array[i][round]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

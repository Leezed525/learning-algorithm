//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1414 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(vector<int>(n, 0));
        }
        int cur = 1;
        int i = 0, j = 0;
        int num = 1;
        int all_round = (n + 1) / 2;
        for (int round = 0; round < all_round; round += 1) {
            //向右填充
            while (j < n - round) {
                cout << i << " " << j << " " <<  num << endl;
                ans[i][j++] = num++;
            }
            j--;
            i++;
            if (num > n * n) {
                break;
            }
            //向下
            while (i < n - round) {
                cout << i << " " << j << " " <<  num << endl;
                ans[i++][j] = num++;
            }
            j--;
            i--;
            //向左
            while (j >= 0 + round) {
                cout << i << " " << j << " " <<  num << endl;
                ans[i][j--] = num++;
            }
            i--;
            j++;
            //向上
            while (i > 0 + round) {
                cout << i << " " << j << " " <<  num << endl;
                ans[i--][j] = num++;
            }
            i++;
            j++;
        }

        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

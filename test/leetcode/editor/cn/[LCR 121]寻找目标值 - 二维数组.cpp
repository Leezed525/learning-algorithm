//m*n 的二维数组 plants 记录了园林景观的植物排布情况，具有以下特性： 
//
// 
// 每行中，每棵植物的右侧相邻植物不矮于该植物； 
// 每列中，每棵植物的下侧相邻植物不矮于该植物。 
// 
//
// 
//
// 请判断 plants 中是否存在目标高度值 target。 
//
// 
//
// 示例 1： 
//
// 
//输入：plants = [[2,3,6,8],[4,5,8,9],[5,9,10,12]], target = 8
//
//输出：true
// 
//
// 
//
// 示例 2： 
//
// 
//输入：plants = [[1,3,5],[2,5,7]], target = 4
//
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 1000 
// 0 <= m <= 1000 
// 
//
// 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/ 
//
// 
//
// Related Topics 数组 二分查找 分治 矩阵 👍 1037 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool binary_search(vector<int> &arr, int target){
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) l = mid + 1;
            else r = mid;
        }
        return arr[l] == target;
    }

    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target) {
        int n = plants.size();
        for (int i = 0; i < n; i++) {
            if(plants[i].size() == 0) continue;
            if(plants[i][0] <= target && plants[i][plants[i].size() - 1] >= target){
                if(binary_search(plants[i], target)) return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

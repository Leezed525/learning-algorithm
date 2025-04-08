//为了深入了解这些生物群体的生态特征，你们进行了大量的实地观察和数据采集。数组 arrayA 记录了各个生物群体数量数据，其中 arrayA[i] 表示第 
//i 个生物群体的数量。请返回一个数组 arrayB，该数组为基于数组 arrayA 中的数据计算得出的结果，其中 arrayB[i] 表示将第 i 个生物群体的数
//量从总体中排除后的其他数量的乘积。 
//
// 
//
// 示例 1： 
//
// 
//输入：arrayA = [2, 4, 6, 8, 10]
//输出：[1920, 960, 640, 480, 384]
// 
//
// 
//
// 提示： 
//
// 
// 所有元素乘积之和不会溢出 32 位整数 
// arrayA.length <= 100000 
// 
//
// 
//
// Related Topics 数组 前缀和 👍 356 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> statisticalResult(vector<int> &arrayA) {
        int sum = 1;
        vector<int> pre(arrayA.size(), 1);
        vector<int> suf(arrayA.size(), 1);
        for (int i = 0; i < arrayA.size(); i++) {
            pre[i] = sum;
            sum *= arrayA[i];
        }
        sum = 1;
        for (int i = arrayA.size() - 1; i >= 0; i--) {
            suf[i] = sum;
            sum *= arrayA[i];
        }

        vector<int> res;

        for (int i = 0; i < arrayA.size(); i++) {
            res.push_back(pre[i] * suf[i]);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//教练使用整数数组 actions 记录一系列核心肌群训练项目编号。为增强训练趣味性，需要将所有奇数编号训练项目调整至偶数编号训练项目之前。请将调整后的训练项
//目编号以 数组 形式返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：actions = [1,2,3,4,5]
//输出：[1,3,5,2,4] 
//解释：为正确答案之一 
//
// 
//
// 提示： 
//
// 
// 0 <= actions.length <= 50000 
// 0 <= actions[i] <= 10000 
// 
//
// 
//
// Related Topics 数组 双指针 排序 👍 339 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        vector<int> odd, even;
        for (int i = 0; i < actions.size(); i++) {
            if (actions[i] % 2 == 0) {
                even.push_back(actions[i]);
            } else {
                odd.push_back(actions[i]);
            }
        }
        vector<int> res;
        for (int i = 0; i < odd.size(); i++) {
            res.push_back(odd[i]);
        }
        for (int i = 0; i < even.size(); i++) {
            res.push_back(even[i]);
        }
        return res;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

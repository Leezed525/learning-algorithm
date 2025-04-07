//教学过程中，教练示范一次，学员跟做三次。该过程被混乱剪辑后，记录于数组 actions，其中 actions[i] 表示做出该动作的人员编号。请返回教练的编
//号。 
//
// 
//
// 示例 1： 
//
// 
//输入：actions = [5, 7, 5, 5]
//输出：7
// 
//
// 示例 2： 
//
// 
//输入：actions = [12, 1, 6, 12, 6, 12, 6]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= actions.length <= 10000 
// 1 <= actions[i] < 2^31 
// 
//
// Related Topics 位运算 数组 👍 479 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trainingPlan(vector<int>& actions) {
        int count[32] = {0};
        for (int i: actions) {
            int idx = 0;
            while (idx < 32) {
                count[idx] += (i >> idx) & 1;
                idx++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] % 3 == 1) {
                ans |= (1 << i);
            }
        }

        return ans;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

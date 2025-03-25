//给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 
//i 的概率与 w[i] 成正比。 
//
// 
// 
//
// 例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 +
// 3) = 0.75（即，75%）。 
//
// 也就是说，选取下标 i 的概率为 w[i] / sum(w) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：
//inputs = ["Solution","pickIndex"]
//inputs = [[[1]],[]]
//输出：
//[null,0]
//解释：
//Solution solution = new Solution([1]);
//solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。 
//
// 示例 2： 
//
// 
//输入：
//inputs = ["Solution","pickIndex","pickIndex","pickIndex","pickIndex",
//"pickIndex"]
//inputs = [[[1,3]],[],[],[],[],[]]
//输出：
//[null,1,1,1,1,0]
//解释：
//Solution solution = new Solution([1, 3]);
//solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
//solution.pickIndex(); // 返回 1
//solution.pickIndex(); // 返回 1
//solution.pickIndex(); // 返回 1
//solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。
//
//由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
//[null,1,1,1,1,0]
//[null,1,1,1,1,1]
//[null,1,1,1,0,0]
//[null,1,1,1,0,1]
//[null,1,0,1,0,0]
//......
//诸若此类。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= w.length <= 10000 
// 1 <= w[i] <= 10^5 
// pickIndex 将被调用不超过 10000 次 
// 
//
// 
//
// 
// 注意：本题与主站 528 题相同： https://leetcode-cn.com/problems/random-pick-with-weight/ 
//
// Related Topics 数组 数学 二分查找 前缀和 随机化 👍 62 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sum = 0;
    vector<int> presum;

    Solution(vector<int> &w) {
        for (int i: w) {
            sum += i;
            presum.push_back(sum);
        }
    }

    int pickIndex() {
        //生成一个从0到sum的随机数
//        srand(time(0));
        int rand_sum = rand() % sum + 1;
        int l = 0, r = presum.size() - 1;
//        int ans = lower_bound(presum.begin(), presum.end(), rand_sum) - presum.begin();
//        return ans;

        while (l < r) {
            int mid = (l + r) / 2;
            if (presum[mid] == rand_sum) {
                return mid;
            } else if (presum[mid] < rand_sum) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
//leetcode submit region end(Prohibit modification and deletion)

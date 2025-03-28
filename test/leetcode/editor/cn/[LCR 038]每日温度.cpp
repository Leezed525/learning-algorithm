//请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不
//会升高，请在该位置用 0 来代替。 
//
// 
//
// 示例 1： 
//
// 
//输入：temperatures = [73,74,75,71,69,72,76,73]
//输出：[1,1,4,2,1,1,0,0]
// 
//
// 示例 2： 
//
// 
//输入：temperatures = [30,40,50,60]
//输出：[1,1,1,0]
// 
//
// 示例 3： 
//
// 
//输入：temperatures = [30,60,90]
//输出：[1,1,0] 
//
// 
//
// 提示： 
//
// 
// 1 <= temperatures.length <= 10⁵ 
// 30 <= temperatures[i] <= 100 
// 
//
// 
//
// 
// 注意：本题与主站 739 题相同： https://leetcode-cn.com/problems/daily-temperatures/ 
//
// Related Topics 栈 数组 单调栈 👍 107 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size(), 0);
        s.push(0);
        for (int i = 1; i < temperatures.size(); i += 1) {
            int t = temperatures[i];
            while (!s.empty() && t > temperatures[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

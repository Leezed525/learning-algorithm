//给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
//
// 
//
// 
// 注意：本题与主站 78 题相同： https://leetcode-cn.com/problems/subsets/ 
//
// Related Topics 位运算 数组 回溯 👍 93 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> numtobits(int num, int len) {
        stack<int> s;

        while (num) {
            s.push(num % 2);
            num /= 2;
        }
        vector<int> res(len, 0);
        for (int i = len - s.size(); i <len && !s.empty(); i += 1) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }

    string tostring(vector<int> nums) {
        string s = "";
        for (int i = 0; i < nums.size(); i += 1) {
            s += to_string(nums[i]) + " ";
        }
        return s;
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        int len = nums.size();
        int iter_max = pow(2, len);
        vector<vector<int>> ans;
        for (int i = 0; i < iter_max; i += 1) {
            vector<int> tmp;
            vector<int> pos = numtobits(i, len);
//            cout << tostring(pos) << endl;

            for (int j = 0; j < len; j += 1) {
                if(pos[j] == 1) tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
        }
        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

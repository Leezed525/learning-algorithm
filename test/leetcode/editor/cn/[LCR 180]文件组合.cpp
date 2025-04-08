//待传输文件被切分成多个部分，按照原排列顺序，每部分文件编号均为一个 正整数（至少含有两个文件）。传输要求为：连续文件编号总和为接收方指定数字 target 
//的所有文件。请返回所有符合该要求的文件传输组合列表。 
//
// 注意，返回时需遵循以下规则： 
//
// 
// 每种组合按照文件编号 升序 排列； 
// 不同组合按照第一个文件编号 升序 排列。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：target = 12
//输出：[[3, 4, 5]]
//解释：在上述示例中，存在一个连续正整数序列的和为 12，为 [3, 4, 5]。
// 
//
// 示例 2： 
//
// 
//输入：target = 18
//输出：[[3,4,5,6],[5,6,7]]
//解释：在上述示例中，存在两个连续正整数序列的和分别为 18，分别为 [3, 4, 5, 6] 和 [5, 6, 7]。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
//
// Related Topics 数学 双指针 枚举 👍 584 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ans;
        int l = 1, r = 2;
        int sum = 1;
        while (r <= (target + 1) / 2) {
            sum += r;
            r++;
            while (sum > target) {
                sum -= l++;
            }
            if (sum == target) {
                vector<int> tmp;
                for (int i = l; i < r; i++) {
                    tmp.push_back(i);
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

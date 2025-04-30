//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 如果非空，则仅由小写英文字母组成 
// 
//
// Related Topics 字典树 字符串 👍 3331 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s = "";
        int cur_len = 0;
        while (1) {
            bool flag = true;
            if (cur_len >= strs[0].size()) {
                return s;
            }
            char ch = strs[0][cur_len];
            for (int i = 1; i < strs.size(); i += 1) {
                if (cur_len >= strs[i].size() || strs[i][cur_len] != ch) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                s += ch;
                cur_len += 1;
            } else {
                return s;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

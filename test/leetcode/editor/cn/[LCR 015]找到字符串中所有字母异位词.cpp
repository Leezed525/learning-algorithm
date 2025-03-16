//给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 变位词 指字母相同，但排列不同的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的变位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的变位词。
// 
//
// 示例 2： 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的变位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的变位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的变位词。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
//
// 
//
// 注意：本题与主站 438 题相同： https://leetcode-cn.com/problems/find-all-anagrams-in-a-
//string/ 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 66 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool check(vector<int> &need, vector<int> &window) {
        for (int i = 0; i < 26; i += 1) {
            if (need[i] != window[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> need(26, 0), window(26, 0);
        int p_len = p.size();

        if (p_len > s.size()) {
            return res;
        }

        for (int i = 0; i < p_len; i += 1) {
            need[p[i] - 'a'] += 1;
            window[s[i] - 'a'] += 1;
        }

        if (check(need, window)) {
            res.push_back(0);
        }

        for (int i = p_len; i < s.size(); i += 1) {
            window[s[i] - 'a'] += 1;
            window[s[i - p_len] - 'a'] -= 1;
            if (check(need, window)) {
                res.push_back(i - p_len + 1);
            }
        }

        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

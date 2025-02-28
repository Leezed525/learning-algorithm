//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 1610 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> need;
        for (int i = 0; i < p.size(); i++) {
            need[p[i]]++;
        }
        int p_len = p.size();
        vector<int> res;
        for (int i = 0; i < s.size(); i += 1) {
            need[s[i]]--;
            if (i >= p_len - 1) {
                for (auto it = need.begin(); it != need.end(); it++) {
                    if (it->second != 0) {
                        break;
                    }
                    if (it == prev(need.end())) {
                        res.push_back(i - p_len + 1);
                    }
                }
                need[s[i - p_len + 1]]++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

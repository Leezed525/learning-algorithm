//给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。 
//
// 如果 s 中存在多个符合条件的子字符串，返回任意一个。 
//
// 
//
// 注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC" 
//解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C' 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3： 
//
// 
//输入：s = "a", t = "aa"
//输出：""
//解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 10⁵ 
// s 和 t 由英文字母组成 
// 
//
// 
//
// 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ 
//
// 
//
// 
// 注意：本题与主站 76 题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-
//substring/ 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 132 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> need, window;
        int res = INT_MAX;
        int ansl = 0, ansr = 0;
        int l = 0, r = 0;
        int need_char_cnt = 0;
        int window_char_cnt = 0;
        for (int i = 0; i < t.size(); i += 1) {
            if (!need.count(t[i])) need_char_cnt += 1;
            need[t[i]] += 1;
        }

        while (r < s.size()) {
            char c = s[r++];
            window[c] += 1;
            if (need.count(c) && window[c] == need[c]) {
                window_char_cnt += 1;
            }
            //如果满足了条件，开始缩小窗口
            while (need_char_cnt == window_char_cnt) {
                if (res > r - l) {
                    res = r - l;
                    ansl = l;
                    ansr = r;
                }
                char d = s[l++];
                if (need.count(d) && window[d] == need[d]) window_char_cnt -= 1;
                window[d] -= 1;
            }
        }
        return res == INT_MAX ? "" : s.substr(ansl, ansr - ansl);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

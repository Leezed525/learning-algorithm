//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。 
//
// 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入: s1 = "ab" s2 = "eidbaooo"
//输出: True
//解释: s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入: s1= "ab" s2 = "eidboaoo"
//输出: False
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s1.length, s2.length <= 10⁴ 
// s1 和 s2 仅包含小写字母 
// 
//
// 
//
// 
// 注意：本题与主站 567 题相同： https://leetcode-cn.com/problems/permutation-in-string/ 
//
// Related Topics 哈希表 双指针 字符串 滑动窗口 👍 110 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        int need_char_size = 0, window_char_size = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (!need.count(s1[i])) {
                need_char_size++;
            }
            need[s1[i]]++;
        }
        int l = 0, r = 0;
        while (r < s2.size()) {
            char c = s2[r++];
            if (need.count(c)) {
                window[c] += 1;
                //如果这个字符正好达到了要求，那么就满足一个字符
                if (window[c] == need[c]) window_char_size++;
                //如果这个字符超过了要求，那么就l++直到这个字符的数量正好等于要求
                while (window[c] > need[c]) {
                    char d = s2[l++];
                    if (window[d] == need[d]) window_char_size--;
                    window[d]--;
                }

                if (window_char_size == need_char_size) return true;
            } else {
                //如果不需要这个字符，代表以l为起点的子串不可能包含s1的排列
                // 清空窗口
                window.clear();
                l = r;
                window_char_size = 0;
            }

        }

        return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

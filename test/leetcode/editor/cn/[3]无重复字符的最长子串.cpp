//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 9642 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.length(); i += 1) {
            mp[s[i]] = -1;
        }
        //记录现在遍历的子串的长度
        int currentLength = 0;
        //记录现在遍历的子串的起始位置
        int currentStart = 0;
        //记录最长子串的长度
        int maxLength = 0;
        for (int i = 0; i < s.length(); i += 1) {
            if (mp[s[i]] == -1 || mp[s[i]] < currentStart) {
                currentLength += 1;
                mp[s[i]] = i;
            } else {
                currentStart = mp[s[i]] + 1;
                currentLength = i - mp[s[i]];
                mp[s[i]] = i;
            }
//            printf("i = %d, currentLength = %d\n", i, currentLength);
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

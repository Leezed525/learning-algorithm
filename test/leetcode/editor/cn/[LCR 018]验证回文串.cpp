//给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 本题中，将空字符串定义为有效的 回文串 。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "A man, a plan, a canal: Panama"
//输出: true
//解释："amanaplanacanalpanama" 是回文串 
//
// 示例 2： 
//
// 
//输入: s = "race a car"
//输出: false
//解释："raceacar" 不是回文串 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2 * 10⁵ 
// 字符串 s 由 ASCII 字符组成 
// 
//
// 
//
// 
// 注意：本题与主站 125 题相同： https://leetcode-cn.com/problems/valid-palindrome/ 
//
// Related Topics 双指针 字符串 👍 71 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool is_number(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool is_word(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }


    bool isPalindrome(string s) {
        int l = 0, r = 0;
        while (r < s.size()) {
            bool word_flag = is_word(s[r]);
            bool number_flag = is_number(s[r]);
            if (word_flag || number_flag) {
                if (word_flag) s[l] = tolower(s[r]);
                else s[l] = s[r];
                l += 1;
            }
            r += 1;
        }
        s = s.substr(0, l);
        l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l += 1;
            r -= 1;
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

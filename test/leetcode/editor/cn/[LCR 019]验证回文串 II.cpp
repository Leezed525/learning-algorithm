//给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "aba"
//输出: true
// 
//
// 示例 2： 
//
// 
//输入: s = "abca"
//输出: true
//解释: 可以删除 "c" 字符 或者 "b" 字符
// 
//
// 示例 3： 
//
// 
//输入: s = "abc"
//输出: false 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁵ 
// s 由小写英文字母组成 
// 
//
// 
//
// 
// 注意：本题与主站 680 题相同： https://leetcode-cn.com/problems/valid-palindrome-ii/ 
//
// Related Topics 贪心 双指针 字符串 👍 89 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool is_palindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }

    bool validPalindrome(string s) {
        //判断不删除字符的情况
        int l = 0, r = s.size() - 1;
        if (is_palindrome(s, l, r)) return true;
        //删除一个字符的情况
        l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return is_palindrome(s, l + 1, r) || is_palindrome(s, l, r - 1);
            }
            l += 1;
            r -= 1;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

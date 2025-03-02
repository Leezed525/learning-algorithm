//给定一个非空的字符串
// s ，检查是否可以通过由它的一个子串重复多次构成。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abab"
//输出: true
//解释: 可由子串 "ab" 重复两次构成。
// 
//
// 示例 2: 
//
// 
//输入: s = "aba"
//输出: false
// 
//
// 示例 3: 
//
// 
//输入: s = "abcabcabcabc"
//输出: true
//解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 1 <= s.length <= 10⁴ 
// s 由小写英文字母组成 
// 
//
// Related Topics 字符串 字符串匹配 👍 1261 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void getNext(string s, int next[]) {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); i += 1) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) j += 1;
            next[i] = j;
        }
    }

    bool kmp(string s, string t) {
        int next[t.size()];
        getNext(t, next);
        int j = 0;
        for (int i = 0; i < s.size(); i += 1) {
            while (j > 0 && s[i] != t[j]) j = next[j - 1];
            if (s[i] == t[j]) j += 1;
            if (j == t.size()) return true;
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t = t.substr(1, t.size() - 2);
        return kmp(t, s);

    }
};
//leetcode submit region end(Prohibit modification and deletion)

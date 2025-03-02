//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
// 
//
// 示例 2： 
//
// 
//输入：haystack = "leetcode", needle = "leeto"
//输出：-1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
//
// Related Topics 双指针 字符串 字符串匹配 👍 2367 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void get_Next(string s, int next[])        //这个函数对字符串s进行预处理得到next数组
    {
        int j = 0;
        next[0] = 0;    //初始化
        for (int i = 1; i < s.size(); i++) {    //i指针指向的是后缀末尾，j指针指向的是前缀末尾
            while (j > 0 && s[i] != s[j]) j = next[j - 1];    //前后缀不相同，去找j前一位的最长相等前后缀
            if (s[i] == s[j]) j++;    //前后缀相同，j指针后移
            next[i] = j;    //更新next数组
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];    //next数组
        get_Next(needle, next);        //得到next数组
        int j = 0;
        for (int i = 0; i < haystack.size(); i += 1) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j += 1;
            }
            if (j == needle.size()) {
                return i - j + 1;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

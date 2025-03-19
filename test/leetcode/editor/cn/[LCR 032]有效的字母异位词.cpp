//给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。 
//
// 注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "anagram", t = "nagaram"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "rat", t = "car"
//输出：false 
//
// 示例 3： 
//
// 
//输入：s = "a", t = "a"
//输出：false 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s 和 t 仅包含小写字母 
// 
//
// 
//
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
//
// 
//
// 
// 注意：本题与主站 242 题相似（字母异位词定义不同）：https://leetcode-cn.com/problems/valid-anagram/ 
//
// Related Topics 哈希表 字符串 排序 👍 51 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        if (s == t) return false;
        vector<int> sv(26, 0), tv(26, 0);
        for (int i = 0; i < s.length(); i += 1) {
            sv[s[i] - 'a'] += 1;
            tv[t[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i += 1) {
            if (sv[i] != tv[i]) {
                return false;
            }
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//有效数字（按顺序）可以分成以下几个部分： 
//
// 
// 若干空格 
// 一个 小数 或者 整数 
// （可选）一个 'e' 或 'E' ，后面跟着一个 整数 
// 若干空格 
// 
//
// 小数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 下述格式之一： 
// 
// 至少一位数字，后面跟着一个点 '.' 
// 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字 
// 一个点 '.' ，后面跟着至少一位数字 
// 
// 
//
// 整数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 至少一位数字 
// 
//
// 部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7
//", "+6e-1", "53.5e93", "-123.456e789"] 
//
// 部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"] 
//
// 给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "0"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "e"
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：s = "."
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。 
// 
//
// 
//
// Related Topics 字符串 👍 566 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool isInt(string s, bool allow_symbol = true) {
        //判断一个数是否是整数，只能包含数字和正负号
        //如果是空串，返回false
        if (s.size() == 0) return false;
        //判断首位后是否出现了正负号
        for (int i = 1; i < s.size(); i += 1) {
            if (s[i] < '0' || s[i] > '9') return false;
        }
        if (s[0] == '+' || s[0] == '-') {
            if (!allow_symbol) return false;
            //如果首位是正负号
            if (s.size() == 1) return false;
            return true;
        } else return true;

        return false;
    }

    bool isDecimal(string s, int dot_pos) {
        string pre;
        if (s[0] == '+' || s[0] == '-')
            pre = s.substr(1, dot_pos - 1);
        else pre = s.substr(0, dot_pos);
        string post = s.substr(dot_pos + 1);
        if (pre.size() == 0) return isInt(post, false);
        if (post.size() == 0) return isInt(pre, true);
        else return isInt(pre, true) && isInt(post, false);
    }


    bool validNumber(string s) {
        //去除首尾空格
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        //去除所有空格,以及排除掉不是数字的情况
        string str = "";
        //判断有没有e
        int e_num = 0;
        int e_index = -1;
        //判断是否有小数点
        int dot_num = 0;
        int dot_index = -2;
        for (char c: s) {
            str += c;
            if (c == 'e' || c == 'E') {
                e_num++;
                e_index = str.size() - 1;
            } else if (c == '.') {
                dot_num++;
                dot_index = str.size() - 1;
            } else if (c < '0' || c > '9') {
                //如果不是数字，返回false
                if (c != '+' && c != '-') return false;
            }
        }

        //判断e的个数
        if (e_num > 1 || dot_num > 1 || str.size() == 0) {
            return false;
        }
        if (e_num == 0) {
            //没有e的情况
            // 判断正负号出现的位置，如果
            if (dot_num == 0) {
                return isInt(str);
            } else { //只是一个简单的小数的情况
                return isDecimal(str, dot_index);
            }
        } else {
            if (dot_index > e_index) {
                //如果小数点在e的后面，返回false
                return false;
            }
            //判断e后面的数字是否是整数
            string pre = str.substr(0, e_index);
            string post = str.substr(e_index + 1);

//            cout << pre << " " << post << endl;
            if (dot_num == 1) {
                return isDecimal(pre, dot_index) && isInt(post);
            } else return isInt(pre,true) && isInt(post,true);
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

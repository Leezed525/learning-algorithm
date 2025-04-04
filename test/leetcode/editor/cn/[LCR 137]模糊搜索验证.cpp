//请设计一个程序来支持用户在文本编辑器中的模糊搜索功能。用户输入内容中可能使用到如下两种通配符： 
//
// 
// '.' 匹配任意单个字符。 
// '*' 匹配零个或多个前面的那一个元素。 
// 
//
// 
//
// 请返回用户输入内容 input 所有字符是否可以匹配原文字符串 article。 
//
// 
//
// 示例 1： 
//
// 
//输入：article = "aa", input = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2： 
//
// 
//输入：article = "aa", input = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3： 
//
// 
//输入：article = "ab", input = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= article.length <= 20 
// 1 <= input.length <= 20 
// article 只包含从 a-z 的小写字母。 
// input 只包含从 a-z 的小写字母，以及字符 . 和 * 。 
// 保证每次出现字符 * 时，前面都匹配到有效的字符 
// 
//
// 
//
// 注意：本题与主站 10 题相同：https://leetcode-cn.com/problems/regular-expression-matching/
// 
//
// 
//
// Related Topics 递归 字符串 动态规划 👍 575 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int n, m;

    struct node {
        char ch;
        int type; //0:normal char,1:dot,2 dot + *,3:normal char + *
    };
    vector<node> pattern;

    bool recursive_match(string &s, int i, int j) {
        if (i == n && j == m) return true;
        else if(i == n){
            while(j < m){
                if(pattern[j].type == 2 || pattern[j].type == 3)j++;
                else return false;
            }
            return true;
        }else if(j == m){
            return false;
        }
        //获取当前node
        node cur = pattern[j];
        if (cur.type == 0) {
            if (s[i] == cur.ch) {
                return recursive_match(s, i + 1, j + 1);
            } else {
                return false;
            }
        } else if (cur.type == 1) {
            //匹配任意字符
            return recursive_match(s, i + 1, j + 1);
        } else if (cur.type == 2) {
            //匹配 .*
            for (int k = i; k <= n; k++) {
                if (recursive_match(s, k, j + 1))return true;
            }
        }else{
            //匹配 normal char + *
            //先匹配0个
            if (recursive_match(s, i, j + 1))return true;
            //匹配任意个
            for (int k = i; k < n && s[k] == cur.ch; k++) {
                if (recursive_match(s, k + 1, j + 1))return true;
            }
        }
        return false;
    }

    void get_pattern(string &p) {
        int i = 0;
        while (i < p.size()) {
            if (p[i] == '.') {
                //判断下一个字符
                if (i + 1 < p.size() && p[i + 1] == '*') {
                    pattern.push_back({'.', 2});
                    i += 2;
                } else {
                    pattern.push_back({'.', 1});
                    i++;
                }
            } else {
                //判断下一个字符
                if (i + 1 < p.size() && p[i + 1] == '*') {
                    pattern.push_back({p[i], 3});
                    i += 2;
                } else {
                    pattern.push_back({p[i], 0});
                    i++;
                }
            }
        }

        m = pattern.size();
    }


    bool articleMatch(string s, string p) {
        n = s.size();
        get_pattern(p);
        //输出pattern
//        for (int i = 0; i < m; i++) {
//            cout << pattern[i].ch << " " << pattern[i].type << endl;
//        }

        return recursive_match(s, 0, 0);


    }
};
//leetcode submit region end(Prohibit modification and deletion)

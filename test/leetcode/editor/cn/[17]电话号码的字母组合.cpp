//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 3007 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<char>> num2char;
    vector<string> res;
    vector<char> path;

    void get_num2char() {
        for (int i = 0; i < 10; i += 1) {
            vector<char> tmp;
            num2char.push_back(tmp);
        }
        num2char[2].push_back('a');
        num2char[2].push_back('b');
        num2char[2].push_back('c');
        num2char[3].push_back('d');
        num2char[3].push_back('e');
        num2char[3].push_back('f');
        num2char[4].push_back('g');
        num2char[4].push_back('h');
        num2char[4].push_back('i');
        num2char[5].push_back('j');
        num2char[5].push_back('k');
        num2char[5].push_back('l');
        num2char[6].push_back('m');
        num2char[6].push_back('n');
        num2char[6].push_back('o');
        num2char[7].push_back('p');
        num2char[7].push_back('q');
        num2char[7].push_back('r');
        num2char[7].push_back('s');
        num2char[8].push_back('t');
        num2char[8].push_back('u');
        num2char[8].push_back('v');
        num2char[9].push_back('w');
        num2char[9].push_back('x');
        num2char[9].push_back('y');
        num2char[9].push_back('z');
    }

    void dfs(string s, int cur) {
        if (path.size() == s.length()) {
            string tmp;
            for (int i = 0; i < path.size(); i += 1)
                tmp += path[i];
            res.push_back(tmp);
            return;
        }
        char c = s[cur];
        int num = c - '0';
        for (int i = 0; i < num2char[num].size(); i += 1) {
            path.push_back(num2char[num][i]);
            dfs(s, cur + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
//            res.push_back("");
            return res;
        }
        get_num2char();
        dfs(digits, 0);
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

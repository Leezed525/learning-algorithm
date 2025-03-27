//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。 
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 
//输入：s = "10203040"
//输出：["10.20.30.40","102.0.30.40","10.203.0.40"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
//
// 
//
// 
// 注意：本题与主站 93 题相同：https://leetcode-cn.com/problems/restore-ip-addresses/ 
//
// Related Topics 字符串 回溯 👍 56 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    vector<string> ans;
    vector<int> path;
    string str;

    string pathToString() {
        string tmp = "";
        for (int i = 0; i < 4; i += 1) {
            tmp += to_string(path[i]);
            if (i != 3) tmp += ".";
        }
        return tmp;
    }


    void dfs(int start) {

        if (path.size() == 4) {
            if (start == str.size()) ans.push_back(pathToString());
            return;
        }
        if (str[start] == '0') {
            path.push_back(0);
            dfs(start + 1);
            path.pop_back();
            return;
        }
        for (int i = 1; i <= 3 && start + i <= str.size(); i += 1) {
            string tmp = str.substr(start, i);
            int num = stoi(tmp);
            if (num > 255) return;
            path.push_back(num);
            dfs(start + i);
            path.pop_back();
        }
        return;
    }


    vector<string> restoreIpAddresses(string s) {
        str = s;
        dfs(0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

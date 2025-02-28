//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。 
//
// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。 
//
// 
//
// 示例 1: 
//
// 
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// 示例 2: 
//
// 
//输入: strs = [""]
//输出: [[""]]
// 
//
// 示例 3: 
//
// 
//输入: strs = ["a"]
//输出: [["a"]] 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] 仅包含小写字母 
// 
//
// Related Topics 数组 哈希表 字符串 排序 👍 2157 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i += 1) {
            if (strs[i] == "") {
                mp[""].push_back(i);
                continue;
            }
            int num[26] = {0};

            for (int j = 0; j < strs[i].size(); j += 1) {
                num[strs[i][j] - 'a'] += 1;
            }

            string key = "";
            for (int j = 0; j < 26; j += 1) {
                key += to_string(num[j]) + " ";
            }
            mp[key].push_back(i);
        }

        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<string> tmp;
            for (int i = 0; i < it->second.size(); i += 1) {
                tmp.push_back(strs[it->second[i]]);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

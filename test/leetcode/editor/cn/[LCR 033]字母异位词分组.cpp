//给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。 
//
// 注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。 
//
// 
//
// 示例 1： 
//
// 
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// 示例 2： 
//
// 
//输入: strs = [""]
//输出: [[""]]
// 
//
// 示例 3： 
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
// 
//
// 
// 注意：本题与主站 49 题相同： https://leetcode-cn.com/problems/group-anagrams/ 
//
// Related Topics 数组 哈希表 字符串 排序 👍 69 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    string str_to_key(string s){
        vector<int> vis(26, 0);
        for (char i: s) {
            vis[i - 'a'] += 1;
        }
        string key = "";
        for (int i: vis) {
            key += to_string(i) + " ";
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i += 1) {
            mp[str_to_key(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (pair<string, vector<string>> it: mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

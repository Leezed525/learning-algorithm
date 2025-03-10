//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。 
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 
//
// 示例 2： 
//
// 
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s 和 wordDict[i] 仅由小写英文字母组成 
// wordDict 中的所有字符串 互不相同 
// 
//
// Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 👍 2690 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int dp[305] = {0};
        for(int i = 0; i <= s.size(); i += 1) {
            for(int j = 0;j < wordDict.size(); j += 1) {
                if(i >= wordDict[j].size()) {
                    if(s.substr(i - wordDict[j].size(), wordDict[j].size()) == wordDict[j]) {
                        dp[i] = max(dp[i],(int)(dp[i - wordDict[j].size()] + wordDict[j].size()));
                    }
                }
            }

            for(int j = 1; j <= s.size(); j += 1) {
                cout << dp[j] << " ";
            }

            cout << endl;
        }
        return dp[s.size()] == s.size();

    }
};
//leetcode submit region end(Prohibit modification and deletion)

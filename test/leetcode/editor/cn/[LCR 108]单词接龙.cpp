//在字典（单词列表） wordList 中，从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列： 
//
// 
// 序列中第一个单词是 beginWord 。 
// 序列中最后一个单词是 endWord 。 
// 每次转换只能改变一个字母。 
// 转换过程中的中间单词必须是字典 wordList 中的单词。 
// 
//
// 给定两个长度相同但内容不同的单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 
//的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。 
//
// 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot",
//"log","cog"]
//输出：5
//解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot",
//"log"]
//输出：0
//解释：endWord "cog" 不在字典中，所以无法进行转换。 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 10 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有字符串 互不相同 
// 
//
// 
//
// 
// 注意：本题与主站 127 题相同： https://leetcode-cn.com/problems/word-ladder/ 
//
// Related Topics 广度优先搜索 哈希表 字符串 👍 44 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count_diff(string s, string t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) cnt++;
        }
        return cnt;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int n = wordList.size();
        vector<vector<int>> e(n, vector<int>());
        int end_flag = 0;
        int vis[10000] = {0};
        queue<int> q;
        for (int i = 0; i < n; i += 1) {
            if (wordList[i] == endWord) end_flag = 1;
            if (count_diff(beginWord, wordList[i]) == 1) vis[i] = 1, q.push(i);
            for (int j = i + 1; j < n; j += 1) {
                if (count_diff(wordList[i], wordList[j]) == 1) e[i].push_back(j), e[j].push_back(i);
            }
        }

        if (!end_flag) return 0;
        int step = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i += 1) {
                int u = q.front();
                q.pop();
                if (wordList[u] == endWord) return step + 1;
                for (int v: e[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            step += 1;
        }

        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

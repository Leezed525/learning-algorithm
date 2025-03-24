//设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。 如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单
//词存在于已构建的神奇字典中。 
//
// 实现 MagicDictionary 类： 
//
// 
// MagicDictionary() 初始化对象 
// void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary 中的字
//符串互不相同 
// bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，使得
//所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。 
// 
//
// 
//
// 
// 
// 
// 示例： 
// 
// 
// 
//
// 
//输入
//inputs = ["MagicDictionary", "buildDict", "search", "search", "search", 
//"search"]
//inputs = [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], [
//"leetcoded"]]
//输出
//[null, null, false, true, false, false]
//
//解释
//MagicDictionary magicDictionary = new MagicDictionary();
//magicDictionary.buildDict(["hello", "leetcode"]);
//magicDictionary.search("hello"); // 返回 False
//magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
//magicDictionary.search("hell"); // 返回 False
//magicDictionary.search("leetcoded"); // 返回 False
// 
//
// 
//
// 提示： 
//
// 
// 1 <= dictionary.length <= 100 
// 1 <= dictionary[i].length <= 100 
// dictionary[i] 仅由小写英文字母组成 
// dictionary 中的所有字符串 互不相同 
// 1 <= searchWord.length <= 100 
// searchWord 仅由小写英文字母组成 
// buildDict 仅在 search 之前调用一次 
// 最多调用 100 次 search 
// 
//
// 
//
// 
// 注意：本题与主站 676 题相同： https://leetcode-cn.com/problems/implement-magic-
//dictionary/ 
//
// Related Topics 深度优先搜索 设计 字典树 哈希表 字符串 👍 54 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MagicDictionary {
public:

    struct TrieTree {
        bool isEnd;
        TrieTree *next[26];

        TrieTree() {
            isEnd = false;
            for (int i = 0; i < 26; i += 1) next[i] = nullptr;
        }
    } *head;


    void insert(string word) {
        //插入前缀树
        TrieTree *tmp = head;
        int i = 0;
        while (i < word.size()) {
            if (tmp->next[word[i] - 'a'] == nullptr) {
                TrieTree *next = new TrieTree();
                tmp->next[word[i] - 'a'] = next;
                tmp = next;
            } else {
                tmp = tmp->next[word[i] - 'a'];
            }
            i += 1;
        }
        tmp->isEnd = true;
    }


    /** Initialize your data structure here. */
    MagicDictionary() {
        head = new TrieTree();
    }

    void buildDict(vector<string> dictionary) {
        for (string s: dictionary) {
            insert(s);
        }
    }

    bool dfs_search(TrieTree *cur, string word, bool modified, int pos) {
        if (pos == word.size()) return modified && cur->isEnd;
        if (cur->next[word[pos] - 'a']) {
            if (dfs_search(cur->next[word[pos] - 'a'], word, modified, pos + 1)) {
                return true;
            }
        }
        if (!modified) {
            for (int i = 0; i < 26; i += 1) {
                if (i != word[pos] - 'a' && cur->next[i]) {
                    if (dfs_search(cur->next[i], word, true, pos + 1)) return true;
                }
            }
        }
        return false;

    }

    bool search(string searchWord) {
        return dfs_search(head, searchWord, false, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
//leetcode submit region end(Prohibit modification and deletion)

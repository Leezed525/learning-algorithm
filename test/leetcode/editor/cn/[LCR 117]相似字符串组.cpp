//如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。 
//
//
// 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 
//"tars"，"rats"，或 "arts" 相似。 
//
// 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同
//一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。 
//
// 给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个 字母异位词 。请问 strs 中有多少个相似字符串组？ 
//
// 字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["tars","rats","arts","star"]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：strs = ["omv","ovm"]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 300 
// 1 <= strs[i].length <= 300 
// strs[i] 只包含小写字母。 
// strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。 
// 
//
// 
//
// 
// 注意：本题与主站 839 题相同：https://leetcode-cn.com/problems/similar-string-groups/ 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 哈希表 字符串 👍 37 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int fa[310];

    void init(int n) {
        for (int i = 0; i < n; i += 1) fa[i] = i;
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        fa[find(x)] = find(y);
    }

    bool check(string a, string b) {
        vector<int> diff;
        for (int i = 0; i < a.size(); i += 1) {
            if (a[i] != b[i]) diff.push_back(i);
        }
        if (diff.size() == 0) return true;
        if (diff.size() != 2) return false;
        return a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]];
    }

    int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();
        init(n);
        for (int i = 0; i < n; i += 1) {
            for (int j = i + 1; j < n; j += 1) {
                if(find(i) == find(j)) continue;
                if (check(strs[i], strs[j])) {
                    merge(i, j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            if (find(i) == i) ans += 1;
        }
        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

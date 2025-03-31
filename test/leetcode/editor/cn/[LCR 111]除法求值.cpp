//给定一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 
//values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。 
//
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj =
// ? 的结果作为答案。 
//
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替
//代这个答案。 
//
// 注意：输入总是有效的。可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"]
//,["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
//解释：
//条件：a / b = 2.0, b / c = 3.0
//问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
// 
//
// 示例 2： 
//
// 
//输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], 
//queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//输出：[3.75000,0.40000,5.00000,0.20000]
// 
//
// 示例 3： 
//
// 
//输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],[
//"a","c"],["x","y"]]
//输出：[0.50000,2.00000,-1.00000,-1.00000]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= equations.length <= 20 
// equations[i].length == 2 
// 1 <= Ai.length, Bi.length <= 5 
// values.length == equations.length 
// 0.0 < values[i] <= 20.0 
// 1 <= queries.length <= 20 
// queries[i].length == 2 
// 1 <= Cj.length, Dj.length <= 5 
// Ai, Bi, Cj, Dj 由小写英文字母与数字组成 
// 
//
// 
//
// 
// 注意：本题与主站 399 题相同： https://leetcode-cn.com/problems/evaluate-division/ 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 数组 最短路 👍 53 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int fa[100] = {0};

    void init() {
        for (int i = 0; i < 100; i++) {
            fa[i] = i;
        }
    }

    int get(int x) {
        return x == fa[x] ? x : fa[x] = get(fa[x]);
    }

    void merge(int x, int y) {
        fa[get(x)] = get(y);
    }


    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        init();
        //离散化
        unordered_map<string, int> hash;
        int cnt = 0;
        for (auto &e: equations) {
            if (!hash.count(e[0])) hash[e[0]] = cnt++;
            if (!hash.count(e[1])) hash[e[1]] = cnt++;
        }
        //建图
        vector<vector<pair<int, double>>> g(cnt);
        for (int i = 0; i < equations.size(); i++) {
            int a = hash[equations[i][0]], b = hash[equations[i][1]];
            g[a].emplace_back(b, values[i]);
            g[b].emplace_back(a, 1.0 / values[i]);
            merge(a, b);
        }

        vector<double> res;

        for (int i = 0; i < queries.size(); i++) {
            if (!hash.count(queries[i][0]) || !hash.count(queries[i][1])) {
                res.push_back(-1.0);
                continue;
            }
            int a = hash[queries[i][0]], b = hash[queries[i][1]];
            if (get(a) != get(b)) {
                res.push_back(-1.0);
                continue;
            }
            queue<int> q;
            vector<double> dist(cnt, -1.0);
            q.push(a);
            dist[a] = 1.0;
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                if (t == b) {
                    res.push_back(dist[t]);
                    break;
                }
                for (pair<int, double> p: g[t]) {
                    int j = p.first;
                    double val = p.second;
                    if (dist[j] != -1.0) continue;
                    dist[j] = dist[t] * val;
                    q.push(j);
                }
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

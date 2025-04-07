//给你一个整数 n ，请你找出并返回第 n 个 丑数 。 
//
// 说明：丑数是只包含质因数 2、3 和/或 5 的正整数；1 是丑数。 
//
// 
//
// 示例 1： 
//
// 
//输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 提示： 
//
// 
// 1 <= n <= 1690 
// 
//
// 
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
//
// 
//
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 👍 512 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_map<long, int> mp;
        pq.push(1);
        while (--n) {
            long cur = pq.top();
            pq.pop();
//            cout << "pop" << cur << endl;
            if(!mp[cur * 2]) {
                pq.push(cur * 2);
                mp[cur * 2] = 1;
            }
            if(!mp[cur * 3]) {
                pq.push(cur * 3);
                mp[cur * 3] = 1;
            }
            if(!mp[cur * 5]) {
                pq.push(cur * 5);
                mp[cur * 5] = 1;
            }
        }

        return pq.top();
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//整数数组 sockets 记录了一个袜子礼盒的颜色分布情况，其中 sockets[i] 表示该袜子的颜色编号。礼盒中除了一款撞色搭配的袜子，每种颜色的袜子均
//有两只。请设计一个程序，在时间复杂度 O(n)，空间复杂度O(1) 内找到这双撞色搭配袜子的两个颜色编号。 
//
// 
//
// 示例 1： 
//
// 
//输入：sockets = [4, 5, 2, 4, 6, 6]
//输出：[2,5] 或 [5,2]
// 
//
// 示例 2： 
//
// 
//输入：sockets = [1, 2, 4, 1, 4, 3, 12, 3]
//输出：[2,12] 或 [12,2] 
//
// 
//
// 提示： 
//
// 
// 2 <= sockets.length <= 10000 
// 
//
// Related Topics 位运算 数组 👍 890 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sockCollocation(vector<int>& sockets) {
        int res = 0;
        for (int i: sockets) {
            res ^= i;
        }
        int a = 0, b = 0;
        //找到res的最后一位1
        int last = res & (-res);
        for(int i: sockets) {
            if(i & last) {
                a ^= i;
            } else {
                b ^= i;
            }
        }
        return {a, b};
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

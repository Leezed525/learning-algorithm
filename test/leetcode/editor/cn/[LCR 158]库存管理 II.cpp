//仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品 id，可能存在重复。请返回库存表中数量大于 stock.length / 2 
//的商品 id。 
//
// 
//
// 示例 1： 
//
// 
//输入：stock = [6, 1, 3, 1, 1, 1]
//输出：1 
//
// 
//
// 提示： 
//
// 
// 1 <= stock.length <= 50000 
// 给定数组为非空数组，且存在结果数字 
// 
//
// 
//
// 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/ 
//
// Related Topics 数组 哈希表 分治 计数 排序 👍 418 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        unordered_map<int, int> count;
        for(int i: stock) {
            count[i]++;
        }

        for(auto p: count) {
            if(p.second > stock.size() / 2) {
                return p.first;
            }
        }
        return -1; // 这个情况不会发生，因为题目保证存在结果数字
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

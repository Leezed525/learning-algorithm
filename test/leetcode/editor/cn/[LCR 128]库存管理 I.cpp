//仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品 id，可能存在重复。原库存表按商品 id 升序排列。现因突发情况需要进行商品紧
//急调拨，管理员将这批商品 id 提前依次整理至库存表最后。请你找到并返回库存表中编号的 最小的元素 以便及时记录本次调拨。 
//
// 
//
// 示例 1： 
//
// 
//输入：stock = [4,5,8,3,4]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：stock = [5,7,9,1,2]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= stock.length <= 5000 
// -5000 <= stock[i] <= 5000 
// 
//
// 
//
// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-
//sorted-array-ii/ 
//
// 
//
// Related Topics 数组 二分查找 👍 875 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        int l = 0,r = stock.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (stock[mid] > stock[r]) {
                l = mid + 1;
            } else if (stock[mid] < stock[r]) {
                r = mid;
            } else {
                r--;
            }
        }

        return stock[l];
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

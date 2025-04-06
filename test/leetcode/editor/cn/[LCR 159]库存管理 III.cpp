//仓库管理员以数组 stock 形式记录商品库存表，其中 stock[i] 表示对应商品库存余量。请返回库存余量最少的 cnt 个商品余量，返回 顺序不限。 
//
//
// 
//
// 示例 1： 
//
// 
//输入：stock = [2,5,7,4], cnt = 1
//输出：[2]
// 
//
// 示例 2： 
//
// 
//输入：stock = [0,2,3,6], cnt = 2
//输出：[0,2] 或 [2,0] 
//
// 
//
// 提示： 
//
// 
// 0 <= cnt <= stock.length <= 10000 0 <= stock[i] <= 10000 
// 
//
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 600 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    struct heap {
        vector<int> q;
        int size;

        heap() {
            q.push_back(0);
            size = 0;
        }


        void push(int val) {
            if (size + 1 < q.size()) q[size + 1] = val;
            else q.push_back(val);
            shiftup(++size);
        }


        void pop() {
            swap(q[1], q[size--]);
            heapify(1);
        }

        int top() {
            return q[1];
        }


        void shiftup(int x) {
            while (x > 1 && q[x] > q[x / 2]) {
                swap(q[x], q[x / 2]);
                x /= 2;
            }
        }


        void heapify(int x) {
            int l = x * 2, r = x * 2 + 1;
            int minx = x;
            if (l <= size && q[l] > q[minx]) minx = l;
            if (r <= size && q[r] > q[minx]) minx = r;
            if (minx != x) {
                swap(q[x], q[minx]);
                heapify(minx);
            }
        }
    };


    vector<int> inventoryManagement(vector<int> &stock, int cnt) {
        heap h;

        for (int i: stock) {
            h.push(i);
        }
        while(h.size > cnt){
            h.pop();
        }
        vector<int> res;
        while(h.size > 0){
            res.push_back(h.top());
            h.pop();
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

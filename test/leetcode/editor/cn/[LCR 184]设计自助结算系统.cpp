//请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，需要实现的功能有： 
//
// 
// get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1 
// add(value)：将价格为 value 的商品加入待结算商品队列的尾部 
// remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1 
// 
//
// 注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1) 
//
// 
//
// 示例 1： 
//
// 
//输入: 
//["Checkout","add","add","get_max","remove","get_max"]
//[[],[4],[7],[],[],[]]
//
//输出: [null,null,null,7,4,7]
// 
//
// 示例 2： 
//
// 
//输入: 
//["Checkout","remove","get_max"]
//[[],[],[]]
//
//输出: [null,-1,-1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= get_max, add, remove 的总操作数 <= 10000 
// 1 <= value <= 10^5 
// 
//
// 
//
// Related Topics 设计 队列 单调队列 👍 532 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Checkout {
public:

    queue<int> l;
    deque<int> q;

    Checkout() {

    }

    int get_max() {
        if(l.empty()) {
            return -1;
        }
        return q.front();
    }

    void add(int value) {
        l.push(value);
        while(!q.empty() && q.back() < value) {
            q.pop_back();
        }
        q.push_back(value);
    }

    int remove() {
        if(l.empty()) {
            return -1;
        }
        int res = l.front();
        l.pop();
        if(res == q.front()) {
            q.pop_front();
        }
        return res;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */
//leetcode submit region end(Prohibit modification and deletion)

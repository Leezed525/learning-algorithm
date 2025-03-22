//设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。 
//
// 请实现 KthLargest 类： 
//
// 
// KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。 
// int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["KthLargest", "add", "add", "add", "add", "add"]
//[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
//输出：
//[null, 4, 5, 5, 8, 8]
//
//解释：
//KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
//kthLargest.add(3);   // return 4
//kthLargest.add(5);   // return 5
//kthLargest.add(10);  // return 5
//kthLargest.add(9);   // return 8
//kthLargest.add(4);   // return 8
// 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= 10⁴ 
// 0 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// -10⁴ <= val <= 10⁴ 
// 最多调用 add 方法 10⁴ 次 
// 题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素 
// 
//
// 
//
// 
// 注意：本题与主站 703 题相同： https://leetcode-cn.com/problems/kth-largest-element-in-a-
//stream/ 
//
// Related Topics 树 设计 二叉搜索树 二叉树 数据流 堆（优先队列） 👍 62 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class KthLargest {
public:
//    priority_queue<int, vector<int>, greater<int>> q;
//    int k;

    struct heap {
        vector<int> q;
        int size = 0;

        //建堆
        void build(vector<int> &nums) {
            q = vector<int>(nums.size() + 1);
            for (int i = 0; i < nums.size(); i++) q[i + 1] = nums[i];
            size = nums.size();
            for (int i = size / 2; i >= 1; i--) heapify(i);
        }

        //插入堆
        void push(int x) {
            if (size == q.size() - 1) q.push_back(x);
            else q[size + 1] = x;
            size++;
            up(size);
        }

        void pop() {
            q[1] = q[size--];
            heapify(1);
        }

        int top() {
            return q[1];
        }

        //维护堆
        void heapify(int x) {
            int l = x * 2, r = x * 2 + 1, m = x;
            //小根堆
            if (l <= size && q[l] < q[m]) m = l;
            if (r <= size && q[r] < q[m]) m = r;
            if (m != x) {
                swap(q[m], q[x]);
                heapify(m);
            }
        }
        //上浮
        void up(int x) {
            while (x > 1 && q[x] < q[x / 2]) {
                swap(q[x], q[x / 2]);
                x /= 2;
            }
        }

        void print() {
            for (int i = 1; i <= size; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
        }

    } h;

    int k;

    KthLargest(int k, vector<int> &nums) {
        h.build(nums);
        this->k = k;
        while (h.size > k) h.pop();
//        this->k = k;
//        for (int i: nums) {
//            q.push(i);
//        }
//        while (q.size() > k) {
//            q.pop();
//        }
    }

    int add(int val) {
        h.push(val);
        while (h.size > k) h.pop();
        return h.top();
//        q.push(val);
//        if(q.size() > k) q.pop();
//        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//leetcode submit region end(Prohibit modification and deletion)

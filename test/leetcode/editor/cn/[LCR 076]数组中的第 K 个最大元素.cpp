//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,2,1,5,6,4], k = 2
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,3,1,2,4,5,5,6], k = 4
//输出：4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 
// 注意：本题与主站 215 题相同： https://leetcode-cn.com/problems/kth-largest-element-in-an-
//array/ 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 107 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    struct heap {
        vector<int> q;
        int size = 0;

        void push(int val) {
            if (size + 1 < q.size()) q[size + 1] = val;
            else q.push_back(val);
            size += 1;
            shift_up(size);
        }

        void pop() {
            q[1] = q[size--];
            heapify(1);
        }

        int top() {
            return q[1];
        }

        void shift_up(int x) {
            while (x > 1 && q[x] < q[x / 2]) {
                swap(q[x], q[x / 2]);
                x /= 2;
            }
        }

        void heapify(int x) {
            int l = x * 2, r = x * 2 + 1;
            int minn = x;
            if (l <= size && q[l] < q[minn]) minn = l;
            if (r <= size && q[r] < q[minn]) minn = r;
            if (minn != x) {
                swap(q[x], q[minn]);
                heapify(minn);
            }
        }
        heap(){
            q = vector<int>(1, 0);
            size = 0;
        }
    };


    int findKthLargest(vector<int> &nums, int k) {
        heap h = heap();
        for (int i: nums) {
            h.push(i);
        }
        while (h.size > k) {
            h.pop();
        }
        return h.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

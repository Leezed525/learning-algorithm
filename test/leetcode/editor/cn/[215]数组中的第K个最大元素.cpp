//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4], k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6], k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 2743 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    struct heap {
        vector<int> arr;
        int size;

        heap() {
            arr.push_back(0);
            size = 0;
        }

        void push(int x) {
            if (size + 1 < arr.size()) arr[size + 1] = x;
            else arr.push_back(x);
            size++;
            shiftup(size);
        }

        void pop() {
            if (size == 0) return;
            swap(arr[1], arr[size]);
            size--;
            heapify(1);
        }

        int top(){
            if (size == 0) return -1;
            return arr[1];
        }

        void heapify(int x) {
            int l = x * 2, r = x * 2 + 1;
            int minn = x;
            if (l <= size && arr[l] < arr[minn]) minn = l;
            if (r <= size && arr[r] < arr[minn]) minn = r;
            if (minn != x) {
                swap(arr[minn], arr[x]);
                heapify(minn);
            }
        }

        void shiftup(int x) {
            while (x > 1 && arr[x] < arr[x / 2]) {
                swap(arr[x], arr[x / 2]);
                x /= 2;
            }
        }
    };


    int findKthLargest(vector<int> &nums, int k) {
        heap h;
        for (int i = 0; i < nums.size(); i += 1) {
            h.push(nums[i]);
            if (h.size > k) h.pop();
        }
        return h.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

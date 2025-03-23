//给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。 
//
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。 
//
// 请找到和最小的 k 个数对 (u1,v1), (u2,v2) ... (uk,vk) 。 
//
// 
//
// 示例 1： 
//
// 
//输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//输出: [1,2],[1,4],[1,6]
//解释: 返回序列中的前 3 对数：
//    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// 
//
// 示例 2： 
//
// 
//输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//输出: [1,1],[1,1]
//解释: 返回序列中的前 2 对数：
//     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// 
//
// 示例 3： 
//
// 
//输入: nums1 = [1,2], nums2 = [3], k = 3 
//输出: [1,3],[2,3]
//解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums1.length, nums2.length <= 10⁴ 
// -10⁹ <= nums1[i], nums2[i] <= 10⁹ 
// nums1, nums2 均为升序排列 
// 1 <= k <= 1000 
// 
//
// 
//
// 
// 注意：本题与主站 373 题相同：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-
//sums/ 
//
// Related Topics 数组 堆（优先队列） 👍 87 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    struct heap {
        vector<pair<int, int>> q;
        int size = 0;
        vector<int> nums1, nums2;

        void build(vector<int> nums1, vector<int> nums2) {
            this->nums1 = nums1;
            this->nums2 = nums2;
            q = vector<pair<int, int>>(1);
        }


        void push(pair<int, int> p) {
            if (size + 1 < q.size()) q[size + 1] = p;
            else q.push_back(p);
            size++;
            up(size);
        }

        void pop() {
            q[1] = q[size--];
            heapify(1);
        }

        pair<int, int> top() {
            return q[1];
        }


        void up(int i) {
            while (i > 1 && nums1[q[i].first] + nums2[q[i].second] < nums1[q[i / 2].first] + nums2[q[i / 2].second]) {
                swap(q[i], q[i / 2]);
                i /= 2;
            }
        }


        void heapify(int i) {
            int l = 2 * i, r = 2 * i + 1, smallest = i;
            if (l <= size && nums1[q[l].first] + nums2[q[l].second] < nums1[q[i].first] + nums2[q[i].second])
                smallest = l;
            if (r <= size &&
                nums1[q[r].first] + nums2[q[r].second] < nums1[q[smallest].first] + nums2[q[smallest].second])
                smallest = r;
            if (smallest != i) {
                swap(q[i], q[smallest]);
                heapify(smallest);
            }
        }
    };


    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        heap h;
        h.build(nums1, nums2);
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); i++) {
            h.push({i, 0});
        }
        while (k-- && h.size) {
            auto t = h.top();
            res.push_back({nums1[t.first], nums2[t.second]});
            h.pop();
            if (t.second + 1 < nums2.size()) {
                h.push({t.first, t.second + 1});
            }
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

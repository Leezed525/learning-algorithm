//给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2： 
//
// 
//输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
//
// 
//
// 
// 注意：本题与主站 347 题相同：https://leetcode-cn.com/problems/top-k-frequent-elements/ 
//
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 75 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    struct heap {
        vector<pair<int, int>> q;
        int size = 0;

        void build(vector<pair<int, int>> pairs) {
            q = vector<pair<int, int>>(pairs.size() + 1);
            for (int i = 0; i < pairs.size(); i++) q[i + 1] = pairs[i];
            size = pairs.size();
            for (int i = size / 2; i >= 1; i--) heapify(i);
        }

        void push(pair<int, int> p) {
            if (size + 1 < q.size()) q[size + 1] = p;
            else q.push_back(p);
            size++;
            up(size);
        }

        void up(int i) {
            while (i > 1 && q[i].second < q[i / 2].second) {
                swap(q[i], q[i / 2]);
                i /= 2;
            }
        }

        pair<int, int> top() {
            return q[1];
        }

        void pop() {
            q[1] = q[size--];
            heapify(1);
        }

        //从上往下维护堆
        void heapify(int i) {
            int l = 2 * i, r = 2 * i + 1, smallest = i;
            if (l <= size && q[l].second < q[i].second) smallest = l;
            if (r <= size && q[r].second < q[smallest].second) smallest = r;
            if (smallest != i) {
                swap(q[i], q[smallest]);
                heapify(smallest);
            }

        }
    };

    int k;


    unordered_map<int, int> mp;

    vector<int> topKFrequent(vector<int> &nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> pairs;
        for (auto &p: mp) {
            pairs.push_back(p);
        }
        heap h;
        h.build(pairs);
        vector<int> res;
        while (h.size > k) {
            h.pop();
        }
        for (int i = 0; i < k; i++) {
            res.push_back(h.top().first);
            h.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

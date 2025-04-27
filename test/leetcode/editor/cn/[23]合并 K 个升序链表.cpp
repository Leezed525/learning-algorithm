//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
//
// Related Topics 链表 分治 堆（优先队列） 归并排序 👍 3000 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct heap {
        // 小顶堆
        vector<ListNode *> h = {nullptr};
        int size = 0;

        void push(ListNode *x) {
            if (size + 1 < h.size()) h[++size] = x;
            else {
                h.push_back(x);
                size++;
            }
            up(size);
        }

        ListNode *top() {
            return h[1];
        }

        void pop() {
            swap(h[1], h[size]);
            size--;
            heapify(1);
        }

        void heapify(int x) {
            int l = x * 2, r = x * 2 + 1;
            int minn = x;
            if (l <= size && h[l]->val < h[minn]->val) minn = l;
            if (r <= size && h[r]->val < h[minn]->val) minn = r;
            if (x != minn) {
                swap(h[x], h[minn]);
                heapify(minn);
            }
        }

        void up(int x) {
            while (x > 1 && h[x / 2]->val > h[x]->val) {
                swap(h[x], h[x / 2]);
                x /= 2;
            }
        }
    };


    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        heap h;

        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                h.push(lists[i]);
            }
        }
        while (h.size > 0) {
            ListNode *x = h.top();
            h.pop();
            cur->next = x;
            cur = cur->next;
            if (x->next) {
                h.push(x->next);
            }
//            cout << h.size << endl;
        }

        cur->next = nullptr;
        return head->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//给定一个链表数组，每个链表都已经按升序排列。 
//
// 请将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 
//输入：lists = [[1,4,5],[1,3,4],[2,6]]
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
// 
//输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：lists = [[]]
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
// 
//
// 
// 注意：本题与主站 23 题相同： https://leetcode-cn.com/problems/merge-k-sorted-lists/ 
//
// Related Topics 链表 分治 堆（优先队列） 归并排序 👍 119 👎 0

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

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
public:
    struct heap {
        vector<ListNode *> q;
        int size = 0;

        heap() {
            q = vector<ListNode *>(1);
            size = 0;
        }


//        void print() {
//            for (int i = 1; i <= size; i += 1) {
//                cout << "q[" << i << "] ";
//                ListNode *tmp = q[i];
//                while(tmp != null)
//            }
//        }


        void push(ListNode *x) {
            if (size + 1 < q.size()) q[size + 1] = x;
            else q.push_back(x);
            shift_up(++size);
        }

        void pop() {
            q[1] = q[1]->next;
            if (q[1] == nullptr) {
                q[1] = q[size];
                size--;
            }
            heapify(1);
//            if (tmp->next != nullptr) {
//                tmp = tmp->next;
//                heapify(1);
//            } else {
//                q[1] = q[size];
//                size--;
//                heapify(1);
//            }
        }

        ListNode *top() {
            return q[1];
        }

        void shift_up(int x) {
            while (x > 1 && q[x]->val < q[x / 2]->val) {
                swap(q[x], q[x / 2]);
                x /= 2;
            }
        }


        void heapify(int x) {
            int l = x * 2, r = x * 2 + 1;
            int minn = x;
            if (l <= size && q[l]->val < q[minn]->val) minn = l;
            if (r <= size && q[r]->val < q[minn]->val) minn = r;
            if (minn != x) {
                swap(q[x], q[minn]);
                heapify(minn);
            }
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        heap h;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        for (ListNode *i: lists) {
            if (i != nullptr)
                h.push(i);
        }

        while (h.size != 0) {

            cur->next = h.top();
            h.pop();
            cur = cur->next;
        }
        return head->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//给定链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
//
// 
//
// 
// 注意：本题与主站 148 题相同：https://leetcode-cn.com/problems/sort-list/ 
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 152 👎 0

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


    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        while (left != nullptr && right != nullptr) {
            if (left->val > right->val) {
                tmp->next = right;
                right = right->next;
            } else {
                tmp->next = left;
                left = left->next;
            }
            tmp = tmp->next;
        }
        while (left != nullptr) {
            tmp->next = left;
            left = left->next;
            tmp = tmp->next;
        }
        while (right != nullptr) {
            tmp->next = right;
            right = right->next;
            tmp = tmp->next;
        }
        return head->next;
    }

    ListNode *merge_sort(ListNode *head, ListNode *tail) {
        if (head == nullptr) return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }
        ListNode *mid = slow;
        return merge(merge_sort(head, mid), merge_sort(mid, tail));
    }


    ListNode *sortList(ListNode *head) {
        return merge_sort(head, nullptr);

    }
};
//leetcode submit region end(Prohibit modification and deletion)

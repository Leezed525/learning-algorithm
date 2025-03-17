//给定一个单链表 L 的头节点 head ，单链表 L 表示为： 
//
// L0 → L1 → … → Ln-1 → Ln 请将其重新排列后变为： 
//
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → … 
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: head = [1,2,3,4]
//输出: [1,4,2,3] 
//
// 示例 2： 
//
// 
//
// 
//输入: head = [1,2,3,4,5]
//输出: [1,5,2,4,3] 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 5 * 10⁴] 
// 1 <= node.val <= 1000 
// 
//
// 
//
// 
// 注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/ 
//
// Related Topics 栈 递归 链表 双指针 👍 152 👎 0

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
    void reorderList(ListNode *head) {
        //找到中间节点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<ListNode *> s;
        ListNode *end = slow;
        while (slow) {
            s.push(slow);
            slow = slow->next;
        }
        ListNode *cur = head;
        while (cur != end) {
            ListNode *tmp = s.top();
            s.pop();
            ListNode *next = cur->next;
            cur->next = tmp;
            if(next == tmp) {
                tmp->next = nullptr;
                break;
            }
            tmp->next = next;
            cur = next;
        }
        if (!s.empty()) s.top()->next = nullptr;

        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

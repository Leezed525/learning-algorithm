//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
//
// Related Topics 递归 链表 👍 3757 👎 0

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;
        while(cur1 && cur2){
            if (cur1->val < cur2->val) {
                pre->next = cur1;
                cur1 = cur1->next;
            }else{
                pre->next = cur2;
                cur2 = cur2->next;
            }
            pre = pre->next;
        }
        while(cur1){
            pre->next = cur1;
            cur1 = cur1->next;
            pre = pre->next;
        }
        while(cur2){
            pre->next = cur2;
            cur2 = cur2->next;
            pre = pre->next;

        }
        return head->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

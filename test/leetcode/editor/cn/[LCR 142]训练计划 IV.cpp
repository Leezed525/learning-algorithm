//给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，按训练项目编号 升序 记录于链表并返回。 
//
// 注意：新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4] 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[] 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0] 
//
// 
//
// 提示： 
//
// 0 <= 链表长度 <= 1000 
//
// 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
//
// 
//
// Related Topics 递归 链表 👍 395 👎 0

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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while(cur1 && cur2){
            if (cur1->val > cur2->val) {
                cur -> next = cur2;
                cur2 = cur2->next;
            }else{
                cur -> next = cur1;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }

        while(cur1){
            cur -> next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }
        while(cur2){
            cur -> next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

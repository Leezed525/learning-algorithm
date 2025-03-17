//给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。 
//
// 可以假设除了数字 0 之外，这两个数字都不会以零开头。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：l1 = [7,2,4,3], l2 = [5,6,4]
//输出：[7,8,0,7]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[8,0,7]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 100] 
// 0 <= node.val <= 9 
// 输入数据保证链表代表的数字无前导 0 
// 
//
// 
//
// 进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。 
//
// 
//
// 
// 注意：本题与主站 445 题相同：https://leetcode-cn.com/problems/add-two-numbers-ii/ 
//
// Related Topics 栈 链表 数学 👍 108 👎 0

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
    int get_length(ListNode *h) {
        int len = 0;
        while (h) {
            h = h->next;
            len += 1;
        }
        return len;
    }

    ListNode *addTwoList(ListNode *h1, ListNode *h2) {
        if (h1 == nullptr && h2 == nullptr) {
            return nullptr;
        }
        ListNode *next = addTwoList(h1->next, h2->next);
        ListNode *cur = new ListNode(h1->val + h2->val);
        cur->next = next;
        if (next != nullptr) {
            cur->val += next->val / 10;
            next->val %= 10;
        }
        return cur;
    }


    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int len1 = get_length(l1);
        int len2 = get_length(l2);
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i += 1) {
                ListNode *tmp = new ListNode(0);
                tmp->next = h2;
                h2 = tmp;
            }
        } else {
            for (int i = 0; i < len2 - len1; i += 1) {
                ListNode *tmp = new ListNode(0);
                tmp->next = h1;
                h1 = tmp;
            }
        }
        ListNode *res = addTwoList(h1, h2);
        if (res->val >= 10) {
            ListNode *tmp = new ListNode(res->val / 10);
            res->val %= 10;
            tmp->next = res;
            res = tmp;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

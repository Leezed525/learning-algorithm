//给你一棵二叉搜索树，请 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
//输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [5,1,7]
//输出：[1,null,5,null,7]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的取值范围是 [1, 100] 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 
// 注意：本题与主站 897 题相同： https://leetcode-cn.com/problems/increasing-order-search-
//tree/ 
//
// Related Topics 栈 树 深度优先搜索 二叉搜索树 二叉树 👍 82 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> vals;

    void in_order_iter(TreeNode *root) {
        if (root == nullptr) return;
        in_order_iter(root->left);
        vals.push_back(root->val);
        in_order_iter(root->right);
        return;
    }

    TreeNode *increasingBST(TreeNode *root) {
        in_order_iter(root);
        int i = 0;
        TreeNode *res = new TreeNode(vals[i++]);
        TreeNode *cur = res;
        while (i < vals.size()) {
            TreeNode *tmp = new TreeNode(vals[i++]);
            cur->right = tmp;
            cur = tmp;
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

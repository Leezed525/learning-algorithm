//给定一棵二叉树的根节点 root，请左右翻转这棵二叉树，并返回其根节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [5,7,9,8,3,2,4]
//输出：[5,9,7,4,2,3,8]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围在 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/ 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 393 👎 0

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
    TreeNode* flipTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* left = flipTree(root->left);
        TreeNode* right = flipTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

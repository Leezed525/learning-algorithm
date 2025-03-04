//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2481 👎 0

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        //找到前序的第一个点
        TreeNode *cur = new TreeNode(preorder[0]);
        //找到中序的根节点
        int root = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == cur->val) {
                root = i;
                break;
            }
        }
        //递归构建左右子树
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + root);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + root);

        vector<int> right_preorder(preorder.begin() + 1 + root, preorder.end());
        vector<int> right_inorder(inorder.begin() + root + 1, inorder.end());

        if (left_inorder.size() > 0) {
            cur->left = buildTree(left_preorder, left_inorder);
        }
        if (right_inorder.size() > 0) {
            cur->right = buildTree(right_preorder, right_inorder);
        }
        return cur;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

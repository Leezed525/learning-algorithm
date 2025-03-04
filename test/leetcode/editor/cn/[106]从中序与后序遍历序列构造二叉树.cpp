//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
// 
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1311 👎 0

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //找到后续的最后一个点
        TreeNode *cur = new TreeNode(postorder[postorder.size() - 1]);
        //找到中序的根节点
        int root = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == cur->val) {
                root = i;
                break;
            }
        }
        //递归左右子树
        vector<int> leftInorder(inorder.begin(), inorder.begin() + root);
        vector<int> rightInorder(inorder.begin() + root + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + root);
        vector<int> rightPostorder(postorder.begin() + root, postorder.end() - 1);

        if (leftInorder.size() > 0) {
            cur->left = buildTree(leftInorder, leftPostorder);
        }
        if (rightInorder.size() > 0) {
            cur->right = buildTree(rightInorder, rightPostorder);
        }
        return cur;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

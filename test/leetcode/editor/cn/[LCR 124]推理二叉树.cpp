//某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组 inorder。请根据 preorder 和 inorder 的提示
//构造出这棵二叉树并返回其根节点。 
//
// 
//
// 注意：preorder 和 inorder 中均不含重复数字。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//
//输出: [3,9,20,null,null,15,7]
// 
//
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//
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
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
//
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1147 👎 0

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
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        //从前序遍历中获取根节点
        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);
        //找到中序遍历中根节点的位置
        int rootIndex = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        //获取左子树的中序遍历
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        //获取右子树的中序遍历
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        //获取左子树的前序遍历
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        //获取右子树的前序遍历
        vector<int> rightPreorder(preorder.begin() + rootIndex + 1, preorder.end());
        //递归构建左子树
        if (!leftInorder.empty()) {
            root->left = deduceTree(leftPreorder, leftInorder);
        }
        //递归构建右子树
        if (!rightInorder.empty()) {
            root->right = deduceTree(rightPreorder, rightInorder);
        }

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

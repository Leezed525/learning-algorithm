//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2900 👎 0

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

    bool recursion(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr) return false;
        if (right == nullptr) return false;
        if (left->val == right->val) {
            bool out = recursion(left->left, right->right);
            bool in = recursion(left->right, right->left);
            return out && in;
        } else {
            return false;
        }
    }

    bool iteration_method(TreeNode *root){
        int expand = -INT32_MAX;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i += 1) {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr) {
                    tmp.push_back(expand);
                } else {
                    tmp.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            int left = 0, right = tmp.size() - 1;
            while (left < right) {
                if (tmp[left] != tmp[right]) return false;
                left += 1;
                right -= 1;
            }
        }

        return true;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
//        return recursion(root->left, root->right);
        return iteration_method(root);

    }
};
//leetcode submit region end(Prohibit modification and deletion)

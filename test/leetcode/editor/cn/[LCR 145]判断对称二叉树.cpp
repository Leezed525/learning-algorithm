//请设计一个函数判断一棵二叉树是否 轴对称 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [6,7,7,8,9,9,8]
//输出：true
//解释：从图中可看出树是轴对称的。 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
//解释：从图中可看出最后一层的节点不对称。 
//
// 
//
// 提示： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/ 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 483 👎 0

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

    bool isSymmetry(TreeNode *left, TreeNode *right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;
        return isSymmetry(left->left, right->right) && isSymmetry(left->right, right->left);
    }

    bool checkSymmetricTree(TreeNode* root) {
        if(root == nullptr) return true;
        return isSymmetry(root->left, root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

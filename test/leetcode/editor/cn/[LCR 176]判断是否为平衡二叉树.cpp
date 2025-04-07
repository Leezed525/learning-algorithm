//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true 
//解释：如下图
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
//解释：如下图
// 
//
// 
// 
//
// 提示： 
//
// 
// 0 <= 树的结点个数 <= 10000 
// 
//
// 注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/ 
//
// Related Topics 树 深度优先搜索 二叉树 👍 401 👎 0

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


    bool balance_flag = true;

    int recursive_find_depth(TreeNode *cur){
        if (cur == nullptr) return 0;
        if(!balance_flag) return 0;
        int left = recursive_find_depth(cur->left);
        int right = recursive_find_depth(cur->right);
        if(abs(left - right) > 1) {
            balance_flag = false;
        }
        return max(left, right) + 1;
    }



    bool isBalanced(TreeNode* root) {
        recursive_find_depth(root);
        return balance_flag;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

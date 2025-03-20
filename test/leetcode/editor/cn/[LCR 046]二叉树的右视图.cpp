//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: [1,2,3,null,5,null,4]
//输出: [1,3,4]
// 
//
// 示例 2： 
//
// 
//输入: [1,null,3]
//输出: [1,3]
// 
//
// 示例 3： 
//
// 
//输入: []
//输出: []
// 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点个数的范围是 [0,100] 
// 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 
// 注意：本题与主站 199 题相同：https://leetcode-cn.com/problems/binary-tree-right-side-
//view/ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 52 👎 0

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
    vector<int> rightSideView(TreeNode *root) {
        if(!root ) return vector<int>();
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i += 1) {
                TreeNode *tmp = q.front();
                if (i == size - 1) res.push_back(tmp->val);
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

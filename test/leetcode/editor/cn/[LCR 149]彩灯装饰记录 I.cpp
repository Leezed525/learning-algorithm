//一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从 左 到 右 的顺序返回每一层彩灯编号。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [8,17,21,18,null,null,6]
//输出：[8,17,21,18,6]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
//
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 313 👎 0

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
    vector<int> decorateRecord(TreeNode *root) {
        if (!root) return vector<int>();
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            res.push_back(cur->val);
            if (cur->left)q.push(cur->left);
            if (cur->right)q.push(cur->right);
        }
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

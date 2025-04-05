//一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照如下规则记录彩灯装饰结果： 
//
// 
// 第一层按照从左到右的顺序记录 
// 除第一层外每一层的记录顺序均与上一层相反。即第一层为从左到右，第二层为从右到左。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [8,17,21,18,null,null,6]
//输出：[[8],[21,17],[18,6]]
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
// Related Topics 树 广度优先搜索 二叉树 👍 315 👎 0

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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        int len = 0;
        while (!q.empty()) {
            len += 1;
            int size = q.size();
            vector<int> level;
            while (size--) {
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
            if(len % 2 == 0) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//某公司架构以二叉树形式记录，请返回该公司的层级数。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1, 2, 2, 3, null, null, 5, 4, null, null, 4]
//输出: 4
//解释: 上面示例中的二叉树的最大深度是 4，沿着路径 1 -> 2 -> 3 -> 4 或 1 -> 2 -> 5 -> 4 到达叶节点的最长路径上有 4 
//个节点。
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 10000 
// 
//
// 注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-
//tree/ 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 276 👎 0

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
    int calculateDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans += 1;
            int size = q.size();
            while (size--) {
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur -> right) q.push(cur->right);
            }
        }

        return ans;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

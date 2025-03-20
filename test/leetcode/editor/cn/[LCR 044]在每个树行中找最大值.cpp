//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。 
//
// 
//
// 示例 1： 
//
// 
//输入: root = [1,3,2,5,3,null,9]
//输出: [1,3,9]
//解释:
//          1
//         / \
//        3   2
//       / \   \  
//      5   3   9 
// 
//
// 示例 2： 
//
// 
//输入: root = [1,2,3]
//输出: [1,3]
//解释:
//          1
//         / \
//        2   3
// 
//
// 示例 3： 
//
// 
//输入: root = [1]
//输出: [1]
// 
//
// 示例 4： 
//
// 
//输入: root = [1,null,2]
//输出: [1,2]
//解释:      
//           1 
//            \
//             2     
// 
//
// 示例 5： 
//
// 
//输入: root = []
//输出: []
// 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点个数的范围是 [0,10⁴] 
// 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// 
//
// 
// 注意：本题与主站 515 题相同： https://leetcode-cn.com/problems/find-largest-value-in-
//each-tree-row/ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 54 👎 0

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
    vector<int> largestValues(TreeNode *root) {
        if(!root) return vector<int>();
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            int maxn = INT_MIN;
            for (int i = 0; i < size; i += 1) {
                TreeNode *tmp = q.front();
                q.pop();
                maxn = max(maxn, tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(maxn);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//某公司组织架构以二叉搜索树形式记录，节点值为处于该职位的员工编号。请返回第 cnt 大的员工编号。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [7, 3, 9, 1, 5], cnt = 2
//       7
//      / \
//     3   9
//    / \
//   1   5
//输出：7
// 
//
// 示例 2： 
//
// 
//
// 
//输入: root = [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8], cnt = 4
//       10
//      / \
//     5   15
//    / \    \
//   2   7    20
//  /   / \ 
// 1   6   8
//输出: 8 
//
// 
//
// 提示： 
//
// 
// 1 ≤ cnt ≤ 二叉搜索树元素个数 
// 
//
// 
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 423 👎 0

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


    bool find_flag = false;
    int ans;

    void dfs(TreeNode *cur, int &cnt){
        if(!cur || find_flag) return;
        dfs(cur->right, cnt);
        cnt--;
        if(cnt == 0){
            ans = cur->val;
            find_flag = true;
            return;
        }
        dfs(cur->left, cnt);
    }

    int findTargetNode(TreeNode* root, int cnt) {
        dfs(root, cnt);
        return ans;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

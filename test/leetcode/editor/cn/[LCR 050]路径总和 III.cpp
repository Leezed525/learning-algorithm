//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。 
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//输出：3
//解释：和等于 8 的路径有 3 条，如图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：3
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,1000] 
// 
// -10⁹ 
// -1000 <= targetSum <= 1000 
// 
//
// 
//
// 
// 注意：本题与主站 437 题相同：https://leetcode-cn.com/problems/path-sum-iii/ 
//
// Related Topics 树 深度优先搜索 二叉树 👍 110 👎 0

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
    unordered_map<long long, int> mp;
    int target;
    int ans = 0;

    void recursion_path_sum(TreeNode *cur, long long presum) {
        if (cur == nullptr) {
            return;
        }
        long long cur_sum = presum + cur->val;
        ans += mp[cur_sum - target];
        mp[cur_sum] += 1;
        recursion_path_sum(cur->left, cur_sum);
        recursion_path_sum(cur->right, cur_sum);
        mp[cur_sum] -= 1;
        return;
    }

    int pathSum(TreeNode *root, int targetSum) {
        mp[0] = 1;
        target = targetSum;
        recursion_path_sum(root, 0L);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

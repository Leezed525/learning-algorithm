//给定一个二叉树，我们在树的节点上安装摄像头。 
//
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。 
//
// 计算监控树的所有节点所需的最小摄像头数量。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[0,0,null,0,0]
//输出：1
//解释：如图所示，一台摄像头足以监控所有节点。
// 
//
// 示例 2： 
//
// 
//
// 输入：[0,0,null,0,null,0,null,null,0]
//输出：2
//解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
// 
//
// 提示： 
//
// 
// 给定树的节点数的范围是 [1, 1000]。 
// 每个节点的值都是 0。 
// 
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 768 👎 0

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

    int res = 0;

    int recursion_find(TreeNode *root) {
        if (root == nullptr) {
            return 2;
        }
        int left = recursion_find(root->left);
        int right = recursion_find(root->right);
        //叶子节点
        if (left == 2 && right == 2) {
            return 0;
        }
        //子节点是叶子节点 放置摄像头
        if (left == 0 || right == 0) {
            res += 1;
            return 1;
        }
        //子节点有摄像头
        if (left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }

    int minCameraCover(TreeNode *root) {
        if(recursion_find(root) == 0) {
            res += 1;
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

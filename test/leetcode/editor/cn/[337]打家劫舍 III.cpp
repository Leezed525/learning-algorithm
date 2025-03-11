//小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为
// root 。 
//
// 除了
// root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的
//房子在同一天晚上被打劫 ，房屋将自动报警。 
//
// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: root = [3,2,3,null,3,null,1]
//输出: 7 
//解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7 
//
// 示例 2: 
//
// 
//
// 
//输入: root = [3,4,5,1,3,null,1]
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 树的节点数在 [1, 10⁴] 范围内 
// 0 <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 2057 👎 0

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

    int recursion_steal(TreeNode *root, int &unsteal) {
        if (root == nullptr) {
            unsteal = 0;
            return 0;
        }
        int left_unsteal = 0, right_unsteal = 0;
        int left_steal = recursion_steal(root->left, left_unsteal);
        int right_steal = recursion_steal(root->right, right_unsteal);
        //当前节点不偷的情况
        //情况1：左右子树都不偷
        int num1 = left_unsteal + right_unsteal;
        //情况2：左右子树都偷
        int num2 = left_steal + right_steal;
        //情况3：左子树偷，右子树不偷
        int num3 = left_steal + right_unsteal;
        //情况4：左子树不偷，右子树偷
        int num4 = left_unsteal + right_steal;
        unsteal = max(num1, max(num2, max(num3, num4)));

        return left_unsteal + right_unsteal + root->val;
    }


    int rob(TreeNode *root) {
        int root_unsteal = 0;
        return max(recursion_steal(root, root_unsteal), root_unsteal);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

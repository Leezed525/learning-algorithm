//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 1208 👎 0

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

    string path2string(vector<int> &path) {
        string ans = "";
        for (int i = 0; i < path.size(); i++) {
            ans += to_string(path[i]);
            if (i != path.size() - 1) {
                ans += "->";
            }
        }
        return ans;
    }

    void recursion(TreeNode *root, vector<int> &path, vector<string> &ans) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            string s = path2string(path);
            ans.push_back(s);
            return;
        }
        if (root->left) {
            recursion(root->left, path, ans);
            path.pop_back();
        }
        if (root->right) {
            recursion(root->right, path, ans);
            path.pop_back();
        }
    }


    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        vector<int> path;
        recursion(root, path, ans);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

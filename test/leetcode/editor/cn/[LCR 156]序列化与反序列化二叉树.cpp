//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 10⁴] 内 
// -1000 <= Node.val <= 1000 
// 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-
//binary-tree/ 
//
// 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 👍 442 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        queue<TreeNode *> q;
        string res = "[";
        if (root == nullptr) return res + "]";
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) {
                res += "null,";
            } else {
                res += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        res[res.size() - 1] = ']'; // 替换最后一个逗号为右括号
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {

        cout << data << endl;
        if (data == "[]") return nullptr;
        data = data.substr(1, data.size() - 2); // 去掉前后的中括号
        int l = 0, r = 0;
        queue<TreeNode *> needChildNodes;
        //找到第一个root节点的值
        while (r < data.size() && data[r] != ',') r++;
        string rootVal = data.substr(l, r - l);
        l = r + 1;
        r = l;
        TreeNode *root = new TreeNode(stoi(rootVal));
        needChildNodes.push(root);
        while (r < data.size()) {
            TreeNode *cur = needChildNodes.front();
            needChildNodes.pop();
            //找到当前的两个子节点
            for (int i = 0; i < 2; i++) {
                while (r < data.size() && data[r] != ',') r++;
                string childVal = data.substr(l, r - l);
                l = r + 1;
                r = l;
                if (childVal == "null") {
                    if (i == 0) cur->left = nullptr;
                    else cur->right = nullptr;
                } else {
                    TreeNode *childNode = new TreeNode(stoi(childVal));
                    if (i == 0) cur->left = childNode;
                    else cur->right = childNode;
                    needChildNodes.push(childNode);
                }
            }
        }

        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)

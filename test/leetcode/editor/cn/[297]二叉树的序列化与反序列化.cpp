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
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 👍 1282 👎 0

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
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i += 1) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp == nullptr) {
                    s += "N ";
                } else {
                    q.push(tmp->left);
                    q.push(tmp->right);
                    s += to_string(tmp->val) + " ";
                }
            }
        }
//        cout << s << endl;
        return s;
    }


    TreeNode *getTreeNodeFromString(string data) {
        if (data == "N") {
            return nullptr;
        }
        int val = stoi(data);
        return new TreeNode(val);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data[0] == 'N') return nullptr;


        queue<TreeNode *> need_insert_node;
        int l = 0, r = 0;
        //找到第一个节点
        while (data[r] != ' ') {
            r++;
        }
        TreeNode *root = getTreeNodeFromString(data.substr(l, r));
        TreeNode *end = new TreeNode(10000);
        r++;
        l = r;
        need_insert_node.push(root);

        int len = data.size();
        while (r < len) {
            if (data[r] == ' ') {
                string s = data.substr(l, r - l);
                l = r + 1;
                TreeNode *tmp = getTreeNodeFromString(s);
                TreeNode *fa = need_insert_node.front();
                if (fa->left == nullptr)
                    fa->left = tmp == nullptr ? end : tmp;
                else {
                    fa->right = tmp == nullptr ? end : tmp;
                    need_insert_node.pop();
                    if(fa -> left == end) fa->left = nullptr;
                    if(fa -> right == end) fa->right = nullptr;
                }
                if (tmp != nullptr)
                    need_insert_node.push(tmp);
            }
            r++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)

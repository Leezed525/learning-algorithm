#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main() {

//    vector<int> postorder = {4, 6, 5, 9, 8};
    string data = "[1,2,3,null,null,4,5,null,null,null,null]";
//    cout << (verifyTreeOrder(postorder) ? "true" : "false") << endl;
    deserialize(data);
}

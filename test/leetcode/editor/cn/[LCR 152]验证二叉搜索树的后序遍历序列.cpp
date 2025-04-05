//请实现一个函数来判断整数数组 postorder 是否为二叉搜索树的后序遍历结果。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: postorder = [4,9,6,5,8]
//输出: false 
//解释：从上图可以看出这不是一颗二叉搜索树
// 
//
// 示例 2： 
//
// 
//
// 
//输入: postorder = [4,6,5,9,8]
//输出: true 
//解释：可构建的二叉搜索树如上图
// 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// postorder 中无重复数字 
// 
//
// 
//
// Related Topics 栈 树 二叉搜索树 递归 数组 二叉树 单调栈 👍 785 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool verifyTreeOrder(vector<int> &postorder) {
        //获取最后一个元素，找到分界线
        int n = postorder.size();
        if (n == 0) return true;
        int root = postorder[n - 1];
        int i = n - 2;
        //判断右子树
        while (i >= 0 && postorder[i] > root) {
            i--;
        }
        //判断左子树
        for (int j = 0; j <= i; j++) {
            if (postorder[j] > root) return false;
        }
        vector<int> left = vector<int>(postorder.begin(), postorder.begin() + i + 1);
        vector<int> right = vector<int>(postorder.begin() + i + 1, postorder.end() - 1);
        //划分左右子树
        return verifyTreeOrder(left) && verifyTreeOrder(right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

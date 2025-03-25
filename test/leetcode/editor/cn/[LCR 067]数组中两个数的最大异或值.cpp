//给定一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。 
//
// 
//
// 
// 
// 示例 1： 
// 
// 
//
// 
//输入：nums = [3,10,5,25,2,8]
//输出：28
//解释：最大运算结果是 5 XOR 25 = 28. 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：nums = [2,4]
//输出：6
// 
//
// 示例 4： 
//
// 
//输入：nums = [8,10,2]
//输出：10
// 
//
// 示例 5： 
//
// 
//输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
//输出：127
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2 * 10⁵ 
// 0 <= nums[i] <= 2³¹ - 1 
// 
//
// 
//
// 进阶：你可以在 O(n) 的时间解决这个问题吗？ 
//
// 
//
// 
// 注意：本题与主站 421 题相同： https://leetcode-cn.com/problems/maximum-xor-of-two-
//numbers-in-an-array/ 
//
// Related Topics 位运算 字典树 数组 哈希表 👍 87 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    struct TrieTree {
        TrieTree *left, *right;

        TrieTree() {
            left = nullptr;
            right = nullptr;
        }
    } *head = new TrieTree();

    void insert(int x) {
        TrieTree *cur = head;
        for (int i = 30; i >= 0; i -= 1) {
            int mask = 1 << i;
            if ((x & mask) >> i) {
                if (!cur->right) cur->right = new TrieTree();
                cur = cur->right;
            } else {
                if (!cur->left) cur->left = new TrieTree();
                cur = cur->left;
            }
        }
    }

    int find_max_xor(int x) {
        TrieTree *cur = head;
        int ans = 0;
        for (int i = 30; i >= 0; i -= 1) {
            int mask = 1 << i;
            if ((x & mask) >> i) {
                if (cur->left) {
                    cur = cur->left;
                    ans |= mask;
                } else {
                    cur = cur->right;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                    ans |= mask;
                } else {
                    cur = cur->left;
                }
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int> &nums) {
        for (int i: nums) insert(i);

        int ans = 0;
        for(int i: nums) ans = max(ans, find_max_xor(i));
        return ans;
//        int max_len = 0;
//        for (int i: nums) max_len = i != 0 ? max(max_len, (int) log2(i)) : max_len;
//        int ans = 0, mask = 0;
//        unordered_set<int> seen;
//        for (int i = max_len; i >= 0; i -= 1) {
//            seen.clear();
//            mask |= (1 << i);
//            int new_ans = ans | (1 << i);
//            for (int x: nums) {
//                x &= mask;
//                if (seen.count(new_ans ^ x)) {
//                    ans = new_ans;
//                    break;
//                }
//                seen.insert(x);
//            }
//        }
//
//        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

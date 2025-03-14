//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
//
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,0,1,2]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
//
// Related Topics 并查集 数组 哈希表 👍 2425 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    unordered_map<int, int> fa;

    int get(int x) {
        if (fa[x] == x) return x;
        return fa[x] = get(fa[x]);
    }

    void merge(int x, int y) {
        fa[get(x)] = get(y);
    }


    int longestConsecutive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i += 1) {
            if (fa.count(nums[i])) continue;
            fa[nums[i]] = nums[i];
            if (fa.count(nums[i] - 1)) merge(nums[i], nums[i] - 1);
            if (fa.count(nums[i] + 1)) merge(nums[i], nums[i] + 1);
        }


//        for(auto it = fa.begin(); it != fa.end(); it++) {
//            cout << it->first << " " << it->second << endl;
//        }
//        cout << endl;


        unordered_map<int, int> cnt;
        int maxn = 0;

        for(auto it = fa.begin(); it != fa.end(); it++) {
            cnt[get(it->first)]++;
            maxn = max(maxn, cnt[get(it->first)]);
        }

//        for(int i = 0;i < nums.size(); i += 1) {
//            cnt[get(nums[i])]++;
//            maxn = max(maxn, cnt[get(nums[i])]);
//        }

        return maxn;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

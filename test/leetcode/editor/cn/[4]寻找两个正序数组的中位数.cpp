//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//
// 算法的时间复杂度应该为 O(log (m+n)) 。
//
//
//
// 示例 1：
//
//
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
//
//
// 示例 2：
//
//
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//
//
//
//
//
//
// 提示：
//
//
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10⁶ <= nums1[i], nums2[i] <= 10⁶
//
//
// Related Topics 数组 二分查找 分治 👍 7477 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nums1;
    vector<int> nums2;
    int n, m;

    int getKth(int start1, int start2, int k) {
        if (start1 >= n)
            return nums2[start2 + k - 1];
        if (start2 >= m)
            return nums1[start1 + k - 1];

        int len = k > 1 ? k / 2 : 1;
        int index1 = min(start1 + len - 1, n - 1);
        int index2 = min(start2 + len - 1, m - 1);
        if (nums1[index1] <= nums2[index2]) {
            if (k == 1) return nums1[index1];
            return getKth(index1 + 1, start2, k - (index1 - start1 + 1));
        } else {
            if (k == 1) return nums2[index2];
            return getKth(start1, index2 + 1, k - (index2 - start2 + 1));
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        n = nums1.size();
        m = nums2.size();
        if ((n + m) % 2 == 0) {
            return (getKth(0, 0, (n + m) / 2) + getKth(0, 0, (n + m) / 2 + 1)) / 2.0;
        } else {
            return getKth(0, 0, (n + m + 1) / 2);
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)

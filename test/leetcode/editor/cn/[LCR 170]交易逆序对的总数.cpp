//在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的
//「交易逆序对」总数。 
//
// 
//
// 示例 1： 
//
// 
//输入：record = [9, 7, 5, 4, 6]
//输出：8
//解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)。
// 
//
// 
//
// 提示： 
//
// 0 <= record.length <= 50000 
//
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 1131 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> arr;
    int ans = 0;


    void merge(int l, int mid, int r){
        int lp = l, rp = mid + 1;

        vector<int> tmp;

        while (lp <= mid && rp <= r) {
            if (arr[lp] > arr[rp]) {
                ans += (mid - lp + 1);
                tmp.push_back(arr[rp]);
                rp++;
            } else {
                tmp.push_back(arr[lp]);
                lp++;
            }
        }
        while (lp <= mid) {
            tmp.push_back(arr[lp]);
            lp++;
        }
        while (rp <= r) {
            tmp.push_back(arr[rp]);
            rp++;
        }
        for (int i = l; i <= r; i++) {
            arr[i] = tmp[i - l];
        }
    }


    void merge_sort(int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }


    int reversePairs(vector<int> &record) {
        arr = record;
        merge_sort(0, record.size() - 1);
//        for(int i = 0; i < arr.size(); i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

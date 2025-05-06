//给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区
//间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的
//开始和结束。 
//
// 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，
//可以合并区间）。 
//
// 返回插入之后的 intervals。 
//
// 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
//输出：[[1,5],[6,9]]
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//输出：[[1,2],[3,10],[12,16]]
//解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁵ 
// intervals 根据 starti 按 升序 排列 
// newInterval.length == 2 
// 0 <= start <= end <= 10⁵ 
// 
//
// Related Topics 数组 👍 981 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool static cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }


    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        int cl = intervals[0][0],cr = intervals[0][1];
        for (int i = 1; i < intervals.size(); i += 1) {
            if(intervals[i][0] > cr){
                ans.push_back({cl,cr});
                cl = intervals[i][0];
                cr = intervals[i][1];
            }else{
                cr = max(cr, intervals[i][1]);
            }
        }
        ans.push_back({cl,cr});
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

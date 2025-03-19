//给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：timePoints = ["23:59","00:00"]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：timePoints = ["00:00","23:59","00:00"]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 2 <= timePoints <= 2 * 10⁴ 
// timePoints[i] 格式为 "HH:MM" 
// 
//
// 
//
// 
// 注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/ 
//
// Related Topics 数组 数学 字符串 排序 👍 50 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    int string_to_int(string s) {
        int sum = 0;
        for (char c: s) {
            sum = sum * 10 + c - '0';
        }
        return sum;
    }

    int time_to_minutes(string s) {
        int hours = string_to_int(s.substr(0, 2));
        int minutes = string_to_int(s.substr(3, 2));
        return hours * 60 + minutes;
    }

    int findMinDifference(vector<string> &timePoints) {
        vector<int> times;
        for (string s: timePoints) {
            times.push_back(time_to_minutes(s));
        }
        sort(times.begin(), times.end());
        //输出times
//        for (int i: times) {
//            cout << i << " ";
//        }
//        cout << endl;
        int res = 24 * 60;
        for (int i = 1; i < times.size(); i += 1) {
            res = min(times[i] - times[i - 1], res);
        }
        res = min(times[0] + 24 * 60 - times[times.size() - 1], res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

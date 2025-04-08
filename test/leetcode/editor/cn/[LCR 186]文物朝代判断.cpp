//展览馆展出来自 13 个朝代的文物，每排展柜展出 5 个文物。某排文物的摆放情况记录于数组 places，其中 places[i] 表示处于第 i 位文物的
//所属朝代编号。其中，编号为 0 的朝代表示未知朝代。请判断并返回这排文物的所属朝代编号是否能够视为连续的五个朝代（如遇未知朝代可算作连续情况）。 
//
// 
//
// 示例 1： 
//
// 
//输入：places = [0, 6, 9, 0, 7]
//输出：True
// 
//
// 
//
// 示例 2： 
//
// 
//输入：places = [7, 8, 9, 10, 11]
//输出：True
// 
//
// 
//
// 提示： 
//
// 
// places.length = 5 
// 0 <= places[i] <= 13 
// 
//
// 
//
// Related Topics 数组 排序 👍 371 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkDynasty(vector<int> &places) {
        sort(places.begin(), places.end());
        int zeroCount = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < 5; i += 1) {
            if (places[i] == 0) {
                zeroCount += 1;
            }else{
                if (places[i] != 0) {
                    min = std::min(min, places[i]);
                    max = std::max(max, places[i]);
                }
                if(i > 0 && places[i] == places[i - 1]) {
                    return false;
                }
            }

        }

        if(max - min > 4) {
            return false;
        }
        return min + 4 - max <= zeroCount;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//某套连招动作记作仅由小写字母组成的序列 arr，其中 arr[i] 第 i 个招式的名字。请返回第一个只出现一次的招式名称，如不存在请返回空格。 
//
// 
//
// 示例 1： 
//
// 
//输入：arr = "abbccdeff"
//输出：'a'
// 
//
// 示例 2： 
//
// 
//输入：arr = "ccdd"
//输出：' '
// 
//
// 
//
// 限制： 
//
// 0 <= arr.length <= 50000 
//
// Related Topics 队列 哈希表 字符串 计数 👍 366 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<int, int> mp;
        for (char ch : arr) {
            mp[ch]++;
        }
        for (char ch : arr) {
            if (mp[ch] == 1) {
                return ch;
            }
        }
        return ' ';
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

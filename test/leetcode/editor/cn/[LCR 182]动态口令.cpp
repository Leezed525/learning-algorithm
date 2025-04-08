//某公司门禁密码使用动态口令技术。初始密码为字符串 password，密码更新均遵循以下步骤： 
//
// 
// 设定一个正整数目标值 target 
// 将 password 前 target 个字符按原顺序移动至字符串末尾 
// 
//
// 请返回更新后的密码字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入: password = "s3cur1tyC0d3", target = 4
//输出: "r1tyC0d3s3cu"
// 
//
// 示例 2： 
//
// 
//输入: password = "lrloseumgh", target = 6
//输出: "umghlrlose"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target < password.length <= 10000 
// 
//
// 
//
// Related Topics 数学 双指针 字符串 👍 482 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string dynamicPassword(string password, int target) {
        reverse(password.begin() , password.end());
        reverse(password.end() - target, password.end());
        reverse(password.begin(), password.end() - target);
        return password;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

//你在与一位习惯从右往左阅读的朋友发消息，他发出的文字顺序都与正常相反但单词内容正确，为了和他顺利交流你决定写一个转换程序，把他所发的消息 message 转
//换为正常语序。 
//
// 注意：输入字符串 message 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空
//格。 
//
// 
//
// 示例 1： 
//
// 
//输入: message = "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 
//输入: message = "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 
//输入: message = "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= message.length <= 10⁴ 
// message 中包含英文大小写字母、空格和数字 
// 
//
// 注意： 
//
// 
// 本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ 
// 
//
// 
//
// Related Topics 双指针 字符串 👍 340 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseMessage(string message) {
        //去掉前后空格
        int l = 0, r = message.size() - 1;
        while (l < r && message[l] == ' ') l++;
        while (l < r && message[r] == ' ') r--;
        string res = "";
        //去掉中间多余的空格
        while (l <= r) {
            if (message[l] != ' ') {
                res += message[l];
            } else if (res != "" && res.back() != ' ') {
                res += ' ';
            }
            l++;
        }
        if(res ==  "") return res;
        reverse(res.begin(), res.end());
        l = 0, r = 0;
        while (r < res.size()) {
            if(res[r] == ' ') {
                reverse(res.begin() + l, res.begin() + r);
                l = r + 1;
            }
            r += 1;
        }
        reverse(res.begin() + l, res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

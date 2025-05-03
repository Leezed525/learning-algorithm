//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。 
//
// 
//
// 示例 1: 
//
// 
//输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 
//输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 和 num2 只能由数字组成。 
// num1 和 num2 都不包含任何前导零，除了数字0本身。 
// 
//
// Related Topics 数学 字符串 模拟 👍 1425 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    string add(string num1, string num2) {
        int increment = 0;
        int i = 0;
        string res = "";
        int size1 = num1.size(), size2 = num2.size();
        while (size1 - i > 0 && size2 - i > 0) {
            int tmp = num1[size1 - 1 - i] - '0' + num2[size2 - 1 - i] - '0' + increment;
            res += tmp % 10 + '0';
            increment = tmp / 10;
            i += 1;
        }
        while (size1 - i > 0) {
            int tmp = num1[size1 - 1 - i] - '0' + increment;
            res += tmp % 10 + '0';
            increment = tmp / 10;
            i += 1;
        }
        while (size2 - i > 0) {
            int tmp = num2[size2 - 1 - i] - '0' + increment;
            res += tmp % 10 + '0';
            increment = tmp / 10;
            i += 1;
        }

        if (increment > 0) {
            res += increment + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {
        string sum = "0";
        for (int i = num2.size() - 1; i >= 0; i -= 1) {
            int cur = num2[i] - '0';
            string tmp = "";
            int incr = 0;
            for (int j = num1.size() - 1; j >= 0; j -= 1) {
                int num = (num1[j] - '0') * cur + incr;
                tmp += num % 10 + '0';
                incr = num / 10;
            }
            if (incr > 0) {
                tmp += incr + '0';
            }
            reverse(tmp.begin(), tmp.end());
            for(int j = 0; j < num2.size() - 1 - i; j += 1) {
                tmp += '0';
            }
//            cout << tmp << endl;
            sum = add(sum, tmp);
        }
        //去掉前导零
        while (sum.size() > 1 && sum[0] == '0') {
            sum.erase(sum.begin());
        }
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

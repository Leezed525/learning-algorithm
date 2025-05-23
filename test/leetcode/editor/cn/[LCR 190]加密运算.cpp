//计算机安全专家正在开发一款高度安全的加密通信软件，需要在进行数据传输时对数据进行加密和解密操作。假定 dataA 和 dataB 分别为随机抽样的两次通信的
//数据量： 
//
// 
// 正数为发送量 
// 负数为接受量 
// 0 为数据遗失 
// 
//
// 请不使用四则运算符的情况下实现一个函数计算两次通信的数据量之和（三种情况均需被统计），以确保在数据传输过程中的高安全性和保密性。 
//
// 
//
// 示例 1： 
//
// 
//输入：dataA = 5, dataB = -1
//输出：4
// 
//
// 
//
// 提示： 
//
// 
// dataA 和 dataB 均可能是负数或 0 
// 结果不会溢出 32 位整数 
// 
//
// 
//
// Related Topics 位运算 数学 👍 472 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int encryptionCalculate(int dataA, int dataB) {
        while(dataB != 0)
        {
            int c = (unsigned int)(dataA & dataB) << 1;
            dataA ^= dataB;
            dataB = c;
        }
        return dataA;
    }
};


//leetcode submit region end(Prohibit modification and deletion)

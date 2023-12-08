//
// Created by Leezed on 2023/12/8.
//
#include <stdio.h>
#include <cstring>

int main() {
    //注意这题如果细细考究可以在加上是否是一个单词的判断
    //因为可能一个单词内部包含the三个字母，比如“there”
    //如果需要考虑这种情况只需要搜索" the "这5个字符就好了
    char str[2000];
    gets(str);
    //输出字符串中“the”单词的个数
    int length = strlen(str);
    int count = 0;
    for (int i = 0; i < length - 2; i += 1) {
        //判断当前字符是否为t
        if (str[i] == 't') {
            //判断当前字符的下一个字符是否为h
            if (str[i + 1] == 'h') {
                //判断当前字符的下两个字符是否为e
                if (str[i + 2] == 'e') {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
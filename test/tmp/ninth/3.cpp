#include<cstdio>
#include<stdio.h>

char ch[100];

int main() {
    FILE *fp1 = fopen("My_string.txt", "r");
    FILE *fp2 = fopen("My_string_temp.txt", "w");
    while (fscanf(fp1, "%s", ch) != EOF) {//依次读入数据
        for (int i = 0; i < sizeof(ch); i++) {
            if ('a' <= ch[i] && ch[i] <= 'z') ch[i] -= 'a' - 'A';//小写改大写
        }
        fprintf(fp2, "%s\n", ch);
    }
    fclose(fp1);
    fclose(fp2);
    remove("My_string.txt");//删除原文件
    rename("My_string_temp.txt", "My_string.txt");//改名
    return 0;
}

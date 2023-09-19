#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 10100;
int a[MAXN],b[MAXN];
string add(string s1,string s2)
{
int len1 = s1.length();
    int len2 = s2.length();
    if(len1 < len2){
        for(int i = 1;i <= len2 - len1;i++){
            s1 = "0" + s1;
        }
    }
    else{
        for(int i = 1;i <= len1 - len2;i++){
            s2 = "0" + s2;
        }
    }
    len1 = s1.length();
    string ans;
    int tmp = 0;
    for(int i = len1 - 1;i >= 0;i--){
        int num = s1[i] - '0' + s2[i] - '0' + tmp;
        tmp = num / 10;
        num %= 10;
        ans = char(num + '0') + ans;
    }
    while(tmp != 0){
        ans = char(tmp%10 + '0') + ans;
        tmp /= 10;
    }
    return ans;
}

void sub(string s1,string s2)
{
    int flag = 0;
    int len1 = s1.length(),len2 = s2.length();
    if(len1 < len2){
        swap(s1,s2);
        flag = 1;
    }
    else if(len1 == len2){
        for(int i = 0;i < len1;i++){
            if(s1[i] < s2[i]){
                swap(s1,s2);
                flag = 1;
                break;
            }
        }
    }
    len1 = s1.length();
    len2 = s2.length();
    for(int i = 0;i < len1;i++) a[len1 - i] = s1[i] - '0';
    for(int i = 0;i < len2;i++) b[len2 - i] = s2[i] - '0';
    for(int i = 1;i <= len1;i++){
        a[i] -= b[i];
        if(a[i] < 0){
            a[i + 1]--;
            a[i] += 10;
        }
    }
    while(a[len1] == 0 && len1 > 1) len1--;
    if(flag){
        printf("-");
    }
    for(int i = len1;i >= 1;i--){
        printf("%d",a[i]);
    }
    cout << endl;
    return ;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    //cout << add(s1,s2) << endl;
    sub(s1,s2);
    //system("pause");
    return 0;
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
int vis[10];
int arr[10];
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) vis[s[i] - '0'] = 1;
    int num = 0;
    for (int i = 9; i >= 0; i--)
        if (vis[i]) arr[num++] = i;
    printf("int[] arr = new int[]{");
    for (int i = 0; i < num; i++) {
        if (i) printf(",");
        printf("%d", arr[i]);
    }
    printf("};\n");
    printf("int[] index = new int[]{");
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < num; j++) {
            if (s[i] - '0' == arr[j]) {
                if (i) printf(",");
                printf("%d", j);
            }
        }
    printf("};\n");

    // system("pause");
    return 0;
}
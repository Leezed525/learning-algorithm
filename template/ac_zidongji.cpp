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
/*
        hdu 2222
*/
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const int N = 26;
const int MAXN = 5e5 + 10;

struct trie {
    int next[MAXN][N], fail[MAXN], end[MAXN];
    int root;
    int tot;
    int newnode() {
        for (int i = 0; i < N; i++) next[tot][i] = -1;
        end[tot++] = 0;
        return tot - 1;
    }
    void init() {
        tot = 0;
        root = newnode();
    }
    void insert(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            int k = buf[i] - 'a';
            if (next[now][k] == -1) next[now][k] = newnode();
            now = next[now][k];
        }
        end[now]++;
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < N; i++) {
            if (next[root][i] == -1)
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < N; i++) {
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    q.push(next[now][i]);
                }
            }
        }
    }
    int query(char buf[]) {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while (temp != root) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};
trie ac;
char s[MAXN +MAXN];
int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ac.init();
        for(int i = 0;i < n;i++){
            scanf("%s",s);
            ac.insert(s);
        }
        ac.build();
        scanf("%s",s);
        printf("%d\n",ac.query(s));
    }
    // system("pause");
    return 0;
}
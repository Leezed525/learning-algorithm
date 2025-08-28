#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100005][11];
int n, k;
vector<int> head[2005];

bool check(int x, int y) {
    int sum = a[x][1] + a[y][1];
    for (int i = 2; i <= k; i++)
        if (a[x][i] + a[y][i] != sum)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int i, j, ans = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= k; j++)
            cin >> a[i][j];
    for (i = 1; i <= n; i++) {
        int sum = 0;
        for (j = 2; j <= k; j++)
            sum += a[i][j] - a[i][j - 1];
        for (j = 0; j < head[-sum + 1000].size(); j++)
            if (check(i, head[-sum + 1000][j]))
                ans++;
        head[sum + 1000].push_back(i);
    }
    cout << ans;
    return 0;
}

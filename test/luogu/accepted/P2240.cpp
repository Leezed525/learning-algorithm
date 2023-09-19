#include <bits/stdc++.h>
using namespace std;

struct node {
    int m, v;
};

bool cmp(node a, node b) {
    //  return a.v * 1.0 / (a.m * 1.0) > b.v * 1.0 / (b.m * 1.0); 
     return a.v * b.m > b.v * a.m ; 
}

int main() {
    int n, t;
    cin >> n >> t;
    node a[110];
    for (int i = 0; i < n; i += 1) {
        scanf("%d %d", &a[i].m, &a[i].v);
    }
    sort(a, a + n, cmp);
    double ans = 0;
    int index = 0;
    while (t > 0 && index < n) {
        if (a[index].m <= t) {
            t -= a[index].m;
            ans += a[index].v;
        } else {
            // ans += t * a[index].v * 1.0 / (a[index].m * 1.0);
            ans+=a[index].v*t*1.0/(a[index].m*1.0);
            t = 0;
        }
        index += 1;
    }
    printf("%.2lf\n", ans);

    // system("pause");
    return 0;
}
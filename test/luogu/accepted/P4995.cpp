#include <bits/stdc++.h>
using namespace std;

long long getVal(int a, int b) { return (long long)((a - b) * (a - b)); }

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    // for(int i = 0; i < n; i++) printf("%d", a[i]);
    int l = 0, r = n - 1;
    int currentpos = 0;
    while (l <= r) {
        sum += getVal(a[r], currentpos);
        currentpos = a[r--];
        if (l <= r) {
            sum += getVal(a[l], currentpos);
            currentpos = a[l++];
        }
    }
    cout << sum << endl;

    // system("pause");
    return 0;
}
//
// Created by Leezed on 2025/8/16.
//
#include"bits/stdc++.h"

using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
        }
        map<int, int> count;
        int increase[n];
        int last_pos[n];//对于每个点而言，比当前点大一的数字在他之前出现的位置
        int pos[n + 1];//记录某个最近出现的位置


        memset(increase, 0, sizeof increase);

        for (int i = 0; i < n; i += 1) {
            last_pos[i] = -1;
        }

        for (int i = 1; i <= n; i += 1) {
            pos[i] = -1;
        }

        for (int i = 0; i < n; i += 1) {
            auto it = count.upper_bound(a[i]);
            if (it != count.end()) {
                //计算当前数加一能让减少多少逆序数
                if (it->first == a[i] + 1) {
                    increase[i] = it->second;
                }
            }
            count[a[i]] += 1;
            pos[a[i]] = i;
            last_pos[i] = (a[i] == n ? -1 : pos[a[i] + 1]);
        }

        int l = 0, r = 0;
        int ans = 0;
        int sum = 0;
        while (r < n) {
            sum += increase[r];
            if (last_pos[r] != -1) {
                while (l <= last_pos[r]) {
                    sum -= increase[l];
                    l++;
                }
            }
            r++;
            ans = max(ans, sum);
        }

        cout << sum << endl;

    }
    return 0;
}
/*
3
11
4 2 3 1 5 1 2 2 2 2 2
20
4 2 3 1 5 1 2 2 2 2 2 1 1 1 1 1 1 1 1 1
13
4 2 3 1 5 1 2 2 2 2 2 1 1

*/
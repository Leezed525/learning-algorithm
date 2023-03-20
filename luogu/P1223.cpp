#include <bits/stdc++.h>
using namespace std;

struct node {
    int index;
    int time;
};

bool cmp(node a, node b) { return a.time < b.time ? true : a.time == b.time ? a.index < b.index : false; }

int main() {
    int n;
    cin >> n;
    node a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].time);
        a[i].index = i;
    }
    sort(a,a + n ,cmp);
    long long sum = 0;
    long long wait = 0;
    for(int i = 0; i < n; i+= 1){
        printf("%d ",a[i].index + 1);
        sum += wait;
        wait += a[i].time;
    }
    printf("\n%.2lf",sum *1.0 / n);
    // system("pause");
    return 0;
}
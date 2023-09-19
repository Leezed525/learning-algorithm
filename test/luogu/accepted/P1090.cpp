#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    while(n--) {
        int x;
        cin >> x;
        q.push(x);
    }
    int sum = 0;
    while(q.size() > 1) {
        int a1 = q.top();
        q.pop();
        int a2 = q.top();
        q.pop();
        int x = a1 + a2;
        sum += x;
        q.push(x);
    }
    cout << sum << endl;
    // system("pause");
    return 0;
}
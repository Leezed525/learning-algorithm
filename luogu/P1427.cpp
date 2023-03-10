#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    int num;
    while(cin >> num && num != 0){
        s.push(num);
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    // system("pause");
    return 0;
}
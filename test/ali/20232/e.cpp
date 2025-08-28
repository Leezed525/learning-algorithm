//
// Created by Leezed on 2025/8/26.
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        vector<vector<int>> pos(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                cin >> pos[i][j];
            }
        }
        sort(pos.begin(), pos.end(), [&](auto& a, auto& b){
            return a[0] < b[0];
        });
        long sum = 0;
        int left = 0, right = n - 1;
        while(left < right){
            sum += pos[right][0] - pos[left][0];
            left++;
            right--;
        }
        cout << sum << endl;
    }
}
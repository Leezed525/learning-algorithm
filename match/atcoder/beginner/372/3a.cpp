//
// Created by Leezed on 2024/9/21.
//
#include<string>
#include<iostream>

using namespace std;
int a[11] = {0};
int ans[10];


int main() {
    int num;
    cin >> num;
    a[0] = 1;
    for (int i = 1; i < 11; i += 1) {
        a[i] = a[i - 1] * 3;
    }
    int index = 0;
    int current_max = 10;
    while (num != 0) {
        while (num >= a[current_max]) {
            ans[index++] = current_max;
            num -= a[current_max];
        }
        current_max -= 1;
    }

    cout << index << endl;
    for (int i = 0; i < index; i += 1) {
        cout << ans[i] << " ";
    }


    return 0;
}
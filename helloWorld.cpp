#include "bits/stdc++.h"

using namespace std;

bool verifyTreeOrder(vector<int> &postorder) {
    //获取最后一个元素，找到分界线
    int n = postorder.size();
    if (n == 0) return true;
    int root = postorder[n - 1];
    int i = n - 2;
    //判断右子树
    while (i >= 0 && postorder[i] > root) {
        i--;
    }
    //判断左子树
    for (int j = 0; j <= i; j++) {
        if (postorder[j] > root) return false;
    }
    vector<int> left = vector<int>(postorder.begin(), postorder.begin() + i + 1);
    vector<int> right = vector<int>(postorder.begin() + i + 1, postorder.end() - 1);
    //划分左右子树
    return verifyTreeOrder(left) && verifyTreeOrder(right);
}


int main() {

    vector<int> postorder = {4, 6, 5, 9, 8};
    cout << (verifyTreeOrder(postorder) ? "true" : "false") << endl;

}

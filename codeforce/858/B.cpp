#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define ms(x, n) memset(x, n, sizeof(x));
using namespace std;
//*(int(*)[10])arr_name
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
inline int lowbit(int x) { return x & -x; }

void minimumMEX(int arr[], int N, int K)
{
    // Stores element from [1, N + 1]
    // which are not present in subarray
    set<int> s;
 
    // Store number 1 to N + 1 in set s
    for (int i = 1; i <= N + 1; i++)
        s.insert(i);
 
    // Find the MEX of K-length
    // subarray starting from index 0
    for (int i = 0; i < K; i++)
        s.erase(arr[i]);
 
    int mex = *(s.begin());
 
    // Find the MEX of all subarrays
    // of length K by erasing arr[i]
    // and inserting arr[i - K]
    for (int i = K; i < N; i++) {
 
        s.erase(arr[i]);
 
        s.insert(arr[i - K]);
 
        // Store first element of set
        int firstElem = *(s.begin());
 
        // Updating the mex
        mex = min(mex, firstElem);
    }
 
    // Print minimum MEX of
    // all K length subarray
    cout << mex << endl;
}
 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int flag[200010];
        ms(flag, 0);
        int a[n] = {0};
        for(int i = 1;i <=n;i+=1) {
            scanf("%d",&a[i]);
        }
        minimumMEX(a,n,2);
        // int b[n] = {0};
        // for(int i = 0;i < n - 1;i += 1){
        //     b[i] = b[i] + b[i + 1];
        //     flag[b[i]] = 1;
        // }
        // for(int i = 0;;i+= 1){
        //     if(flag[i] == 0){
        //         cout << i << endl;
        //         break;
        //     }
        // }
    }
    // system("pause");
    return 0;
}
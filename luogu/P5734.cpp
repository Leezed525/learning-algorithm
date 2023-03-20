#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (n--) {
        int op;
        cin >> op;
        if(op == 1){
            string tmp;
            cin >> tmp;
            s = s + tmp;
            cout << s << endl;
        }else if(op == 2){
            int start,len;
            cin >> start >> len;
            s = s.substr(start,len);
            cout << s << endl;
        }else if(op == 3){
            int index;
            string tmp;
            cin >> index >> tmp;
            s.insert(index,tmp);
            cout << s << endl;
        }else if(op == 4){
            string tmp;
            cin >> tmp;
            int key = s.find(tmp);
            if(key == string::npos){
                cout << -1 << endl;
            }else{
                cout << key << endl;
            }
        }
    }
    
    // system("pause");
    return 0;
}
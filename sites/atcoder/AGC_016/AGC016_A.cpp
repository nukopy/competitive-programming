#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
using ll = long long;

int main() {
    // input
    string S;
    cin >> S;
    set<char> chars;
    for (ll i = 0; i < S.length(); ++i) chars.insert(S[i]);  // チェックするための文字秋雨号
    
    if (chars.size() == 1) {
        // 全部同じ文字
        cout << 0 << "\n";
        return 0;
    }
    
    // calculation
    ll res = 100, times;
    for (auto key = chars.begin(); key != chars.end(); ++key) {
        // prepare simulation
        string str = S;
        bool flag = true;  // 全ての文字が同じでない:true
        times = 1;
        
        while (flag) {
            string vacant;
            flag = false;
            for (ll i = 0; i < str.length()-1; ++i) {
                // shrink
                if (str[i] == *key || str[i+1] == *key) {
                    vacant += *key;
                } else {
                    vacant += str[i];
                    flag = true;
                }
            }
            
            if (flag) {
                // 1回の操作後，違う文字が混じっていた場合
                str = vacant;
                times++;
            }
        }
        
        // update
        res = min(res, times);
    }
    
    cout << res << "\n";
    
    return 0;
}

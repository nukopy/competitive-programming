// ABC110_C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // std::copy()
using namespace std;
using ll = long long;

int main() {
    // input
    string S, T;
    cin >> S >> T;
    
    // calculation
    if (S == T) {
        cout << "Yes" << "\n";
    } else {
        // 対応関係を作る
        vector<ll> start(26, -1), goal(26, -1);
        ll sta, go;
        bool flag = true;
        for (ll i = 0; i < S.length(); ++i) {
            sta = S[i] - 'a';
            go = T[i] - 'a';
            if (start[sta] != -1 || goal[go] != -1) {
                // 既に書かれていた場合
                if (start[sta] != go || goal[go] != sta) {
                    // 対応関係が異なっていたら No
                    cout << "No" << "\n";
                    return 0;
                }
            } else {
                start[sta] = go;
                goal[go] = sta;
            }
        }
        cout << "Yes" << "\n";
    }
    return 0;
}

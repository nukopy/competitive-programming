// AGC013_A
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N), vec_diff(N-1);
    REP(i, N) cin >> vec[i];
    for (ll i = 1; i < N; ++i) {
        vec_diff[i-1] = vec[i] - vec[i-1];
    }
    
    // calculation
    if (N <= 2) {
        cout << 1 << "\n";
    } else {
        ll res = 1;
        ll diff_now;
        bool flag_before = (vec[1]-vec[0]) > 0, flag_now;
        bool flag_flat = (vec[1]-vec[0] == 0);
        
        for (ll i = 2; i < N; ++i) {
            diff_now = vec[i] - vec[i-1];
            flag_now = diff_now > 0;  // 増加なら true
            if (diff_now == 0) {
                continue;
            }
            
            if (flag_flat) {
                flag_flat = false;
            } else {
                // flag の変化があった時に それを数える
                if (flag_before != flag_now) {
                    res += 1;
                    flag_flat = true;
                }
            }
            
            flag_before = flag_now;
        }
        cout << res << "\n";
    }
    return 0;
}

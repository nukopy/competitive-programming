#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // std::greater<T>()
#include <climits>  // INT_MIN
#include <cmath>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
const ll INF = 1LL<<60; 

int main() {
    // input
    ll A, B, Q, q;
    cin >> A >> B >> Q;
    vector<ll> Jin(A), Tera(B);
    REP(i, A) cin >> Jin[i];
    REP(i, B) cin >> Tera[i];
    Jin.push_back(INF); Jin.push_back(-INF);
    Tera.push_back(INF); Tera.push_back(-INF);
    sort(Jin.begin(), Jin.end());
    sort(Tera.begin(), Tera.end());
    
    // calculation
    REP(i, Q) {
        cin >> q;
        auto s = lower_bound(Jin.begin(), Jin.end(), q);
        auto t = lower_bound(Tera.begin(), Tera.end(), q);
        
        // 距離の最小値を求める
        vector<ll> ss = {*s, *prev(s)};
        vector<ll> tt = {*t, *prev(t)};
        ll res = INF;
        REP(j, 2) {
            REP(k, 2) {
                if (q < ss[j] && q < tt[k]) {
                    res = min(res, max(ss[j], tt[k]) - q);
                } else if (ss[j] < q && tt[k] < q) {
                    res = min(res, q - min(ss[j], tt[k]));
                } else {
                    // q が間にある
                    res = min(res, abs(tt[k]-ss[j]) + min(abs(tt[k]-q), abs(ss[j]-q)));
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
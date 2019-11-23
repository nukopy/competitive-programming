// ABC121_B
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, M, C, code;
    cin >> N >> M >> C;
    vector<ll> vec(M);
    REP(i, M) cin >> vec[i];
    
    ll res = 0;
    REP(i, N) {
        ll sum = C;
        REP(j, M) {
            cin >> code;
            sum += vec[j]*code;
        }
        if (sum > 0) res++;
    }
    
    cout << res << "\n";
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int greedy() {
    // input(sunippets: inpv, inpn, inps)
    ll N, B, C, D;
    cin >> N >> B >> C >> D;
    
    if (N == B || N == C || N == D) {
        cout << "NO" << "\n";
    } else {
        ll n;
        for (ll i = 0; i < 100; ++i) {
            if (N-3 != B && N-3 != C && N-3 != D) N -= 3;
            else if (N-2 != B && N-2 != C && N-2 != D) N -= 2;
            else if (N-1 != B && N-1 != C && N-1 != D) N -= 1;
            else {
                cout << "NO" << "\n";
                return 0;
            }
            if (N <= 0) break;
        }
        
        if (N <= 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}

const ll INF = 1LL<<60;
vector<ll> dp(310, INF);

int DP() {
    ll N;
    cin >> N;
    dp[N] = 0;
    vector<ll> NG(3);
    for (ll i = 0; i < 3; ++i) cin >> NG[i];
    
    for (ll i = N; i >= 0; ++i) {
        if (NG)
    }
}

int main() {
    // greedy();
    DP();
    return 0;
}
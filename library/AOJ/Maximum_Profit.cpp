/*
時系列データでの最大差を求める問題
各時点での１つ前の時点までの最小値を保持しておく実装により，
 O(N)で一番価格（値）が離れた最大利益を算出できる．
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

// BEGIN CUT
// verified AOJ: ALDS1_1 - D: Maximum Profit
int ALDS1_1_D() {
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for (ll i = 0; i < N; ++i) cin >> vec[i];
    
    // calculation
    ll minv = vec[0], max_benefit = LLONG_MIN;
    for (ll i = 1; i < N; ++i) {
        // vec[i] - minv は，これまでの最小値と現在価格の差
        max_benefit = max(max_benefit, vec[i] - minv);
        minv = min(minv, vec[i]);  // これまでの最小値を更新
    }
    cout << max_benefit << "\n";
    return 0;
}
// END CUT

int main() {
    ALDS1_1_D();
    
    return 0;
}

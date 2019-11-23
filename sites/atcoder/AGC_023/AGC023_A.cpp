#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
    // input
    ll N, A_i, sum = 0, res = 0;
    cin >> N;
    map<ll, ll> mp;
    mp[0] = 1;
    
    for (ll i = 0; i < N; ++i) {
        cin >> A_i;
        sum += A_i;
        res += mp[sum];  // key がなければ 0 を返す
        mp[sum]++;
    }
    
    cout << res << "\n";
    
    return 0;
}

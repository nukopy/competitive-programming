// ABC120_B
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll A, B, K, cnt = 0;
    cin >> A >> B >> K;
    
    // calculation
    for (ll i = min(A, B); i >= 0; --i) {
        if (A%i == 0 && B%i == 0) cnt++;
        if (cnt == K) {
            cout << i << "\n";
            return 0;
        }
    }
    
    return 0;
}
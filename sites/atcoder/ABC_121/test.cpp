#include <iostream>
using namespace std;
using ll = long long;

int main() {
    // input
    ll A, B, K;
    cin >> A >> B >> K;
    
    // calculation
    ll mn = min(A, B), n = 0;
    for (ll i = mn; i >= 1; --i) {
        if (A%i == 0 && B%i == 0) ++n;
        if (n == K) {
            cout << i << "\n";
            return 0;
        }
    }
    
    return 0;
}
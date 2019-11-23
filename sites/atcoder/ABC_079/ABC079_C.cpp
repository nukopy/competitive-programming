#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int test() {
    // input
    string S;
    cin >> S;
    const ll BIT_0 = (1<<0);
    const ll BIT_1 = (1<<1);
    const ll BIT_2 = (1<<2);
    
    // calculation
    ll A = S[0] - '0', B = S[1] - '0', C = S[2] - '0', D = S[3] - '0';
    ll bit = 1, res;
    bool flag_A, flag_B, flag_C;
    for (ll i = 0; i < (bit<<3); ++i) {
        res = A;
        flag_A = BIT_0 & i, flag_B = BIT_1 & i, flag_C = BIT_2 & i;
        res = res + (flag_A ? B: -B);
        res = res + (flag_B ? C: -C);
        res = res + (flag_C ? D: -D);
        if (res == 7) break;
    }
    
    cout << A << (flag_A ? '+': '-') << B << (flag_B ? '+': '-') << C << (flag_C ? '+': '-') << D << "=7" << "\n";
    
    return 0;
}

int main() {
    string S;
    cin >> S;
    
    ll BIT = (1<<3), sum;  // 2^3
    for (ll i = 0; i < BIT; ++i) {
        string res; res += S[0];
        sum = S[0] - '0';
        
        // +: 1, -: 0 とする
        // 0 ~ 2 のビットを全探索
        for (ll j = 0; j < 3; ++j) {
            if (i & 1<<j) {
                sum += S[j+1] - '0';
                res += '+';
                res += S[j+1];
            } else {
                sum -= S[j+1] - '0';
                res += '-';
                res += S[j+1];
            }
        }
        
        if (sum == 7) {
            cout << res << "=7" << "\n";
            return 0;
        }
    }
    
    return 0;
}
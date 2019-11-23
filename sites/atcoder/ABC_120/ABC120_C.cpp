// ABC120_C
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    // input(sunippets: inpv, inpn)
    string S;
    cin >> S;
    
    // calculation
    // 最終的に 0, 1 どちらかだけになる
    ll zero = 0, one = 0;
    for (ll i = 0; i < S.size(); ++i) {
        if (S[i] == '0') ++zero;
        else ++one;
    }
    cout << min(zero, one)*2 << "\n";
    
    return 0;
}
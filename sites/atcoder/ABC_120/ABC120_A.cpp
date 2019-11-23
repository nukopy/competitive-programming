// ABC120_A
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    // input(sunippets: inpv, inpn)
    ll A, B, C;
    cin >> A >> B >> C;
    
    // calculation
    cout << min(C, B/A) << "\n";
    
    return 0;
}
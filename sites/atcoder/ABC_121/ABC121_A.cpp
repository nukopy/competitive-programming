// ABC121_A
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    
    // calculation
    cout << (H-h)*(W-w) << endl;
    
    return 0;
}
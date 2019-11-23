#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    // input
    ll N;
    cin >> N;
    string ans = "";
    
    // calculation
    while(N != 0) {
        if (N%2 != 0) {
            --N;
            ans = "1" + ans;
        } else {
            ans = "0" + ans;
        }
        N /= -2;
    }
    if (ans == "") ans = "0";
    
    cout << ans << "\n";
    
    return 0;
}
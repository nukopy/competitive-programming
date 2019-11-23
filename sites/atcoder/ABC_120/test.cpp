#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

template <class T>
void printVec(vector <T> &vec) {
    size_t len = vec.size();
    for (ll i = 0; i < len; ++i) {
        if (i) cout << " ";
        cout << vec[i];
    }
    cout << "\n";
}

int main() {
    // input
    ll N = 5;
    vector<ll> vec(N, 5);
    
    for (ll i = 0; i < N; i++) vec[i] = i;
    
    printVec(vec);
    
    printVec(vec);
    
    return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

//CUT HERE BEGIN ysys13
template <typename T>
T LinearSearch(vector<T> &vec, T key) {
    for (T i = 0; i < vec.size(); ++i) {
        if (vec[i] == key) return i;
    }
    return -1;
}

template <typename T>
T LinearSearch2(vector<T> vec, T key) {
    // 定数倍計算量落とした版
    T i = 0, n = (T)vec.size();
    vec.push_back(key);
    while (vec[i] != key) i++;
    return (i != n)? i: -1;
}
//CUT HERE END

// verified AOJ: ALDS1_4_A
int ALDS1_4_A() {
    // input
    int N, M;
    cin >> N;
    vector<ll> S(N);
    for (ll i = 0; i < N; i++) cin >> S[i];
    cin >> M;
    vector<ll> T(M);
    for (ll i = 0; i < M; i++) cin >> T[i];
    
    // calculation
    ll res = 0;
    for (ll j = 0; j < M; ++j) {
        if (LinearSearch2(S, T[j]) != -1) {
            res++;
        }
    }
    
    cout << res << "\n";
    return 0;
}

int main() {
    ALDS1_4_A();
    return 0;
}

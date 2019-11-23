// #include<bits/stdc++.h>
#include <numeric>  // std::gcd, std::lcm
#include <utility>  // std::swap()
#include <iostream>
using namespace std;
using ll = long long;

//BEGIN CUT HERE ysys13
// ユークリッドの互除法：最大公約数を求めるアルゴリズム
/*
a % b = c
b % c = d
c % d = e
...
y % z = 0
このとき z は最大公約数となる
*/
// 最大公約数（Greatest Common Divisor）：gcd()
template <typename T>
T gcd(T a, T b) {
    if (a <= 0 || b <= 0) {
        // どちらかが 0 以下であれば -1 を返す
        return -1;
    } else if (a == 1 || b == 1) {
        // どちらかが 1 であれば，最大公約数は 1
        return 1;
    } else {
        if (a < b) swap(a, b);
        if (a%b == 0) return b;
        return gcd(b, a%b);
    }
}

// 最小公倍数（Least Common Multiple）：lcm()
template <typename T>
T lcm(T a, T b) {
    return (a*b)/gcd(a, b);
}

//END CUT HERE ysys13
// verified AOJ: ALDS1_1 - B
int ALDS1_1_B() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    int N, M;
    cin >> N >> M;
    
    // calculation
    cout << gcd(N, M) << "\n";
    
    return 0;
}

// verified AtCoder: ABC118 - C

int ABC118_C() {
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N);
    REP(i, N) cin >> vec[i];
    
    // calculation
    // 各項で引き算し合うときに，
    // ユークリッドの互除法であることに気づけば，
    // 各項の最小公倍数を考えれば良いことに気づく．
    // (a * x - b * x) (a > b) より a - b も x の倍数になる．
    ll res, g = vec[0];
    for (ll i = 1; i < N; ++i) {
        g = gcd(g, vec[i]);
    }
    
    cout << g << "\n";
    
    return 0;
}


int test() {
    // 最大公約数
    cout << gcd(12, 18) << "\n";
    cout << lcm(3, 5) << "\n";
    return 0;
}

int main() {
    ALDS1_1_B();
    return 0;
}

// verify: ABC109: C - Skip https://atcoder.jp/contests/abc109/tasks/abc109_c
// verify: ABC118: C - Monster

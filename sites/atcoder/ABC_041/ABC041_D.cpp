// ABC041_D
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <bitset>  // static_cast<std::bitset<8>>
#include <sstream>  // std::stringstream
#include <cmath>
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
#include <iomanip>  // std::setprecision()
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値
#define pll pair<ll, ll>
#define F first
#define S second

template <typename T>
T factorial(T num) {
    if (num == 0 || num == 1) {
        // 0! = 1, 1! = 1;
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

template <typename T>
T nCr(T n, T r) {
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
    // input
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M), Y(M);
    REP(i, N) cin >> X[i] >> Y[i];
    
    // calculation
    if (N == 2) {
        // M == 1
        cout << 1 << "\n";
    } else {
        ll res = 0; bool flag;
        vector<ll> rank(N); REP(i, N) rank[i] = i+1;
        do {
            flag = true;
            REP(i, M) {
                auto fir = find(rank.begin(), rank.end(), X[i]);
                auto sec = find(rank.begin(), rank.end(), Y[i]);
                if (distance(rank.begin(), fir) > distance(rank.begin(), sec)) {
                    flag = false;
                    break;
                }
            }
            if (flag) res++;
        } while (next_permutation(rank.begin(), rank.end()));
        cout << res << "\n";
    }
    return 0;
}
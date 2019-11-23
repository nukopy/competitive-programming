// ABC109_C
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <tuple>  // std::tuple std::get
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>  // std::copy()
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

template <typename T>
T gcd(T a, T b) {
    if (a <= 0 || b <= 0) {
        // どちらかが 0 以下であれば -1 を返す
        return -1;
    } else if (a == 1 || b == 1) {
        // どちらかが 1 であれば，最小公約数は 1
        return 1;
    } else {
        if (a < b) swap(a, b);
        if (a%b == 0) return b;
        return gcd(b, a%b);
    }
}

int main() {
    // input
    ll N, X;
    cin >> N >> X;
    vector<ll> vec(N);
    REP(i, N) cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    // calculation
    if (N == 1) {
        cout << abs(X - vec[0]) << "\n";
    } else {
        auto iter = lower_bound(vec.begin(), vec.end(), X);
        vec.insert(vec.begin()+IDX(vec, iter), X);
    
        vector<ll> diff(N);
        for (ll i = 0; i < N; ++i) {
            diff[i] = vec[i+1] - vec[i];
        }
        
        // diff の最大公約数をとる
        
        ll res = gcd(diff[1], diff[0]);
        for (ll i = 1; i < N; ++i) {
            res = gcd(diff[i], res);
        }
        
        cout << res << "\n";
    }
    
    return 0;
}

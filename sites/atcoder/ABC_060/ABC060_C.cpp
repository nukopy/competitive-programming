// ABC060_C
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
#define vl vector<ll>
#define pll pair<ll, ll>
#define F first
#define S second

int main() {
    // input
    ll N, T;
    cin >> N >> T;
    vl vec(N), diff(N-1);
    REP(i, N) cin >> vec[i];
    
    if (N == 1) {
        cout << T << "\n";
        return 0;
    }
    
    REP(i, N-1) diff[i] = vec[i+1] - vec[i];
    
    // calculation
    ll res = 0;
    for (ll i = 0; i < N-1; ++i) {
        if (diff[i] <= T) {
            res += diff[i];
        } else {
            // diff[i] > T
            res += T;
        }
    }
    res += T;
    
    cout << res << "\n";
    
    return 0;
}
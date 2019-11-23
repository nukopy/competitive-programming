// ABC099_C
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::prev(iter, n) n 個分デクリメントしたイテレータ
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
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

template<class T> inline bool chmin(T& a, T b) {
    // chmin: change minimum
    // a より b の方が小さかったら，a の値を b の値に置き換える．
    // 書き換えた場合，true を返す
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    
    // calculation
    // prepare [6, 36, ...], [9, 81, ...]
    vector<ll> vec = {1};  // [1]
    for (ll i = 6; i <= N; i *= 6) vec.push_back(i);
    for (ll i = 9; i <= N; i *= 9) vec.push_back(i);
    sort(vec.begin(), vec.end());
    
    // init dp table
    vector<ll> dp(N+1, INF);
    REP(i, vec.size()) dp[vec[i]] = 1;
    dp[0] = 0;
    
    ll basis = 1;
    for (ll i = 1; i <= N; ++i) {
        REP(j, vec.size()) {
            if (i - vec[j] > 0) chmin(dp[i], dp[i - vec[j]] + 1);
        }
    }
    
    cout << dp[N] << "\n";
    
    return 0;
}
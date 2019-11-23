// ABC123_B
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

template <typename T>
T getDigit(T num) {
    if (num == 0) return 1;
    
    ll digits = 0;
    while (num != 0) {
        digits++;
        num /= 10;
    }
    return digits;
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    vector<pair<ll, ll>> vec(5);
    REP(i, 5) {
        cin >> vec[i].S;
        vec[i].F = (vec[i].S%10 ? 10 - vec[i].S%10: 0);
    }
    sort(vec.begin(), vec.end(), greater<>());  // int big -> small
    
    // calculation
    ll res = vec[0].S;
    for (ll i = 1; i < 5; ++i) {
        res += vec[i].F + vec[i].S;
    }
    cout << res << "\n";
    
    return 0;
}
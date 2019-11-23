// ABC087_C
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
const ll INF = 1LL<<60;  // 10^18

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    vector< vector<ll> > vec(2, vector<ll>(N));
    REP(i, 2) {
        REP(j, N) cin >> vec[i][j];
    }
    
    // calculation
    ll res = -1, sum_up, sum_down;
    REP(i, N) {
        sum_up = accumulate(vec[0].begin(), next(vec[0].begin(), i+1), 0LL);
        sum_down = accumulate(next(vec[1].begin(), i), vec[1].end(), 0LL);
        res = max(res, sum_up+sum_down);
    }
    
    cout << res << "\n";
    
    return 0;
}
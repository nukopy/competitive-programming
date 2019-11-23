// ABC123_D
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

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> one(X), two(Y), three(Z);
    REP(i, X) cin >> one[i];
    REP(i, Y) cin >> two[i];
    REP(i, Z) cin >> three[i];
    
    vector<ll> ab;
    REP(i, X) {
        REP(j, Y) {
            ab.push_back(one[i]+two[j]);
        }
    }
    sort(ab.begin(), ab.end(), greater<>());  // int big -> small
    sort(three.begin(), three.end(), greater<>());  // int big -> small
    
    // calculation
    // 最後大きい順に出力
    REP(i, K) {
        cout << ab[i] + three[i] << "\n";
    }
    
    return 0;
}
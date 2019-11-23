// ABC016_C
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
    ll N, M, a_i, b_i;
    cin >> N >> M;
    
    // calculation
    vector<vector<ll>> dist(N, vector<ll>(N));
    REP(i, N) {
        REP(j, N) {
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    REP(i, M) {
        cin >> a_i >> b_i; --a_i, --b_i;
        dist[a_i][b_i] = 1;
        dist[b_i][a_i] = 1;
    }
    
    REP(i, N) {
        REP(j, N) {
            REP(k, N) {
                dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    
    REP(i, N) {
        ll res = 0;
        REP(j, N) {
            if (dist[i][j] == 2) res++;
        }
        cout << res << "\n";
    }
    
    return 0;
}
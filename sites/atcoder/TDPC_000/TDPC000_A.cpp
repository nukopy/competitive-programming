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

template <class T>
void print2DVec(vector<vector<T>> &vec) {
    size_t len = vec.size(), front = vec.front().size();
    REP(i, len) {
        REP(j, front) {
            if (j) cout << " ";
            cout << vec[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    vector<ll> q(N);
    REP(i, N) cin >> q[i];
    ll sum = SUM(q);
    
    // calculation
    // i 番目までで j を作れるか
    vector<vector<ll>> dp(N+1, vector<ll>(sum+1, 0));
    dp[0][0] = 1;
    
    // i 番目までで j を作れるか
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j <= sum; ++j) {
            // j は問題を解いて取れる点数の合計
            // j を作れるかを見ていく
            if (j - q[i] < 0) {
                // 作れない場合
                dp[i+1][j] = dp[i][j];
            } else {
                // 作ろうとする場合
                dp[i+1][j] = dp[i][j] || dp[i][j-q[i]];
            }
        }
        print2DVec(dp);
    }
    
    ll res = 0;
    REP(i, sum+1) res += dp[N][i];
    
    cout << res << "\n";
    
    return 0;
}
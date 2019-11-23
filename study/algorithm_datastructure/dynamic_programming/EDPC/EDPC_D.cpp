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

template<class T> inline bool chmax(T& a, T b) {
    // chmax: change maximum
    // a より b の方が大きかったら，a の値を b の値に置き換える．
    // 書き換えた場合，true を返す
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

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
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    REP(i, N) cin >> w[i] >> v[i];
    
    // calculation
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    
    for (ll i = 0; i < N; ++i) {
        for (ll sum_w = 0; sum_w <= W; ++sum_w) {
            // dp[i][sum_w]: 品物 i までで，sum_w のリュックを使った時の最大容量
            // 品物 i を選ぶ時
            if (sum_w - w[i] >= 0) chmax(dp[i+1][sum_w], dp[i][sum_w - w[i]] + v[i]);
            
            // 品物 i を選ばない時
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
        print2DVec(dp);
    }
    
    cout << dp[N][W] << "\n";
    
    return 0;
}
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
#include <cstring>  // std::memset 初期化
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

ll N, W;

// 1. N <= 30
ll v[210], w[210];
ll max_v = 0, max_w = 0;

// 2. N <= 200 && max_w <= 1000
// i 番目までの価値の総和の最大値を返す
ll memo[210][200010];
ll dfs2(ll i, ll j) {
    // メモされていたら返す
    if (memo[i][j] >= 0) {
        return  memo[i][j];
    }
    
    // i 番目の荷物を使い，重量が j を超えないようにリュックに荷物を詰める
    ll value = 0;
    if (i == N) {
        value = 0;
    } else if (j - w[i] < 0) {
        // i 番目の荷物を入れられない
        value = dfs2(i+1, j);
    } else {
        // i 番目の荷物を入れることができる
        value = max(dfs2(i+1, j), dfs2(i+1, j-w[i]) + v[i]);
    }
    
    // メモしながら返す
    return memo[i][j] = value;
}

// 3. N <= 200 && max_v <= 1000

int main() {
    // input(sunippets: inpv, inpn, inps)
    cin >> N >> W;
    REP(i, N) {
        cin >> v[i] >> w[i];
        max_v = max(max_v, v[i]);
        max_w = max(max_w, w[i]);
    }
    
    // calculation
    ll val = 0;  // 達成できる最大の合計価値
    if (N <= 30) {
        // v, w に制限なし：DPは困難
        // v, w それぞれの総和: 0 <= sum_v, sum_w <= 30 * 10^9
        
    } else if (N <= 200 && max_w <= 1000) {
        // 一般的なナップサック DP でイケる
        memset(memo, -1, sizeof(memo));
        val = dfs2(0, W);
    } else if (N <= 200 && max_v <= 1000) {
        
    }
    
    cout << val << "\n";
    
    return 0;
}
// ABC032_D
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

ll v[210], w[210];
ll N, W;
ll value = 0;

// 1. dfs による全探索解：(部分点解法)
// i 番目を使うか使わないか: O(2^N)
ll dfs1(ll v_i, ll w_i, ll idx) {
    // 停止条件
    if (idx == N) {
        // 価値の更新
        if (w_i <= W) {
            value = max(value, v_i);
        }
        return 0;
    }
    
    // 荷物 v[i] を使う or 使わない
    dfs1(v_i + v[idx], w_i + w[idx], idx+1);
    dfs1(v_i, w_i, idx+1);
}

// 2. i 番目以降の品物から重さの総和が j 以下となる様に選ぶ
ll dfs2(ll i, ll j) {
    ll value = 0;
    if (i == N) {
        // 停止条件
        value = 0;
    } else if (j - w[i] < 0) {
        // i 番目の荷物が入らない場合
        value = dfs2(i+1, j);
        // dfs1 と比べてここの部分で枝刈りしている
        // dfs1 は容量が超えたものでも分岐を増やしている
    } else {
        // i 番目の荷物が入れられる場合（入れる場合と入れない場合に分ける）
        value = max(dfs2(i+1, j), dfs2(i+1, j-w[i]) + v[i]);
    }
    
    return value;
}


int TLE_dfs_knapsack() {
    // 部分点解法
    cin >> N >> W;
    REP(i, N) cin >> v[i] >> w[i];
    
    // calculation
    // 解法 1: 使うか使わないか（容量を気にせず，最後の総重量，総価値が算出されたら判定するアルゴリズム）
    // dfs1(0, 0, 0);
    
    // 解法 2: 使うか使わないかだけどちょっと違う
    value = dfs2(0, W);
    cout << value << "\n";
    
    return 0;
}

// 愚直解：dfs


// 部分点解法：ナップサック DP
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

ll dp[210][1000000100];
// dp[200][200];
int bubun1_knapsack_DP() {
    // input
    cin >> N >> W;
    REP(i, N) cin >> v[i] >> w[i];
    // REP(i, 1000000100) dp[0][i] = 0;
    
    // calculation
    for (ll i = 0; i < N; ++i) {
        // i 番目の荷物を運ぶか運ばないか
        for (ll w_i = 0; w_i <= W; ++w_i) {
            // w_i の容量のリュック
            // i 番目の荷物を（持てたら）持つ
            if (w_i - w[i] >= 0) chmax(dp[i+1][w_i], dp[i][w_i - w[i]] + v[i]);
            
            // i 番目の荷物を持たない
            chmax(dp[i+1][w_i], dp[i][w_i]);
        }
    }
    
    cout << dp[N][W] << "\n";
    
    return 0;
}

int main() {
    // 部分点解法: DFS による愚直な全探索
    TLE_dfs_knapsack();
    
    // 部分点解法: DP
    // bubun1_knapsack_DP();
    
    return 0;
}
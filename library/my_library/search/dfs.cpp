#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll N, A, B, C, D, E;

// 一度使ったものを使わないようにする dfs（フラグで管理）
void dfs(bool flag_A, bool flag_B, bool flag_C, bool flag_D, bool flag_E, ll res, ll depth) {
    // stop
    if (depth == N) 1;
    
    if (!flag_A) dfs(true, flag_B, flag_C, flag_D, flag_E, res+A, depth+1);
    if (!flag_B) dfs(flag_A, true, flag_C, flag_D, flag_E, res+B, depth+1);
    if (!flag_C) dfs(flag_A, flag_B, true, flag_D, flag_E, res+C, depth+1);
    if (!flag_D) dfs(flag_A, flag_B, flag_C, true, flag_E, res+D, depth+1);
    if (!flag_E) dfs(flag_A, flag_B, flag_C, flag_D, true, res+E, depth+1);
}

// 配列の要素を端から使っていく dfs
// 下記は分岐が A/B/C/使わない の 4 通りに分かれている
vector<ll> vec(N);
ll dfs2(ll i, ll a, ll b, ll c, ll cost) {
    // 終端処理
    if (i == N) {
        // 一つでも 0 があったらMAXを出力．
        if (!a || !b || !c) return LLONG_MAX;
        else return abs(a - A) + abs(b - B) + abs(c - C) + cost;
    }
    
    // 現在の竹 vec[i] を使用しない場合
    // 竹を合成しないままインデックスを進める．当然合成コストは 0．
    ll ret0 = dfs2(i+1, a, b, c, cost);
    
    // vec[i] を A, B, C どれに使うか割り当てる
    // 0 のときは合成コストは 0 を表す
    // それぞれの分岐で min が帰ってくる
    ll ret1 = dfs2(i + 1, a + vec[i], b, c, cost + ((a == 0) ? 0 : 10));
    ll ret2 = dfs2(i + 1, a, b + vec[i], c, cost + ((b == 0) ? 0 : 10));
    ll ret3 = dfs2(i + 1, a, b, c + vec[i], cost + ((c == 0) ? 0 : 10));
    
    return min({ret0, ret1, ret2, ret3});
}
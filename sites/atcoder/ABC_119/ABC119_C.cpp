#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

ll N, num, A, B, C, res = LLONG_MAX;
vector<ll> vec;

#define REP(i, N) for(ll i = 0; i < N; ++i)

ll recursion(ll i, ll a, ll b, ll c, ll cost) {
    // 終端処理
    if (i == N) {
        // 一つでも 0 があったらMAXを出力．
        if (!a || !b || !c) return LLONG_MAX;
        else return abs(a - A) + abs(b - B) + abs(c - C) + cost;
    }
    
    // 現在の竹 vec[i] を使用しない場合
    // 竹を合成しないままインデックスを進める．当然合成コストは 0．
    ll ret0 = recursion(i+1, a, b, c, cost);
    
    // vec[i] を A, B, C どれに使うか割り当てる
    // 0 のときは合成コストは 0 を表す
    // それぞれの分岐で min が帰ってくる
    ll ret1 = recursion(i + 1, a + vec[i], b, c, cost + ((a == 0) ? 0 : 10));
    ll ret2 = recursion(i + 1, a, b + vec[i], c, cost + ((b == 0) ? 0 : 10));
    ll ret3 = recursion(i + 1, a, b, c + vec[i], cost + ((c == 0) ? 0 : 10));
    
    return min({ret0, ret1, ret2, ret3});
}

int ans_dfs() {
    // input
    cin >> N >> A >> B >> C;
    // REP(i, N) {
    //     cin >> num;
    //     vec.push_back(num);
    // }
    // 以下の受け取り方の方がスマート
    vec.resize(N);
    for(ll  i = 0; i < N; i++) cin >> vec[i];
    
    // calculation
    cout << recursion(0, 0, 0, 0, 0) << "\n";
    
    return 0;
}

int ans_bit_all_search() {
    
    return 0;
}

int main() {
    // ans_dfs();
    ans_bit_all_search();
    return 0;
}
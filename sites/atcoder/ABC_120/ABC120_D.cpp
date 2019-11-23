#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

#define REP(i, N) for (ll i = 0; i < N; ++i)
#define pll pair<ll, ll>
#define F first
#define S second

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        siz.assign(sz_, 1LL);  // assign: 再代入
        par.resize(sz_);  // resize: 再確保
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main() {
    // input
    ll N, M;
    ll node1, node2;
    cin >> N >> M;
    vector<pll> A(M);
    for (ll i = 0; i < M; i++) {
        cin >> node1 >> node2; --node1, --node2;
        A[i].F = node1;
        A[i].S = node2;
    }
    
    // calculation
    vector<ll> ans(M);
    ans[M-1] = (N*(N-1))/2;  // 全ての頂点が孤立している状態
    
    UnionFind uf(N);
    for (ll i = M-1; i >= 1; --i) {
        node1 = A[i].F, node2 = A[i].S;
        if (uf.issame(node1, node2)) {
            ans[i-1] = ans[i];
        } else {
            // 根が異なるとき，それぞれのサイズの積（頂点の組み合わせ）を引く．
            ans[i-1] = ans[i] - (uf.size(node1) * uf.size(node2));
            uf.merge(node1, node2);
        }
    }
    
    REP(i, M) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
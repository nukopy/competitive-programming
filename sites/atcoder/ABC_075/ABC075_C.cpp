// ABC075_C
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>  // std::swap()
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
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
        par.resize(sz_);
        siz.assign(sz_, 1LL);
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
    // input(sunippets: inpv, inpn, inps)
    ll N, M, a, b;
    cin >> N >> M;
    vector<pll> vec(M);
    REP(i, M) {
        cin >> a >> b; --a, --b;
        vec[i].F = a;
        vec[i].S = b;
    }
    
    // calculation
    UnionFind uf(N);
    ll res = 0;
    REP(i, M) {
        uf.init(N);
        REP(j, M) {
            if (j == i) continue;
            uf.merge(vec[j].F, vec[j].S);
        }
        if (uf.size(0) < N) res++;
    }
    
    cout << res << "\n";
    
    return 0;
}
// VABC049_D
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define pll pair<ll, ll>

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.resize(sz_, 1);
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

template <class T>
void printVec(vector <T> &vec) {
    size_t len = vec.size();
    REP(i, len) {
        if (i) cout << " ";
        cout << vec[i];
    }
    cout << "\n";
}

int abc049_d() {
    // input(sunippets: inpv, inpn, inps)
    ll N, K, L, p, q;
    cin >> N >> K >> L;
    vector<ll> res(N, 1);
    UnionFind Road(N), Rail(N);
    REP(i, K) {
        cin >> p >> q; --p; --q;
        Road.merge(p, q);
    }
    
    REP(i, L) {
        cin >> p >> q; --p; --q;
        Rail.merge(p, q);
    }
    
    // 道路でも電車でも連結してる
    // 根が同じ
    map<pll, ll> mp;
    REP(i, N) mp[{Road.root(i), Rail.root(i)}]++;
    REP(i, N) cout << mp[{Road.root(i), Rail.root(i)}] << " ";
    cout << endl;
    
    return 0;
}

template <typename T>
T gcd(T a, T b) {
    if (a <= 0 || b <= 0) {
        // どちらかが 0 以下であれば -1 を返す
        return -1;
    } else if (a == 1 || b == 1) {
        // どちらかが 1 であれば，最小公約数は 1
        return 1;
    } else {
        if (a < b) swap(a, b);
        if (a%b == 0) return b;
        return gcd(b, a%b);
    }
}

int ddcc2016_C() {
    ll N, K;
    cin >> N >> K;
    vector<ll> vec(N);
    REP(i, N) cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    if (N == 1) {
        cout << 0 << "\n";
    } else if (N == 2) {
        if ((vec[0]*vec[1])%K == 0) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else {
        // カードが 3 枚以上
        ll res = 0;
        vector<ll> need(N);
        set<ll> need_set;
        REP(i, N) {
            need[i] = K/gcd(vec[i], K);
            need_set.insert(need[i]);
        }
        
        map<ll, ll> cnt;
        REP(i, N) {
            for (auto iter = need_set.begin(); iter != need_set.end(); iter++) {
                if (vec[i]%(*iter) == 0) ++cnt[(*iter)];
            }
        }
        
        REP(i, N) {
            res += cnt[need[i]]/2;
        }
        
        cout << res << "\n";
    }
    return 0;
}

int main() {
    // abc049_d();
    ddcc2016_C();
    return 0;
}
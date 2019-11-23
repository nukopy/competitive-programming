// AGC039_B
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

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pll;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値
#define F first
#define S second
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

// 0-indexed
class UnionFind {
public:
    vector<ll> par; // 各元の親を表す配列
    vector<ll> siz; // 素集合のサイズを表す配列(1 で初期化)

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
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    set<pll> edges;
    ll s_i, e, d;
    
    REP(i, N) {
        REP(j, N) {
            cin >> s_i;
            e = i+1;
            d = j+1;
            if (s_i) {
                if (e > d) swap(e, d);
                edges.insert(make_pair(e, d));
            }
        }
    }
    
    // calculation
    UnionFind uf(210);
    vector<vector<ll>> vec(N+1, vector<ll>(N+1));
    auto begin = edges.begin(), end = edges.end();
    for (auto iter = begin; iter != end; iter++) {
        // *iter = set's element
        pll edg = *iter;
        if (!uf.issame(edg.F, edg.S)) {
            uf.merge(edg.F, edg.S);
            vec[edg.F][edg.S] = 1;
            vec[edg.S][edg.F] = 1;
            
        } else {
            if () {
                vec[edg.F][edg.S] = 1;
                vec[edg.S][edg.F] = 1;
            } else {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    
    cout << uf.size(1) << "\n";
    
    return 0;
}
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
    // input(sunippets: inpv, inpn, inps)
    // bridges
    // 橋の順序は保持しなくて良い
    ll N, M;
    cin >> N >> M;
    
    ll city1, city2, brd_year;
    vector<pair<ll, pair<ll, ll>>> bridges(M);
    
    REP(i, M) {
        cin >> city1 >> city2 >> brd_year;
        bridges[i] = make_pair(brd_year, make_pair(city1, city2));
    }
    sort(bridges.begin(), bridges.end());  // year で降順ソート，重みが大きい橋からつなぐため
    reverse(bridges.begin(), bridges.end());
    
    // queries
    // クエリの順序は保持する必要がある．
    ll Q;
    cin >> Q;
    
    ll city, year;
    vector<tuple<ll, ll, ll>> queries(Q);
    
    REP(i, Q) {
        cin >> city >> year;
        queries[i] = make_tuple(year, i, city);  // このようにインデックスを持つことでソート時にクエリの順序が保存される
    }
    sort(queries.begin(), queries.end());
    reverse(queries.begin(), queries.end());
    
    // calculation
    UnionFind uf(N+10);
    vector<ll> res(Q, -1);
    ll idx_brd = 0;
    
    REP(i, Q) {
        tuple<ll, ll, ll> query = queries[i];
        ll idx_query = get<1>(query);
        ll city = get<2>(query);
        ll year = get<0>(query);
        
        // 重みが大きい橋から繋いでいく
        while (idx_brd < M && year < bridges[idx_brd].F) {
            pair<ll, ll> brd = bridges[idx_brd].S;
            // year 以前の橋を繋がない
            uf.merge(brd.F, brd.S);
            
            idx_brd++;
        }
        
        res[idx_query] = uf.size(city);  // 連結成分の数を格納
    }
    
    REP(i, Q) {
        cout << res[i] << "\n";
    }
    
    return 0;
}

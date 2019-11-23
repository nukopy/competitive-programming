# ABC040: D - 道路の老朽化対策について

[:contents]

## 問題

- [ABC040: D - 道路の老朽化対策について](https://atcoder.jp/contests/abc040/tasks/abc040_d)

[img]

- 基礎用語
  - グラフ：ノードとエッジからなる構造．
  - 重み付きグラフ：エッジについて特定の値が付いているグラフ．
  - 連結成分：無向グラフにおいて「ある頂点から辺を辿って行き来できるような頂点の集合」．

## 考察

ぱっと見 Union-Find で解けそうと思った．しかし，どうしても計算量を [tex: O(Q \times M] から落とせるような解法が思い浮かばず，部分点しか得られなかった．

部分点を得た解法は，クエリごとに，特定の年数 [tex: w_i] より大きい橋を Union Find で連結し，最後にノード [tex: v_i] のサイズを取得する，という解法だった．

## 解法

- [Official Editorial](http://abc040.contest.atcoder.jp/data/abc/040/editorial.pdf)

### 問題をグラフの言葉で落とし込む

自分の部分点の解法では，作られた年数を別に持ち，無向グラフとして年を扱うものであった．しかし解法は，作られた年数をエッジの重みとして扱う重み付き無向グラフを利用してクエリを処理するものだった．問題はグラフの言葉を使って以下のように言い換えられる．

**N 個の頂点と M 本の辺からなる重みつき無向グラフが与えられる．Q 個の質問に答えよ．それぞれの質問は『重みが w より大きい辺だけを考えたとき，頂点 v が属する連結成分の大きさは？』である．**

以上のような問題に落とし込める．このように問題をグラフなどの言葉を使って言い換えることにより，問題をグラフに関するさまざまなアルゴリズムや過去に解いたことのある問題などと結びつけるのに役立つ．

### 解法

考察の部分で書いた解法は，クエリごとに毎回 Union-Find を構築しエッジの重み（橋の作られた年数）を走査するものだったため，計算量が [tex: O(M \times Q)] 程度になり TLE となってしまう．

ここで考えるべきは Union-Find の性質である．Union-Find の重要な制約として「**連結成分をつなげることはできるが辺を壊すことはできない**」がある．これを考えた上で解法を考えればこの問題は解ける．

解法は以下．

---

辺の重みが大きい順に（Union-Find の）各ノードを繋いでいけば，Union-Find の構築は 1 回で済むし，クエリごとにエッジの重みを走査しなくてもよくなる．Union-Find での操作回数は全体で [tex: O(M + Q)] 回程度になり，TLE にならない．実装は，エッジとクエリを重みでソートして以上の処理をすればよい．

注意点は，クエリの順序を保持しておく必要があるということ．クエリの入力を `std::tuple` を要素とする `std::vector` で受け取るが，vector の各要素を `(年数, クエリ番号, 国民の在住都市番号)` で受け取ることにより，ソートしたときに年数が等しいクエリの順序を保持できる．クエリ番号（元のインデックス）を tuple に加えて置かないと，最終的な出力を行うときの順序がクエリの vector をソートしたときに失われてしまう．

実装

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
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
```

### 補足：Union-Find の性質

以下の記事で取り扱っているが，Union-Find のポイントについて簡単にまとめておく．

- （高速に）ノードを繋ぐことができる
- （高速に）ノード同士の連結判定ができる
- 連結成分をつなげることはできるが，その逆は出来ない．
- グラフを扱う際に，「辺を繋ぐ」処理は簡単だが，「辺を切り離す」処理は難しい．

4 つ目の「難しい」というのは，（辺を壊したあとに）グラフ上を遠くまで探索して連結かどうかを愚直に調べることができるのは DFS，BFS であり，入力の制約が大きい数になると連結を判定する計算量が膨大になり「連結判定が難しい」という意味である．**連結かどうかを判定するだけ**であれば，Union-Find が高速に判定できるため有効である．

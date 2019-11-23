#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

/* Union-Find
・つなぐ処理：簡単
・切り離す処理：難しい（遠くまで見ないと切り離されたことは分からない．）
・切り離す処理を見るときに，つなぐ処理にできる？
・クエリ先読み：橋が壊れるとかの文章が出てきたらとりあえず　UnionFind　でクエリ先読みって，考えとけば水色くらいまでは問題ない
*/

class UnionFind {
public:
    vector<ll> par;  // 各元の親を表す配列
    vector<ll> siz;  // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;  // 初期では親は自分自身
    }
    
    void init(ll sz_) {
        par.resize(sz_);
        siz.resize(sz_, 1);
        for (ll i = 0; i < sz_; ++i) par[i] = i;  // 初期では親は自分自身
    }
    
    // Member Function
    // Find
    ll root(ll x) {
        // root(Find, Path Having): ある要素の根（親）を検索する
        while (par[x] != x) {
            par[x] = par[par[x]];  // x の親の親を x の親にする
            x = par[x];  // 更新された x の親
            // 更新された x の親が，親自身であれば return
        }
        return x;
    }
    
    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        // merge: x, y の属する素集合を合併する
    // 各素集合の根（親）同士を合併
        x = root(x); y = root(y);
        if (x == y) {
            return false;
        } else {
            // merge technique（データ構造をマージするテク．）
            // サイズが小さい方の根を，大きい方につなぎ直す
            if (siz[x] < siz[y]) {
                swap(x, y);
            }
            siz[x] += siz[y];  // 併合後の素集合のサイズの更新（x の根の集合の大きさが更新される）
            par[y] = x;  // 小さい方の集合の根を大きい方の集合の根につなぎ替える
            return true;  // 合併できた
        }
    }
    
    // 連結判定
    bool issame(ll x, ll y) {
        // issame: 同じグループ（素集合）に属するかの判定
        // 連結であるかの判定（連結：頂点 A から頂点 B まで辺をたどって到達可能であること）
        return root(x) == root(y);
    }
    
    // union by size(or union by rank)
    ll size(ll x) {
        // size: x を含むグループ（素集合）の大きさを求める（連結成分のサイズの獲得）
        return siz[root(x)];
    }
};

void printUF(UnionFind &uf);
int test();
int ATC001_B();  // verified

int main() {
    // test();
    ATC001_B();
    return 0;
}

// functions
void printUF(UnionFind &uf) {
    for (ll i = 0; i < uf.par.size(); ++i) {
        if (i) cout << " ";
        cout << uf.par[i];
    }
    cout << endl;
}

int test() {
    UnionFind uf(5);
    
    // output
    cout << "start: "; printUF(uf); cout << endl;
    uf.merge(0, 1);
    cout << "merge(0, 1): "; printUF(uf);
    uf.merge(1, 2);
    cout << "merge(1, 2): "; printUF(uf);
    uf.merge(2, 3);
    cout << "merge(2, 3): "; printUF(uf);
    uf.merge(3, 4);
    cout << "merge(3, 4): "; printUF(uf);
    cout << "root(4) = " << uf.root(4) << endl;
    return 0;
}

// verified at 2019/03/07: ATC001_B - https://atc001.contest.atcoder.jp/tasks/unionfind_a
int ATC001_B() {
    ll N, Q, P, A, B;
    cin >> N >> Q;
    UnionFind uf(N);
    
    while(cin >> P >> A >> B) { // REP(i, Q){}
        if (P == 0) {
            // merge
            uf.merge(A, B);
        } else {
            // 連結判定
            if (uf.issame(A, B)) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
    
    return 0;
}

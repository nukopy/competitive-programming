// insert_sort
#include <iostream>
#include <vector>
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define REPN(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0LL)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007

template <class T>
void printVec(vector<T> vec) {
    size_t len = vec.size();
    REP(i, len) {
        if (i) cout << " ";
        cout << vec[i];
    }
    cout << "\n";
}

int ALDS1_1_A() {
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N), diff(N-1);
    REP(i, N) cin >> vec[i];
    
    // insert sort: 挿入ソートの過程を出力
    //BEGIN CUT
    for (int j = 0; j < N; ++j) {
        ll back = vec[j];
        ll k = j-1;
        while (k >= 0 && vec[k] > back) {
            // 後ろの方が小さかったら入れ替え
            vec[k+1] = vec[k];
            vec[k] = back;
            k--;
        }
        printVec(vec);
    }
    //BEGIN CUT
    return 0;
}

int main() {
    // ALDS1_1_A();
    for (int j = 0; j < N; ++j) {
        ll back = vec[j];
        ll k = j-1;
        while (k >= 0 && vec[k] > back) {
            // 後ろの方が小さかったら入れ替え
            vec[k+1] = vec[k];
            vec[k] = back;
            k--;
        }
        printVec(vec);
    }
    
    return 0;
}

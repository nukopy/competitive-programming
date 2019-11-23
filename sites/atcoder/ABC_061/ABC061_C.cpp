// ABC061_C
#include <iostream>
#include <vector>
#include <algorithm>  // std::copy()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり

int main() {
    // input
    ll N, K, a, b, sum = 0, maxN = 100000 + 1;
    cin >> N >> K;
    vector<ll> num(maxN, 0);
    REP(i, N) {
        cin >> a >> b;
        num[a] += b;
    }
    
    // 各数が何個あるかの累積和を計算
    for (ll i = 0; i < maxN; ++i) {
        sum += num[i];
        if (K <= sum) {
            cout << i << "\n";
            return 0;
        }
    }
    
    return 0;
}

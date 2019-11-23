// ABC077_C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))

int main() {
    // input
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    // calculation
    ll now_B, num_A, num_C, res = 0;
    ll idx_bound_A, idx_bound_C;
    
    for (ll i = 0; i < N; ++i) {
        now_B = B[i];
        num_A = 0;
        num_C = 0;
        
        // 1 段目: now_B 未満の数を求める
        auto iter_A = lower_bound(A.begin(), A.end(), now_B);
        idx_bound_A = distance(A.begin(), iter_A);
        num_A = (iter_A == A.end())? N: (idx_bound_A + 1) - 1;
        
        // 3 段目: now_B より大きい数
        auto iter_C = upper_bound(C.begin(), C.end(), now_B);
        idx_bound_C = distance(C.begin(), iter_C);
        num_C = (iter_C == C.end())? 0: N - idx_bound_C;
        
        res += num_A*num_C;
    }
    
    cout << res << "\n";
    
    return 0;
}

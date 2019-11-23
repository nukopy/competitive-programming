// ABC112_C
#include <iostream>
#include <vector>
#include <tuple>  // std::tuple std::get
#include <algorithm>
using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

int main() {
    // input
    ll N, idx = 0;
    cin >> N;
    vector<ll> X(N), Y(N), H(N);
    REP(i, N) {
        cin >> X[i] >> Y[i] >> H[i];
        if (H[i] > 0) idx = i;  // 制約上，必ず1組は h_i > 0 となっている
    }
    
    // 中心座標を全探索
    ll now_H, d_i, tmp_h_i, tmp_d_i;
    bool flag;
    
    for (ll Cx = 0; Cx <= 100; ++Cx) {
        for (ll Cy = 0; Cy <= 100; ++Cy) {
            d_i = abs(X[idx] - Cx) + abs(Y[idx] - Cy);
            now_H = H[idx] + d_i;
            
            // 中心座標を固定した時，それが入力に合うかを求める
            flag = true;
            
            for (ll i = 0; i < N; ++i) {
                tmp_d_i = abs(X[i] - Cx) + abs(Y[i] - Cy);
                tmp_h_i = max(now_H - tmp_d_i, 0LL);
                if (H[i] != tmp_h_i) {
                    flag = false;  // 矛盾したら false
                    break;
                }
            }
            
            if (flag) {
                cout << Cx << " " << Cy << " " << now_H << "\n";
                return 0;
            }
        }
    }
    
    return 0;
}

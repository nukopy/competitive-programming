#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // std::greater<T>()
#include <climits>  // INT_MIN
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define vl vector<ll>

template <typename T>
vector<T> BinarySearch(vector<T> &vec, T key) {
    if (vec.size() == 1) return vec;
    // key: 検索対象の値
    // T left = 0, right = (T)vec.size(), mid, idx_res;
    T left = 0, right = (T)vec.size()-1, mid, idx_res;  // ほんとうは番兵を N とおく
    while (left < right) {
        mid = (left + right)/2;
        if (right - left == 1) {
            vector<T> res = {vec[left], vec[right]};
            return res;
        } else if (key < vec[mid]) {
            // 半分より下
            right = mid;
        } else if (vec[mid] < key) {
            // 半分より上
            // left = mid+1;
            left = mid;  // これだと永遠に2つ以下に絞れない
        }
    }
    return {-1, -1};
}

int main() {
    // input
    ll A, B, Q;
    cin >> A >> B >> Q;
    vl Jin(A), Tera(B), Query(Q);
    REP(i, A) cin >> Jin[i];
    REP(i, B) cin >> Tera[i];
    REP(i, Q) cin >> Query[i];
    
    // calculation
    vector<ll> res_A, res_B;
    ll query, jin, ter, res;
    REP(i, Q) {
        query = Query[i];
        res_A = BinarySearch(Jin, query);  // size: 1 or 2
        res_B = BinarySearch(Tera, query);  // size: 1 or 2
        res = LLONG_MAX;
        REP(j, res_A.size()) {
            REP(k, res_B.size()) {
                jin = res_A[j];
                ter = res_B[k];
                if (query < jin && query < ter) {
                    // query が小さい
                    res = min(res, max(jin, ter) - query);
                } else if (query > jin && query > ter){
                    // query が大きい
                    res = min(res, query - min(jin, ter));
                } else {
                    // 間にあるとき
                    res = min(res, min(abs(query - jin), abs(query - ter)) + abs(jin - ter));
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
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

int main() {
    // input
    ll N, x, half;
    cin >> N;
    half = N/2;
    vector<ll> vec_A, vec_B, A(100010, 0), B(100010, 0);
    REP(i, N) {
        cin >> x;
        if (i%2 == 0) {
            vec_A.push_back(x);
            A[x]++;
        } else {
            vec_B.push_back(x);
            B[x]++;
        }
    }
    
    // calculation
    ll res_A = 0, a, res_B = 0, b;
    REP(i, 100010) {
        if (res_A < A[i]) {
            res_A = A[i];
            a = i;
        }
        if (res_B < B[i]) {
            res_B = B[i];
            b = i;
        }
    }
    
    ll sec_A = 0, sA, sec_B = 0, sB;
    REP(i, 100010) {
        if (i != a) {
            if (sec_A < A[i]) {
                sec_A = A[i];
            }
        }
    }
    
    REP(i, 100010) {
        if (i != b) {
            if (sec_B < B[i]) {
                sec_B = B[i];
            }
        }
    }
    
    if (a == b) {
        ll res = min((half-res_A)+(half-sec_B), (half-sec_A)+(half-res_B));
        cout << res << "\n";
    } else {
        cout << (half - res_A) + (half - res_B) << "\n";
    }
    
    return 0;
}
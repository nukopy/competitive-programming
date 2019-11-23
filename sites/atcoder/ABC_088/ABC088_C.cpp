// ABC088_C
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <tuple>  // std::tuple std::get
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>  // std::copy()
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

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define REPN(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0LL)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
#define zero_pad(num) setfill('0') << std::right << setw(num)
#define space_pad(num) setfill(' ') << std::right << setw(num)

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    vector< vector<ll> > vec((size_t)3, vector<ll>((size_t)3));
    REP(i, 3) {
        // N 行
        REP(j, 3) {
            // M 列：入力が逆になることもあるので注意
            cin >> vec[i][j];
        }
    }
    
    // calculation
    vector<ll> A(3), B(3);
    B[0] = 0;
    REP(i, 3) A[i] = vec[0][i] - B[0];
    REP(i, 3) B[i] = vec[i][0] - A[0];
    
    REP(i, 3) {
        REP(j, 3) {
            if ((A[j] + B[i]) != vec[i][j]) {
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    
    cout << "Yes" << "\n";
    
    return 0;
}

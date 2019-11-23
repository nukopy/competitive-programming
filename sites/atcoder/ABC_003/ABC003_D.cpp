// ABC003_D
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
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007

// CUT HERE BEGIN
template <typename T>
T factorial(T num) {
    if (num == 0 || num == 1) {
        // 0! = 1, 1! = 1;
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}
template <typename T>
T nCr(T n, T r) {
    return factorial(n)/(factorial(r)*factorial(n-r));
}
// CUT HERE END

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll row, col, after_row, after_col, desk, luck;
    cin >> row >> col;
    cin >> after_row >> after_col;
    cin >> desk >> luck;
    
    // calculation
    if (desk + luck == after_row * after_col) {
        ll field = (row - after_row + 1) * (col - after_col + 1);
        ll place = after_row * after_col;  // 置ける場所の総数
        ll min_d_l = min(desk, luck);  // 少ない方を置いてしまえば多い方は定まる
        
        cout << nCr(place, min_d_l) * field << "\n";
    } else {
        cout << "" << "\n";
    }
    
    return 0;
}

// ABC055_C
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::prev(iter, n) n 個分デクリメントしたイテレータ
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
#define pll pair<ll, ll>
#define F first
#define S second
const ll INF = 1LL<<60;  // 10^18

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll S_num, c_num;
    cin >> S_num >> c_num;
    
    // calculation
    if (S_num >= c_num) {
        // ex) S:c = 4:2
        // 小さい方に合わせる
        cout << c_num/2 << "\n";
    } else {
        // S_num < c_num
        // ex) S:c = 10:11, 1:10
        if (S_num*2 <= c_num) {
            // 2 倍以上
            ll res = S_num;
            c_num -= 2*S_num;  // 残り
            if (c_num <= 3) {
                cout << res << "\n";
            } else if (c_num == 4) {
                // 4 だとちょうど 1 セット作れる
                cout << res+1 << "\n";
            } else {
                cout << res + c_num/4 << "\n";
            }
        } else {
            // 2 倍未満
            cout << c_num/2 << "\n";
        }
    }
    
    return 0;
}
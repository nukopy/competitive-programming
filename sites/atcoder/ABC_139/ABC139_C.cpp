// ABC139_C
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
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, M;
    cin >> N >> M;
    
    // calculation
    if (M == 1) {
        cout << 0 << "\n";
    } else {
        // M が 2 以上
        if (N >= M) {
            cout << 1 << "\n";
        } else {
            // N < M
            ll res = 1;
            M -= N;
            if (N > M) {
                res++;
                cout << res << "\n";
            } else {
                ll n = N-1;
                res += (M + n - 1)/n;
                cout << res << "\n";
            }
        }
    }
    
    return 0;
}
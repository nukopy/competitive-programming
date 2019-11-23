// VABC049_C
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
// #define S second
const ll INF = 1LL<<60;  // 10^18

int main() {
    // input(sunippets: inpv, inpn, inps)
    string S;
    cin >> S;
    
    // calculation
    reverse(S.begin(), S.end());
    ll idx = 0; string sub5, sub6, sub7;
    while (idx != S.length()) {
        sub5 = S.substr(idx, 5);
        sub6 = S.substr(idx, 6);
        sub7 = S.substr(idx, 7);
        if (sub5 == "maerd" || sub5 == "esare") {
            idx += 5;
        } else if (sub6 == "resare") {
            idx += 6;
        } else if (sub7 == "remaerd") {
            idx += 7;
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    }
    
    if (idx == (ll)S.length()) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
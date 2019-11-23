// ABC038_C
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
    ll N;
    cin >> N;
    vector<ll> vec(N), diff(N-1);
    REP(i, N) {
        cin >> vec[i];
    }
    
    for (ll i = 0; i < N-1; ++i) {
        diff[i] = (vec[i+1] - vec[i] > 0 ? 1: 0);
    }
    
    // calculation
    if (N == 1) {
        cout << 1 << "\n";
    } else if (N == 2) {
        cout << 2 + (vec[1] -vec[0] > 0 ? 1: 0) << "\n";
    } else {
        ll res = N, sum = 0;
        for (ll i = 0; i < N-1; ++i) {
            if (diff[i] > 0) {
                sum += diff[i];
                res += sum;
            } else {
                sum = 0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
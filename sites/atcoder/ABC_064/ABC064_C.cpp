// ABC064_C
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
#define pll pair<ll, ll>
#define F first
#define S second

int main() {
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N), num(9, 0);
    REP(i, N) cin >> vec[i];
    
    // calculation
    REP(i, N) {
        if (vec[i] <= 399) {
            num[0]++;
        } else if (400 <= vec[i] && vec[i] <= 799) {
            num[1]++;
        }  else if (800 <= vec[i] && vec[i] <= 1199) {
            num[2]++;
        }  else if (1200 <= vec[i] && vec[i] <= 1599) {
            num[3]++;
        }  else if (1600 <= vec[i] && vec[i] <= 1999) {
            num[4]++;
        }  else if (2000 <= vec[i] && vec[i] <= 2399) {
            num[5]++;
        }  else if (2400 <= vec[i] && vec[i] <= 2799) {
            num[6]++;
        } else if (2800 <= vec[i] && vec[i] <= 3199) {
            num[7]++;
        } else {
            num[8]++;
        }
    }
    
    ll res = 0;
    REP(i, 8) {
        if (num[i] != 0) res++;
    }
    
    if (res == 0) {
        // 赤より大きい人しかいない
        cout << 1 << " " << num[8] << "\n";
    } else {
        cout << res << " " << res + num[8] << "\n";
    }
    
    return 0;
}
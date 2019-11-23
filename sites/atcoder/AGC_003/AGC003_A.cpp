// AGC003_A
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
#define zero_pad(num) setfill('0') << std::right << setw(num)
#define space_pad(num) setfill(' ') << std::right << setw(num)

typedef long long ll;

const ll MOD7 = 1000000007;  // 1 000 000 007
const ll MOD9 = 1000000009;  // 1 000 000 009

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    string str;
    cin >> str;
    
    // calculation
    // 縦，横
    ll north = 0, south = 0, west = 0, east = 0;
    REP(i, str.length()) {
        if (str[i] == 'N') north++;
        else if (str[i] == 'S') south++;
        else if (str[i] == 'W') west++;
        else east++;
    }
    
    if ((north == 0 && south != 0) || (north != 0 && south == 0) || (west == 0 && east != 0) || (west != 0 && east == 0)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
    return 0;
}

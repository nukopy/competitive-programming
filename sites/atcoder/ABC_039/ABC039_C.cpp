// ABC039_C
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
    string S;
    cin >> S;
    
    // calculation
    // WBWBWWBWBWBWBW
    string piano = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    ll idx = piano.find(S);
    string res;
    switch (idx) {
        case 0:
            res = "Do";
            break;
        case 2:
            res = "Re";
            break;
        case 4:
            res = "Mi";
            break;
        case 5:
            res = "Fa";
            break;
        case 7:
            res = "So";
            break;
        case 9:
            res = "La";
            break;
        case 11:
            res = "Si";
            break;
        case 13:
            res = "Do";
            break;
        default:
            break;
    }
    
    cout << res << "\n";
    
    return 0;
}
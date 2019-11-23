// ABC108_C
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
    ll x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    
    ll diff_y = y_2 - y_1, diff_x = x_2 - x_1;
    
    ll x_3 = x_2 - diff_y, y_3 = y_2 + diff_x;
    ll x_4 = x_1 - diff_y, y_4 = y_1 + diff_x;  
    
    cout << x_3 << " " << y_3 << " " << x_4 << " " << y_4 << "\n";
    
    return 0;
}

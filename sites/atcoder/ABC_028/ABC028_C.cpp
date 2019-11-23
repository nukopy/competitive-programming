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

ll A, B, C, D, E;
set<ll> st;
void dfs(bool flag_A, bool flag_B, bool flag_C, bool flag_D, bool flag_E, ll res, ll depth) {
    // stop
    if (depth == 3) st.insert(res);
    
    if (!flag_A) dfs(true, flag_B, flag_C, flag_D, flag_E, res+A, depth+1);
    if (!flag_B) dfs(flag_A, true, flag_C, flag_D, flag_E, res+B, depth+1);
    if (!flag_C) dfs(flag_A, flag_B, true, flag_D, flag_E, res+C, depth+1);
    if (!flag_D) dfs(flag_A, flag_B, flag_C, true, flag_E, res+D, depth+1);
    if (!flag_E) dfs(flag_A, flag_B, flag_C, flag_D, true, res+E, depth+1);
}

int main() {
    // input
    cin >> A >> B >> C >> D >> E;
    
    // calculation
    dfs(false, false, false, false, false, 0, 0);
    auto max_it = MAX(st);
    max_it--; max_it--;
    cout << *max_it << "\n";
    
    return 0;
}
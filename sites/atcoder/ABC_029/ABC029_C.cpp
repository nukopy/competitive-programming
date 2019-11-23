// ABC029_C
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <tuple>  // std::tuple std::get
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
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
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値

vector< vector<string>> vec(3);
ll N, a = 0, b = 1, c = 2;

void dfs(string str, ll idx) {
    if (str.length() == N) {
        vec[idx].push_back(str);
    } else {
        dfs(str + "a", idx);
        dfs(str + "b", idx);
        dfs(str + "c", idx);
    }
}

int main() {
    // input
    cin >> N;
    
    // calculation
    dfs("a", a);
    dfs("b", b);
    dfs("c", c);
    
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << "\n";
        }
    }
    
    return 0;
}

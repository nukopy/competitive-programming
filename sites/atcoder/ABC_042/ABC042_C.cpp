// ABC042_C
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

ll N, K, num;
vector<ll> vec(10, 0), ok, res;

void dfs(string str) {
    if (N <= stoll(str)) {
        res.push_back(stoll(str));
    } else {
        REP(i, ok.size()) {
            dfs(str + to_string(ok[i]));
        }
    }
}

int main() {
    // input
    cin >> N >> K;
    REP(i, K) {
        cin >> num;
        vec[num]++;
    }
    
    // 大丈夫な数字
    REP(i, 10) {
        if (vec[i] == 0) ok.push_back(i);
    }
    
    // calculation
    REP(i, ok.size()) {
        if (ok[i] == 0) continue;
        dfs(to_string(ok[i]));
    }
    
    cout << *MIN(res) << "\n";
    
    return 0;
}

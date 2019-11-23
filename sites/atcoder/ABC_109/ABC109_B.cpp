// ABC109_B
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

int main() {
    // input
    ll N;
    cin >> N;
    vector<string> vec(N);
    set<string> set_s;
    REP(i, N) cin >> vec[i];
    REP(i, N) set_s.insert(vec[i]);
    
    // calculation
    if (set_s.size() != N) {
        cout << "No" << "\n";
    } else {
        string start = vec[0], now;
        bool flag = true;
        
        for (ll i = 1; i < N; ++i) {
            now = vec[i];
            if (start.back() == now.front()) {
                start = now;
            } else {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}

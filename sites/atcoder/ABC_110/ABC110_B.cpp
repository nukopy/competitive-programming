// ABC110_B
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
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<ll> vec_X(N), vec_Y(M);
    REP(i, N) cin >> vec_X[i];
    REP(i, M) cin >> vec_Y[i];
    vec_X.push_back(X);
    vec_Y.push_back(Y);
    
    
    // calculation
    ll max_X = *MAX(vec_X);
    ll min_Y = *MIN(vec_Y);
    if (max_X < min_Y) {
        cout << "No War" << "\n";
    } else {
        cout << "War" << "\n";
    }
    return 0;
}

// div2542_B
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
    vector<ll> vec(2*N);
    REP(i, 2*N) cin >> vec[i];
    
    // calculation
    
    if (N == 1) {
        cout << 0 + 1 << "\n";
    } else {
        // get minimum
        vector< vector<ll> > idxs(N+1);
        REP(i, 2*N) {
            idxs[vec[i]].push_back(i);
        }
    
        // start point
        ll res = 0;
        ll Sasha = idxs[1][0]; res += Sasha;
        ll Dima = idxs[1][1]; res += Dima;
        for (ll i = 2; i < N+1; ++i) {
            res += min(abs(Sasha - idxs[i][0]) + abs(Dima - idxs[i][1]), abs(Sasha - idxs[i][1]) + abs(Dima - idxs[i][0]));
            Sasha = idxs[i][0], idxs[i][1];
        }
        
        cout << res << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::prev(iter, n) n 個分デクリメントしたイテレータ
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
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    vector<ll> stairs;
    while (cin >> N) {
        if (N) stairs.push_back(N);
        else break;
    }
    
    // calculation
    REP(i, stairs.size()) {
        ll num_stair = stairs[i];
        
        // dp table
        vector<ll> dp(num_stair+1, 0);
        
        // dp table init
        dp[num_stair] = 1;
        if (num_stair >= 2) dp[num_stair-1] = 1;
        if (num_stair >= 3) dp[num_stair-2] = 2;
        
        for (ll j = num_stair-3; j >= 0; --j) {
            dp[j] = dp[j+1] + dp[j+2] + dp[j+3];
        }
        
        cout << (365 + (dp[0]/10))/365 << "\n";
    }
    
    
    
    return 0;
}
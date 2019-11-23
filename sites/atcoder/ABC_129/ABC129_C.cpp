// ABC129_C
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
const ll MOD7 = 1000000007; // 1 000 000 007

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, M;
    cin >> N >> M;
    vector<ll> holes(M), broken(N+1, 1);
    
    REP(i, M) {
        cin >> holes[i];
        broken[holes[i]] = 0;
        
        if (i > 0) {
            if (holes[i] - holes[i-1] == 1) {
                cout << 0 << "\n";
                return 0;
            }
        }
    }
    
    // calculation
    // dp table init
    vector<ll> dp(N+1, 0);
    dp[N] = 1;
    if (broken[N-1]) dp[N-1] = 1;
    
    // calc
    for (ll i = N-2; i >= 0; --i) {
        if (broken[i]) {
            dp[i] = dp[i+1] + dp[i+2];
            dp[i] %= MOD7;
        }
    }
    
    cout << dp[0] << "\n";
    
    return 0;
}
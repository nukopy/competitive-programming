// ABC143_D
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
#include <cstring>  // std::memset 初期化
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
#include <iomanip>  // std::setprecision()
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pll;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値
#define F first
#define S second
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    vector<ll> vec(N);
    REP(i, N) cin >> vec[i];
    
    // calculation
    sort(vec.begin(), vec.end());
    
    ll sum = 0, idx;
    for (ll i = 0; i < N-2; ++i) {
        for (ll j = i+1; j < N-1; ++j) {
            ll two = vec[i] + vec[j];
            auto iter = lower_bound(vec.begin()+j+1, vec.end(), two);
            if (iter == vec.end()) sum += N - j -1;
            else {
                ll idx = distance(vec.begin(), iter);
                sum += (idx-1) - j;
            }
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}
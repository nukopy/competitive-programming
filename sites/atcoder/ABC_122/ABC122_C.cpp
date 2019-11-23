// ABC122_C
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
    ll N, Q, l, r;
    cin >> N >> Q;
    string S;
    cin >> S;
    
    // calculation
    // if (N == 2) {
        
    // } else {
        vector<ll> num(N, 0);
        REP(i, N-1) {
            if (S[i] == 'A' && S[i+1] == 'C') {
                num[i] = 1;
                num[i+1] = 1;
            }
        }
        vector<ll> partial = num; // copy vec
        partial_sum(num.begin(), num.end(), partial.begin());
        partial.insert(partial.begin(), 0);
        
        ll tmp;
        REP(i, Q) {
            cin >> l >> r;
            tmp = partial[r] - partial[l-1];
            if (tmp >= 2) {
                if (S[l-1] == 'C' && num[l-1] == 1) --tmp;
                if (S[r-1] == 'A' && num[r-1] == 1) --tmp;
            }
            tmp /= 2;
            
            cout << tmp << "\n";
        }
    // }
    
    return 0;
}
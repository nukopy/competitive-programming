// ABC154_E
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
#include <cstring>  // std::memset
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
#include <iomanip>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define rep1(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define repr(i, n) for (ll i=n-1; i >= 0; i++)  // n-1 ~ 0
#define all(vec) (vec).begin(), (vec).end()
#define sum(vec) accumulate(all(vec), 0LL)  // 0 は初期値
#define min_vec(vec) min_element(all(vec))  // iterator: * を先頭につける
#define max_vec(vec) max_element(all(vec))  // iterator: * を先頭につける
#define idx(vec, element_iter) distance((vec).begin(), element_iter)
const ll INF = 1LL<<60;  // 10^18（const int inf = 1<<29;）
const double PI = acos(-1);

ll ctoll(const char c) {
    switch(c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default : return -1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    // input(sunippets: inpv, inpn, inps)
    string N;
    ll K;
    cin >> N >> K;
    
    // calculation
    ll res = 0;
    ll digits = (ll)N.size();
    ll top = ctoll(N[0]);
    
    // if (K == 1) {
    //     /* 0 出ない数字がちょうど 1 個
    //     以下 2 パターン
    //     - 1 桁の数字: 1 ~ 9
    //     - 最上位の数字が 1 ~ 9
    //     */
    //     if (digits == 1) {
    //         cout << N << "\n";
    //     } else {
    //         res += (digits-1)*9;  // (digits-1)桁まで
    //         res += ctoll(N[0]);
    //         cout << res << "\n";
    //     }
    // } else if (K == 2) {
    //     /* 0 出ない数字がちょうど 2 個
    //     以下 x パターン
    //     - 2 桁の数字: 11-19, 21-99, 
    //     - 最上位の数字が 1 ~ 9
    //     */
    //    if (digits == 1) {
    //        // 該当なし
    //        cout << 0 << "\n";
    //    } else if (digits == 2) {
    //        // (最上位の数字-1) の桁で場合分け
    //        // ex) 53
    //        // 11-19, 21-29, 31-39, 41-49, 51-53
    //        res += (top-1)*9;
    //        res += ctoll(N[1]);  // 最上位の数字を考慮
    //        cout << res << "\n";
    //    } else {
             
    //    }
    // }
    
    
    return 0;
}

